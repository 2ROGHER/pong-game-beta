#include "GameOverScene.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "MenuScene.h"
#include <GL/freeglut.h>

using namespace std;

/**
 * @implementation GameOverScene
 * @brief
 * Esta es la implementación de la clase GameOverScene.
 * Controla la lógica que se ejecuta cuando el jugador pierde la partida.
 *
 * @file GameOverScene.cpp
 * @date 2025-06-26
 * @version 1.0
 */

GameOverScene::GameOverScene() :waitingInput(false), message("¡Game Over! Presiona 'M' para ir al menú o 'Q' para salir.") {} // Constructor de la clase GameOverScene. Inicializa la variable waitingInp en false

GameOverScene::~GameOverScene() {} // Destructor

void GameOverScene::init() {
	std::cout << "[INFO] GameOverScene iniciada correctamente.\n";
	// Aquí podrías cargar recursos visuales o sonidos si se usan
}

void GameOverScene::update(float dt) {
	// La escena no requiere lógica de actualización compleja
	// Solo espera la entrada del jugador
	if (!waitingInput) {
		// Lógica para cambiar de escena se debería manejar en el SceneManager del juego
	}

}


void GameOverScene::clean() {
    // Aquí podrías liberar memoria o recursos si se usaran
}


void GameOverScene::handleInput(unsigned char key, bool isPressed) {
    if (!isPressed) return; // Solo actuar cuando se presiona la tecla

    switch (key) {

    case 'n':
    case 'N':
        std::cout << "[INFO] MenuScene cargado exitosamente" << std::endl;
        SceneManager::setScene(new GameScene());
        break;

    case 'm':
    case 'M':
        std::cout << "[INFO] Volviendo al menú principal...\n";
        waitingInput = false;
        // Aquí deberías hacer un cambio de escena hacia MainMenuScene
        SceneManager::setScene(new MenuScene());
        break;
    case 27:
        std::cout << "[INFO] Saliendo del juego...\n";
        std::exit(EXIT_SUCCESS); // Salir del juego
        break;
    default:
        std::cout << "[INFO] Tecla no válida. Usa 'M' para menú o 'Q' para salir.\n";
        break;
    }
}

void GameOverScene::render() {
	// Renderiza el mensaje de fin de juego en consola
    // -------------------------
    // Renderizar el título del juego
    // -------------------------
    glPushMatrix(); // Guardar el estado actual de la matriz
    glColor3f(1.0f, 1.0f, 1.0f); // Color blanco

    // Posicionar y escalar el título con texto de tipo STROKE
    glTranslatef(275.0f, 400.0f, 0.0f); // Mover a una posición visible en la pantalla
    glScalef(0.3f, 0.3f, 1.0f); // Escalar el texto
    std::string title = "GAME OVER";
    for (char c : title) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
    }
    glPopMatrix(); // Restaurar la matriz

    // -------------------------
    // Renderizar las opciones del menú (texto bitmap)
    // -------------------------
    glColor3f(1.0f, 1.0f, 1.0f); // Color blanco
    glRasterPos2f(330.0f, 280.0f); // Metodo para posicionar el texto
    std::string opt1 = "N - New Game";
    for (char c : opt1) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    glRasterPos2f(330.0f, 250.0f);
    std::string opt2 = "M - Menu Game";
    for (char c : opt2) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    glRasterPos2f(330.0f, 220.0f);
    std::string opt3 = "ESC - Exit";
    for (char c : opt3) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}

