/*
 * jugador.c
 *
 *  Created on: 22 oct. 2022
 *      Author: Ali Ansidey
 */


#include <stdio.h>
#include <float.h>
#include "utn.h"
#include "confederacion.h"
#include "jugador.h"

#define ERROR -1
#define VACIO 0
#define LLENO 1



int inicializarArrayJugador(eJugador* array, int tamanio){
    int retorno = ERROR;
    int i;
    if(array != NULL && tamanio >0){
        for(i = 0; i < tamanio; i++){
        	(*(array+i)).isEmpty = VACIO;
        }
        retorno = 0;
    }
    return retorno;
}


int findFirstSpaceJugador (eJugador* array, int tamanio){
	int index = ERROR;
	int i;
	for(i = 0; i < tamanio; i++){
		if((*(array+i)).isEmpty == VACIO){
			index = i;
			break;
		}
	}
return index;
}



int buscarJugadorPorId(eJugador* array, int tamanio, int id){
	int retorno = ERROR;
	int i;
	if(array != NULL && tamanio >0 && id >0){
		for(i = 0; i<tamanio; i++){
			if((*(array+i)).id == id && (*(array+i)).isEmpty == LLENO ){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int buscarJugadorPorId2(eJugador2* array, int tamanio, int id){
	int retorno = ERROR;
	int i;
	if(array != NULL && tamanio >0 && id >0){
		for(i = 0; i<tamanio; i++){
			if((*(array+i)).id == id && (*(array+i)).isEmpty == LLENO ){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int altaJugador(eJugador* array, int tamanio,eConfederacion* arrayConf,int tamanioConf, int* lastId){
	int retorno = ERROR;
	int id = *lastId;
	char nombre[50];
	char posicion[50];
	int numeroCamiseta;
	int idConfederacion;
	float salario;
	int aniosContrato;
	int indice;
	int flag1, flag2, flag3, flag4,flag5,flag6;

	if(array != NULL && tamanio >0){
		indice = findFirstSpaceJugador(array,tamanio);
		flag1 = utn_getCadena(nombre,50,"Ingrese el nombre del jugador: \n","Reingrese el nombre: \n",3);
		flag2 = utn_getNombre(posicion,50,"Ingrese la posicion del jugador [delantero/mediocampista/defensor/arquero]:\n","Reingrese la posicion [delantero/mediocampista/defensor/arquero]: \n",3);
		while((stricmp(posicion,"delantero") != 0) && (stricmp(posicion,"mediocampista") != 0) && (stricmp(posicion,"defensor") != 0) && (stricmp(posicion,"arquero") != 0)){
			flag2 = utn_getNombre(posicion,50,"Ingrese la posicion del jugador [delantero/centro/defensor/arquero]:\n","Reingrese la posicion [delantero/centro/defensor/arquero]: \n",3);
		}
		flag3 = utn_getNumero(&numeroCamiseta,"Ingrese el numero de camiseta [1 al 99]:]\n","Reingrese el numero de camiseta [1 al 99]:\n",1,99,3);
		flag4 = utn_getNumeroFlotante(&salario,"Ingrese el salario del jugador ($):\n","Reingrese el salario ($): \n",1,FLT_MAX,3);
		flag5 = utn_getNumero(&aniosContrato,"Ingrese los anios de contrato:\n","Reingrese anios del contrato:\n",1,99,3);
		listarConfederaciones(arrayConf,tamanioConf);
		flag6 = utn_getNumero(&idConfederacion,"Ingrese el id de la confederacion:\n",
				"Reingrese el id de la confederacion:\n",100,105,3);

		if(indice != ERROR && flag1 !=ERROR && flag2 !=ERROR && flag3 !=ERROR && flag4 !=ERROR && flag5 !=ERROR && flag6 !=ERROR){
			eJugador jugadorNuevo;
			jugadorNuevo.id = id;
			strcpy(jugadorNuevo.nombre,nombre);
			strcpy(jugadorNuevo.posicion,posicion);
			jugadorNuevo.numeroCamiseta = numeroCamiseta;
			jugadorNuevo.salario = salario;
			jugadorNuevo.aniosContrato = aniosContrato;
			jugadorNuevo.idConfederacion = idConfederacion;
			jugadorNuevo.isEmpty = LLENO;
			*(array+indice) = jugadorNuevo;
			retorno = 0;
			printf("Se ha dado de alta al jugador %s con el id: %d\n",jugadorNuevo.nombre,jugadorNuevo.id);
			(*lastId)++;
		}
	}
	return retorno;
}


void mostrarJugador(eJugador jugador, eConfederacion* arrayConf, int tamanio){
	int i;
	if(arrayConf != NULL && tamanio >0 ){
		for(i = 0; i < tamanio; i++){
			if(jugador.idConfederacion == (*(arrayConf+i)).id){
				printf("|%*d|%*s|%*s|%*d|$%*.2f |%*s|%*d|\n",10,jugador.id,20,jugador.nombre,20,jugador.posicion,
						20,jugador.numeroCamiseta,20,jugador.salario,20,(*(arrayConf+i)).nombre,10,jugador.aniosContrato);
				break;
			}
		}
	}
}

void mostrarJugador2(eJugador2 jugador){
	int id;
	char nombre[20];
	char posicion[20];
	int nroCamiseta;
	float salario;
	char nombreConf[20];
	int aniosContrato;
	int isEmpty;

	id = jugador.id;
	strcpy(nombre,jugador.nombre);
	strcpy(posicion,jugador.posicion);
	nroCamiseta = jugador.numeroCamiseta;
	salario = jugador.salario;
	strcpy(nombreConf,jugador.nombreConf);
	aniosContrato = jugador.aniosContrato;
	isEmpty = jugador.isEmpty;

	if( id >0 && (nroCamiseta >= 1 || nroCamiseta <100) && salario >0 && aniosContrato >0 && isEmpty == LLENO)
	{
		printf("|%*d|%*s|%*s|%*d|$%*.2f |%*s|%*d|\n",10,jugador.id,20,jugador.nombre,20,jugador.posicion,
		20,jugador.numeroCamiseta,20,jugador.salario,20,jugador.nombreConf,10,jugador.aniosContrato);
	}
}

void mostrarJugadores(eJugador* arrayjugadores,int tamanioArray, eConfederacion* arrayConf, int tamanio){
	int i;
	char id[5] = "ID";
	char nombre[10] = "NOMBRE";
	char posicion[10] = "POSICION";
	char nroCamiseta[13]= "No. CAMISETA";
	char sueldo[10] = "SUELDO";
	char confederacion[13] = "CONFEDERACION";
	char aniosContrato[20]= "ANIOS DE CONTRATO";

	if(arrayjugadores != NULL && arrayConf != NULL && tamanioArray >0 && tamanio >0){
		printf("--------------------------------------------------------------------------------------------------------------------------------\n");
		printf("--------------------------------------------------------------------------------------------------------------------------------\n");
		printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",10,id,20,nombre,20,posicion,20,nroCamiseta,20,sueldo,20,confederacion,20,aniosContrato);
		printf("--------------------------------------------------------------------------------------------------------------------------------\n");
		for(i = 0; i < tamanioArray; i++){
			if((*(arrayjugadores+i)).isEmpty != VACIO){
				mostrarJugador((*(arrayjugadores+i)), arrayConf,tamanio);
			}
		}
		printf("---------------------------------------------------------------------------------------------------------------------------------\n");
		printf("---------------------------------------------------------------------------------------------------------------------------------\n");
	}
}


void mostrarJugadores2(eJugador2* arrayjugadores,int tamanioArray){
	int i;
	char id[5] = "ID";
	char nombre[10] = "NOMBRE";
	char posicion[10] = "POSICION";
	char nroCamiseta[13]= "No. CAMISETA";
	char sueldo[10] = "SUELDO";
	char confederacion[13] ="CONFEDERACION";
	char aniosContrato[20]="ANIOS DE CONTRATO";

	if(arrayjugadores != NULL && tamanioArray >0){
		printf("--------------------------------------------------------------------------------------------------------------------------------\n");
		printf("--------------------------------------------------------------------------------------------------------------------------------\n");
		printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",10,id,20,nombre,20,posicion,20,nroCamiseta,20,sueldo,20,confederacion,20,aniosContrato);
		printf("--------------------------------------------------------------------------------------------------------------------------------\n");
		for(i = 0; i < tamanioArray; i++){
			if((*(arrayjugadores+i)).isEmpty != VACIO){
				mostrarJugador2(*(arrayjugadores+i));
			}
		}
		printf("---------------------------------------------------------------------------------------------------------------------------------\n");
		printf("---------------------------------------------------------------------------------------------------------------------------------\n");
	}
}

int bajaJugador(eJugador* arrayjugadores, int tamanioArray, eConfederacion* arrayConf, int tamanio){
	int retorno = ERROR;
	int id, indice;
	char opcion;
	if(arrayjugadores != NULL && arrayConf != NULL && tamanioArray >0 && tamanio >0){
		mostrarJugadores(arrayjugadores,tamanioArray,arrayConf,tamanio);
		utn_getNumero(&id,"Ingrese el id del jugador a eliminar:\n","Reingrese el id del jugador a eliminar:\n",1,10000,3);
		indice = buscarJugadorPorId(arrayjugadores,tamanioArray,id);
		if(indice != ERROR){
			utn_getNombre(&opcion,2,"Desea dar de baja al recurso [S/N]\n","Desea dar de baja al recurso [S/N]\n",3);
			strMayuscula(&opcion);
			while(opcion!= 'S' && opcion != 'N'){
				utn_getNombre(&opcion,2,"Desea dar de baja al recurso [S/N]\n","Desea dar de baja al recurso [S/N]\n",3);
				strMayuscula(&opcion);
			}
			if(opcion =='S'){
				(*(arrayjugadores+indice)).isEmpty = VACIO;
				printf("Se dio de baja al jugador con id %d",(*(arrayjugadores+indice)).id);
				retorno =0;
			}
		}
	}
	return retorno;
}


int modificarJugador(eJugador* arrayjugadores, int tamanioArray, eConfederacion* arrayConf, int tamanio){
	int retorno = ERROR;
	int id, indice, opcion, aniosC, nroCamiseta, idConfederacion;
	float salario;
	if(arrayjugadores != NULL && arrayConf != NULL && tamanioArray >0 && tamanio >0){
		mostrarJugadores(arrayjugadores,tamanioArray,arrayConf,tamanio);
		utn_getNumero(&id,"Ingrese el id del jugador a modificar:\n","Reingrese el id del jugador a modificar:\n",1,10000,3);
		indice = buscarJugadorPorId(arrayjugadores,tamanioArray,id);
		if(indice != ERROR){
			utn_getNumero(&opcion,"Ingrese la opcion a modificar: [1 - nombre/2 - posicion/3- nro camiseta/4 - confederacion/5 - salario/6 - anios contrato]\n",
					"Reingrese la opcion a modificar:[1 - nombre/2 - posicion/3- nro camiseta/4 - confederacion/5 - salario/6 - anios contrato]\n",1,6,3);
			switch(opcion){
			case 1:
				utn_getCadena((*(arrayjugadores+indice)).nombre,50,"Ingrese el nombre del jugador: \n","Reingrese el nombre: \n",3);
				break;
			case 2:
				utn_getNombre((*(arrayjugadores+indice)).posicion,50,"Ingrese la posicion del jugador [delantero/centro/defensor/arquero]:\n","Reingrese la posicion del jugador [delantero/centro/defensor/arquero]:\n",3);
				while((stricmp((*(arrayjugadores+indice)).posicion,"delantero") != 0) && (stricmp((*(arrayjugadores+indice)).posicion,"mediocampista") != 0) && (stricmp((*(arrayjugadores+indice)).posicion,"defensor") != 0) && (stricmp((*(arrayjugadores+indice)).posicion,"arquero") != 0)){
				utn_getNombre((*(arrayjugadores+indice)).posicion,50,"Ingrese la posicion del jugador [delantero/mediocampista/defensor/arquero]:\n","Reingrese la posicion [delantero/mediocampista/defensor/arquero]: \n",3);
						}
				break;
			case 3:
				utn_getNumero(&nroCamiseta,"Ingrese el numero de camiseta [1 al 99]:]\n","Reingrese el numero de camiseta [1 al 99]:\n",1,99,3);
				(*(arrayjugadores+indice)).numeroCamiseta = nroCamiseta;
				break;
			case 4:
				listarConfederaciones(arrayConf,tamanio);
				utn_getNumero(&idConfederacion,"Ingrese el id de la confederacion:\n",
						"Reingrese el id confederacion:\n",100,105,3);
				(*(arrayjugadores+indice)).idConfederacion = idConfederacion;
				break;
			case 5:
				utn_getNumeroFlotante(&salario,"Ingrese el salario del jugador ($):\n","Reingrese el salario ($): \n",1,FLT_MAX,3);
				(*(arrayjugadores+indice)).salario = salario;

				break;
			case 6:
				utn_getNumero(&aniosC,"Ingrese los anios de contrato:\n","Reingrese anios del contrato:\n",1,99,3);
				(*(arrayjugadores+indice)).aniosContrato = aniosC;
				break;
			}
			retorno = 0;
		}
	}

	return retorno;
}



void mostrarJugadoresPorConfederacion(eJugador* arrayjugadores,int tamanioArray, eConfederacion* arrayConf, int tamanio, int idConf){
	int i;
	char id[5] = "ID";
	char nombre[10] = "NOMBRE";
	char posicion[10] = "POSICION";
	char nroCamiseta[13]= "NRO CAMISETA";
	char sueldo[10] = "SUELDO";
	char confederacion[13] = "CONFEDERACION";
	char aniosContrato[20]= "ANIOS DE CONTRATO";

	if(arrayjugadores != NULL && arrayConf != NULL && tamanioArray >0 && tamanio >0){
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		printf("|%*s|%*s|%*s|%*s|%*s|%*s|%*s|\n",10,id,20,nombre,20,posicion,20,nroCamiseta,20,sueldo,20,confederacion,20,aniosContrato);
		printf("----------------------------------------------------------------------------------------------------------------------\n");
		for(i = 0; i < tamanioArray; i++){
			if((*(arrayjugadores+i)).isEmpty != VACIO && (*(arrayjugadores+i)).idConfederacion == idConf ){
				mostrarJugador((*(arrayjugadores+i)), arrayConf,tamanio);
			}
		}
		printf("-----------------------------------------------------------------------------------------------------------------------\n");
	}
}



int ordenarPornombreJuga(eJugador* arrayJug, int tamanio){
	int retorno = ERROR;
	int i, j;
	if(arrayJug != NULL && tamanio){
		eJugador auxJug;
	  for (i = 0; i < tamanio - 1; i++)
	    {
	      for (j = i + 1; j < tamanio; j++)
		{
	    	  if(compararPorNombre((*(arrayJug+i)).nombre, (*(arrayJug+j)).nombre) == 1){
	    		  auxJug = *(arrayJug+i);
	    		  *(arrayJug+i) =  *(arrayJug+j);
	    		  *(arrayJug+j) = auxJug;
	    	  }
		}
	    }
	  retorno =0;
	}
	return retorno;

}

int listaVacia(eJugador* arrayJug, int tamanio){
	int contadorJugadores= VACIO;
	int i;
	if(arrayJug != NULL && tamanio){
		for(i = 0;i < tamanio; i++){
			if((*(arrayJug+i)).isEmpty == LLENO){
				contadorJugadores++;
			}
		}
	}
	return contadorJugadores;
}
