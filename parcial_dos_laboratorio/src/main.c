/*
 ============================================================================
 Name        : parcial_dos_laboratorio.c
 Author      : Ali Ansidey
 Version     :
 Copyright   : Todos los derechos reservados
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "linkedList.h"
#include "compra.h"
#include "controlador.h"
#include "utn.h"

#define SALIDA 7

int main(void) {
	setbuf(stdout, NULL);
	LinkedList* listaCompras = ll_newLinkedList();
	LinkedList* listaCompras2 = ll_newLinkedList();
	int option = 0;
	do{
	    	mostrarMenuPrincipal();
	    	utn_getNumero(&option,"Ingrese la opcion deseada: \n","Reingrese la opcion deseada: \n",1,SALIDA,3);
	        switch(option)
	        {
	            case 1:
	            	cotrolador_cargarArchivo("data.csv",listaCompras);
	                break;
	            case 2:
	            	controlador_imprimirLista(listaCompras);
	            	break;
	            case 3:
	            	listaCompras2 = ll_map(listaCompras,controlador_asignarTotal);//corregir esto
	            	controlador_imprimirLista(listaCompras2);
	            	break;
	            case 4:
	            	break;
	            case 5:
	            	break;
	            case 6:
	            	break;
	        }

	}while(option != SALIDA);

	 puts("Ha salido del sistema\n");
	return EXIT_SUCCESS;
}
