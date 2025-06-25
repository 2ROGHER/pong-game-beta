#include "Game.h"
#include <GL/freeglut.h>
#include <iostream>
#include "../utils/Timer.h"
using namespace std;

/**
 * @brief
 * Esta es la implementacion de la clase Game.h [cabecera] que se encarga de la logica del juego y se definio en el archivo Game.h dentro de la carpeta core
 * Esta es la implementacion que controla la logica del juego
 *
 *
 * @file Game.cpp
 * @version 0.1
 * @date 2025-06-19
 * @copyright Copyright (c) 2025
 *
*/

// 1. Nota importante: el tamaño de la ventana es de 1000x600
// 2. Si desea agregar el tamaño de la raqueta y la bola, puede hacerlo pasando al constructor de la siguiente manera: player = new Paddle(Vector2D(50, 250), 100, 20);
Game::Game() {

	player = new Paddle(Vector2D(50, 250)); // La raqueta se inicializa en la posición (50, 250)

	ball = new Ball(Vector2D(400, 300)); // La Pelota se inicializa en la posición (400, 300)
	
	score = new Score(); // Crea un nuevo objeto de score
	timer = new Timer(); // Crea un nuevo objeto de temporizador

	label = new Label(player, timer, score);

}

Game::~Game() {
	delete player;
	delete ball;
	
	delete score;
	delete label;
	delete timer;

}

// Inicializa el juego estableciendo los valores para los vectores de posiciones y velocidad, iniciales
void Game::init() {
	ball->reset(); // Resetea la pelota a su posición y velocidad iniciales listo para el juego
	label->init(); // Inicializa el score cuando se cargue el juego

	// Inicia el temporizador
	timer->start();
}

void Game::update(float dt) {
	// Actuliza el temporizador (importante)
	timer->update();

	player->update(dt); // Actualiza la posicióny la velocidad del jugador pasando como parametro el delta time, por cada unidad de tiempo
	ball->update(dt); // Actualiza la posición y la velocidad de la pelota pasando como parametro el delta time, por cada unidad de tiempo

	label->update(dt);


	// Maneja las colisiones con el jugador 1 con la pelota, es decir establece la logica para que la pelota rebote con la raqueta
	// TODO("Implementar las colisiones en otra cabecera/archivo de tal forma que no se repita el codigo y hacerlo mas modular")
	if (ball->right() > player->left() &&
		ball->left() < player->right() &&
		ball->top() < player->bottom() &&
		ball->bottom() > player->top()) {
		ball->velocity.x = -ball->velocity.x; // Invierte la velocidad horizontal de la pelota
		ball->position.x = player->right(); // Establece la posición de la pelota en la derecha de la raqueta
	}

	// Reiniciar el juego si la pelota sale de la pantalla lateral izquierda, esto es para un jugador por defecto
	if (ball->position.x < 0) {
		// TODO("implementar la logica para restar/disminuir un vida al jugador si este sale de la ventana")
		player->loseLife();
		ball->reset(); // Resetea la pelota a su posición y velocidad iniciales, cuando la pelota sale de la pantalla lateral izquierda
	}

}

void Game::render() {
	player->render();
	ball->render();

	// Renderizar el Label en la ventana
	label->render();
}

void Game::handleInput(unsigned char key, bool isPressed) {
	if (key == 'w') player->velocity.y = isPressed ? player->getSpeed() : 0;
	if (key == 's') player->velocity.y = isPressed ? -player->getSpeed() : 0;
	if (key == 27) exit(0);
}