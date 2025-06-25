#pragma once
#include "IScene.h"

/**
 * @implementation Esta es la implementacion de la clase ManagerScene.h
 * @brief
 * Esta clase se encarga de manejar la escena actual que se esta mostrando en la ventana
 * Este es la clase que se preocupa gestionar/controlar cada escena que se va a mostrar en la ventana de forma optimizada.
 *
 * @file SceneManager.h
 * @date 2025-06-19
 * @version 1.0
 * @copyright Copyright (c) 2025
 */

class SceneManager {
    private:
        // Este patron de relacion es como un singleton e inyeccion de dependencias
        static IScene* currentScene; // Puntero a la escena actual que se esta mostrando en la ventana

    public:
        SceneManager(); // Constructor de la clase
        // Estos metodos son los tipicos metodos getters y setters que se encuentran en la clase Score
        static void setScene(IScene* scene); // Este metodo se encarga de establecer la escena actual, que se pasa como parametro
        static IScene* getScene(); // Este metodo se encarga de obtener la escena actual
};
