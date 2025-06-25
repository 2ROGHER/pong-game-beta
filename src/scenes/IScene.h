#pragma once
/**
 * @interface IScene
 * @brief
 * Esta declaracion de la interface permite que todas las escenas compartan los metodos de inicializacion, actualizacion y finalizacion
 * Estos metodos pueden ser intercambiables
 * Esta es una interface pura con metodos virtuales, que permite que pueda ser reescrito o sobrescrito por cualquier clase que herede esta clase.
 * Esta forma de declarar las interfaces, permite inicializar los metodos de tal forma que al usar un (puntero o referencia) se ejecute
 * la version correcta del metodo en tiemo de ejecucion (importante).
 *
 * Esta clase no se puede instanciar directamente ya que es una interface pura
 *
 * Posee metodos genericos y abstratos propios que se pueden extraer de una escena de juego
 *
 * Esta interfaz pura permite que las escenas se puedan intercambiar sin afectar el comportamiento general de la aplicacion,
 * tambien como permiten la implementacion de estos metodos de manera diferentes
 *
 * @file IScene.h
 * @date 2025-06-19
 * @version 1.0
 * @copyright Copyright (c) 2025
 */

class IScene {
public:
    IScene() = default; // constructor default
    virtual ~IScene() = default; // Destructor virtual
    virtual void init() = 0; // Metodo virtual, que controla la inicializacion para cada escena

    // Metodo virtual, que controla la actualizacion(refresh) para cada escena por cada unidad de tiempo trascurrido. Este metodo permite actualizar el estado de la escenan
    // en la ventana
    virtual void update(float dt) = 0;
    virtual void render() = 0; // Metodo virtual, que controla la renderizacion/pintado para cada escena
    virtual void clean() = 0; // Metodo virtual, que controla la limpieza para cada escena, cuando se cambia de escena se necestia limpiar para liberar recursos y memoria
    virtual void handleInput(unsigned char key, bool isPressed) = 0; // Metodo virtual, que controla la entrada de teclado para cada escena
};