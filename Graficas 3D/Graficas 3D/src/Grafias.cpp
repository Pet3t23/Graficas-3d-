#include "BaseApp.h"

/**
 * @brief Punto de entrada de la aplicaci�n.
 *
 * Este es el m�todo principal que inicia la aplicaci�n creando una instancia
 * de BaseApp y llamando a su m�todo run() para ejecutar el ciclo de vida
 * de la aplicaci�n.
 *
 * @return Un valor entero que indica el estado de la aplicaci�n al cerrarse.
 */
int main() {
	BaseApp app; // Crea una instancia de BaseApp.
	return app.run(); // Llama al m�todo run() para iniciar la aplicaci�n.
}
