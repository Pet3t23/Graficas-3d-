#include "BaseApp.h"

/**
 * @brief Ejecuta la aplicaci�n.
 *
 * Este m�todo inicializa la aplicaci�n, maneja eventos, actualiza el estado y
 * renderiza los objetos en un bucle hasta que la ventana se cierre.
 *
 * @return Un valor entero que indica el estado de la ejecuci�n.
 */
int BaseApp::run() {
	if (!initialize()) {
		ERROR("BaseApp", "run", "Initializes result on a false statemente, check method validations");
	}
	while (m_window->isOpen()) {
		m_window->handleEvents();
		deltaTime = clock.restart();
		update();
		render();
	}

	cleanup();
	return 0;
}

/**
 * @brief Inicializa la ventana y los actores.
 *
 * Este m�todo crea una nueva ventana y establece los actores (Circle y Triangle)
 * junto con sus componentes iniciales.
 *
 * @return true si la inicializaci�n es exitosa, false en caso contrario.
 */
bool BaseApp::initialize() {
	m_window = new Window(800, 600, "Galvan Engine");
	if (!m_window) {
		ERROR("BaseApp", "initialize", "Error on window creation, var is null");
		return false;
	}

	// Triangle Actor
	Circle = EngineUtilities::MakeShared<Actor>("Circle");
	if (!Circle.isNull()) {
		Circle->getComponent<ShapeFactory>()->createShape(ShapeType::CIRCLE);
		Circle->getComponent<ShapeFactory>()->setPosition(200.0f, 200.0f);
		Circle->getComponent<ShapeFactory>()->setFillColor(sf::Color::Blue);
	}

	// Triangle Actor
	Triangle = EngineUtilities::MakeShared<Actor>("Triangle");
	if (!Triangle.isNull()) {
		Triangle->getComponent<ShapeFactory>()->createShape(ShapeType::TRIANGLE);
	}

	return true;
}

/**
 * @brief Actualiza la l�gica de la aplicaci�n.
 *
 * Este m�todo se encarga de obtener la posici�n del mouse y actualiza el movimiento
 * del c�rculo hacia esa posici�n. Tambi�n gestiona el recorrido entre los puntos de
 * referencia definidos.
 */
void BaseApp::update() {
	// Mouse Position
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window->getWindow());
	sf::Vector2f mousePosF(static_cast<float>(mousePosition.x),
		static_cast<float>(mousePosition.y));

	if (!Circle.isNull()) {
		/*Circle->getComponent<ShapeFactory>()->Seek(mousePosF,
																							 200.0f,
																							 deltaTime.asSeconds(),
																							 10.0f);*/
		updateMovement(deltaTime.asSeconds(), Circle);
	}
}

/**
 * @brief Renderiza los actores en la ventana.
 *
 * Este m�todo limpia la ventana y dibuja los actores (Circle y Triangle)
 * antes de mostrar el contenido actualizado en pantalla.
 */
void BaseApp::render() {
	m_window->clear();
	Circle->render(*m_window);
	Triangle->render(*m_window);
	m_window->display();
}

/**
 * @brief Limpia y libera los recursos utilizados por la aplicaci�n.
 *
 * Este m�todo destruye la ventana y libera la memoria asociada a ella.
 */
void BaseApp::cleanup() {
	m_window->destroy();
	delete m_window;
}

/**
 * @brief Actualiza el movimiento del c�rculo hacia el punto de recorrido actual.
 * @param deltaTime El tiempo transcurrido desde la �ltima actualizaci�n.
 * @param circle Un puntero compartido al actor que representa el c�rculo.
 *
 * Este m�todo verifica si el c�rculo ha alcanzado su destino y, en caso
 * afirmativo, pasa al siguiente punto de referencia en el recorrido.
 */
void BaseApp::updateMovement(float deltaTime, EngineUtilities::TSharedPointer<Actor> circle) {
	// Verificar si el Circle es nulo
	if (!circle || circle.isNull()) return;

	// Posici�n actual del destino (punto de recorrido)
	sf::Vector2f targetPos = waypoints[currentWaypoint];

	// Llamar al Seek hacia el punto de recorrido actual
	circle->getComponent<ShapeFactory>()->Seek(targetPos, 200.0f, deltaTime, 10.0f);

	// Obtener la posici�n actual del actor
	sf::Vector2f currentPos = circle->getComponent<ShapeFactory>()->getShape()->getPosition();

	// Comprobar si el actor ha alcanzado el destino (o est� cerca)
	float distanceToTarget = std::sqrt(std::pow(targetPos.x - currentPos.x, 2) + std::pow(targetPos.y - currentPos.y, 2));

	if (distanceToTarget < 10.0f) { // Umbral para considerar que ha llegado
		// Pasar al siguiente waypoint
		currentWaypoint = (currentWaypoint + 1) % waypoints.size(); // Ciclar a trav�s de los puntos
	}
}
