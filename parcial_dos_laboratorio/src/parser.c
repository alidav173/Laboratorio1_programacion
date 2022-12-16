/*
 * parser.c
 *
 *  Created on: 14 nov. 2022
 *      Author: Ali Ansidey
 */


#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "compra.h"

#define ERROR -1

int parser_compraFromText(FILE* pFile , LinkedList* pArrayListCompra)
{
	int retorno = ERROR;
	Compra* pCompra;
	char codigoCompra[30];
	char descripcion[30];
	char origen[30];
	char precioUnitario[30];
	char cantidad[30];
	char totalCompra[30];
	int esHeader = 1;
	if(pFile != NULL){

		if(esHeader == 1){
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",codigoCompra,descripcion,origen,precioUnitario,cantidad,totalCompra);
		esHeader = 0;
		}

		while(!feof(pFile)){
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",codigoCompra,descripcion,origen,precioUnitario,cantidad,totalCompra);
			pCompra = compra_newParametros(codigoCompra,descripcion,origen,precioUnitario,cantidad,totalCompra);
			if(pCompra != NULL){
				ll_add(pArrayListCompra,pCompra);
				retorno = 0;
				mostrarInfoCompra(pCompra);
			}
		}
	}
    return retorno;
}



int parser_compraFromBinary(FILE* pFile , LinkedList* pArrayListCompra)
{
	int retorno = ERROR;
	if(pFile != NULL){
		Compra* pCompra;
		while(!feof(pFile)){
			pCompra = compra_new();
			if(fread(pCompra,sizeof(Compra),1,pFile)==1){
				ll_add(pArrayListCompra,pCompra);
			}
		}
	}
	return retorno;
}


