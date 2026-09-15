cmake_minimum_required(VERSION 3.15)
project(MiJuegoTerminal VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(MiJuego 
    src/main.cpp
)

target_include_directories(MiJuego PUBLIC include)


