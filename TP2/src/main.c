/*
 ============================================================================
 Name        : TP2.c
 Author      : Ali Ansidey
 Version     : 2.1.0
 Copyright   : Todos los derechos reservados
 Description : TP2 Laboratorio de Programacion 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "informes.h"
#include "menu.h"
#include "jugador.h"
#include "confederacion.h"
#include "utn.h"

#define SALIR_MENU 5
#define SALIR_MENU_INFORMES 7
#define TAM_LISTADO_JUGADORES 3000 //Dado por el TP
#define TAM_LISTADO_CONFEDERACIONES 6
#define OK 1
#define ERROR -1

int main(void) {
	setbuf(stdout, NULL);
	int opcionMenu, opcionMenu2;
	int flag1 = ERROR;
	int lastId = 1;

	//harcodeo de las confederaciones
	eConfederacion listadoConfederaciones[TAM_LISTADO_CONFEDERACIONES] = {{100,"CONMEBOL","SUDAMERICA",1916},{101,"UEFA","EUROPA",1954},{102,"AFC","ASIA",1954},
	{103,"CAF","AFRICA",1957},{104,"CONCACAF","NORTE Y CENTRO AMERICA",1961},{105,"OFC","OCEANIA",1966}};

	//creo la lista de jugadores e inicializo
	eJugador listadoJugadores[TAM_LISTADO_JUGADORES];
	inicializarArrayJugador(listadoJugadores,TAM_LISTADO_JUGADORES);

	/*harcodeo con la lista pasada por la correccion
	 eJugador jugadoresTest[15]={
	       {1,"Emiliano Martinez","ARQUERO",1,100,100000,4,OK},
	       {2,"Juan Musso","ARQUERO",12,100,80000,2,OK},
	       {3,"Leo Messi","DELANTERO",10,100,80000,4,OK},
	       {4,"Almirez Ali","DELANTERO",9,100,55000,1,OK},
	       {5,"Harry Maguire","DEFENSOR",2,101,70000,4,OK},
	       {6,"Eric Dier","DEFENSOR",3,101,60000,2,OK},
	       {7,"Harry Kane","DELANTERO",10,101,3000,2,OK},
	       {8,"Alfred Gomis","ARQUERO",1,101,9000,1,OK},
	       {9,"Abdelkarim Hassan","MEDIOCAMPISTA",8,101,48000,1,OK},
	       {10,"Guillermo Ochoa","ARQUERO",1,104,90000,4,OK},
	       {11,"Tecatito","DELANTERO",11,104,100000,3,OK},
	       {12,"Luis Romo","MEDIOCAMPISTA",7,104,100000,2,OK},
	       {13,"Bamba Dieng ","DELANTERO",9,103,100000,2,OK},
	       {14,"Demba Seck","DELANTERO",11,103,6000,2,OK},
	       {15,"Tarek Salman","DEFENSOR",6,102,78000,5,OK}
	   };
     */
	eJugador2 listaJugadores2[TAM_LISTADO_JUGADORES];
	mostrarMenuPrincipal();
	utn_getNumero(&opcionMenu,"Ingrese su opcion: \n","Reingrese su opcion\n",1,5,3);
	while(opcionMenu!= SALIR_MENU ){
		switch(opcionMenu){
		case 1:
			flag1 = altaJugador(listadoJugadores,TAM_LISTADO_JUGADORES,listadoConfederaciones,TAM_LISTADO_CONFEDERACIONES,&lastId);//modificar despues
			break;
		case 2:
			if(flag1 != ERROR){
				bajaJugador(listadoJugadores,TAM_LISTADO_JUGADORES,listadoConfederaciones,TAM_LISTADO_CONFEDERACIONES);
			}
			else{
				puts("Tiene que dar de alta a un jugador primero\n");
			}

			break;
		case 3:
			if(flag1 != ERROR){
				modificarJugador(listadoJugadores,TAM_LISTADO_JUGADORES,listadoConfederaciones,TAM_LISTADO_CONFEDERACIONES);
			}
			else{
				puts("Tiene que dar de alta a un jugador primero\n");
			}
			break;
		case 4:
			if(flag1 != ERROR || listaVacia(listadoJugadores,TAM_LISTADO_JUGADORES) >0){
			copiarEstructuraSeteada(listadoJugadores,TAM_LISTADO_JUGADORES,listadoConfederaciones,TAM_LISTADO_CONFEDERACIONES,listaJugadores2);
				mostrarMenuInformes();
				utn_getNumero(&opcionMenu2,"Ingrese su opcion: \n","Reingrese su opcion\n",1,7,3);
				while(opcionMenu2 != SALIR_MENU_INFORMES){
					switch(opcionMenu2){
						case 1:
						listarJugadoresOrdendosAlfabeticamente(listaJugadores2,TAM_LISTADO_JUGADORES,listadoConfederaciones,TAM_LISTADO_CONFEDERACIONES);
						break;
						case 2:
						mostrarConfederacionesYjugadores(listadoJugadores,TAM_LISTADO_JUGADORES,listadoConfederaciones,TAM_LISTADO_CONFEDERACIONES);
						break;
						case 3:
						mostrarTotalYpromedioDeSalarios(listadoJugadores,TAM_LISTADO_JUGADORES);
						break;
						case 4:
						confederacionMayorCantAniosContrato(listadoJugadores,TAM_LISTADO_JUGADORES,listadoConfederaciones,TAM_LISTADO_CONFEDERACIONES);
						break;
						case 5:
						mostrarPorcentajeJugadoresPorConfederacion(listadoJugadores,TAM_LISTADO_JUGADORES,listadoConfederaciones,TAM_LISTADO_CONFEDERACIONES);
						break;
						case 6:
						mostrarRegionConMasJugadores(listadoJugadores,TAM_LISTADO_JUGADORES,listadoConfederaciones,TAM_LISTADO_CONFEDERACIONES);
						break;
						}
						mostrarMenuInformes();
						utn_getNumero(&opcionMenu2,"Ingrese su opcion: \n","Reingrese su opcion\n",1,7,3);
						}
			}
			else{
						puts("Tiene que dar de alta a un jugador primero\n");
					}

			break;
		}
		mostrarMenuPrincipal();
		utn_getNumero(&opcionMenu,"Ingrese su opcion: \n","Reingrese su opcion\n",1,5,3);
	}
	printf("\n Ha salido del sistema \n");
	return EXIT_SUCCESS;
}
