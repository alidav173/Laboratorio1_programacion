/*
 * menu.c
 *
 *  Created on: 22 oct. 2022
 *      Author: Ali Ansidey
 *
 */

#include <stdio.h>

void mostrarMenuPrincipal(){
	printf("\n Menu Principal: \n");
	printf("1. Alta de jugador.\n");
	printf("2. Baja de jugador.\n");
	printf("3. Modificacion de jugador.\n");
	printf("4. Informes.\n");
	printf("5. Salir.\n");

}

void mostrarMenuInformes(){
	printf("\n Menu Informes: \n");
	printf("1. Listado de los jugadores ordenados alfabeticamente por nombre de confederacion y jugador.\n");
	printf("2. Listado de confederaciones con sus jugadores.\n");
	printf("3. Total y promedio de todos los salarios y cuantos jugadores cobran mas del salario promedio.\n");
	printf("4. Confederacion con mayor cantidad de años de contratos total.\n");
	printf("5. Porcentaje de jugadores por cada confederacion.\n");
	printf("6. Region con mas jugadores y listado de los mismos.\n");
	printf("7. Salir menu informes.\n");

}
