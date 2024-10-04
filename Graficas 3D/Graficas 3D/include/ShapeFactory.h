#pragma once
#include "Prerequisites.h"
#include "Component.h"
#include "Window.h"

/**
 * @class ShapeFactory
 * @brief Clase que se encarga de crear y gestionar formas geom�tricas.
 *
 * `ShapeFactory` es un componente que proporciona funcionalidad para crear
 * diferentes tipos de formas (como c�rculos, rect�ngulos y tri�ngulos) y
 * manejar sus propiedades, como posici�n y color de relleno. Esta clase
 * hereda de `Component` y se integra en el sistema de componentes del juego.
 */
class ShapeFactory : public Component {
public:
	/**
	 * @brief Constructor por defecto.
	 *
	 * Inicializa un objeto `ShapeFactory` sin una forma espec�fica.
	 */
	ShapeFactory() = default;

	/**
	 * @brief Destructor virtual.
	 *
	 * Libera los recursos asociados a la instancia de `ShapeFactory`.
	 */
	virtual ~ShapeFactory() = default;

	/**
	 * @brief Constructor que inicializa el tipo de forma.
	 * @param shapeType Tipo de forma a crear.
	 *
	 * Este constructor establece el tipo de forma y asigna el tipo de componente
	 * correspondiente.
	 */
	ShapeFactory(ShapeType shapeType) :
		m_shape(nullptr), m_shapeType(ShapeType::EMPTY), Component(ComponentType::SHAPE) {}

	/**
	 * @brief Crea una forma seg�n el tipo especificado.
	 * @param shapeType Tipo de forma que se desea crear.
	 * @return Puntero a la forma creada, o nullptr si no se puede crear.
	 *
	 * Este m�todo utiliza el tipo de forma proporcionado para instanciar y
	 * devolver la forma correspondiente.
	 */
	sf::Shape* createShape(ShapeType shapeType);

	/**
	 * @brief Actualiza el componente de forma.
	 * @param deltaTime El tiempo transcurrido desde la �ltima actualizaci�n.
	 *
	 * Este m�todo no realiza ninguna acci�n, pero debe ser implementado
	 * para cumplir con la interfaz de `Component`.
	 */
	void update(float deltaTime) override {}

	/**
	 * @brief Renderiza el componente de forma.
	 * @param window Contexto del dispositivo para operaciones gr�ficas.
	 *
	 * Este m�todo no realiza ninguna acci�n, pero debe ser implementado
	 * para cumplir con la interfaz de `Component`.
	 */
	void render(Window window) override {}

	/**
	 * @brief Establece la posici�n de la forma.
	 * @param x Coordenada X de la nueva posici�n.
	 * @param y Coordenada Y de la nueva posici�n.
	 *
	 * Este m�todo actualiza la posici�n de la forma en las coordenadas
	 * especificadas.
	 */
	void setPosition(float x, float y);

	/**
	 * @brief Establece la posici�n de la forma.
	 * @param position Nueva posici�n como un vector 2D.
	 *
	 * Este m�todo actualiza la posici�n de la forma utilizando un
	 * vector 2D para especificar las coordenadas.
	 */
	void setPosition(const sf::Vector2f& position);

	/**
	 * @brief Establece el color de relleno de la forma.
	 * @param color Color de relleno que se va a aplicar a la forma.
	 *
	 * Este m�todo permite definir el color de relleno de la forma
	 * creada por la instancia de `ShapeFactory`.
	 */
	void setFillColor(const sf::Color& color);

	/**
	 * @brief Realiza una b�squeda hacia una posici�n objetivo.
	 * @param targetPosition La posici�n objetivo a alcanzar.
	 * @param speed La velocidad de movimiento hacia la posici�n objetivo.
	 * @param deltaTime El tiempo transcurrido desde la �ltima actualizaci�n.
	 * @param range Distancia m�nima para considerar que se ha alcanzado el objetivo.
	 *
	 * Este m�todo permite que la forma se mueva hacia una posici�n objetivo
	 * a una velocidad determinada.
	 */
	void Seek(const sf::Vector2f& targetPosition, float speed, float deltaTime, float range);

	/**
	 * @brief Obtiene la forma creada.
	 * @return Puntero a la forma actual.
	 *
	 * Este m�todo devuelve el puntero a la forma actualmente gestionada
	 * por la instancia de `ShapeFactory`.
	 */
	sf::Shape* getShape() {
		return m_shape;
	}

private:
	sf::Shape* m_shape; ///< Puntero a la forma creada.
	ShapeType m_shapeType; ///< Tipo de forma actual.
};
