/*
 * menu.c
 *
 *  Created on: 7 oct. 2022
 *      Author: Ali Ansidey
 */

#include <stdio.h>

void menuPrincipal(){
	printf("\n Menu Principal\n");
	printf("A. Alta recurso\n");
	printf("B. Modificar recurso\n");
	printf("C. Baja Recurso\n");
	printf("D. Listar Recurso\n");
	printf("E. Listar tipos\n");
	printf("F. Alta Evento\n");
	printf("G. Listar Eventos\n");
	printf("H. Informes\n");
	printf("I. Salir\n");
	printf("\n");
}

void menuInformes(){
	printf("\n Menu Informes\n");
	printf("1. Mostrar recursos de un tipo seleccionado\n");
	printf("2. Mostrar todos los eventos efectuados en una fecha seleccionada\n");
	printf("3. Informar importe total de los eventos realizados para un recurso seleccionado\n");
	printf("4. Informar importe total de todos los eventos de un tipo en una fecha seleccionada\n");
	printf("5. Mostrar eventos de un cliente seleccionado\n");
	printf("6. Salir Menu Informes\n");
	printf("\n");
}
