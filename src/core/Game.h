#pragma once

#include "../entities/Paddle.h"
#include "../entities/Ball.h"
#include "Score.h"
#include "GameState.h"
#include "../utils/Label.h"
#include "../core/LevelManager.h"

#include <memory>

/**
 * @class Game
 * @brief
 * Declaracion de la clase Game.
 * Esta clase permite controlar el juego principal, y permite crear una instancia de la clase Game.
 * Esta es la clase o cerebro principal del juego, maneja la incializacion, actualizacion, renderizacion y manejo de entrada del juego.
 *
 *
 * @file Game.h
 * @version 1.0
 * @date 2025-06-19
 * @copyright Copyright (c) 2025
 *
*/
class Game {
    // Este juego basico consta de un jugador y una bola (default)
    // Puedes agregar mas elementos al juego si lo deseas
private:
    Paddle* player; // Jugador Paddle (creado con puntero para mayor eficiencia)

    Ball* ball; //Declaracion de la bola mediante punteros para mayor eficiencia
    std::vector<shared_ptr<Ball>> balls;

    // Conectamos la logica del Score con la clase principal Game
    Score* score;
    // Se conecta la logica de Label para mostrar el [Label] objeto en la ventana
	Label* label;

    // Se conecta la logica de Timer para usar propiedades y metodos del temporizador
    Timer* timer;

    // Declaramos una propieadad [levelManager], el cual sera el contenedor de todos los valores del archivo de configuracion, que se pasaron
    // desde GameScene a esta clase. Se comparte el estado de los niveles entre todas las instancias de Game
    std::shared_ptr<LevelManager> levelManager;

    // Conectamos el sistema de menu con el juego principal
    GameState currentState;


public:
    Game(); // constructor
    ~Game(); // destructor
    void init(); // Metodo para inicializar el juego
    void update(float dt); // Metodo para actualizar el juego, se llama en cada frame. Se usa para establecer los valores de la posicion y la velocidad de cada objeto en el juego en cada unidad de tiempo.
    void render(); // Metodo para renderizar el juego o pintar en la ventana

    // Metodo para manejar la entrada del usuario (teclado y mouse). Este metodo nos permite modificar la direccion del movimiento del jugador
    void handleInput(unsigned char key, bool isPressed);

    // Metodos para controlar el estado de todo el juego (setters y getters) para el estado del juego
    GameState getState() const { return currentState; }
    void setGameState(GameState state) { currentState = state; } 

    // Los metodos getters and setters seran usados para manejar la propiedad [levelManager] y cambiar dinamicamente el estado de los niveles
    // Setter para la propiedad [levelManager]
    void setLevelManager(std::shared_ptr<LevelManager> manager);

	// Getter para la propiedad [levelManager]
    std::shared_ptr<LevelManager> getLevelManager() const;

    // Se declara un metodo para poder agregar nuevas pelotas al juego segun el jugador cambie de nivel de juego
    void addBallForCurrentLevel(const LevelData& level);

};