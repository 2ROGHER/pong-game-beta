
/**
 * @class Vector2D
 * @brief Clase base para representar vectores en 2D de movimiento y velocidad aplicando conceptos de simulación física.
 * Esta declaracion de clase, contiene los métodos para calcular la aceleración y velocidad de desplazamiento del objeto (Ball).
 * Esta clase, es una (cabezera) no se implementa solo de declara para poder usarla en otras partes del código implementando los métodos
 * Esta clase basica de vectores, permite manipular posiscion y movimiento de los objetos en 2D en la ventana.
 * Los metodos declarados en esta declaracion de clase no poseen logica interna.

 * En el metodo de constructor se declaran los valores iniciales de x y y de una forma especial que se usa para inicializar los miembros de la clase cuando se crea un objeto de la clase.

 *
 * * La primera x y y (a la izquierda) son las variables miembro de la clase Vector2D.
 * * La segunda x y y (a la derecha) son los parámetros del constructor.
 * * Equivalente a this -> x = x y this -> y = y.
 *
 *
 * Con esta clase podemos representar la (posicion y velocidad) de cualquier objeto en nuestra ventana 2D.
 *
 * @file Vector2D.h
 * @version 1.0
 * @date 2025-06-22
 * @copyright Copyright (c) 2025
 */

class Vector2D {
public:
    float x; // Desplazamiento horizontal (ejex x)
    float y; // Desplazamiento vertical (ejey y)
    // float angle; // Angulo
    // float magnitude;
    // float acceleration;

    // Declaracion del constructor
    // Se inicializan los valores de x y y (inicializacion de lista de miembros)
    // Esta es una forma especial de inilicializar los miembros de una clase en POO.
    Vector2D(float x = 0, float y = 0);

    // Cosntructor por defecto
    Vector2D();

    // Esta forma de declarar un metodo implica que se esta sobreescribiendo el metodo de (+)
    // Se puede definir como deben comportarse los operadores (+, *, *, /, etc) en C++.
    // Esta funcion al igual que los otros metodos sobrescritos son (constante) es decir no modifican el objeto actual (Vector2D).
    // Suma de vectores
    Vector2D operator+(const Vector2D& v) const;

    Vector2D operator*(float scalar) const;

    void normalize();

    float magnitude() const;
};