#pragma once
class Window;

/**
 * @enum ComponentType
 * @brief Define los diferentes tipos de componentes disponibles en el juego.
 *
 * Cada componente tiene un tipo asociado que permite categorizar su funcionalidad.
 * Esto facilita la gesti�n y la identificaci�n de los componentes en el sistema de juego.
 */
enum ComponentType {
	NONE = 0,      ///< Componente vac�o o no inicializado.
	TRANSFORM = 1, ///< Componente de transformaci�n (posici�n, rotaci�n, escala).
	SPRITE = 2,    ///< Componente gr�fico que maneja sprites.
	RENDERER = 3,  ///< Componente encargado de renderizar gr�ficos.
	PHYSICS = 4,   ///< Componente que gestiona la f�sica del objeto.
	AUDIOSOURCE = 5,///< Componente de fuente de audio para reproducir sonidos.
	SHAPE = 6,     ///< Componente que maneja formas geom�tricas.
};

/**
 * @class Component
 * @brief Clase base abstracta para todos los componentes del juego.
 *
 * La clase Component proporciona una interfaz gen�rica que define el comportamiento
 * que debe implementar cualquier componente del sistema. Los componentes son
 * actualizables y renderizables, y cada uno tiene un tipo que define su funcionalidad.
 */
class Component {
public:
	/**
	 * @brief Constructor por defecto.
	 *
	 * Inicializa el componente sin ning�n tipo asociado. Este constructor es �til
	 * para subclases que definir�n el tipo m�s adelante.
	 */
	Component() = default;

	/**
	 * @brief Constructor con tipo de componente.
	 * @param type Tipo del componente.
	 *
	 * Permite crear un componente y asignarle un tipo espec�fico desde el inicio.
	 */
	Component(const ComponentType type) : m_type(type) {}

	/**
	 * @brief Destructor virtual.
	 *
	 * Se asegura de que las clases derivadas puedan limpiar correctamente sus
	 * recursos cuando sean destruidas.
	 */
	virtual ~Component() = default;

	/**
	 * @brief M�todo virtual puro para actualizar el componente.
	 * @param deltaTime El tiempo transcurrido desde la �ltima actualizaci�n.
	 *
	 * Este m�todo debe ser implementado por las clases derivadas para definir
	 * el comportamiento de actualizaci�n del componente en cada fotograma.
	 */
	virtual void update(float deltaTime) = 0;

	/**
	 * @brief M�todo virtual puro para renderizar el componente.
	 * @param window Contexto del dispositivo para operaciones gr�ficas.
	 *
	 * Este m�todo debe ser implementado por las clases derivadas para definir
	 * c�mo se debe dibujar el componente en pantalla.
	 */
	virtual void render(Window window) = 0;

	/**
	 * @brief Obtiene el tipo del componente.
	 * @return El tipo del componente.
	 *
	 * Devuelve el tipo espec�fico de componente, permitiendo su identificaci�n
	 * y clasificaci�n dentro del sistema.
	 */
	ComponentType getType() const { return m_type; }

protected:
	ComponentType m_type; ///< Tipo de componente que define su funcionalidad.
};
