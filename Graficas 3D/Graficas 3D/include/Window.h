#pragma once
#include "Prerequisites.h"

/**
 * @class Window
 * @brief Clase que representa una ventana de renderizado en la aplicación.
 *
 * `Window` gestiona la creación, actualización y renderizado de una ventana
 * utilizando la biblioteca SFML. Permite manejar eventos de entrada y
 * dibujar objetos en la ventana.
 */
class Window {
public:
	/**
	 * @brief Constructor por defecto.
	 *
	 * Inicializa un objeto `Window` sin dimensiones específicas o título.
	 */
	Window() = default;

	/**
	 * @brief Constructor que inicializa la ventana con dimensiones y título.
	 * @param width Ancho de la ventana.
	 * @param height Alto de la ventana.
	 * @param title Título de la ventana.
	 *
	 * Este constructor establece las dimensiones y el título de la ventana
	 * al momento de su creación.
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
	 * Este método procesa eventos como teclas, ratón y otros eventos
	 * del sistema operativo que afectan la ventana.
	 */
	void handleEvents();

	/**
	 * @brief Limpia el contenido de la ventana con el color predeterminado.
	 *
	 * Este método restablece el contenido de la ventana a un estado vacío,
	 * utilizando el color de fondo predeterminado.
	 */
	void clear();

	/**
	 * @brief Muestra el contenido de la ventana en la pantalla.
	 *
	 * Este método presenta todos los cambios realizados en la ventana
	 * desde la última vez que se limpió o se actualizó.
	 */
	void display();

	/**
	 * @brief Verifica si la ventana sigue abierta.
	 *
	 * @return true si la ventana está abierta, false en caso contrario.
	 *
	 * Este método permite comprobar el estado actual de la ventana para
	 * determinar si debe continuar procesando eventos y renderizando.
	 */
	bool isOpen() const;

	/**
	 * @brief Dibuja un objeto que puede ser dibujado en la ventana.
	 * @param drawable Referencia a un objeto SFML que puede ser dibujado.
	 *
	 * Este método permite agregar un objeto gráfico a la ventana para
	 * que sea renderizado en la próxima actualización.
	 */
	void draw(const sf::Drawable& drawable);

	/**
	 * @brief Obtiene el objeto interno SFML RenderWindow.
	 *
	 * @return Un puntero al objeto interno SFML RenderWindow.
	 *
	 * Este método proporciona acceso directo al objeto de ventana de
	 * SFML, permitiendo manipulaciones más específicas si es necesario.
	 */
	sf::RenderWindow* getWindow();

	/**
	 * @brief Inicializa la ventana.
	 *
	 * Este método se encarga de realizar las operaciones de inicialización
	 * necesarias para configurar la ventana antes de su uso.
	 */
	void init();

	/**
	 * @brief Actualiza la ventana en cada frame.
	 *
	 * Este método se invoca en cada frame para realizar las actualizaciones
	 * necesarias para mantener la ventana en un estado adecuado.
	 */
	void update();

	/**
	 * @brief Renderiza el contenido de la ventana.
	 *
	 * Este método se encarga de dibujar todos los elementos en la ventana
	 * en cada frame.
	 */
	void render();

	/**
	 * @brief Destruye la ventana y libera los recursos asociados.
	 *
	 * Este método realiza las operaciones necesarias para cerrar la
	 * ventana de manera segura y liberar todos los recursos que utilizó.
	 */
	void destroy();

private:
	sf::RenderWindow* m_window; ///< Puntero al objeto interno SFML RenderWindow.
};
