/*Pues este es un experimento, la neta creo que   sería interezantehacer un videojuego con esto y ver hasta donde puedo llegar, en plan de que ¿podría yo hacer un motor de videojuegos aquí? hasta donde podré llegar? por ahora voy a intentar hacer todo aquí a ver hasta donde puedo llegar empezemos   por algo simple*/

/*Terminar movimientoJugador(){} linea: 196
 * Creo que al final de reaccionar input pestana 2 hay que agregar una función que se asegure la camara no intente salirse del mapa*/
/*
#ifdef __ANDROID__
    // Si estamos en Termux/Android, apagamos los servidores de audio de escritorio
    #define MA_NO_PULSEAUDIO
    #define MA_NO_ALSA
    #define MA_NO_JACK
#endif*/

#define MINIAUDIO_IMPLEMENTATION
#include "miniaudio.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <array>
#include <string>
#include <limits>
#include <memory>
#include <fstream>

using std::cout;
using std::endl;
using std::vector;
using std::cin;

//Una entidad será cualquier cosa que tenga un símbolo en mapa y una posición X Y

namespace debug{

}
namespace dat {

	int dimencionY_Camara = 4;
	int dimencionX_Camara = 8;
}

struct Entidad{
	int posicionY = 0;
	int posicionX = 0;
	char sprite = ' ';
};

struct Camara{
	int inicioY = 0;
	int inicioX = 0;
	int finalY = 0;
	int finalX = 0;

	void igualarPosicionJugador(const Entidad& py1,vector<vector<char>>& mapa){
		//posicion Y jugador - 7
//if(py1.posicionY > 0 && py1.posicionX > 0){
		if(py1.posicionY - dat::dimencionY_Camara >= 0){
 
	inicioY = py1.posicionY - dat::dimencionY_Camara;
		}
//posicion X jugador - 15

		if(py1.posicionX - dat::dimencionX_Camara >= 0){

	inicioX = py1.posicionX - dat::dimencionX_Camara;
		}

	//Posicion Y jugador + 7

		if(py1.posicionY + dat::dimencionY_Camara <= mapa.size() - 2){
			finalY = py1.posicionY + dat::dimencionY_Camara;
		}
	
	//posicion X jugador + 15


	if(py1.posicionX + dat::dimencionX_Camara <= mapa[py1.posicionY].size()){

		finalX = py1.posicionX + dat::dimencionX_Camara;
	}
//}
	

	cout << inicioY << endl;
	cout << inicioX << endl;
	cout << finalY << endl;
	cout << finalX << endl;
	}
};

//El flujo de juego principal va a estar aqui
class FlujoJuego {

bool juegoCorriendo;  
vector<vector<char>> tileMap;
vector<vector<char>> mapaMenu;

void archivoTxtA_Vector(std::string nombreArchivo, vector<vector<char>>& vectorVacio){

    std::ifstream archivo(nombreArchivo); //abrir archivo
    char tile; //para leer el archivo es x linea
    vectorVacio.push_back(vector<char>());//Coss a mejorar: hacer un if por si algo raro pasa y tengo un tileMap con 1 fila o más
    int filas = 0;

    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo." << std::endl;
    }

    while (archivo.get(tile)){
	
	if(tile == '\n'){
		vectorVacio.push_back(vector<char>());
		filas++;
	}else{
		vectorVacio[filas].push_back(tile);
	}

    }

    archivo.close(); //cerrar archivo
    
}

//como mapa o archivos de guardado
void cargarDatos(){

	//pantalla de carga
	cout << "Cargando datos 0%" << endl;

	archivoTxtA_Vector("assets/Menu.txt", mapaMenu);
	cout << "Menu Cargado" << endl;
	cout << "Cargando datos 50%" << endl;

	archivoTxtA_Vector("assets/Mapa.txt", tileMap);
	cout << "TileMap Cargado" << endl;
	cout << "Cargando datos 100%" << endl;

	cout << "Datos cargados" << endl;

}

Entidad jugador1;

void dibujarMapPantalla(const Camara& posicionCamara, const vector<vector<char>>& map){
	/*cout << posicionCamara.inicioY << endl;
	cout << posicionCamara.finalY << endl;
	cout << posicionCamara.inicioX << endl;
	cout << posicionCamara.finalX << endl;*/
#ifdef _WIN32
	std::system("cls");
#else
	std::system("clear");
#endif
	for(int numeroFila = posicionCamara.inicioY; numeroFila <= posicionCamara.finalY; numeroFila++){

		for(int numeroColumna = posicionCamara.inicioX; numeroColumna <= posicionCamara.finalX; numeroColumna++){
//capás y lo wue sigue como otra función
			if(numeroFila == jugador1.posicionY && numeroColumna == jugador1.posicionX && indicadorPestana == 2){
			cout<<jugador1.sprite;
			}else{
				cout<<map[numeroFila][numeroColumna];
			}
		}

		cout << endl;
	}
	
	cout << endl;
}

