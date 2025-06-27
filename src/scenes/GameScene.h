#pragma once
#include "IScene.h"
#include "../core/Game.h"
#include "../core/LevelManager.h"
#include <memory>
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


    // Ahora conectamos el LevelManager, para cuando se inicie la escena del juego se carguen los niveles desde el archivo de configuracion exterior
    std::shared_ptr<LevelManager> levelManager;

public:
    GameScene(); // constructor de la clase
    void init() override;
    void update(float dt) override;
    void render() override;
    void clean() override;
    void handleInput(unsigned char key, bool isPressed) override;

 
};