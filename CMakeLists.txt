cmake_minimum_required(VERSION 3.15)
project(MiJuegoTerminal VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# EN LUGAR DE GLOB: Listas tus archivos a mano. 
# Cuando agregues jugador.cpp, solo lo escribes aquí al lado.
add_executable(MiJuego 
    src/main.cpp
)

target_include_directories(MiJuego PUBLIC include)

