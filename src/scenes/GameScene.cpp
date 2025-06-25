#include "GameScene.h"
/**
 * @implementation esta clase es la implementacion de la clase MenuScene.h
 * @brief
 * Esta clase es la implementacion de la clase MenuScene.h
 * Esta es la implementacion de la clase MenuScene.h, lista y encapsulada dentro de esta clase
 *
 * @file MenuScene.h
 * @date 2025-06-21
 * @version 1.0
 * @copyright Copyright (c) 2025
 */

GameScene::GameScene() {}

void GameScene::init() {

	game.init(); // Se inicializa la escena del juego
}

void GameScene::update(float dt) {
	game.update(dt);
}

void GameScene::render() {
	game.render();
}

void GameScene::clean() {
}

void GameScene::handleInput(unsigned char key, bool isPressed) {
	game.handleInput(key, isPressed);
}