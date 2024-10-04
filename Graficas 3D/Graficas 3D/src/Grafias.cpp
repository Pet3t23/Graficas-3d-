#include "BaseApp.h"

/**
 * @brief Punto de entrada de la aplicación.
 *
 * Este es el método principal que inicia la aplicación creando una instancia
 * de BaseApp y llamando a su método run() para ejecutar el ciclo de vida
 * de la aplicación.
 *
 * @return Un valor entero que indica el estado de la aplicación al cerrarse.
 */
int main() {
	BaseApp app; // Crea una instancia de BaseApp.
	return app.run(); // Llama al método run() para iniciar la aplicación.
}
