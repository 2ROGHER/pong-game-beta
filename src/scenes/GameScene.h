#pragma once
#include "IScene.h"
#include "../core/Game.h"

/**
 * @class GameScene es la implementacion de la interfaz IScene para la escena del juego
 * @brief
 *

 @file MenuScene.h
 * @version 1.0
 * @copyright Copyright (c) 2025
 */

class GameScene : public IScene {
private:
    // Se aplica un patron tipo inyeccion de dependencias para poder usar la clase Game
    Game game;

    // Integracion de LevelManager en la escena del juego GameScene
    //LevelManager levelManager;
public:
    GameScene(); // constructor de la clased
    void init() override;
    void update(float dt) override;
    void render() override;
    void clean() override;
    void handleInput(unsigned char key, bool isPressed) override;
};