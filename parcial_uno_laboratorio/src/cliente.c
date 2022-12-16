/*
 * cliente.c
 *
 *  Created on: 23 nov. 2022
 *      Author: Ali Ansidey
 */

#include <stdio.h>
#include "cliente.h"
#define ERROR -1



int listarClientes(cliente* array, int tamanio){
	int retorno = ERROR;
	int i;
	if(array!= NULL && tamanio >0){
		for(i=0; i<tamanio;i++){
			printf("Id cliente: %d\t Nombre: %s\t Apellido: %s\t Telefono : %d\n",
					(*(array+i)).idCliente, (*(array+i)).nombre,(*(array+i)).apellido,(*(array+i)).telefono);
		}
		retorno = 0;
	}
	return retorno;
}


int buscarClientePorId(cliente* array, int tamanio,int id){
	int retorno = ERROR;
	int i;
	if(array != NULL && tamanio >0 && id != ERROR){
		for(i =0; i < tamanio; i++){
			if((*(array+i)).idCliente == id){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
