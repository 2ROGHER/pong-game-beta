// Esta es una directiva donde el preprocesador le dice al preprocesador que el archivo se debe incluir una sola vez, este previene erroes de compilacion y mejora la eficiencia del programa
// Nueva caracteristica de C++11 (moderno)
#pragma once
#include "../physics/Vector2D.h"
/**
 * @class Entity (header)
 * @brief Clase base para las entidades del juego
 *
 * Declaracion de la clase base para las entidades del juego.
 * Esta clase declara las variables y metodos de las entidades del juego, que sera implementadas en las clases derivadas.
 * Esta es una clase (abstracta) ya que no puede ser instanciada directamente, solo puede ser usada como base para otras clases.No se puede crear objetos.
 * Importante, toda entidad del juego debe tener una posicion, una velocidad que definen el comportamiento de la entidad del juego. Estos se modelan como vectores en 2D.
 * El vector de la posicion representa la ubicacion en el tiempo de la entidad, es decir la posicion en el espacio (ventana) en el tiempo. Esto permite que ubicar la entidad en el espacio.
 * El vector de la velocidad representa la velocidad en el tiempo de la entidad, es decir la velocidad en el espacio (ventana) en el tiempo. Esto permite que la entidad se mueva en el espacio.
 *
 * @file Entity.h
 * @version 1.0
 * @author Roger Mestanza
 * @date 2025-06-19
 * @copyright Copyright (c) 2025
 *
 */

class Entity {
	public:
		Vector2D position; // Vector de posicion de la entidad en el espacio
		Vector2D velocity; // Vector de la velocidad de la entidad en el espacio
		
		float width; // Ancho de la entidad
		float height; // Alto de la entidad

		// Inicializamos el constructor con una posición y una velocidad definida en coordendadas cartesinas con valores predeterminados {0, 0}
		// Asi mismo establecemos el ancho y el alto de la entidad por defecto a 0 cuando se crea este Objeto por primera vez
		Entity(Vector2D pos = {0, 0}, Vector2D vel = {0, 0}, float w = 10.0f, float h = 10.0f): position(pos), velocity(vel), width(w), height(h) {}

		// udpate() y render() son metodos puros y virtuales que se deben implementar en las clases derivadas.
		virtual void update(float dt) = 0;
		virtual void render() = 0;

		// Metodo para obtener la posicion de cada entidad, de tal forma que s pueda actualizar la entidad en el espacio en el tiempo 
		// y para poder estimar las colisiones e interacciones entre las entidades en el juego
		float left() const { return position.x; } // retorna la posicion x de la entidad
		float right() const { return position.x + width; } // retorna la posicion x + ancho de la entidad
		float top() const { return position.y; } // retorna la posicion y de la entidad
		float bottom() const { return position.y + height; } // retorna la posicion y + alto de la entidad

};