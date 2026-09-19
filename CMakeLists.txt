cmake_minimum_required(VERSION 3.15)
project(MiJuegoTerminal VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Definir el ejecutable
add_executable(MiJuego 
	src/neoMain.cpp
	src/game_engine.cpp
	# Luego cambiar por main.cpp cuando todo funcione adecuadamente
)

# 2. Configurar el directorio de inclusión de cabeceras
target_include_directories(MiJuego PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 3. Dependencias de audio multi-plataforma. Hilos y librerías base. Por ahora tal vez no ocupamos, pero en el futuro es probable que sí
#find_package(Threads REQUIRED)
#target_link_libraries(MiJuego PRIVATE Threads::Threads)

if(WIN32)
    # Evita que Windows rompa std::min y std::max
    target_compile_definitions(MiJuego PRIVATE NOMINMAX)
else()
    # Termux y Linux necesitan estas librerías matemáticas y de enlace para el audio
    target_link_libraries(MiJuego PRIVATE dl m)
endif()

# 4. Copiar la carpeta 'assets' automáticamente a la carpeta de compilación (build)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

