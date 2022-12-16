/*
 * tipo.c
 *
 *  Created on: 7 oct. 2022
 *      Author: Ali Ansidey
 */

#include "tipo.h"

int listarTipos(tipo* array, int tamanio){
	int retorno = ERROR;
	int i;
	if(array!= NULL && tamanio >0){
		for(i=0; i<tamanio;i++){
			printf("ID tipo: %d\t Descripcion: %s\n",(*(array+i)).idTipo, (*(array+i)).descripcion);
		}
		retorno = 0;
	}
	return retorno;
}


int buscarTipoPorId(tipo* array, int tamanio,int id){
	int retorno = ERROR;
	int i;
	if(array != NULL && tamanio >0 && id != ERROR){
		for(i =0; i < tamanio; i++){
			if((*(array+i)).idTipo == id){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int mostrarTipoString(tipo* array, int tamanio,int id, char* tipoString){
	int retorno = ERROR;
	int i;
	if(array != NULL && tamanio >0 && id != ERROR){
		for(i =0; i < tamanio; i++){
			if( (*(array+i)).idTipo == id){
				strcpy(tipoString, (*(array+i)).descripcion);
				break;
			}
		}
	}
	return retorno;
}
