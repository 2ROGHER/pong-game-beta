#include "Game.h"
#include <GL/freeglut.h>
#include <iostream>
#include "../utils/Timer.h"
#include "../core/LevelManager.h"

#include <memory>

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

// Implementacion del constructor de la clase Game
Game::Game() {

	player = new Paddle(Vector2D(50, 250)); // La raqueta se inicializa en la posición (50, 250)

	ball = new Ball(Vector2D(400, 300)); // La Pelota se inicializa en la posición (400, 300)

	score = new Score(); // Crea un nuevo objeto de score
	timer = new Timer(); // Crea un nuevo objeto de temporizador


	label = new Label(player, timer, score, levelManager); // No se crea ningun instancia de [LevelManager] sino se usa el atributo declarado en esta clase 
	// para modificar la logica del juego cuando se cambie el nivel. Esta propiead se pasa a [Label] para modificar su logica, ya que este tiene estados compartidos


}

Game::~Game() {
	delete player;
	delete ball;

	delete score;
	//delete levelManager;
	delete label;
	delete timer;


}

// Inicializa el juego estableciendo los valores para los vectores de posiciones y velocidad, iniciales
void Game::init() {
	const LevelData& level = levelManager->getCurrentLevel();
	addBallForCurrentLevel(level);

	int currentScore = levelManager->getLevelNumber(); // 1

	if (currentScore != levelManager->getNextLevelThreshold()) {
		std::cout << "[INFO] El nivel actual es : " << levelManager->getCurrentLevel().level << std::endl;
		const LevelData& level = levelManager->getCurrentLevel(); // Obtiene el nivel actual que se paso en la clas GameScene

		std::cout << "[INFO] Iniciando juego con configuración del nivel dentro de Game.h " << level.level << std::endl;


		std::cout << "[INFO] Estableciendo valores de velocidad de la bola: " << level.ballSpeedX << ", " << level.ballSpeedY << "y el [Paddle]:  " << level.paddleSpeed << std::endl;

		ball->setSpeed(level.ballSpeedX, level.ballSpeedY); // modifica la velocidad de la pelota, cuando el juego se inicie
		std::cout << "[INFO] Iniciando juego con configuración del nivel exitoso " << level.level << std::endl;
	}

	ball->reset(); // Resetea la pelota a su posición inicial listo para el juego
	label->init(); // Inicializa el score cuando se cargue el juego

	// Inicia el temporizador
	timer->start();
}

void Game::update(float dt) {
	// Actualiza el estado de los objetos del juego con las velocidades y posiciones que se obtienen del archivo de configuracion
	// Actualiza el temporizador (importante), al inciar el juego
	timer->update();

	player->update(dt); // Actualiza la posición y la velocidad del jugador pasando como parametro el delta time, por cada unidad de tiempo (frame)

	for (auto& ball : balls) {
		ball->update(dt); // Se actualiza la posición y la velocidad de cada bola por cada unidad de tiempo  (FRAME)
	}


	label->update(dt);


	// Logica que permite cambiar de nivel bajo las condiciones del juego
	int totalScore = score->getPlayerScore();
	int nextThreshold = levelManager->getNextLevelThreshold();

	if (totalScore >= nextThreshold) {
		if (levelManager->updateLevel(totalScore)) {
			int currentLevel = levelManager->getLevelNumber();
			const LevelData& levelData = levelManager->getCurrentLevel();

			std::cout << "[INFO] Cambio de nivel detectado desde Game.cpp. Nivel actual: " << currentLevel << " . El puntaje total: " << totalScore << std::endl;

			// Aplicar nueva velocidad de la pelota cuando se cambia de nivel con los valores de la configuracion del juego
			ball->setSpeed(levelData.ballSpeedX, levelData.ballSpeedY);

			std::cout << "[INFO] Estableciendo valores de velocidad de la bola: velocidadX:" << levelData.ballSpeedX << ", " << "velocidadY:" << levelData.ballSpeedY << std::endl;

			// Se actucaliza la velocidad del jugador, es decir del objeto Paddle
			player->setSpeed(levelData.paddleSpeed);
			// Agrega o suma las vidas para el jugador cuando se cambia de nivel con los valores del archivo de configuracion
			player->setLives(levelData.lives);

			std::cout << "[INFO] Estableciendo velocidad del jugador: " << levelData.paddleSpeed << std::endl;

			// Agregar mas pelotas cuando el jugador sube de nivel
			addBallForCurrentLevel(levelData);


			timer->reset(); // Resetear tiempo al cambiar de nivel
			timer->start(); // Comenzar el temporizador nuevamente para medir el tiempo en cada nivel del juego, cuando el jugador suba de nivel
			label->init();  // Re-inicializar label con nueva config para mostrar toda la informacion del juego cuando se cambia de nivel
		}
	}
	// Esta es la logica que  permite controlar cuando la pelota sale de la ventana lateral izquierda
	// cuando la pelota sale, este se elimina de la ventana y el jugador pierde una vida.
	// El juego termina cuando el jugador pierde todas sus vidas o cuando pierde todas las pelotas en la ventana
	for (auto it = balls.begin(); it != balls.end();) {
		auto ball = *it; // obtenemos el shared_ptr<Ball>, es decir una bola de la lista de pelotas como referencia para modificar la lista de pelotas, sino no se puede modificar la lista de pelotas
		// Esta logica maneja las colisiones del jugador  con la pelota, es decir establece la logica para que la pelota rebote con la raqueta
		// Los metodos right(), left(), top(), bottom() permiten obtener las coordenadas de la posicion de la (Pelota) y el (Jugador) y con ello poder cacular y estimar las colisiones
		if (ball->right() > player->left() && 
			ball->left() < player->right() &&
			ball->top() < player->bottom() &&
			ball->bottom() > player->top()) {
			ball->velocity.x = -ball->velocity.x;
			ball->position.x = player->right();
		}


		// Si la pelota sale de la ventana lateral izquierda, se resta una vida al jugador y se quita dicha pelota del la colección
		if (ball->position.x < 0) {
			player->loseLife(); // Si la pelota sale de la pantalla lateral izquierda, se resta una vida al jugador
			std::cout << "[INFO] Una pelota fue eliminada. Pelotas restantes: " << balls.size() - 1 << std::endl; // Debug

			// Elimina la pelota del vector y continúa sin incrementar el iterador
			it = balls.erase(it);
			continue;
		}
		++it; // En cada iteracion increment el iterador
	}

	if (balls.empty() || player->getLives() <= 0) {
		std::cout << "[INFO] Todas las pelotas fueron eliminadas. Fin del juego." << std::endl;
		// Logica que controla el reinicio del juego
		Game::setGameState(GameState::GAMEOVER);
		//ball->reset();
	}


}

