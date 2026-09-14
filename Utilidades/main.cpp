/*Script para manejar versiones de prueba del
 * código principal.
 * Cambiar P_X por P_Y
 * Subir de nivel P_X
 * Convertir P_X a UltimaVersion
 * Crear Nueva Prueba
 * */
#include "MotorPrograma.hpp"

int main (){

	MotorPrograma motor;

	motor.cargar();
	motor.init();
	motor.run();
	motor.apagar();

	return 0;
}
