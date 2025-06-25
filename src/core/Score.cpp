#include "Score.h"
#include <GL/freeglut.h>
#include <iostream>
#include <string>

using namespace std;
/**
 * @implementation Score.h
 * @brief
 * Esta archivo se encarga de implementar el score del juego, se definio en el archivo Score.h dentro de la carpeta core
 *
 *
 * @file Score.h
 * @version 1.0
 * @date 2025-06-21
 * @copyright Copyright (c) 2025
 */

// 1. Implementar el constructor de la clase Score.h
Score::Score() {
    // Cuando se crea el objeto Score se inicializa el puntaje del jugador en 0
    reset();
}

// 2. Metodo que permite implementar la logica para reiniciar el score
// Permite reiniciar el score del jugador a 0
void Score::reset() {
	playerScore = 0;
}

// 3. Metodo que permite implementar la logica para aumentar el score del jugador
// Este metodo permite aumentar el score del jugador en un valor
void Score::increasePlayerScore() {
	playerScore++;
}

// 4. Metodo que permite implementar la logica para recuperar el score del jugador
int Score::getPlayerScore() {
	return playerScore;
}

// 5. Metodo que permite implementar la logica para establecer el score del jugador
void Score::setPlayerScore(int score) {
	playerScore = score;
}


// 6. Metodo que permite implementar la logica para renderizar el score en la ventana
void Score::render() {
    // Renderiza el puntaje en la pantalla o la ventana
    std::string scoreText = std::to_string(playerScore);
    glColor3f(1.0f, 1.0f, 1.0f); // Pinta el puntaje en blanco en la ventana
    glRasterPos2f(370, 30); // Posicion del puntaje en la pantalla
    for (char c : scoreText) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c); // Renderiza cada caracter del puntaje en la ventana
    }

}
