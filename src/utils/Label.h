#pragma once

#include <cstdlib> // Se incluye la libreria para generar numeros aleatorios
#include <cmath> // incluye la libreria para operaciones matematicas
#include <GL/freeglut.h>
#include <iostream>
#include <string>
#include "../core/Score.h"
#include "../utils/Timer.h"
#include <string>
#include <chrono>

using namespace std;

/**

 * @file Label.h
 * @brief
 *
 * @file Label.h
 * @version 0.1
 * @date 2025-06-21
 * @copyright Copyright (c) 2025
 *
 *
*/

// 1. Define constantes importantes
// TODO("Eliminar las constantes cuando se trabaje con configuraciones en archivo JSON y cuando se implemente ConfigManager.h")
const float DEFAULT_GAME_SCORE = 0.0f; // puntaje por defecto 
const int DEFAULT_LIVES = 3; // vidas por defecto
const float DEFAULT_TIME = 0.0f; // tiempo por defecto
const int DEFAULT_LEVEL = 1; // nivel por defecto

class Label {
	private:
		Score* score;
		int lives_;
		std::chrono::steady_clock::time_point time_; // Tiempo transcurrido del juego
		
		// Conectar el [level] a esta clase 
		int level_;

		// Conectamos el [score] con la entidad de [Paddle] para utilizar sus metodos y propiedades
		// Usamos aqui una referencia a la clase [Paddle] o puntero para compartir los estados entre los objetos
		Paddle* paddle;

		// Conectamos la clase [Timer] para hacer uso de las funcionalidades de control de timpo 
		// Se usa el valor de referencia para intercambiar estados dinamicos
		Timer* timer; // Est es un nuevo componente [timer]

		float lastScoreTime_ = 0.0f; // Esta propieadad es para almacenar el ultimo puntaje obtenido


		// Este metodo es privado y exclusivo de esta clase, que permite formatear el texto del HUD del tiempo para mostrar en la ventana
		std::string formatHUDCal() {
			float elapsedTime = timer->getElapsedTime(); // Obtenemos el tiempo transcurrido desde que se inicio el juego
			int minutes = static_cast<int>(elapsedTime / 60); // Obtenemos los minutos transcurridos
			int seconds = static_cast<int>(elapsedTime) % 60; // Obtenemos los segundos transcurridos
			int milliseconds = static_cast<int>((elapsedTime - static_cast<float>(seconds)) * 1000); // Obtenemos los milisegundos transcurridos
			char buffer[32];
			sprintf(buffer, "Time: %02d:%02d:%03d", minutes, seconds, milliseconds);
			return std::string(buffer);
		}

	public:
		Label(Paddle* paddle, Timer* timer, Score* score) : level_(DEFAULT_LEVEL), paddle(paddle), timer(timer), score(score) {}
		//Label(Paddle* paddle, Score(), int lives_ = 5, float time_ = 60.0f, int level_ = 1): score_(score_), lives_(paddle->getLives()), time_(time_), level_(level_) {};

		// Metodo para inicializar el label con los valores iniciales cuando se cargue cada escena
		void init() {
			reset();
		}

		// Metodo para actualizar el label, por cada unidad de tiempo que pasa
		void update(float dt) {
			// Actualizar la logica juego par cada unidad de tiempo.
			// Este implementacion, permite actualizar el puntaje y el tiempo transcurrido del juego
			float elapsedTime = timer->getElapsedTime(); // Obtenemos el tiempo transcurrido desde que se inicio el juego

			// Si el tiempo transcurrido es mayor a 60 segundos, aumenta el puntaje [score]
			// Este controla que se incremente el puntaje cada 60 segundos
			if (elapsedTime - lastScoreTime_ >= 45.0f) { 
				score->increasePlayerScore();
				lastScoreTime_ = elapsedTime;
				
			}

			// Logica para actualizar de nivel
			if (score->getPlayerScore() >= 15) {
				// TODO("Implementar logica para cambiar de nivel")
				level_++;
				timer->reset();
			}
		}

		// Metodo para renderizar el label en la ventana
		void render() {
			glColor3f(1.0f, 1.0f, 1.0f); // Texto de color blanco

			glRasterPos2f(330.0f, 100.0f); // Posicion del texto en la ventana
			std::string scoreLabel = "Score: " + to_string(score->getPlayerScore());
			for (char c : scoreLabel) {
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
			}

			glRasterPos2f(330.0f, 80.0f); // Posicion del texto en la ventana
			std::string livesLabel = "Lives: " + to_string(paddle->getLives());
			for (char c : livesLabel) {
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
			}

			glRasterPos2f(330.0f, 60.0f); // Posicion del texto en la ventana
			std::string timeLabel = formatHUDCal();
			for (char c : timeLabel) {
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
			}

			glRasterPos2f(330.0f, 40.0f); // Posicion del texto en la ventana
			std::string levelLabel = "Level: " + to_string(level_);
			for (char c : levelLabel) {
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
			}


		}
		// Metodo para resetear el label cuando el jugador cambia de nivel
		void reset() {
			score->setPlayerScore(DEFAULT_GAME_SCORE); // Se establece el puntaje por defecto 0
			lives_ = paddle->getLives(); // Se establece las vidas por defecto 3, recuperando las vidas por defector de Paddle (Raqueta)
			time_ = timer->getStartTime(); // Se establece el tiempo por defecto 0
			level_ = DEFAULT_LEVEL;
			lastScoreTime_ = 0.0f; // Se establece el puntaje por defecto 0
		}


};