/*
 * confederacion.c
 *
 *  Created on: 22 oct. 2022
 *      Author: Ali Ansidey
 */


#include <stdio.h>
#include <string.h>
#include "confederacion.h"
#define ERROR -1
#define VACIO 0
#define LLENO 1


int mostrarConfederacion(eConfederacion confederacion){
	int retorno = ERROR;
		printf("|%*d|%*s|%*s|%*d|\n",10,confederacion.id,20,confederacion.nombre,30,confederacion.region,
		15,confederacion.anioCreacion);
		retorno = 0;
	return retorno;
}

int listarConfederaciones(eConfederacion* array, int tamanio){
	int retorno = ERROR;
	if(array != NULL && tamanio >0 ){
		int i;
		printf("|%*s|%*s|%*s|%*s|\n",10,"Id",20,"Nombre",30,"Region",
				15,"Anio Creacion");
		for(i = 0; i < tamanio; i++){
			mostrarConfederacion(*(array+i));
		}
		retorno = 0;
	}
	return retorno;
}

//comparo el campo nombre de 2 estructuras


int compararPorNombre(char* nombre1, char* nombre2){
	int retorno = 0;
	if(nombre1 != NULL && nombre2 != NULL){

	if(strcmp(nombre1,nombre2) >0){
		retorno = 1;
	}
	else if(strcmp(nombre1,nombre2) <0){
		retorno = -1;
	}
	}

 return retorno;
}


int ordenarPornombre( eConfederacion* arrayConf, int tamanio){
	int retorno = ERROR;
	int i, j;
	if(arrayConf != NULL && tamanio){
		eConfederacion auxConf;
	  for (i = 0; i < tamanio - 1; i++)
	    {
	      for (j = i + 1; j < tamanio; j++)
		{
	    	  if(compararPorNombre((*(arrayConf+i)).nombre, (*(arrayConf+j)).nombre) == 1){
	    		  auxConf = *(arrayConf+i);
	    		  *(arrayConf+i) =  *(arrayConf+j);
	    		  *(arrayConf+j) = auxConf;
	    	  }
		}
	    }
	  retorno =0;
	}
	return retorno;

}


int buscarConfPorId(eConfederacion* array, int tamanio, int id){
	int retorno = ERROR;
	int i;
	if(array != NULL && tamanio >0 && id >0){
		for(i = 0; i<tamanio; i++){
			if((*(array+i)).id == id){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
