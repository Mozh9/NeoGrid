
cmake_minimum_required(VERSION 3.15)

# 1. DETECCIÓN EXCLUSIVA DE TERMUX
# Si detecta que estamos en la consola de Termux, fuerza el modo Linux estándar
if(DEFINED ENV{PREFIX} AND "$ENV{PREFIX}" MATCHES "com.termux")
    set(SO_TERMUX TRUE)
    set(ANDROID FALSE CACHE BOOL "Desactivar NDK en Termux" FORCE)
    set(CMAKE_SYSTEM_NAME "Linux" CACHE STRING "Forzar entorno Linux estándar" FORCE)
endif()

project(MiJuegoTerminal VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. Definir el ejecutable
add_executable(MiJuego 
    src/main.cpp
)

# 3. Configurar directorios de inclusión de forma limpia
target_include_directories(MiJuego PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 4. Solucionar dependencias de audio de forma automática por plataforma
find_package(Threads REQUIRED)
target_link_libraries(MiJuego PRIVATE Threads::Threads)

if(WIN32)
    # Configuración limpia para Windows
    target_compile_definitions(MiJuego PRIVATE NOMINMAX)
    target_compile_definitions(MiJuego PRIVATE SISTEMA_WINDOWS=1)
else()
    # Configuración para Termux y Linux de escritorio
    target_link_libraries(MiJuego PRIVATE dl m)
    
    if(SO_TERMUX)
        target_compile_definitions(MiJuego PRIVATE SISTEMA_TERMUX=1)
    else()
        target_compile_definitions(MiJuego PRIVATE SISTEMA_LINUX=1)
    endif()
endif()

# 5. Copiar la carpeta 'assets' automáticamente a la carpeta de ejecución
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
