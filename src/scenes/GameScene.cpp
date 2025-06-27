#include "GameScene.h"
#include "SceneManager.h"
#include "GameOverScene.h"

using namespace std;
/**
 * @implementation esta clase es la implementacion de la clase GameScene.h
 * @brief
 * Esta clase es la implementacion de la clase GameScene.h
 * Esta clase se encarga de controlar y manejar las escenas del juego
 * La clase tiene como finalidad manejar y controlar las escenas que se cargaran dependiendo de la configuracion del juego y el nivel que comience el jugador
 * Este componente usa patrones de softare como SOLID y patrones de comportamiento como Observer  e injeccion de dependencias
 * 
 * @file GameScene.cpp
 * @date 2025-06-21
 * @version 1.0
 * @copyright Copyright (c) 2025
 */

GameScene::GameScene() {
	levelManager = std::shared_ptr<LevelManager>(new LevelManager()); // Se crea un objeto de la clase LevelManager(), el cual se usa para cargar la configuracion de niveles del juego
}

// Metodo que permite inicializar la escena del juego
// Este metodo contiene todos los archivos que se van a utilizar en la escena arrancar
void GameScene::init() {
	char path[MAX_PATH]; // variable para almacenar la ruta del archivo
	GetModuleFileName(NULL, path, MAX_PATH); // este metodo obtiene la ruta del archivo que se esta ejecutando
	std::string exepath = std::filesystem::path(path).parent_path().string(); // este metodo obtiene la ruta del archivo
	std::string fullpath = exepath + "\\config\\levels.json"; // se concatena la ruta del archivo con el nombre del archivo

	// cuando se inicia la escena del juego se debe cargar las configuraciones del juego en el formato json definido
	if (!levelManager->loadFromFile(fullpath)) {
		std::cerr << "[ERROR] GameScene no se pudo cargar el archivo de niveles. El juego no podrá continuar." << std::endl;
		std::exit(EXIT_FAILURE); // si no se puede cargar el archivo de niveles se sale del juego con un estado de error
	}

	// Se inyecta el objeto con los datos cargados al Game, el cual hara uso de estos valores para modificar el estado del juego
	game.setLevelManager(std::shared_ptr<LevelManager>(levelManager)); // Se inyecta el objeto desde la clase GameScene a Game, este objeto es el que se creo en el constructor

	game.init(); // Se inicializa la escena del juego

}

// Metodo que permite actualizar la escena del juego
void GameScene::update(float dt) {
	game.update(dt);

	if (game.getState() == GameState::GAMEOVER) {
		SceneManager::setScene(new GameOverScene());
	}



}

// Metodo que controla el renderizado del juego, es decir controla el renderizado en la ventana del juego
void GameScene::render() {
	game.render();
}

// Metodo que permite limpiar la escena del juego, es decir limpiar escenars de juego anteriores
void GameScene::clean() {
	levelManager = nullptr; // Importante, aqui no se puede usar (delete levelManager)
}

// Metodo que permite manejar la entrada de teclado en la escena de juego
void GameScene::handleInput(unsigned char key, bool isPressed) {
	game.handleInput(key, isPressed);
}

