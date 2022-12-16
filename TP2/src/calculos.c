/*
 * calculos.c
 *
 *  Created on: 27 oct. 2022
 *      Author: Ali Ansidey
 */


#include <stdio.h>
#define ERROR -1

int calcularPromedio(float salarios,int cantidad,float* promedio){
	int retorno = ERROR;

	if(promedio != NULL && cantidad >0){
		*promedio = salarios/cantidad;
		retorno = 0;
	}

	return retorno;
}

int porcentajePorTipo(int numero1, int numero2, float* porcentaje){
	int retorno = ERROR;
	if(porcentaje != NULL && numero2 >0){
		*porcentaje = ((float)numero1/numero2)*100;
		retorno =0;
	}

	return retorno;
}
