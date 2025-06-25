
#include "Vector2D.h" // Incluimos la cabecera correspondiente
#include <cmath>      // Aseguramos tener acceso a funciones matem�ticas como sqrt

/*
 * @implementation Implementaci�n de la clase Vector2D.h 
 * @brief
 * @file Vector2D.h
 * @version 1.0
 * @date 2025-06-22
 * @copyright Copyright (c) 2025
 * 
*/

Vector2D::Vector2D(float x, float y) : x(x), y(y) {} // Implementaci�n del constructor con miembros (propiedades)

Vector2D::Vector2D() : x(0), y(0) {} // constructor por defecto (por si no lo tienes)

// Implementaci�n del m�todo de suma de vectores
Vector2D Vector2D::operator+(const Vector2D& v) const {
    return Vector2D(x + v.x, y + v.y);
}

// Implementaci�n del m�todo de multiplicaci�n por escalar
Vector2D Vector2D::operator*(float scalar) const {
    return Vector2D(x * scalar, y * scalar);
}

// Implementaci�n del m�todo para calcular la magnitud del vector
float Vector2D::magnitude() const {
    return std::sqrt(x * x + y * y);
}

// Implementaci�n del m�todo para normalizar el vector
void Vector2D::normalize() {
    float mag = magnitude();
    if (mag > 0.0f) {
        x /= mag;
        y /= mag;
    }
}