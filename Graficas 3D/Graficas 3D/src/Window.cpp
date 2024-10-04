#include "Window.h"

/**
 * @brief Constructor de la clase Window.
 *
 * Este constructor inicializa una ventana de SFML con las dimensiones y título
 * especificados. Se utiliza para crear el contexto gráfico de la aplicación.
 *
 * @param width Ancho de la ventana.
 * @param height Alto de la ventana.
 * @param title Título de la ventana.
 */
Window::Window(int width, int height, const std::string& title) {
	m_window = new sf::RenderWindow(sf::VideoMode(width, height), title);

	if (!m_window) {
		ERROR("Window", "Window", "CHECK CONSTRUCTOR"); // Manejo de errores en caso de fallo al crear la ventana.
	}
	else {
		MESSAGE("Window", "Window", "OK"); // Mensaje de confirmación.
	}
}

/**
 * @brief Destructor de la clase Window.
 *
 * Este destructor libera la memoria asignada a la ventana de SFML.
 */
Window::~Window() {
	delete m_window; // Liberación de recursos.
}

/**
 * @brief Maneja los eventos de la ventana.
 *
 * Este método procesa todos los eventos de la ventana, como la solicitud de cierre.
 */
void Window::handleEvents() {
	sf::Event event;
	while (m_window->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
			m_window->close(); // Cierra la ventana si se recibe el evento de cierre.
	}
}

/**
 * @brief Limpia el contenido de la ventana.
 *
 * Este método borra el contenido actual de la ventana, preparándola para un nuevo
 * renderizado.
 */
void Window::clear() {
	if (m_window != nullptr) {
		m_window->clear(); // Limpia la ventana.
	}
	else {
		ERROR("Window", "clear", "CHECK FOR WINDOW POINTER DATA"); // Manejo de errores.
	}
}

/**
 * @brief Muestra el contenido actual de la ventana.
 *
 * Este método actualiza la ventana para mostrar el contenido que ha sido dibujado
 * desde la última llamada a clear().
 */
void Window::display() {
	if (m_window != nullptr) {
		m_window->display(); // Muestra el contenido de la ventana.
	}
	else {
		ERROR("Window", "display", "CHECK FOR WINDOW POINTER DATA"); // Manejo de errores.
	}
}

/**
 * @brief Verifica si la ventana está abierta.
 *
 * Este método comprueba el estado de la ventana.
 *
 * @return true si la ventana está abierta, false en caso contrario.
 */
bool Window::isOpen() const {
	if (m_window != nullptr) {
		return m_window->isOpen(); // Devuelve el estado de apertura de la ventana.
	}
	else {
		ERROR("Window", "isOpen", "CHECK FOR WINDOW POINTER DATA"); // Manejo de errores.
		return false; // Retorna false si hay un problema con el puntero.
	}
}

/**
 * @brief Dibuja un objeto en la ventana.
 *
 * Este método dibuja un objeto que implementa la interfaz sf::Drawable
 * en la ventana.
 *
 * @param drawable Referencia al objeto a dibujar.
 */
void Window::draw(const sf::Drawable& drawable) {
	if (m_window != nullptr) {
		m_window->draw(drawable); // Dibuja el objeto en la ventana.
	}
	else {
		ERROR("Window", "draw", "CHECK FOR WINDOW POINTER DATA"); // Manejo de errores.
	}
}

/**
 * @brief Obtiene el puntero a la ventana de SFML.
 *
 * Este método devuelve el puntero a la ventana de SFML.
 *
 * @return Un puntero a la ventana de SFML, o nullptr si hay un problema con el puntero.
 */
sf::RenderWindow* Window::getWindow() {
	if (m_window != nullptr) {
		return m_window; // Devuelve el puntero a la ventana.
	}
	else {
		ERROR("Window", "getWindow", "CHECK FOR WINDOW POINTER DATA"); // Manejo de errores.
		return nullptr; // Retorna nullptr si hay un problema.
	}
}

/**
 * @brief Libera los recursos de la ventana.
 *
 * Este método libera la memoria asignada a la ventana de SFML, asegurando que
 * no haya fugas de memoria.
 */
void Window::destroy() {
	SAFE_PTR_RELEASE(m_window); // Llama a la macro para liberar el puntero.
}
