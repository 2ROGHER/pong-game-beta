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
 "src/core/GameState.h" "src/core/Game.h" "src/scenes/IScene.h" "src/scenes/GameScene.h" "src/scenes/MenuScene.h" "src/scenes/SceneManager.h" "src/scenes/SceneManager.cpp" "src/core/LevelManager.h" "src/core/LevelManager.cpp" "src/core/Score.h" "src/utils/Timer.h" "src/utils/Timer.cpp" "src/utils/Label.h" "src/scenes/GameOverScene.h" "src/scenes/GameOverScene.cpp")


 
# IMPORTANTE: Copia el archivo config.json automáticamente después del build
# Esto es importante para el funcionamiento de la aplicaci�n al cargar las configuraciones de archivos externos
add_custom_command(TARGET pong POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory "$<TARGET_FILE_DIR:pong>/config"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/config/config.json"
        "$<TARGET_FILE_DIR:pong>/config/config.json"
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_SOURCE_DIR}/config/levels.json"
        "$<TARGET_FILE_DIR:pong>/config/levels.json"
)



# Enlaza GLUT si es necesario (CMake lo har� con vcpkg si est� bien instalado)
find_package(freeglut CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

target_link_libraries(pong PRIVATE
    OpenGL::GL
    GLUT::GLUT 
    FreeGLUT::freeglut
)