#pragma once
#include "Prerequisites.h"
#include "Window.h"
#include "ShapeFactory.h"
#include "Actor.h"

/**
 * @class BaseApp
 * @brief Clase base para la aplicaci�n principal.
 *
 * Esta clase gestiona el ciclo de vida de la aplicaci�n, incluyendo la inicializaci�n,
 * actualizaci�n por fotogramas y renderizaci�n. Tambi�n controla las entidades
 * en el contexto de la aplicaci�n.
 */
class BaseApp {
public:
    /**
     * @brief Constructor por defecto.
     *
     * Inicializa la aplicaci�n sin ninguna configuraci�n inicial espec�fica.
     */
    BaseApp() = default;

    /**
     * @brief Destructor por defecto.
     *
     * Libera cualquier recurso asignado durante la ejecuci�n de la aplicaci�n.
     */
    ~BaseApp() = default;

    /**
     * @brief Ejecuta la aplicaci�n principal.
     * @return C�digo de estado de la ejecuci�n (0 para �xito).
     *
     * Esta funci�n se encarga de arrancar la aplicaci�n y gestionar el ciclo de ejecuci�n
     * principal.
     */
    int run();

    /**
     * @brief Inicializa la aplicaci�n.
     * @return `true` si la inicializaci�n fue exitosa, `false` en caso contrario.
     *
     * Se encarga de inicializar todos los recursos, actores y ventanas que la aplicaci�n
     * necesita para funcionar.
     */
    bool initialize();

    /**
     * @brief Actualiza el estado de la aplicaci�n por cada fotograma.
     *
     * Este m�todo es llamado en cada fotograma y maneja las actualizaciones l�gicas,
     * incluyendo el movimiento y las interacciones de los actores.
     */
    void update();

    /**
     * @brief Renderiza el contenido de la aplicaci�n.
     *
     * Dibuja todos los elementos en pantalla usando el contexto de renderizado
     * proporcionado por la ventana.
     */
    void render();

    /**
     * @brief Limpia los recursos utilizados por la aplicaci�n.
     *
     * Se encarga de liberar la memoria y los recursos asignados durante la ejecuci�n
     * de la aplicaci�n, asegurando que todo se cierre correctamente.
     */
    void cleanup();

    /**
     * @brief Actualiza el movimiento de un actor.
     * @param deltaTime Tiempo transcurrido desde el �ltimo fotograma.
     * @param circle Puntero compartido al actor que representa un c�rculo.
     *
     * Esta funci�n ajusta la posici�n del actor circulo en base al tiempo transcurrido
     * y a la l�gica de movimiento, como seguir waypoints.
     */
    void updateMovement(float deltaTime, EngineUtilities::TSharedPointer<Actor> circle);

private:
    sf::Clock clock;   ///< Reloj para medir el tiempo transcurrido entre fotogramas.
    sf::Time deltaTime; ///< Tiempo transcurrido desde el �ltimo fotograma.

    Window* m_window;  ///< Puntero a la ventana principal de la aplicaci�n.
    EngineUtilities::TSharedPointer<Actor> Triangle; ///< Actor que representa un tri�ngulo.
    EngineUtilities::TSharedPointer<Actor> Circle;   ///< Actor que representa un c�rculo.

    /**
     * @brief �ndice del waypoint actual que el actor sigue.
     *
     * Esta variable indica cu�l es el waypoint actual al que el actor se est�
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
