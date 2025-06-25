# pong-game-beta

Basic videogame inspired by Pong videogame using C++ and FreeGLUT library. This videogame is flexile, scalable and maintainable using best practices and software architectures  

## FASE 1: DISEÑO DE LA ARQUITECTURA DEL SISTEMA
Crear un juego basico de Ping Pong:

- Movimiento suave
- Fisica realista
- Modularidad
- Estructura profesional(mantenible, flexible, desacoplado, SOLID, Desing Patterns, etc)
- Arquitectura limpia para que permita agregar __features__ en el futuro
- Documentación con el estilo CppDoc(Doxygen-Style)

## FASE 2: DISEÑO DE COMPONENTES Y LOGICA
Este juego sige los principios y fundamentos de diseño de juegos aplicando fundamentos matemáticos y físicos aplicados al movimiento, colisión, rebote,etc.

| Concepto            | Aplicación en el juego        |
| ------------------- | ----------------------------- |
| Vectores            | Movimiento de pelota          |
| Colisiones AABB     | Paleta ↔ Pelota               |
| Ángulo de rebote    | Rebote según punto de impacto |
| Velocidad constante | Pelota y paletas              |
| Delta Time          | Movimiento fluido             |


### Modelamiento (Entidades y clases principales)
1. Entity (Abstract)
2. Paddle (Jugador o Paleta)
3. Ball

## FASE 3: INICIO DEL DESARROLLO
# Instalaciones
Para este proyecto se debe tener instalado las siguientes herramientas:
1. CMake
2. vcpkg (sistema de gestion de dependencias moderna y robusta para C++)
3. g++ (opcional)

### Pasos para compilar el juego
```bash
# Paso 1: Ejutar la instalacion de todas las dependencias:
vcpkg install --presets

# Si no funciona, solo ejecutar el siguiente comando: 
vcpkg install 



```

### Paso 2: Vincular las depedencias instaladas para poder usarlas dentro del proyecto.
```bash ##### 1. Dentro del directorio src crear un directorio (build)
mkdir build && cd build
```
### 2. Ubicado en la carpeta build ejectuar lo siguiente:
```bash 
cmake .. -DCMAKE_TOOLCHAIN_FILE=C:/Users/ROGER/Documents/vcpkg/scripts/buildsystems/vcpkg.cmake -DCMAKE_BUILD_TYPE=Release
```

### Paso 3: Compilar el juego usando CMake
```bash 
## Ejecutar este comando siempre ubicado dentro de la carpeta (build)
cmake --build .
```