#pragma once

#include "IScene.h"
#include <iostream>
#include <string>

/**
 * @class GameOverScene
 * @brief
 * Esta clase representa la escena que se muestra cuando el jugador pierde la partida.
 * Implementa la interfaz IScene, por lo tanto define todos los métodos virtuales puros.
 * Permite mostrar un mensaje de fin de juego, esperar entrada del usuario para volver al menú principal
 * o salir del juego.
 *
 * @file GameOverScene.h
 * @date 2025-06-26
 * @version 1.0
 * @copyright Copyright (c) 2025
 */

class GameOverScene : public IScene {
	private: 
		bool waitingInput;
		std::string message;

	public:
		GameOverScene(); // 
		~GameOverScene() override;   // Destructor sobrescrito
		void init() override;
		void update(float dt) override;
		void clean() override;
		void handleInput(unsigned char key, bool isPressed) override;
		void render() override;

};
