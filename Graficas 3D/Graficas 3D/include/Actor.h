#pragma once
#include "Prerequisites.h"
#include "Entity.h"
#include "ShapeFactory.h"

/**
 * @class Actor
 * @brief Clase que representa a un actor dentro del motor de juego.
 *
 * La clase Actor hereda de Entity y act�a como una entidad que puede ser
 * renderizada y actualizada en el contexto del juego. Los actores pueden
 * tener m�ltiples componentes para manejar diferentes aspectos de su
 * comportamiento.
 */
class Actor : public Entity {
public:
    /**
     * @brief Constructor por defecto.
     *
     * Crea un actor sin inicializar ning�n valor espec�fico.
     * Este constructor es �til cuando se necesita un actor vac�o para ser
     * configurado posteriormente.
     */
    Actor() = default;

    /**
     * @brief Constructor con un nombre espec�fico para el actor.
     * @param actorName Nombre del actor.
     *
     * Permite crear un actor asign�ndole un nombre espec�fico para su identificaci�n.
     */
    Actor(std::string actorName);

    /**
     * @brief Destructor virtual.
     *
     * Libera los recursos asociados con el actor cuando este es destruido.
     * Al ser virtual, asegura que se llame el destructor de las clases derivadas
     * si las hay.
     */
    virtual ~Actor() = default;

    /**
     * @brief Actualiza el actor.
     * @param deltaTime El tiempo transcurrido desde la �ltima actualizaci�n.
     *
     * Este m�todo actualiza el estado del actor en funci�n del tiempo transcurrido.
     * Se utiliza para realizar c�lculos de movimiento, l�gica del juego, entre otros.
     */
    void update(float deltaTime) override;

    /**
     * @brief Renderiza el actor.
     * @param window Contexto del dispositivo para operaciones gr�ficas.
     *
     * Dibuja el actor en la pantalla utilizando el contexto gr�fico proporcionado.
     */
    void render(Window& window) override;

    /**
     * @brief Destruye el actor y libera los recursos asociados.
     *
     * Llama a las rutinas necesarias para liberar la memoria y otros recursos
     * que el actor pueda estar utilizando.
     */
    void destroy();

    /**
     * @brief Obtiene un componente espec�fico del actor.
     * @tparam T Tipo del componente que se va a obtener.
     * @return Puntero compartido al componente, o nullptr si no se encuentra.
     *
     * Este m�todo busca entre los componentes del actor uno que coincida
     * con el tipo proporcionado. Si lo encuentra, lo devuelve como un puntero
     * compartido. Si no lo encuentra, devuelve nullptr.
     */
    template <typename T>
    EngineUtilities::TSharedPointer<T> getComponent();

private:
    std::string m_name = "Actor"; ///< Nombre del actor.
};

/**
 * @brief Implementaci�n de getComponent.
 *
 * Busca entre los componentes del actor uno que coincida con el tipo
 * especificado en la plantilla. Utiliza dynamic_pointer_cast para intentar
 * convertir el componente al tipo solicitado.
 *
 * @tparam T Tipo del componente que se va a obtener.
 * @return Un puntero compartido al componente, o un puntero vac�o si no se encuentra.
 */
template<typename T>
inline EngineUtilities::TSharedPointer<T> Actor::getComponent() {
    for (auto& component : components) {
        EngineUtilities::TSharedPointer<T> specificComponent = component.template dynamic_pointer_cast<T>();
        if (specificComponent) {
            return specificComponent;
        }
    }
    // Devuelve un TSharedPointer vac�o si no se encuentra el componente
    return EngineUtilities::TSharedPointer<T>();
}
