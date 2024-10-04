#pragma once
#include "Prerequisites.h"
#include "Window.h"
#include "ShapeFactory.h"
#include "Actor.h"

/**
 * @class BaseApp
 * @brief Clase base para la aplicación principal.
 *
 * Esta clase gestiona el ciclo de vida de la aplicación, incluyendo la inicialización,
 * actualización por fotogramas y renderización. También controla las entidades
 * en el contexto de la aplicación.
 */
class BaseApp {
public:
    /**
     * @brief Constructor por defecto.
     *
     * Inicializa la aplicación sin ninguna configuración inicial específica.
     */
    BaseApp() = default;

    /**
     * @brief Destructor por defecto.
     *
     * Libera cualquier recurso asignado durante la ejecución de la aplicación.
     */
    ~BaseApp() = default;

    /**
     * @brief Ejecuta la aplicación principal.
     * @return Código de estado de la ejecución (0 para éxito).
     *
     * Esta función se encarga de arrancar la aplicación y gestionar el ciclo de ejecución
     * principal.
     */
    int run();

    /**
     * @brief Inicializa la aplicación.
     * @return `true` si la inicialización fue exitosa, `false` en caso contrario.
     *
     * Se encarga de inicializar todos los recursos, actores y ventanas que la aplicación
     * necesita para funcionar.
     */
    bool initialize();

    /**
     * @brief Actualiza el estado de la aplicación por cada fotograma.
     *
     * Este método es llamado en cada fotograma y maneja las actualizaciones lógicas,
     * incluyendo el movimiento y las interacciones de los actores.
     */
    void update();

    /**
     * @brief Renderiza el contenido de la aplicación.
     *
     * Dibuja todos los elementos en pantalla usando el contexto de renderizado
     * proporcionado por la ventana.
     */
    void render();

    /**
     * @brief Limpia los recursos utilizados por la aplicación.
     *
     * Se encarga de liberar la memoria y los recursos asignados durante la ejecución
     * de la aplicación, asegurando que todo se cierre correctamente.
     */
    void cleanup();

    /**
     * @brief Actualiza el movimiento de un actor.
     * @param deltaTime Tiempo transcurrido desde el último fotograma.
     * @param circle Puntero compartido al actor que representa un círculo.
     *
     * Esta función ajusta la posición del actor circulo en base al tiempo transcurrido
     * y a la lógica de movimiento, como seguir waypoints.
     */
    void updateMovement(float deltaTime, EngineUtilities::TSharedPointer<Actor> circle);

private:
    sf::Clock clock;   ///< Reloj para medir el tiempo transcurrido entre fotogramas.
    sf::Time deltaTime; ///< Tiempo transcurrido desde el último fotograma.

    Window* m_window;  ///< Puntero a la ventana principal de la aplicación.
    EngineUtilities::TSharedPointer<Actor> Triangle; ///< Actor que representa un triángulo.
    EngineUtilities::TSharedPointer<Actor> Circle;   ///< Actor que representa un círculo.

    /**
     * @brief Índice del waypoint actual que el actor sigue.
     *
     * Esta variable indica cuál es el waypoint actual al que el actor se está
     * moviendo.
     */
    int currentWaypoint = 0;

    /**
     * @brief Waypoints que el actor sigue.
     *
     * Define un conjunto de posiciones en pantalla por las que el actor debe
     * moverse.
     */
    std::vector<sf::Vector2f> waypoints = {
      {100.0f, 100.0f},
      {400.0f, 100.0f},
      {400.0f, 400.0f},
      {100.0f, 400.0f}
    };
};
