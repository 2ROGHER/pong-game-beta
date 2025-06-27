#pragma once
#include "Entity.h"
#include <cstdlib> // Se incluye la libreria para generar numeros aleatorios
#include <cmath> // incluye la libreria para operaciones matematicas
#include <GL/freeglut.h>
#include <iostream>
#include <sstream>

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
		Ball(Vector2D pos, float r = DEFAULT_BALL_RADIUS, float hexValue = 0x00FF00)
			: Entity(pos, Vector2D(0, 0), DEFAULT_BALL_WIDTH, DEFAULT_BALL_HEIGHT), radius(r), hexColorValue(hexValue) {}
		// Implementacion del constructor de la bola con parametros

		// Este metodo es un metodo que se sobreescribe (override) de su clase padre (Entity)
	   // Este es un metodo que permite actualizar la posicion y velocidad de la bola
		void update(float dt) override {
			position.x += velocity.x * dt;
			position.y += velocity.y * dt;


			// TODO("Esta logica se debe cambiar cuando se agrega otro jugador")
			// Logica que permite controlar la colision de este objeto (Paddle) con la parte superior, inferior y lateral-derecha de la ventana
			// 1. Implementar la logica para menejar colisiones de la (Ball) con la ventana superior
			if (position.y - radius < 0) { // suponiendo que la altura de la ventana es 600px
				position.y = radius; // se establece la posicion y se evita que la bola salga de la ventana
				velocity.y = -velocity.y; // si existe colision con los limites de la ventana, se invierte la velocidad en el eje y
			}
			 

			// 2. Implementar la logica que permite controlar la colision del (Ball) con la ventana lateral derecha
			if (position.x + radius > 800) { // suponiendo que el ancho de la ventana es 800px
				position.x = 800 - radius;
				velocity.x = -velocity.x; // si existe colision con los limites de la ventana, se invierte la velocidad en el eje x
			}

			// Implementar la logica que permite controlar la colision del (Ball) con la ventana inferior de la pantalla
			if (position.y + radius > 600) { // suponiendo que la altura es 600px
				position.y = 600 - radius;
				velocity.y = -velocity.y; // si existe colision con los limites de la ventana, se invierte la velocidad en el eje x
			}
		}

		// Este metodo es una funcion que se sobreescribe (override) de su clase padre Entity
		// Metodo para pintar/renderizar la bola en la ventana
		void render() override {
			// Extraer valores RGB desde el valor entero hexadecimal
			float r = ((int)hexColorValue >> 16 & 0xFF) / 255.0f;
			float g = ((int)hexColorValue >> 8 & 0xFF) / 255.0f;
			float b = ((int)hexColorValue & 0xFF) / 255.0f;

			glColor3f(r, g, b); // Usamos color dinámico extraído del nivel JSON

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
			// Nota importante: Si la velocidad del (Ball) se carga desde un archivo de configuracion como JSON, ya no se necesita esta logica
			//velocity = Vector2D(
				//DEFAULT_BALL_SPEED,
				//DEFAULT_BALL_SPEED
			//);
		}

		// Metodo setter para modificar al velocidad de la pelota a medida que sube de nivel
		void setSpeed(float vx, float xy) {
			velocity.x = vx;
			velocity.y = xy;
		}

		
};