// Metodo que permite renderizar los objetos del juego en la ventana o interfaz grafica
void Game::render() {
	player->render(); // Renderiza el jugador en la ventana

	for (auto& ball : balls) {
		ball->render(); // El bucle itera por cada bola en la lista de pelotas y las renderiza en la ventana
	}

	// Renderizar el Label en la ventana
	label->render();
}

// Metodo del juego que permite manejar y controlar las entradas del teclado del jugador
void Game::handleInput(unsigned char key, bool isPressed) {
	// TODO("Implementar el manejo de entradas del teclado con switch case (profesional)")
	if (key == 'w') player->velocity.y = isPressed ? player->getSpeed() : 0;
	if (key == 's') player->velocity.y = isPressed ? -player->getSpeed() : 0;
	if (key == 27) exit(0);
}

// Este metodo permite establecer el LevelManager que se pasa en la escena del juego
// Permite modificar el el estado de los niveles que comparte y que fueron inyectados desde GameScene
void Game::setLevelManager(std::shared_ptr<LevelManager> manager) {
	// Esta es una forma especial de inicializar propieades en una clase
	this->levelManager = manager; // Establece el LevelManager que se paso en la escena del juego

	if (label != nullptr) {
		label->setLevelManager(manager);
	}
}

// Metodo que permite convertir una cadena hexadecimal en un entero (metodo de casting)
int hexStringToInt(const std::string& hex) {
	return std::stoi(hex.substr(1), nullptr, 16);
}

// Implementacion del metodo para agregar pelotas segun el nivel que alcance el jugador
// ello permite dificultad al subir de nivel
void Game::addBallForCurrentLevel(const LevelData& level) {
	//balls.clear(); // limpia la lista de pelotas anteriores
	for (const std::string& colorHex : level.ballColors) {
		int hexInt = hexStringToInt(colorHex);
		auto ball = std::make_shared<Ball>(
			Vector2D(
				100.0f + rand() % 300, // Genera un número aleatorio entre 100 y 300
				100.0f + rand() % 300 // Genera un número aleatorio entre 100 y 300
			),
			DEFAULT_BALL_RADIUS,
			static_cast<float>(hexInt)
		);

		ball->setSpeed(level.ballSpeedX, level.ballSpeedY); // Establece la velocidad de la pelota que se pasa a traves del nivel
		player->setSpeed(level.paddleSpeed); // Establece el velocidad del paddle que se pasa a traves del nivel
		balls.push_back(ball); // Por ultimo se agrega la bola a la coleccion 
	}
	//const LevelData& level = levelManager->getCurrentLevel();
	//auto  newBall = std::make_shared<Ball>(Vector2D(400, 300)); // Se agrega una nueva bola
	//newBall->setSpeed(level.ballSpeedX, level.ballSpeedY);
	//balls.push_back(newBall);
}


