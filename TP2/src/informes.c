/*
 * informes.c
 *
 *  Created on: 26 oct. 2022
 *      Author: Ali Ansidey
 */


#include <stdio.h>
#include <float.h>
#include "jugador.h"
#include "calculos.h"
#include "informes.h"
#include "utn.h"
#define ERROR -1
#define VACIO 0
#define LLENO 1

int ordenarJugadorPorConfYnombre (eJugador2* arrayjugadores,int tamanioArray, eConfederacion* arrayConf, int tamanio)
{
	int retorno = ERROR;
	eJugador2 auxJugador;
	int i, j;
  for (i = 0; i < tamanioArray - 1; i++)
    {
      for (j = i + 1; j < tamanioArray; j++)
	{
    	  //ordeno primero por el nombre de la confederacion
    	  if(strcmp((*(arrayjugadores+i)).nombreConf, (*(arrayjugadores+j)).nombreConf) == 1){
    	    	auxJugador = *(arrayjugadores+i);
    	    	*(arrayjugadores+i)= *(arrayjugadores+j);
    	    	*(arrayjugadores+j) = auxJugador;
    	    }

    	  //Si son iguales los nombres de las confederaciones, ordeno por nombre del jugador
        	if(strcmp((*(arrayjugadores+i)).nombreConf, (*(arrayjugadores+j)).nombreConf) == 0){
            	  if (strcmp((*((arrayjugadores+i))).nombre, (*((arrayjugadores+j))).nombre) > 0)
        	    {
            	  auxJugador = *(arrayjugadores+i);
            	  *(arrayjugadores+i)= *(arrayjugadores+j);
            	  *(arrayjugadores+j) = auxJugador;
        	    }
        	  }
    }
      retorno = 0;
    }
 return retorno;
 }


eJugador2 copiarJugador(eJugador jugadorOriginal, eConfederacion* arrayConf, int tamanio){
	int indice;
	eJugador2 jugadorAux;
	if(arrayConf != NULL && tamanio >0){
		jugadorAux.id = jugadorOriginal.id;
		strcpy(jugadorAux.nombre,jugadorOriginal.nombre);
		strcpy(jugadorAux.posicion,jugadorOriginal.posicion);
		jugadorAux.numeroCamiseta = jugadorOriginal.numeroCamiseta;
		indice = buscarConfPorId(arrayConf,tamanio, jugadorOriginal.idConfederacion);
		if(indice != ERROR){
		strcpy(jugadorAux.nombreConf,(*(arrayConf+indice)).nombre);
		}
		jugadorAux.salario = jugadorOriginal.salario;
		jugadorAux.aniosContrato = jugadorOriginal.aniosContrato;
		jugadorAux.isEmpty = jugadorOriginal.isEmpty;
	}
	return jugadorAux;
}

int copiarEstructuraSeteada(eJugador* arrayjugadores,int tamanioArray, eConfederacion* arrayConf, int tamanio, eJugador2* pArray){
	int retorno = ERROR;
	eJugador auxJugador;
	if(arrayjugadores !=NULL && arrayConf && pArray != NULL && tamanioArray >0 && tamanio >0){
		int i,index;
		for(i =0; i< tamanioArray; i++){
				auxJugador = *(arrayjugadores+i);
				index = buscarJugadorPorId2(pArray,tamanioArray,auxJugador.id);
				printf("\n index en copiar estructura %d\n",index);
				if(auxJugador.isEmpty == LLENO && index == ERROR){

				*(pArray+i) = copiarJugador(auxJugador,arrayConf,tamanio);
					printf("\n primer if \n");
				}
				if(auxJugador.isEmpty == LLENO  && index > ERROR){
					*(pArray+index) = copiarJugador(auxJugador,arrayConf,tamanio);
					printf("\n segundo if \n");
				}
			}


		retorno = 0;
	}
	return retorno;
}


int listarJugadoresOrdendosAlfabeticamente (eJugador2* arrayjugadores,int tamanioArray, eConfederacion* arrayConf, int tamanio){
	int retorno = ERROR;
	if(arrayjugadores != NULL && arrayConf != NULL && tamanioArray >0 && tamanio>0){
		ordenarJugadorPorConfYnombre(arrayjugadores,tamanioArray,arrayConf,tamanio);
		mostrarJugadores2(arrayjugadores,tamanioArray);
		retorno = 0;
	}
	return retorno;
}


int mostrarConfederacionesYjugadores(eJugador* arrayjugadores,int tamanioArray, eConfederacion* arrayConf, int tamanio){
	int retorno = ERROR;
	int i;
	char id[5] = "ID";
	char nombre[20] ="NOMBRE";
	char region[20] = "REGION";
	char anioCreacion[14] = "ANIO CREACION";
	if(arrayjugadores != NULL && arrayConf != NULL && tamanioArray >0 && tamanio>0){
		printf("|%*s|%*s|%*s|%*s|\n",10,id,20,nombre,30,region,14,anioCreacion);
		for(i=0; i < tamanio; i++){
			printf("|%*d|%*s|%*s|%*d|\n",10,(*(arrayConf+i)).id,20,(*(arrayConf+i)).nombre,30,(*(arrayConf+i)).region,14,(*(arrayConf+i)).anioCreacion);
				mostrarJugadoresPorConfederacion(arrayjugadores,tamanioArray,arrayConf,tamanio,(*(arrayConf+i)).id);

		retorno =0;
		}
	}

	return retorno;
}


