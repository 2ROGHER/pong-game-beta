#pragma once
/**
 * @class Score.h 
 * @brief
 *
 *
 * @file Score.h
 * @version 1.0
 * @date 2025-06-21
 * @copyright Copyright (c) 2025
 */

class Score {
	private:
		int playerScore;

	public: 
		Score();
		void reset(); // Metodo para resetear el puntaje a 0, se actualiza cuando se reinicia el juego
		void increasePlayerScore(); // Metodo para aumentar el puntaje del jugador
		int getPlayerScore(); // Metodo para obtener el puntaje del jugador
		void setPlayerScore(int score);
		void render(); // HUD del mercador, metodo para renderizar el puntaje en la ventana.

};