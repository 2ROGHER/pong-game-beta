#include <iostream>
#include <fstream>
#include <iostream>
#include "LevelManager.h"

using namespace std;

/**
* 
 * @implementation Esta clase es la implementacion de la clase LevelManager.h
 * @brief
 *
 * @file LevelManager.cpp
 * @version 1.0
 * @date 2025-06-21
 * @copyright Copyright (c) 2025
 */

 // Constructor: inicializa el nivel actual a 1 (primer índice del vector) y primer nivel por defecto
LevelManager::LevelManager() : currentLevel(0) {

}

// Metodo para cargar los niveles desde un archivo de configuració JSON
// Este metodo usa libreria <fstream> y la libreria nlohmann/json para leer el archivo de nivel de
// archivo de configuracion y cargar los datos necesarios
bool LevelManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "[ERROR] No se pudo abrir el archivo de niveles JSON en la ruta: " << filename << '\n';
        return false;
    }

    try {
        std::cout << "[INFO] Cargando niveles desde " << filename << "\n";
        json data;
        file >> data;
        levels.clear();

        for (const auto& item : data) {
            LevelData level;
            level.level = item.value("level", 1);
            level.ballSpeedX = item.value("ballSpeedX", 200.0f);
            level.ballSpeedY = item.value("ballSpeedY", 150.0f);
            level.paddleSpeed = item.value("paddleSpeed", 300.0f);
            level.scoreThreshold = item.value("scoreThreshold", 0);
            level.timeThreshold = item.value("timeThreshold", 40);
            level.lives = item.value("lives", 3);

            // Esto es imporatante para agregar una lista de colores para loas pelotas
            // Esto permite crear una lista de colores para las pelotas en el nivel
            if (item.contains("ballColors") && item["ballColors"].is_array()) {
                for (const auto& color : item["ballColors"]) {
                    level.ballColors.push_back(color.get<std::string>());
                }
            }

            levels.push_back(level); // creamos un vector de niveles y lo llenamos con los valores de vector
        }

        std::cout << "[INFO] Se cargaron " << levels.size() << " niveles correctamente desde " << filename << "\n";
        
        return !levels.empty();
    }
    catch (const std::exception& e) {
        std::cerr << "[ERROR] Excepción al leer levels.json: " << e.what() << '\n';
        return false;
    }
}

// Metodo que permite manejar y controlar cuando se cambia de nivel segun el puntaje obtenido
bool LevelManager::updateLevel(int totalScore) {
    int previusLevel = currentLevel;
    for (size_t i = 0; i < levels.size(); i++) {
        if (totalScore >= levels[i].scoreThreshold) {
            currentLevel = static_cast<int>(i);

        }
        else {
            break; // Ya no hay niveles superiores que cumplan la condición
        }
    }
        return currentLevel != previusLevel;
}


int LevelManager::getNextLevelThreshold() const {
    if (currentLevel + 1 < static_cast<int>(levels.size())) {
        return levels[currentLevel + 1].scoreThreshold;
    }
    return std::numeric_limits<int>::max(); // No hay más niveles
}

// Metodo que permite obtener el (nivel actual) en la que se encuentra el juego actualmente
const LevelData& LevelManager::getCurrentLevel() const {
    if (levels.empty()) {
        throw std::runtime_error("[ERROR] No hay niveles cargados en LevelManger.");
    }
    if (currentLevel >= static_cast<int>(levels.size())) {
        throw std::out_of_range("[ERROR] currentLevel fuera del rango de niveles disponibles.");
    }
    return levels[currentLevel];
}

// Metodo que permite obtener o recuperar el nivel numerico
int LevelManager::getLevelNumber() const {
    return getCurrentLevel().level;
}