int mostrarTotalYpromedioDeSalarios(eJugador* arrayjugadores,int tamanioArray){
	int retorno = ERROR;
	float sumaSalarios = 0;
	float promedio = 0;
	int cantidadJugadores = 0;
	int cantJugArribaPromedio = 0;
	if(arrayjugadores != NULL && tamanioArray>0){
		for(int i =0; i < tamanioArray; i++){
			if((*(arrayjugadores+i)).isEmpty == LLENO){
				sumaSalarios += (*(arrayjugadores+i)).salario;
				cantidadJugadores++;
			}
			}
		}
	calcularPromedio(sumaSalarios,cantidadJugadores,&promedio);
		for(int j =0; j < tamanioArray; j++){
			if((*(arrayjugadores+j)).isEmpty == LLENO && (*(arrayjugadores+j)).salario > promedio){
				cantJugArribaPromedio++;
		}
		}

		if(sumaSalarios >0 && promedio >0){
			printf("----------------------------------------------------------------------------------------------------------------------\n");
			printf("El total de los salarios de los jugadores es: $%.2f\n",sumaSalarios);
			printf("El sueldo promedio de los salarios de los jugadores es: $%.2f\n",promedio);
			printf("La cantidad de jugadores que superan el sueldo promedio es: %d\n",cantJugArribaPromedio);
			printf("----------------------------------------------------------------------------------------------------------------------\n");
			retorno =0;
		}
	return retorno;
}


int confederacionMayorCantAniosContrato(eJugador* arrayjugadores,int tamanioArray, eConfederacion* arrayConf, int tamanio){
	int retorno = ERROR;
	int contadorAniosContrato =0;
	int maxCantAniosContrato =0;
	char nombreConf[50];
	int i =0;
	int j,idConfederacion;
	if(arrayjugadores != NULL && arrayConf != NULL && tamanioArray >0 && tamanio>0){
		while(i < tamanio){
			idConfederacion = (*(arrayConf+i)).id;
			for(j = 0; j < tamanioArray; j++){
					if(idConfederacion == (*(arrayjugadores+j)).idConfederacion && (*(arrayjugadores+j)).isEmpty == LLENO){
						contadorAniosContrato += (*(arrayjugadores+j)).aniosContrato;
						if(contadorAniosContrato > maxCantAniosContrato){
							maxCantAniosContrato = contadorAniosContrato;
							strcpy(nombreConf,(*(arrayConf+i)).nombre);
						}
					}
				}
			contadorAniosContrato = 0;
			i++;
		}

		if(maxCantAniosContrato >0){
			printf("----------------------------------------------------------------------------------------------------------------------\n");
			printf("La confederacion con mayor cantidad de anios de contrato es: %s, con: %d anios\n",nombreConf,maxCantAniosContrato );
			printf("----------------------------------------------------------------------------------------------------------------------\n");
			retorno =0;
		}
	}
	return retorno;
}


int mostrarPorcentajeJugadoresPorConfederacion(eJugador* arrayjugadores,int tamanioArray, eConfederacion* arrayConf, int tamanio){
	int retorno = ERROR;
	int i =0;
	int j,idConfederacion;
	int cantidadJugadoresTotales = 0;
	int cantJugadoresConf =0;
	float porcentaje =0;
	char id[5] ="ID";
	char nombre[20] = "NOMBRE";
	char region[20]= "REGION";
	char porcJugadores[25] ="PORCENTAJE DE JUGADORES";

	if(arrayjugadores != NULL && arrayConf != NULL && tamanioArray >0 && tamanio>0){
		while(i < tamanio){
			idConfederacion = (*(arrayConf+i)).id;
			for(j = 0; j < tamanioArray; j++){
					if((*(arrayjugadores+j)).isEmpty == LLENO){
						cantidadJugadoresTotales++;
						if(idConfederacion == (*(arrayjugadores+j)).idConfederacion){
							cantJugadoresConf++;
						}
					}
				}
			porcentajePorTipo(cantJugadoresConf,cantidadJugadoresTotales,&porcentaje);
			printf("----------------------------------------------------------------------------------------------------------------------\n");
			printf("|%*s|%*s|%*s|%*s|\n",10,id,20,nombre,30,region,25,porcJugadores);
			printf("|%*d|%*s|%*s|%*.2f|\n",10,(*(arrayConf+i)).id,20,(*(arrayConf+i)).nombre,30,(*(arrayConf+i)).region,25,porcentaje);
			printf("----------------------------------------------------------------------------------------------------------------------\n");
			cantJugadoresConf =0;
			cantidadJugadoresTotales =0;
			i++;
			retorno = 0;
				}
		}
	return retorno;
}

int mostrarRegionConMasJugadores(eJugador* arrayjugadores,int tamanioArray, eConfederacion* arrayConf, int tamanio){
	int retorno = ERROR;
	int j,idConfederacion, idConfMax;
	int i =0;
	int contadorJugadores =0;
	int maxCantiJugadores =0;
	char region[20];
	if(arrayjugadores != NULL && arrayConf != NULL && tamanioArray >0 && tamanio>0){
		while (i < tamanio){
			idConfederacion = (*(arrayConf+i)).id;
			for(j =0; j <tamanioArray; j++){
				if((*(arrayjugadores+j)).isEmpty == LLENO){
					if(idConfederacion == (*(arrayjugadores+j)).idConfederacion){
						contadorJugadores++;
					}
				}
			}
			if(contadorJugadores > maxCantiJugadores){
				maxCantiJugadores = contadorJugadores;
				idConfMax = idConfederacion;
				strcpy(region,(*(arrayConf+i)).region);
			}
			contadorJugadores =0;
			i++;
		}
		if(maxCantiJugadores >0){
			printf("----------------------------------------------------------------------------------------------------------------------\n");
			printf("La region con mayor cantidad de jugadores es: %s, con: %d jugadores\n",region,maxCantiJugadores);
			mostrarJugadoresPorConfederacion(arrayjugadores,tamanioArray,arrayConf,tamanio,idConfMax);
			retorno = 0;
		}
	}
	return retorno;
}
