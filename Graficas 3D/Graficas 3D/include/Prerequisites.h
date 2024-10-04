#pragma once

// Librerías de la STL
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <thread>

// Librerías de terceros
#include <SFML/Graphics.hpp>
#include "Memory\TSharedPointer.h"
#include "Memory\TWeakPointer.h"
#include "Memory\TStaticPtr.h"
#include "Memory\TUniquePtr.h"

/**
 * @enum ShapeType
 * @brief Define los tipos de formas geométricas disponibles.
 *
 * Este enumerado se utiliza para clasificar las diferentes formas geométricas
 * que pueden ser representadas y gestionadas en el sistema.
 */
enum ShapeType {
    EMPTY = 0,    ///< Forma vacía o no inicializada.
    CIRCLE = 1,   ///< Forma de círculo.
    RECTANGLE = 2,///< Forma de rectángulo.
    TRIANGLE = 3  ///< Forma de triángulo.
};

// Macro para liberar de forma segura recursos de punteros
/**
 * @brief Macro para liberar de manera segura punteros.
 * @param x Puntero que se desea liberar.
 *
 * La macro comprueba si el puntero es diferente de `nullptr`, lo elimina
 * y luego lo establece en `nullptr` para evitar posibles referencias a memoria liberada.
 */
#define SAFE_PTR_RELEASE(x) if(x != nullptr) { delete x; x = nullptr; }

 // Macro para mostrar mensajes sobre el estado de los recursos
 /**
  * @brief Macro para mostrar mensajes informativos sobre la creación de recursos.
  * @param classObj Nombre de la clase donde ocurre el mensaje.
  * @param method Nombre del método donde ocurre el mensaje.
  * @param state Estado o descripción del recurso creado.
  *
  * Esta macro genera un mensaje que indica en qué clase y método se ha creado un recurso,
  * y muestra el estado del recurso para facilitar la depuración.
  */
#define MESSAGE(classObj, method, state)                      \
{                                                             \
    std::ostringstream os_;                                   \
    os_ << classObj << "::" << method << " : "                \
        << "[CREATION OF RESOURCE" << ": " << state "] \n";   \
    std::cerr << os_.str();                                   \
}

  // Macro para mostrar mensajes de error
  /**
   * @brief Macro para mostrar mensajes de error y finalizar el programa.
   * @param classObj Nombre de la clase donde ocurre el error.
   * @param method Nombre del método donde ocurre el error.
   * @param errorMSG Mensaje de error que describe el problema.
   *
   * Esta macro genera un mensaje de error detallado indicando en qué clase y método
   * ha ocurrido el problema, seguido de un mensaje específico del error. Tras mostrar
   * el mensaje, el programa se termina con `exit(1)` para evitar daños adicionales.
   */
#define ERROR(classObj, method, errorMSG)                         \
{                                                                 \
    std::ostringstream os_;                                       \
    os_ << "ERROR : " << classObj << "::" << method << " : "      \
        << "  Error in data from params [" << errorMSG "] \n";     \
    std::cerr << os_.str();                                       \
    exit(1);                                                      \
}
