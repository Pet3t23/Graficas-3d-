#include "Actor.h"

/**
 * @brief Constructor que inicializa un actor con un nombre.
 * @param actorName El nombre del actor que se está creando.
 *
 * Este constructor configura el nombre del actor y agrega un componente
 * `ShapeFactory` para manejar la forma visual del actor.
 */
Actor::Actor(std::string actorName) {
	// Setup Actor Name
	m_name = actorName;

	// Setup Shape
	EngineUtilities::TSharedPointer<ShapeFactory> shape = EngineUtilities::MakeShared<ShapeFactory>();
	addComponent(shape);

	// Setup Transform
	// Aquí se pueden inicializar los componentes de transformación si es necesario.

	// Setup Sprite
	// Aquí se pueden inicializar los componentes de sprite si es necesario.
}

/**
 * @brief Actualiza el estado del actor.
 * @param deltaTime El tiempo transcurrido desde la última actualización.
 *
 * Este método se encarga de actualizar la lógica del actor. Actualmente,
 * no se ha implementado lógica específica en este método.
 */
void Actor::update(float deltaTime)
{
}

/**
 * @brief Renderiza el actor en la ventana.
 * @param window Contexto del dispositivo para operaciones gráficas.
 *
 * Este método recorre todos los componentes del actor y dibuja la forma
 * asociada al componente `ShapeFactory` en la ventana.
 */
void Actor::render(Window& window)
{
	for (unsigned int i = 0; i < components.size(); i++) {
		window.draw(*components[i].dynamic_pointer_cast<ShapeFactory>()->getShape());
	}
}

/**
 * @brief Destruye el actor y libera los recursos asociados.
 *
 * Este método es responsable de liberar los recursos utilizados por el
 * actor. Actualmente, no se ha implementado lógica específica en este método.
 */
void Actor::destroy()
{
}
