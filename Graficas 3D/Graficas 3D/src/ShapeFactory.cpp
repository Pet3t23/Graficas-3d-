#include "ShapeFactory.h"

/**
 * @brief Crea una forma basada en el tipo especificado.
 *
 * Esta función inicializa un nuevo objeto de forma (círculo, rectángulo o triángulo)
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
		sf::CircleShape* circle = new sf::CircleShape(10.0f); // Crea un círculo de radio 10.
		circle->setFillColor(sf::Color::White); // Establece el color de llenado.
		m_shape = circle; // Almacena la forma creada.
		return circle; // Devuelve el puntero al círculo.
	}
	case RECTANGLE: {
		sf::RectangleShape* rectangle = new sf::RectangleShape(sf::Vector2(100.0f, 50.0f)); // Crea un rectángulo.
		rectangle->setFillColor(sf::Color::White); // Establece el color de llenado.
		m_shape = rectangle; // Almacena la forma creada.
		return rectangle; // Devuelve el puntero al rectángulo.
	}
	case TRIANGLE: {
		sf::CircleShape* triangle = new sf::CircleShape(50.0f, 3); // Crea un triángulo con radio 50.
		triangle->setFillColor(sf::Color::White); // Establece el color de llenado.
		m_shape = triangle; // Almacena la forma creada.
		return triangle; // Devuelve el puntero al triángulo.
	}
	default:
		return nullptr; // Devuelve nullptr si el tipo no es válido.
	}
}

/**
 * @brief Establece la posición de la forma.
 *
 * Esta función coloca la forma en las coordenadas (x, y) especificadas.
 *
 * @param x Coordenada x de la posición deseada.
 * @param y Coordenada y de la posición deseada.
 */
void ShapeFactory::setPosition(float x, float y) {
	m_shape->setPosition(x, y); // Establece la posición de la forma.
}

/**
 * @brief Establece la posición de la forma usando un vector.
 *
 * Esta función coloca la forma en la posición especificada por el vector.
 *
 * @param position Vector que contiene las coordenadas de la posición deseada.
 */
void ShapeFactory::setPosition(const sf::Vector2f& position) {
	m_shape->setPosition(position); // Establece la posición de la forma.
}

/**
 * @brief Establece el color de llenado de la forma.
 *
 * Esta función cambia el color de llenado de la forma a uno nuevo.
 *
 * @param color Color a establecer como nuevo color de llenado.
 */
void ShapeFactory::setFillColor(const sf::Color& color) {
	m_shape->setFillColor(color); // Cambia el color de llenado de la forma.
}

/**
 * @brief Mueve la forma hacia una posición objetivo.
 *
 * Esta función calcula la dirección hacia la posición objetivo y mueve la forma
 * en esa dirección si la distancia a la posición objetivo es mayor que el rango
 * especificado.
 *
 * @param targetPosition Posición objetivo a la que se desea mover la forma.
 * @param speed Velocidad a la que se moverá la forma.
 * @param deltaTime Tiempo transcurrido desde la última actualización.
 * @param range Rango dentro del cual la forma no se moverá hacia el objetivo.
 */
void ShapeFactory::Seek(const sf::Vector2f& targetPosition, float speed, float deltaTime, float range) {
	// Obtener la posición actual de la forma.
	sf::Vector2f shapePosition = m_shape->getPosition();

	// Calcular la dirección desde la forma hacia el objetivo.
	sf::Vector2f direction = targetPosition - shapePosition;

	// Calcular la distancia al objetivo.
	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	// Si la distancia es mayor que el rango, mover la forma hacia el objetivo.
	if (length > range) {
		direction /= length; // Normaliza la dirección.
		m_shape->move(direction * speed * deltaTime); // Mueve la forma en la dirección calculada.
	}
}
