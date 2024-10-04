#pragma once
#include "Prerequisites.h"
#include "Component.h"

class Window;

/**
 * @class Entity
 * @brief Clase base abstracta para todas las entidades del juego.
 *
 * Una entidad es cualquier objeto en el juego que puede tener componentes. La clase
 * `Entity` gestiona los componentes asociados y define las interfaces para actualizar
 * y renderizar entidades en el juego.
 */
class Entity {
public:
    /**
     * @brief Destructor virtual.
     *
     * Asegura que al destruir una entidad, todos sus recursos y componentes se liberen
     * correctamente.
     */
    virtual ~Entity() = default;

    /**
     * @brief M�todo virtual puro para actualizar la entidad.
     * @param deltaTime El tiempo transcurrido desde la �ltima actualizaci�n.
     *
     * Este m�todo debe ser implementado por las clases derivadas y define el comportamiento
     * que debe ocurrir en cada fotograma de la entidad, como la l�gica de movimiento o interacci�n.
     */
    virtual void update(float deltaTime) = 0;

    /**
     * @brief M�todo virtual puro para renderizar la entidad.
     * @param window Contexto del dispositivo para operaciones gr�ficas.
     *
     * Debe ser implementado por las clases derivadas para definir c�mo se dibuja la entidad
     * en pantalla, utilizando la ventana o el contexto gr�fico proporcionado.
     */
    virtual void render(Window& window) = 0;

    /**
     * @brief Agrega un componente a la entidad.
     * @tparam T Tipo del componente que se va a agregar, debe derivar de Component.
     * @param component Puntero compartido al componente que se va a agregar.
     *
     * Este m�todo permite a�adir un nuevo componente a la entidad. Se asegura mediante
     * `static_assert` que el tipo T sea una subclase de `Component`, para garantizar que solo
     * componentes v�lidos puedan ser a�adidos.
     */
    template <typename T>
    void addComponent(EngineUtilities::TSharedPointer<T> component) {
        static_assert(std::is_base_of<Component, T>::value, "T must be derived from Component");
        components.push_back(component.template dynamic_pointer_cast<Component>());
    }

    /**
     * @brief Obtiene un componente de la entidad.
     * @tparam T Tipo del componente que se va a obtener.
     * @return Puntero compartido al componente, o nullptr si no se encuentra.
     *
     * Busca entre los componentes de la entidad uno que coincida con el tipo proporcionado.
     * Si lo encuentra, lo devuelve como un puntero compartido al tipo solicitado.
     */
    template<typename T>
    EngineUtilities::TSharedPointer<T> getComponent() {
        for (auto& component : components) {
            EngineUtilities::TSharedPointer<T> specificComponent = component.template dynamic_pointer_cast<T>();
            if (specificComponent) {
                return specificComponent;
            }
        }
        return EngineUtilities::TSharedPointer<T>();
    }

protected:
    bool isActive; ///< Estado de la entidad, indica si est� activa o no.
    int id; ///< Identificador �nico de la entidad.

    /**
     * @brief Lista de componentes asociados a la entidad.
     *
     * Cada entidad puede tener varios componentes que gestionan diferentes aspectos
     * de su comportamiento (f�sica, renderizado, audio, etc.).
     */
    std::vector<EngineUtilities::TSharedPointer<Component>> components;
};
