cmake_minimum_required(VERSION 3.15)
project(MiJuegoTerminal VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Definir el ejecutable
add_executable(MiJuego 
    src/main.cpp
)

# 2. Configurar inclusiones de forma limpia
target_include_directories(MiJuego PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 3. Solucionar dependencias de miniaudio por sistema operativo
find_package(Threads REQUIRED)
target_link_libraries(MiJuego PRIVATE Threads::Threads)

if(NOT WIN32)
    # En Linux/macOS miniaudio necesita las librerías de enlace dinámico y math
    target_link_libraries(MiJuego PRIVATE dl m)
endif()

if(APPLE)
    # En macOS se requieren los frameworks nativos de audio
    target_link_libraries(MiJuego PRIVATE "-framework CoreFoundation" "-framework AudioToolbox")
endif()

if(WIN32)
    target_compile_definitions(MiJuego PRIVATE NOMINMAX)
endif()

# 4. Copiar la carpeta 'assets' automáticamente a la carpeta de compilación (build)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
