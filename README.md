# pong-game-beta

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