#pragma once
#include <iostream>
#include "Entity.h"
#include <GL/freeglut.h> // Se incluye la libreria de FreeGLUT

using namespace std;

/**
* @file Paddle.h
 * @brief Clase Paddle que representa la raqueta del jugador en el juego Pong.
 *
 * Hereda de la clase abstracta Entity e implementa su lógica de movimiento y renderizado.
 * Este paddle puede moverse tanto en el eje Y (jugador vertical) como también en el eje X si se requiere (modo libre o IA).
 *
 * @version 0.1
 * @date 2025-06-19
 *
 * @copyright Copyright (c) 2025
 *
 *
*/
// 1. Define constantes importantes para el Paddle
// TODO("La velocidad de la pelota debe incrementar cuando se incrementa el puntaje")
const float DEFAULT_PADDLE_SPEED = 200.0f;
const float PADDLE_SPEED_X= 200.0f; // Velocidad del paddle debe ser el mismo que el del Pelota (Paddle)
const float PADDLE_SPEED_Y= 200.0f;
const float DEFAULT_PADDLE_WIDTH = 10.0f;
const float DEFAULT_PADDLE_HEIGHT = 80.0f;
const int DEFAULT_PADDLE_LIVES = 3;

class Paddle : public Entity {
	private: 
		float speed;
		// Declaramos las variables de velocidad tanto en X como en Y para la entidad de Pelota
		// float speedX;
		// float speedY;

		// Se declara la propiedad de [lives] para el jugador
		int lives_;
	public: 
		Paddle() : speed(DEFAULT_PADDLE_SPEED), lives_(DEFAULT_PADDLE_LIVES) {}; // Contructor vacio por defecto
		Paddle(Vector2D pos, float s = DEFAULT_PADDLE_SPEED, int lives = DEFAULT_PADDLE_LIVES, float w = DEFAULT_PADDLE_WIDTH, float h = DEFAULT_PADDLE_HEIGHT) :
			Entity(pos, Vector2D(0, 0), w, h), speed(s), lives_(lives) {};

		// Este metodo permite renderizar la raqueta o dibujar la raqueta en la ventana usando la libreria de FreeGLUT
		void update (float dt) override {
			// Este metodo permite controlar el movimiento de la raqueta en el eje Y (jugador vertical) utilizando la velocidad y el tiempo de desplazamiento
			position.y += velocity.y * dt;
			// TODO("Implementar mas tarde para que la paleta pueda moverse en el eje X")

			// Logica que permite que la raqueta no salga de los limites inferior y superior de la ventana
			// Si la raqueta se sale de la ventana inferior, se detiene su movimiento
			if (position.y < 0) position.y = 0;

			// Si la raqueta + su altura, se sale de la ventana superior, se detiene su movimiento tambien
			if (position.y + height > 600) position.y = 600 - height; // Suponiendo 600px alto
		}

		void render() override {
			glColor3f(1.0f, 1.0f, 1.0f); // Color blanco
			glBegin(GL_QUADS); // Dibujar un cuadrado
				glVertex2f(position.x, position.y); // Punto superior izquierdo
				glVertex2f(position.x + width, position.y); // Punto superior derecho
				glVertex2f(position.x + width, position.y + height); // Punto inferior derecho
				glVertex2f(position.x, position.y + height); // Punto inferior izquierdo
			glEnd();
		}
		// Metodo que maneja o controla el movimiento de la raqueta hacia arriba
		void moveUp() {
			velocity.y = speed;
		}
		// Metodo que maneja o controla el movimiento de la raqueta hacia abajo
		void moveDown() {
			velocity.y = -speed;
		}
		// Metodo que maneja o controla el movimiento de la raqueta hacia la izquierda
		void moveLeft() {
			velocity.x = -speed;
		}
		// Metodo que maneja o controla el movimiento de la raqueta hacia la derecha
		void moveRight() {
			velocity.x = speed;
		}
		// Metodo que detiene el movimiento de la raqueta
		void stop() {
			// velocity.x = 0; // Detener el movimiento horizontal
			velocity.y = 0; // Detener el movimiento vertical
		}

		// Getters y setters para la velocidad de la Paleta (speed)
		void setSpeed(float s) {
			speed = s;
		}

		float getSpeed() {
			return speed;
		}

		// Setters y getters para lives
		void setLives(int lives) { lives_ = lives; } // Asigna la cantidad de vidas al Paddle

		int getLives() { return lives_; } // Devuelve la cantidad de vidas que tiene el jugador

		// Metodos que permiten controlar la logica cuando se resta una vida a la Raqueta
		 // Metodo para restar una vida al jugador
		void loseLife() {
			hasLives() ? lives_-- : 0; // Si al jugador aun le queda vidas, se le resta 1, sino es igual a 0
		}

		// Metodo que permite determinar si el jugador a un le quedan vidas
		bool hasLives() { return lives_ > 0; } // Verifica si el jugador tiene vidas


};