#include "MenuScene.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "MenuScene.h"
#include <GL/freeglut.h>
#include <string>
#include <iostream>

using namespace std;

/**
 * @implementation La clase MenuScene  es la implementacion de la clase MenuScene.h
 * @brief
 *
 *
 * @file MenuScene.cpp
 * @version 1.0
 * @copyright Copyright (c) 2025
 */

MenuScene::	MenuScene() {}
// Implementacion del metodo publico para actualizar la escena MenuScene
// Es decir, este metodo permite actualizar el estado, propiedades y comportamiento de la escena que se va a mostrar en la venta, por cada unidad de tiempo transcurrida.
void MenuScene::init() {

}

void MenuScene::update(float dt) {
}

// Este metodo es la funcion principal  de la escena que se encarga de dibujar el menu en la ventana.
void MenuScene::render() {

    // -------------------------
    // Renderizar el título del juego
    // -------------------------
    glPushMatrix(); // Guardar el estado actual de la matriz
    glColor3f(1.0f, 1.0f, 1.0f); // Color blanco

    // Posicionar y escalar el título con texto de tipo STROKE
    glTranslatef(275.0f, 400.0f, 0.0f); // Mover a una posición visible en la pantalla
    glScalef(0.3f, 0.3f, 1.0f); // Escalar el texto
    std::string title = "PONG GAME";
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
    std::string opt2 = "R - Resume Game";
    for (char c : opt2) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    glRasterPos2f(330.0f, 220.0f);
    std::string opt3 = "ESC - Exit";
    for (char c : opt3) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
}


void MenuScene::clean() {
    // TODO("Implementar el codigo cuando la escena se destruya")
}

// Este metodo se encarga de manejar la entrada de teclado en la escena del menu realizar ciertas acciones
void MenuScene::handleInput(unsigned char key, bool isPressed) {
    if (!isPressed) {
        std::cout << "Tecla " << key << " no presionada" << std::endl;
        return;
    } //return; // si isPressed es falso, es decir si no se presiona ninguna tecla se sale de la funcion

    if (key == 'n' || key == 'N') {
        // TODO("conectar todas las Managers de escenas aca")
        // AudioManager::getInstance()->playSound("menu"); implementar manejador de sonido despues
        SceneManager::setScene(new GameScene());
    }
    if (key == 'r' || key == 'R') {
        // TODO("Implementar la funcionalidad para reanudar el juego")
    }

    if (key == 27 || key == 's' || key == 'S') exit(0); // Si se presiona la tecla ESC, se sale del juego

}
