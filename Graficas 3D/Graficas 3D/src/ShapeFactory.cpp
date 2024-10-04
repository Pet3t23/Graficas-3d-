#include "ShapeFactory.h"

/**
 * @brief Crea una forma basada en el tipo especificado.
 *
 * Esta funci�n inicializa un nuevo objeto de forma (c�rculo, rect�ngulo o tri�ngulo)
 * dependiendo del tipo proporcionado. Establece el color de llenado predeterminado
 * como blanco.
 *
 * @param shapeType Tipo de forma a crear.
 * @return Un puntero a la forma creada, o nullptr si el tipo es EMPTY.
 */
sf::Shape* ShapeFactory::createShape(ShapeType shapeType) {
	m_shapeType = shapeType; // Establece el tipo de forma.
	switch (shapeType) {
	case EMPTY: {
		return nullptr; // Devuelve nullptr si el tipo es EMPTY.
	}
	case CIRCLE: {
		sf::CircleShape* circle = new sf::CircleShape(10.0f); // Crea un c�rculo de radio 10.
		circle->setFillColor(sf::Color::White); // Establece el color de llenado.
		m_shape = circle; // Almacena la forma creada.
		return circle; // Devuelve el puntero al c�rculo.
	}
	case RECTANGLE: {
		sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2(100.0f, 50.0f)); // Crea un rect�ngulo.
		rectangle->setFillColor(sf::Color::White); // Establece el color de llenado.
		m_shape = rectangle; // Almacena la forma creada.
		return rectangle; // Devuelve el puntero al rect�ngulo.
	}
	case TRIANGLE: {
		sf::CircleShape* triangle = new sf::CircleShape(50.0f, 3); // Crea un tri�ngulo con radio 50.
		triangle->setFillColor(sf::Color::White); // Establece el color de llenado.
		m_shape = triangle; // Almacena la forma creada.
		return triangle; // Devuelve el puntero al tri�ngulo.
	}
	default:
		return nullptr; // Devuelve nullptr si el tipo no es v�lido.
	}
}

/**
 * @brief Establece la posici�n de la forma.
 *
 * Esta funci�n coloca la forma en las coordenadas (x, y) especificadas.
 *
 * @param x Coordenada x de la posici�n deseada.
 * @param y Coordenada y de la posici�n deseada.
 */
void ShapeFactory::setPosition(float x, float y) {
	m_shape->setPosition(x, y); // Establece la posici�n de la forma.
}

/**
 * @brief Establece la posici�n de la forma usando un vector.
 *
 * Esta funci�n coloca la forma en la posici�n especificada por el vector.
 *
 * @param position Vector que contiene las coordenadas de la posici�n deseada.
 */
void ShapeFactory::setPosition(const sf::Vector2f& position) {
	m_shape->setPosition(position); // Establece la posici�n de la forma.
}

/**
 * @brief Establece el color de llenado de la forma.
 *
 * Esta funci�n cambia el color de llenado de la forma a uno nuevo.
 *
 * @param color Color a establecer como nuevo color de llenado.
 */
void ShapeFactory::setFillColor(const sf::Color& color) {
	m_shape->setFillColor(color); // Cambia el color de llenado de la forma.
}

/**
 * @brief Mueve la forma hacia una posici�n objetivo.
 *
 * Esta funci�n calcula la direcci�n hacia la posici�n objetivo y mueve la forma
 * en esa direcci�n si la distancia a la posici�n objetivo es mayor que el rango
 * especificado.
 *
 * @param targetPosition Posici�n objetivo a la que se desea mover la forma.
 * @param speed Velocidad a la que se mover� la forma.
 * @param deltaTime Tiempo transcurrido desde la �ltima actualizaci�n.
 * @param range Rango dentro del cual la forma no se mover� hacia el objetivo.
 */
void ShapeFactory::Seek(const sf::Vector2f& targetPosition, float speed, float deltaTime, float range) {
	// Obtener la posici�n actual de la forma.
	sf::Vector2f shapePosition = m_shape->getPosition();

	// Calcular la direcci�n desde la forma hacia el objetivo.
	sf::Vector2f direction = targetPosition - shapePosition;

	// Calcular la distancia al objetivo.
	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	// Si la distancia es mayor que el rango, mover la forma hacia el objetivo.
	if (length > range) {
		direction /= length; // Normaliza la direcci�n.
		m_shape->move(direction * speed * deltaTime); // Mueve la forma en la direcci�n calculada.
	}
}
