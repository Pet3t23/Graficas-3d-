#pragma once
#include "Prerequisites.h"

/**
 * @class Window
 * @brief Clase que representa una ventana de renderizado en la aplicaci�n.
 *
 * `Window` gestiona la creaci�n, actualizaci�n y renderizado de una ventana
 * utilizando la biblioteca SFML. Permite manejar eventos de entrada y
 * dibujar objetos en la ventana.
 */
class Window {
public:
	/**
	 * @brief Constructor por defecto.
	 *
	 * Inicializa un objeto `Window` sin dimensiones espec�ficas o t�tulo.
	 */
	Window() = default;

	/**
	 * @brief Constructor que inicializa la ventana con dimensiones y t�tulo.
	 * @param width Ancho de la ventana.
	 * @param height Alto de la ventana.
	 * @param title T�tulo de la ventana.
	 *
	 * Este constructor establece las dimensiones y el t�tulo de la ventana
	 * al momento de su creaci�n.
	 */
	Window(int width, int height, const std::string& title);

	/**
	 * @brief Destructor.
	 *
	 * Libera los recursos asociados a la ventana.
	 */
	~Window();

	/**
	 * @brief Maneja los eventos de entrada en la ventana.
	 *
	 * Este m�todo procesa eventos como teclas, rat�n y otros eventos
	 * del sistema operativo que afectan la ventana.
	 */
	void handleEvents();

	/**
	 * @brief Limpia el contenido de la ventana con el color predeterminado.
	 *
	 * Este m�todo restablece el contenido de la ventana a un estado vac�o,
	 * utilizando el color de fondo predeterminado.
	 */
	void clear();

	/**
	 * @brief Muestra el contenido de la ventana en la pantalla.
	 *
	 * Este m�todo presenta todos los cambios realizados en la ventana
	 * desde la �ltima vez que se limpi� o se actualiz�.
	 */
	void display();

	/**
	 * @brief Verifica si la ventana sigue abierta.
	 *
	 * @return true si la ventana est� abierta, false en caso contrario.
	 *
	 * Este m�todo permite comprobar el estado actual de la ventana para
	 * determinar si debe continuar procesando eventos y renderizando.
	 */
	bool isOpen() const;

	/**
	 * @brief Dibuja un objeto que puede ser dibujado en la ventana.
	 * @param drawable Referencia a un objeto SFML que puede ser dibujado.
	 *
	 * Este m�todo permite agregar un objeto gr�fico a la ventana para
	 * que sea renderizado en la pr�xima actualizaci�n.
	 */
	void draw(const sf::Drawable& drawable);

	/**
	 * @brief Obtiene el objeto interno SFML RenderWindow.
	 *
	 * @return Un puntero al objeto interno SFML RenderWindow.
	 *
	 * Este m�todo proporciona acceso directo al objeto de ventana de
	 * SFML, permitiendo manipulaciones m�s espec�ficas si es necesario.
	 */
	sf::RenderWindow* getWindow();

	/**
	 * @brief Inicializa la ventana.
	 *
	 * Este m�todo se encarga de realizar las operaciones de inicializaci�n
	 * necesarias para configurar la ventana antes de su uso.
	 */
	void init();

	/**
	 * @brief Actualiza la ventana en cada frame.
	 *
	 * Este m�todo se invoca en cada frame para realizar las actualizaciones
	 * necesarias para mantener la ventana en un estado adecuado.
	 */
	void update();

	/**
	 * @brief Renderiza el contenido de la ventana.
	 *
	 * Este m�todo se encarga de dibujar todos los elementos en la ventana
	 * en cada frame.
	 */
	void render();

	/**
	 * @brief Destruye la ventana y libera los recursos asociados.
	 *
	 * Este m�todo realiza las operaciones necesarias para cerrar la
	 * ventana de manera segura y liberar todos los recursos que utiliz�.
	 */
	void destroy();

private:
	sf::RenderWindow* m_window; ///< Puntero al objeto interno SFML RenderWindow.
};
