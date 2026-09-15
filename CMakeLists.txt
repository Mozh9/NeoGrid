

cmake_minimum_required(VERSION 3.15)
project(MiJuegoTerminal VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MiJuego 
    src/main.cpp
)

# Evita que Windows rompa std::min y std::max
if(WIN32)
    add_compile_definitions(NOMINMAX)
endif()

target_include_directories(MiJuego PUBLIC include)

