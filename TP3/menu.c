/*
 * menu.c
 *
 *  Created on: 3 nov. 2022
 *      Author: Ali Ansidey
 */


#include "stdio.h"


void mostrarMenuPrincipal(){
	printf("***** MENU PRINCIPAL *****\n");
	printf("---------------------------\n");
	printf("1. Carga de archivo csv\n");
	printf("2. Alta de jugador\n");
	printf("3. Modificacion de jugador\n");
	printf("4. Baja de jugador\n");
	printf("5. Listados\n");
	printf("6. Convocar jugadores\n");
	printf("7. Ordenar y listar\n");
	printf("8. Generar archivo binario\n");
	printf("9. Cargar archivo binario\n");
	printf("10. Guardar archivo csv\n");
	printf("11. SALIR\n");
	printf("---------------------------\n");

}

void mostrarMenuListados(){
	printf("***** Menu Listados *****\n");
	printf("-------------------------\n");
	printf("A. Todos los jugadores\n");
	printf("B. Todas las selecciones\n");
	printf("C. Jugadores convocados\n");
	printf("D. Volver al Menu Principal\n");
	printf("-------------------------\n");

}

void mostrarMenuConvocar(){
	printf("***** Menu Convocar ******\n");
	printf("--------------------------\n");
	printf("A. Convocar jugador\n");
	printf("B. Quitar de la seleccion\n");
	printf("C. Volver al Menu Principal\n");
	printf("--------------------------\n");
}

void mostrarMenuOrdenarYlistar(){
	printf("***** Menu Ordenar y Listar *****\n");
	printf("---------------------------------\n");
	printf("A. Jugadores por nacionalidad\n");
	printf("B. Selecciones por confederacion\n");
	printf("C. Jugadores por edad\n");
	printf("D. Jugadores por nombre\n");
	printf("E. Volver al Menu Principal\n");
	printf("---------------------------------\n");
}

void mostrarMenuModificarJugador(){
	printf("***** Menu Modificar Jugador *****\n");
	printf("---------------------------------\n");
	printf("1. Modificar nombre\n");
	printf("2. Modificar edad\n");
	printf("3. Modificar posicion\n");
	printf("4. Modificar nacionalidad\n");
	printf("5. Volver al Menu Principal\n");
	printf("---------------------------------\n");
}

void mostrarListadoConfederaciones(){
	printf("***** Listado de confederaciones *****\n");
	printf("---------------------------------\n");
	printf("1. AFC\n");
	printf("2. CAF\n");
	printf("3. CONCACAF\n");
	printf("4. CONMEBOL\n");
	printf("5. UEFA\n");
	printf("---------------------------------\n");
}
