#include <iostream>
#include <GL/freeglut.h>
#include "core/Game.h"
#include <iostream>
#include "scenes/SceneManager.h";
#include "scenes/MenuScene.h"

using namespace std;

/**
 * @mainpage Pong Game
 * @brief
 * Este es el archivo principal del juego.
 * Este archivo sirve como el punto de entrada al juego.
 * En este archivo se inicializa el juego.
 *
 *
 * @file main.cpp
 * @version 1.0
 * @date 2025-06-21
 * @copyright Copyright (c) 2025
 */



// Declarar el control del tiempo del juego, es decir inicializar el tiempo del juego en 0
int previousTime = 0;

// 1. Definir constantes importantes para inicializar el juego
const float DEFAULT_WINDOW_WIDTH = 800;
const float DEFAULT_WINDOW_HEIGHT = 600;

// Metodo principal que se encarga de realizar todas la ejecuciones para renderizar las imagenes en la ventana.
void displayCallback() {
	glClear(GL_COLOR_BUFFER_BIT); // Metodo para limpiar el buffer de color
	
	// add
	glLoadIdentity();


	SceneManager::getScene()->render();

	glutSwapBuffers(); // Metodo para intercambiar los buffers de color (double bufferring)

};

// Metod principal que se encarga de realizar todas las actualizaciones del juego
// Este metodo es el controlador que se encarga de manejar toda la logica del juego desde la entrada.
// Este es administrador de eventos del juego que actualiza la logica  las posiciones, velocidades, colisiones, etc del todo el juego
void idleCallback() { 
	int currentTime = glutGet(GLUT_ELAPSED_TIME); // Obtener el tiempo actual en milisegundos (importante)
	float deltaTime = (currentTime - previousTime) / 1000.0f; // Calcular la diferencia de tiempo en segundos. Es decir, se calcula el tiemo transcurrido desde el ultimo frame en segundos

	// Actualizar el juego con el tiempo transcurrido; es decir, al ejecutar el metodo update() actuliza la tanto la posicion de la raqueta como la de la bola sobre el tiempo
	// y maneja la logica de las colisiones.


	SceneManager::getScene()->update(deltaTime);
	
	previousTime = currentTime; // Importante, actualizar el tiempo del juego con el tiempo actual, este sera usado en el siguiente frame
	glutPostRedisplay(); // Metodo para redibujar la ventana con los nuevos valores de la logica del juego, este metodo se usa para forzar la renderizacion o redibujado en la  ventana

};

// Metodo que nos permite manejar las teclas soltadas
void keyboardUp(unsigned char key, int x, int y) {
	// game.handleInput(key, false); // Manejar la tecla soltada
	SceneManager::getScene()->handleInput(key, false);
}


// Metodo que permite manejar las teclas presionadas
void keyboardDown(unsigned char key, int x, int y) {
	SceneManager::getScene()->handleInput(key, true);
}
// Metodo que permite inicializar los graficos de OpenGL, crear la ventana grafica del juego, etc.
void initGL() {
	std::cout << "[INFO] Renderizando la ventana grafica del juego con OpenGL..." << std::endl;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Establecer el color de fondo a negro
	glMatrixMode(GL_PROJECTION); // Establecer la matriz de proyeccion
	glLoadIdentity(); // Limpiar la matriz de proyeccion
	gluOrtho2D(0.0, 800.0, 0.0, 600.0); // Establecer la proyeccion ortogonal coordenadas en 2D

	glMatrixMode(GL_MODELVIEW); //sistema de coordenadas 2D
	glLoadIdentity();

	std::cout << "[INFO] Renderizado de la ventana grafica del juego con OpenGL finalizado exitosamente." << std::endl;
}
int main(int argc, char** argv) {
	std::cout << "[INFO] Profesional Pong Game initializing..." << std::endl;
	glutInit(&argc, argv); // Inicializar GLUT con los argumentos de la linea de comandos de la aplicacion principal
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Establecer el modo de visualizacion de la ventana en doble bufferring y en color
	glutInitWindowSize(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT); // Establecer el tamanio de la ventana por defecto
	glutInitWindowPosition(100, 100); // Establecer la posicion de la ventana por defecto
	glutCreateWindow("PONG GAME - FreeGLUT + C++"); // Establecer el titulo de la ventana

	initGL(); // Inicializar los graficos de OpenGL

	// Inicializa la escena del juego
	SceneManager::setScene(new MenuScene());

	std::cout << "[INFO] Registrando todos los controladores y manejadores del juego..." << std::endl;
	glutDisplayFunc(displayCallback); // Establecer el callback de dibujo para renderizar todos los elementos en la ventana
	glutIdleFunc(idleCallback); // Establecer el callback de actualizacion para manejar la logica del juego
	glutKeyboardFunc(keyboardDown); // Establecer el callback de manejo de teclas para manejar los eventos de teclado cuando es presionado
	glutKeyboardUpFunc(keyboardUp); // Establecer el callback de manejo de teclas para manejar los eventos de teclado cuando es soltado

	std::cout << "[INFO] Todos los controladores y manejadores del juego registrados exitosamente." << std::endl;
	std::cout << "[INFO] Inicializando el juego..." << std::endl;

	previousTime = glutGet(GLUT_ELAPSED_TIME); // Guardar el tiempo actual para el control del tiempo del juego

	glutMainLoop(); // Iniciar el bucle principal de GLUT

	std::cout << "[INFO] Profesional Pong Game finished." << std::endl;
	return 0;

}

