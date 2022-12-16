#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

#define ERROR -1


int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = ERROR;
	Jugador* pJugador;
	char id[50];
	char nombreCompleto[50];
	char edad[50];
	char posicion[50];
	char nacionalidad[50];
	char idSeleccion[50];
	int esHeader = 1;

	if(pFile != NULL){
		if(esHeader == 1){
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
		esHeader = 0;
		}

		while(!feof(pFile)){
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
			pJugador = jug_newParametros(id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
			if(pJugador != NULL){
				ll_add(pArrayListJugador,pJugador);
				retorno = 0;
			}
		}
	}
    return retorno;
}


int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = ERROR;
	if(pFile != NULL){
		Jugador* pJugador;
		while(!feof(pFile)){
			pJugador = jug_new();
			if(fread(pJugador,sizeof(Jugador),1,pFile)==1){
				ll_add(pArrayListJugador,pJugador);
			}
		}
	}
	return retorno;
}


int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno = ERROR;
	Seleccion* pSeleccion;
	char id[50];
	char pais[50];
	char confederacion[50];
	char convocados[50];
	int esHeader = 1;

		if(pFile != NULL){
			if(esHeader == 1){
				fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,pais,confederacion,convocados);
			esHeader = 0;
			}

		while(!feof(pFile)){
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,pais,confederacion,convocados);
		pSeleccion = selec_newParametros(id,pais,confederacion,convocados);
		if(pSeleccion != NULL){
			ll_add(pArrayListSeleccion,pSeleccion);
			retorno = 0;
		}
		}
	}
    return retorno;
}


int parser_IdFromBinary(FILE* pFile, int* lastId)
{
	int retorno = ERROR;
	if(pFile != NULL){
		while(!feof(pFile)){
			if(fread(lastId,sizeof(int),1,pFile)==1){
				retorno =0;
			}
		}
	}
	return retorno;
}
