#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "utn.h"
#include "menu.h"
#define SALIR_MENU 11
#define ERROR -1
int main()
{
	setbuf(stdout,NULL);
    int option = SALIR_MENU;
    int flag = ERROR;
    int entrarOpcion1 = 1;
    char opcionMenu ='z';
    char opcionMenu2 ='z';

    LinkedList* listaJugadores = ll_newLinkedList();
    LinkedList* listaSelecciones = ll_newLinkedList();
    LinkedList* listaJugadoresConfederacion = ll_newLinkedList();

	mostrarMenuPrincipal();
	utn_getNumero(&option,"Ingrese la opcion deseada: \n","Reingrese la opcion deseada: \n",1,SALIR_MENU,3);
    do{
        switch(option)
        {
            case 1:
            	if(entrarOpcion1 == 1){
                	if(controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores) == 0 &&
                	controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSelecciones) ==0){
                	entrarOpcion1--;
                	}
            	}
               	else{
                	  puts("\nYa se cargaron los archivos de jugadores y selecciones\n");
                	 }
                break;
            case 2:
            	if(ll_isEmpty(listaJugadores) == 0){
            		controller_agregarJugador(listaJugadores);
            	}
            	else{
            		puts("\nPor favor cargue el archivo de los jugadores primero\n");
            	}
            	break;
            case 3:
            	if(ll_isEmpty(listaJugadores) == 0){
            		controller_editarJugador(listaJugadores);
            	}
            	else{
            		puts("\nPor favor cargue el archivo de los jugadores primero\n");
            	}
            	break;
            case 4:
            	if(ll_isEmpty(listaJugadores) == 0){
            		controller_removerJugador(listaJugadores);
            	}
            	else{
            		puts("\nPor favor cargue el archivo de los jugadores primero\n");
            	}
            	break;
            case 5:
            	mostrarMenuListados();
            	utn_getNombre(&opcionMenu,2,"Ingrese la opcion deseada:\n","Reingrese la opcion deseada: \n",3);
            	strMayuscula(&opcionMenu);
            	while(opcionMenu != 'D'){
            		switch(opcionMenu){
            		case 'A':
            			if(ll_isEmpty(listaJugadores) == 0){
            				 controller_listarJugadores2(listaJugadores,listaSelecciones);
            				//controller_listarJugadores(listaJugadores);
            			}
            			else{
            				puts("\nPor favor cargue el archivo de los jugadores primero\n");
            			}
            			break;
            		case 'B':
            			if(ll_isEmpty(listaSelecciones) == 0){
            				controller_listarSelecciones(listaSelecciones);
            			}
            			else{
            				puts("\nPor favor cargue el archivo de las selecciones primero\n");
            			}
            			break;
            		case 'C':
            			if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0){
            				controller_listarConvocados(listaJugadores,listaSelecciones);
            			}
            			else{
            				puts("\nConvoque a un jugador primero\n");
            			}
            			break;
            		}
            		mostrarMenuListados();
            		utn_getNombre(&opcionMenu,2,"Ingrese la opcion deseada:\n","Reingrese la opcion deseada: \n",3);
            	    strMayuscula(&opcionMenu);
            	}
            	break;
            case 6:
            	mostrarMenuConvocar();
            	utn_getNombre(&opcionMenu2,2,"Ingrese la opcion deseada:\n","Reingrese la opcion deseada: \n",3);
            	strMayuscula(&opcionMenu2);
           	    while(opcionMenu2 != 'C'){
           	    	switch(opcionMenu2){
           	    	 case 'A':
           	    		if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0){
           	    			controller_convocarJugador(listaJugadores,listaSelecciones);
           	    		}
           	    		else{
           	    			puts("\n Antes de convocar, por favor cargue el archivo de los jugadores y selecciones primero\n");
           	    		}
           	    	 break;
           	    	 case 'B':
           	    		if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0){
           	    			controller_quitarDeLaSeleccion(listaJugadores,listaSelecciones);
           	    		}
           	    		else{
           	    			puts("\nAntes de quitar a un jugador, cargue el archivo de los jugadores y selecciones primero\n");
           	    		}
           	    	  break;
           	    	    }
                	mostrarMenuConvocar();
                	utn_getNombre(&opcionMenu2,2,"Ingrese la opcion deseada:\n","Reingrese la opcion deseada: \n",3);
                	strMayuscula(&opcionMenu2);
            	    }
            	break;
            case 7:
            	if(ll_isEmpty(listaJugadores) == 0 ){
                	controller_ordenarJugadores(listaJugadores);
                	//controller_ordenarSelecciones(listaSelecciones);
            	}
            	else{
            		puts("\nAntes de ordenar a los jugadores, cargue el archivo de los jugadores y selecciones primero\n");
            	}
            	break;
            case 8:
            	if(ll_isEmpty(listaSelecciones) == 0 && ll_isEmpty(listaJugadores) == 0 ){
            		controller_guardarJugadoresConvocadosPorConfederacion("listadoJugadoresCon.bin",listaJugadores,listaSelecciones,listaJugadoresConfederacion);
            	}
            	else{
            		puts("\nAntes de guardar el archivo de los jugadores convocados por Confederacion, cargue el archivo de los jugadores y selecciones primero\n");
            	}
            	break;
            case 9:
                	controller_cargarJugadoresDesdeBinario("listadoJugadoresCon.bin",listaJugadoresConfederacion);
                	if(ll_isEmpty(listaJugadoresConfederacion) == 0){
                		controller_listarJugadores2(listaJugadoresConfederacion,listaSelecciones);
                	}
                	else{
                		puts("\nAntes de abrir el archivo de los jugadores en binario, guarde los jugadores convocados por confederacion\n");
                	}
            	break;
            case 10:
            	if(ll_isEmpty(listaJugadores) == 0 && ll_isEmpty(listaSelecciones) == 0){
    				controller_guardarJugadoresModoTexto("jugadores.csv",listaJugadores);
                	controller_guardarSeleccionesModoTexto("selecciones.csv",listaSelecciones);
                	flag++;
            	}
            	else{
            		puts("\nLa lista de jugadores y selecciones se encuentra vacia\n");
            	}
            	break;
        }
        if(flag == ERROR){
        	 puts("Recuerde guardar los datos de los jugadores y selecciones antes de salir\n");
        	 option = ERROR;
        }
        mostrarMenuPrincipal();
        utn_getNumero(&option,"Ingrese la opcion deseada: \n","Reingrese la opcion deseada: \n",1,SALIR_MENU,3);

    }while(option != SALIR_MENU);
    puts("Ha salido del sistema\n");

    return 0;
}

