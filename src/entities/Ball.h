#pragma once
#include "Entity.h"
#include <cstdlib> // Se incluye la libreria para generar numeros aleatorios
#include <cmath> // incluye la libreria para operaciones matematicas
#include <GL/freeglut.h>
#include <iostream>

using namespace std;

/**

 * @file Ball.h
 * @brief
 * Declaracion de la clase Ball
 * Esta clase hereda de la clase Entity y permite la creacion de la bola del juego
 * Esta clase tambien permite la actualizacion de la bola en el juego, como su posicion y velocidad, pintar el la ventana de juego y manejar la colision con los bordes del juego.
 * Esta clase llama al constructor de su clas padre (Entity) para inicializar la bola con su posicion (Vector2D(0,0)) y velocidad (Vector2D(0,0))
 *
 * @version 0.1
 * @date 2025-06-19
 * @copyright Copyright (c) 2025
 *
 *
*/

// 1. Define constantes importantes para la bola del juego
const float DEFAULT_BALL_RADIUS = 15.0f;
const float DEFAULT_BALL_SPEED = 200.0f;
const float DEFAULT_BALL_WIDTH = 40.0f;
const float DEFAULT_BALL_HEIGHT = 40.0f;
const int SEGMENTS = 32; // Numero de segmentos para dibujar la bola

class Ball : public Entity {
	private: 
		float radius; // Radio de la bola
		float hexColorValue; // Valor hexadecimal para pintar la bola

		// TODO("Implementar un metodo que pemita cambiar el color de la bola")
		void drawPaddle() {}

	public:
		Ball(); // Constructor de la bola sin parametros por defecto

		// Ball constructor se incializa con un radio por defecto de 10
		Ball(Vector2D pos, float r = DEFAULT_BALL_RADIUS, float hexValue = 0x00FF00): Entity(pos, Vector2D(0, 0)), radius(r), hexColorValue(hexValue) {} // Implementacion del constructor de la bola con parametros

		// Este metodo es un metodo que se sobreescribe (override) de su clase padre (Entity)
	   // Este es un metodo que permite actualizar la posicion y velocidad de la bola
		void update(float dt) override {
			position.x += velocity.x * dt;
			position.y += velocity.y * dt;


			// TODO("Esta logica se debe cambiar cuando se agrega otro jugador")
			// Logica que permite controlar la colision de este objeto (Paddle) con la parte superior, inferior y lateral-derecha de la ventana
			if (position.y - height < 0 || position.y + height > 600) { // suponiendo que el alto de la ventana es 600px
				velocity.y = -velocity.y; // Si existe colision con los limites de la ventana, se invierte la velocidad en el eje y
			}

			// Logica que permite controlar la colision de este objeto (Paddle) con la parte derecha de la ventana
			if (position.x + width > 800) { // suponiendo que el ancho de la ventana es 800px
				position.x = 800 - width;
				velocity.x = -velocity.x; // si existe colision con los limites de la ventana, se invierte la velocidad en el eje x
			}
		}

		// Este metodo es una funcion que se sobreescribe (override) de su clase padre Entity
		// Metodo para pintar/renderizar la bola en la ventana
		void render() override {

			glColor3f(1.0f, 1.0f, 0.0f); // Color amarillo
			glBegin(GL_TRIANGLE_FAN); // Dibuja un triangulo que luego transformaremos en una bola
			glVertex2f(position.x, position.y); // Se ubica el punto central de la bola

				for (int i = 0; i <= SEGMENTS; i++) {
					float angle = 2.0f * 3.14159f * float(i) / float(SEGMENTS); // Calcula el angulo para cada segmento
					float dx = cosf(angle) * radius; // Calcula la componente x del segmento
					float dy = sinf(angle) * radius; // Calcula la componente y del segmento
					glVertex2f(position.x + dx, position.y + dy); // Dibuja el segmento
				}
			glEnd();

		}

		// Resetea la bola a su posicion inicial o su posicion por defecto
	    // Es decir, cuando se inicia el juego este metodo se llama y se establece la bola en su posicion inicial y su velocidad aleatoria
		void reset() {
			// Posicion aleatoria de la bola al reiniciar
			position = {
				(rand() % 2 == 0) ? 50.0f : 550.0f,
				(rand() % 2 == 0) ? 50.0f : 550.0f
			}; // Posicion inicial de la bola aleatoria

			// Velocidad aleatoria de la bola al reiniciar 
			velocity = Vector2D(
				DEFAULT_BALL_SPEED,
				DEFAULT_BALL_SPEED
			);
		}

		
};