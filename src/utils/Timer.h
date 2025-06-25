#pragma once
/**
 * @class Timer.h
 * @brief
 * Esta archivo se encarga de implementar el score del juego, se definio en el archivo Score.h dentro de la carpeta core
 *
 *
 * @file Timer.h
 * @version 1.0
 * @date 2025-06-21
 * @copyright Copyright (c) 2025
 */

#include <chrono> // Importante
using namespace std::chrono;

class Timer {
	private:
		std::chrono::steady_clock::time_point startTime_;
		std::chrono::steady_clock::time_point currentTime_;
		bool isRunning_;


	public:
		Timer();

		void start();
		void stop();
		void reset();
		void update();

		float getElapsedTime() const; // Tiempo transcurrido en segundos
		bool isRunning() const;

		// Setters y Getters
		void setStartTime(const std::chrono::steady_clock::time_point& startTime) { startTime_ = startTime; }
		void setCurrentTime(const std::chrono::steady_clock::time_point& currentTime) { currentTime_ = currentTime; }
		void setIsRunning(bool isRunning) { isRunning_ = isRunning; }

		std::chrono::steady_clock::time_point getStartTime() const { return startTime_; }
		std::chrono::steady_clock::time_point getCurrentTime() const { return currentTime_; }
		bool getIsRunning() const { return isRunning_; }



};