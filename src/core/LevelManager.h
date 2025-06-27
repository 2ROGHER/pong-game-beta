#pragma once
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

/**
*
 * @class LevelManager
 * @brief Esta clase es la encargada controlar y gestionar los niveles del juego
 * su unica responsabilidad es leer archivos de configuarcion JSON y convertilos en coleccion de niveles
 * para modificar el estado del juego segun sea el nivel que alcance el jugador.
 *
 * @file LevelManager.h
 * @version 1.0
 * @date 2025-06-21
 * @copyright Copyright (c) 2025
 */

 // Usar la configuracion de niveles en formato JSON
using json = nlohmann::json;

// Este es un tipo de dato compuesto, que permite agrupar multiples variables en una sola unidad
// Este es una especie de contenedor
// Se usa para modelar entidades complejas u objetos
struct LevelData {
    int level;
    float ballSpeedX;
    float ballSpeedY;
    float paddleSpeed;
    int scoreThreshold;
    int timeThreshold;
    int lives;
    std::vector<std::string> ballColors;
};

class LevelManager {
private:
    std::vector<LevelData> levels; // Vector de (levels), este represanta un objeto de nivel con [key: value]

    int currentLevel = 1; // Nivel actual basico

public:
    LevelManager();

    bool loadFromFile(const std::string& filename);
    void loadFileFromPath(const std::string& path);
    bool updateLevel(int totalScore); // metodo para actualizar el nivel
    int getNextLevelThreshold() const; // metodo para obtener el siguiente nivel
    const LevelData& getCurrentLevel() const; // metodo para obtener los datos del nivel actual
    int getLevelNumber() const; // metodo para obtener el numero de nivel
    // Metodo para obtener el vector de niveles completo
    std::vector<LevelData>& getLevels() { return levels; }

    //Metodo que permite aplicar los datos obtenidos del archivo de configuracion y aplicarlos segun el nivel en el juego
    void applyLevelData(const LevelData& levelData);
};