Camara camara{};
Camara camaraMenu{0,0,14,30};

//dibuja la primera pantalla

int indicadorPestana; //indica en qué pestaña está el usuario en el juego, el menu, la pantalla de título, el mini mapa, etc.

/* 1 = Título del juego
 * 2 = El juego en si
 */

void inicializarDatosBase(){

	//pantalla de carga
	cout << "Inicializando datos base 0%" << endl;
	jugador1 = Entidad{6,10,'@'};

	dibujarMapPantalla(camaraMenu, mapaMenu);
	cout << "Pantalla Inicializada" << endl;
	cout << "Inicializando datos base 50%" << endl;

	indicadorPestana = 1;
	
	cout << "indicadorPestana Inicializado" << endl;
	cout << "Inicializando datos base 100%" << endl;


	//lo mismo que en cargarDatos()
	cout << "Datos base inicializados" << endl;
}

//devuelve el input de usuario
char checkInput(){

bool inputValido = false;
char input = '0';

	do{

	cin >> input;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	if(input == 'e' ||
		input == 's' ||
		input == 'd' ||
		input == 'f' ||
		input == 'u' ||
		input == 'j' ||
		input == 'i' ||
		input == 'k' ||
		input == 'q' ||
		input == 'p'){

		cout << "input valido " << input << endl;
		inputValido = true;

	}else {
			cout << "input invalido, reitere su respuesta" << endl;
		inputValido = false;

		}

	}while(!inputValido);	

	return input;
}

/*void leerPosicionJugador(){

	 tileMap[jugador1.posicionY][jugador1.posicionX] = jugador1.sprite;

} esto ya no me sirve porque así no dibujo arriba del mapa y cuando me mueva tendría que guardar el tile de abajo de la última posición de todas las entidades y remplazarlo después de que cada una se mueva*/ 


//cambiar a la Pestaña 2
void cambiarPestana2(){
	indicadorPestana = 2;

	camara.igualarPosicionJugador(jugador1,tileMap);

	dibujarMapPantalla(camara, tileMap);

}

void pressToStart(int input){

	if(input == 'u'){
		cout << "Juego iniciado" << endl;
		cambiarPestana2();
	}
}

void movimientoJugador(int input){
	if (input == 'e' && jugador1.posicionY > 0){
		jugador1.posicionY -= 1;
	}
	if (input == 'd' && jugador1.posicionY < tileMap.size() - 2){
		jugador1.posicionY += 1;
	}
	if (input == 's' && jugador1.posicionX > 0){
		jugador1.posicionX -= 1;
	}
	if (input == 'f' && jugador1.posicionX < tileMap[jugador1.posicionY].size() - 1){
		jugador1.posicionX += 1;
	}
}


//Reaccionar al input
void reaccionarInput(char input){
	cout << "en reaccionando a input" << endl;
	if(indicadorPestana == 1){
		pressToStart(input);
	}else if(indicadorPestana == 2){
		movimientoJugador(input);
		camara.igualarPosicionJugador(jugador1,tileMap);
		dibujarMapPantalla(camara, tileMap);
	}else{
		cout << "algo salió mal, indicadorPestana no tiene un parametro valido" << endl;
	}

}

public:

FlujoJuego() : juegoCorriendo(false), tileMap(vector<vector<char>>()), mapaMenu(vector<vector<char>>()), indicadorPestana(0){}

void inicializar(){

	//Pantalla carga para los dos. Cargar todo, Inicializar todo + primera pantalla
	cargarDatos();
	inicializarDatosBase();
	juegoCorriendo = true; //bucle principal inicia
}

void ejecutar(){
	cout << "ejecutando programa" << endl; //hacer una función para cualquier debug de cualquier parte del codigo antes y después de la inicialización de la primera pantalla.

	//bucle principal
	while(juegoCorriendo == true){
		char input = checkInput();
		if(input != 'q'){
			reaccionarInput(input);
		}else{
			juegoCorriendo = false;
		}
	}
}

};

//FUNCIÓN MAIN
int main(){
	ma_result result;
	ma_engine engine;
	ma_sound sound;

	result = ma_engine_init(NULL, &engine);
	if (result != MA_SUCCESS){
		return result;
	}

	result = ma_sound_init_from_file(&engine, "assets/audios/RPG_proyecto.mp3", 0, NULL, NULL, &sound);
	if (result != MA_SUCCESS){
		return result;
	}

	ma_sound_start(&sound);

	FlujoJuego gameEngine{};
	gameEngine.inicializar();
	gameEngine.ejecutar();

	return 0;
}

