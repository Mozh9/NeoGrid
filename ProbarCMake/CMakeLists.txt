
cmake_minimum_required(VERSION 3.10)
project(MiJuegoMultiplataforma LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# El ejecutable de tu juego
add_executable(MiJuego main.cpp)

# Configuración para crear el instalador de Windows
install(TARGETS MiJuego DESTINATION bin)
set(CPACK_PACKAGE_NAME "MiJuegoTerminal")
set(CPACK_PACKAGE_VENDOR "TuNombre")
set(CPACK_PACKAGE_VERSION "1.0.0")
include(CPack)
