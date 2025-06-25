# Agregar la version que se va a usar de CMake
cmake_minimum_required(VERSION 3.21)
project(pong-game VERSION 0.1.0 LANGUAGES CXX)

# Usa C++17 o superior
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Habilitar la integraci�n con vcpkg  
if(DEFINED ENV{VCPKG_ROOT})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "")
endif()

# Agrega src y include
include_directories(include)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    src/*.cpp
)

add_executable(pong ${SOURCES} 
    "src/entities/Ball.h"
    "src/entities/Paddle.h"
    "src/entities/Entity.h"
    "src/physics/Vector2D.h"
    "src/physics/Vector2D.cpp"
 "src/core/GameState.h" "src/core/Game.h" "src/scenes/IScene.h" "src/scenes/GameScene.h" "src/scenes/MenuScene.h" "src/scenes/SceneManager.h" "src/scenes/SceneManager.cpp" "src/core/LevelManager.h" "src/core/LevelManager.cpp" "src/core/Score.h" "src/utils/Timer.h" "src/utils/Timer.cpp" "src/utils/Label.h")

# Enlaza GLUT si es necesario (CMake lo har� con vcpkg si est� bien instalado)
find_package(freeglut CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

target_link_libraries(pong PRIVATE
    OpenGL::GL
    GLUT::GLUT 
    FreeGLUT::freeglut
)