/*
 ============================================================================
 Name        : Parcial_Uno_Laboratorio.c
 Author      : Al� Ansidey
 Version     :1.1.1
 Copyright   : Todos los derechos reservados
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "evento.h"
#include "menu.h"
#include "recurso.h"
#include "gestion.h"
#include "cliente.h"

#define TAM_EVENTO 10
#define TAM_RECURSO 10
#define TAM_TIPO_REC 4
#define TAM_CLIENTE 4
#define SALIR_MENU_2 6


int main(void) {
	setbuf(stdout, NULL);
	int IdEvento = 2001;
	int IdRecurso = 1;

	recurso listaRecursos[TAM_RECURSO];
	evento listaEventos[TAM_EVENTO];
	inicializarArrayRecurso(listaRecursos, TAM_RECURSO);
	inicializarArrayEvento(listaEventos,TAM_EVENTO);

	/*
	//harcodeo de datos de recursos y eventos
	recurso listaRecursos[TAM_RECURSO] = {{1,"luces led",15000,1003,1},{2,"sonido",10000,1002,1},{3,"payasos",10000,1002,1},{4,"dj",20000,1004,1},
				{5,"tv plasma",50000,1003,1},{6,"kareoke",9000,1001,1},{7,"consola",8000,1004,1},{8,"microfono",15000,1004,1},{9,"animador",15000,1002,1},
				{10,"humo",7000,1003,1}};

	evento listaEventos[TAM_EVENTO] = {{2001,1,1,10,"lanus",{12,12,2022},1},{2002,2,2,5,"Quilmes",{12,12,2022},1},{2003,3,3,7,"Avellaneda",{10,12,2022},1},
			{2004,4,4,10,"CABA",{10,12,2022},1},{2005,5,1,2,"Wilde",{15,12,2022},1},{2006,6,2,10,"Sarandi",{15,12,2022},1},{2007,1,3,7,"Dock SUD",{15,12,2022},1},
			{2008,2,4,6,"CABA",{12,12,2022},1},{2009,3,1,1,"Avellaneda",{10,12,2022},1},{2010,3,1,5,"CABA",{12,12,2022},1}};
*/

	//harcodeo de datos de tipos de recursos y clientes
	tipo tipoRecursos[TAM_TIPO_REC] ={{1001,"LOCUCION"},{1002,"ANIMACION"},{1003,"ILUMINACION"},{1004,"DJ"}};
	cliente clientes[TAM_CLIENTE] = {{1,"Carlos","Lopez",1123575440},{2,"Karina","Velazquez",1138385015},{3,"Juan","Cabre",1158589966},{4,"Ana","Diaz",1178963621}};

	//despues revisar el flag
	int flag3 = ERROR;
	int flag4,opcion2;
	char opcion ='Z';

	menuPrincipal();
	utn_getNombre(&opcion,2,"Ingrese la opcion deseada:\n","Reingrese la opcion deseada: \n",3);
	strMayuscula(&opcion);
	while(opcion!='I'){
		switch(opcion){
		case 'A':
			flag3=altaRecurso(listaRecursos,TAM_RECURSO,&IdRecurso);
			break;
		case 'B':
			if(flag3 != ERROR){
				modificarRecurso(listaRecursos,TAM_RECURSO,tipoRecursos,TAM_TIPO_REC,&IdRecurso);
			}
			else{
				puts("\n Debe dar de alta a un recurso primero!\n");
			}
			break;
		case 'C':
			if(flag3 != ERROR){
				darDeBajaRecurso(listaRecursos,TAM_RECURSO,tipoRecursos,TAM_TIPO_REC,&IdRecurso);
			}
			else{
				puts("\n Debe dar de alta a un recurso primero!\n");
			}
			break;
		case 'D':
			if(flag3 != ERROR){
				listarRecursos(listaRecursos,TAM_RECURSO,tipoRecursos,TAM_TIPO_REC);
			}
			else{
				puts("\n Debe dar de alta a un recurso primero!\n");
			}
			break;
		case 'E':
			listarTipos(tipoRecursos, TAM_TIPO_REC);
			break;
		case 'F':
			if(flag3 != ERROR){
				//corregir
				flag4= altaEvento(listaEventos,TAM_EVENTO,listaRecursos,TAM_RECURSO,tipoRecursos,TAM_TIPO_REC,clientes,TAM_CLIENTE,&IdEvento);
			}
			else{
				puts("\n Debe dar de alta a un recurso primero!\n");
			}
			break;
		case 'G':
			if(flag4 != ERROR){
				mostrarlistadoEventos(listaEventos,TAM_EVENTO);
			}
			else{
				puts("\n Debe dar de alta a un evento primero!\n");
			}
			break;
		case 'H':
			if(flag3 != ERROR && flag4!= ERROR){
				menuInformes();
				utn_getNumero(&opcion2,"Ingrese su opcion: \n","Reingrese su opcion\n",1,6,3);
				while(opcion2!=SALIR_MENU_2){
					switch(opcion2){
					case 1:
						mostrarRecursoSegunTipo(listaRecursos,TAM_RECURSO, tipoRecursos,TAM_TIPO_REC);
						break;
					case 2:
						mostrarEventoSegunFecha(listaEventos,TAM_EVENTO);
						break;
					case 3:
						 mostrarImporteTotalPorRecurso(listaEventos,TAM_EVENTO,listaRecursos,TAM_RECURSO,tipoRecursos,TAM_TIPO_REC);
						 break;
					case 4:
						mostrarImporteTotalPorTipoyFecha(listaEventos,TAM_EVENTO,listaRecursos,TAM_RECURSO,tipoRecursos,TAM_TIPO_REC);
						break;
					case 5:
						mostrarEventosSegunCliente(listaEventos,TAM_EVENTO,clientes,TAM_CLIENTE);
						break;
					}
					menuInformes();
					utn_getNumero(&opcion2,"Ingrese su opcion: \n","Reingrese su opcion\n",1,6,3);
				}
			}

			break;
		}
		menuPrincipal();
		utn_getNombre(&opcion,2,"Ingrese la opcion deseada:\n","Reingrese la opcion deseada: \n",3);
		strMayuscula(&opcion);
	}
	printf("\n Ha salido del sistema \n");
	return EXIT_SUCCESS;
}
