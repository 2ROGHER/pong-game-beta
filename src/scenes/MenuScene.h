#pragma once
#include "IScene.h"

/**
 * @class MenuScene es la clase que se encarga de mostrar el menu principal del juego en la ventana
 * @brief
 * Controla toda la logica del menu principal o menu de entrada del juego, el cual  se va a mostrara en el juego.
 * Esta clase va a implementar la interfaz IScene.h, asi como tambien ejecutar cada uno de los metodos de la interfaz pura declarada en dicho archivo
 *
 * @file MenuScene.h
 * @date 2025-06-21
 * @version 1.0
 * @copyright Copyright (c) 2025
 */

class MenuScene : public IScene {
private:
public:
	MenuScene(); // Constructor de la clase
	void init() override;
	void update(float dt) override;
	void render() override;
	void clean() override;
	void handleInput(unsigned char key, bool isPressed) override;

};