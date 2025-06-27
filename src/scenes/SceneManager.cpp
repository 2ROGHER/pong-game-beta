#include "SceneManager.h"
#include "IScene.h"
#include <iostream>
#include "../core/LevelManager.h"
#include "MenuScene.h";

using namespace std;
/**
 * @implementation Las clase SceneManager  es la implementacion de la clase SceneManager.h
 * @brief
 *
 *
 * @file SceneManager.cpp
 * @date 2025-06-21
 * @version 1.0
 * @copyright Copyright (c) 2025
 */

// Inicializar las propiedades de la clase SceneManager.h definido en SceneManager.h
// Puntero a la escena actual es igual a nullptr, es decir que no hay ninguna escena en ejecucion cuando se implementa este metodo
IScene* SceneManager::currentScene = nullptr;

 //Constructor inicializado
SceneManager::SceneManager() {
	// Cuando se crea el objeto se deben ejecutar ciertas acciones
}

// Implementacion de metodo publico para establecer la escena actual
void SceneManager::setScene(IScene* scene) {
	if (currentScene) {
		std::cout << "[WARNING] Unloading scene: " << currentScene << std::endl;
		currentScene->clean(); // Limpia la escena anterior
		delete currentScene; // Libera la memoria de la escena anterior
	}
	currentScene = scene;
	currentScene->init(); // Inicializa la escena actual qeu se va a mostrar, es decir se ejecuta el metodo init de la escena en (IScene.h) y se incializa la escena
	std::cout << "[INFO] Unloading scene finished successfully: " << currentScene << std::endl;

}


// Implementacion del metodo publico para obtener la escena actual
IScene* SceneManager::getScene() {
	return currentScene;
}
