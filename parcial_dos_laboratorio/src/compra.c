/*
 * compra.c
 *
 *  Created on: 14 nov. 2022
 *      Author: Ali Ansidey
 */

#include "compra.h"
#include <stdio.h>
#include <string.h>

#define ERROR -1

Compra* compra_new(){
	Compra* pCompra;

	pCompra = (Compra*) malloc(sizeof(Compra));

	return pCompra;
}

Compra* compra_newParametros(char* codigoCompraStr,char* descripcionStr,char* origenStr, char* precioUnitarioStr, char* cantidadStr, char* totalCompraStr){
	Compra* pCompra;

	pCompra = compra_new();
	if(pCompra != NULL){
		compra_setCodigo(pCompra,atoi(codigoCompraStr));
		compra_setDescripcion(pCompra,descripcionStr);
		compra_setOrigen(pCompra,atoi(origenStr));
		compra_setPrecio(pCompra,atof(precioUnitarioStr));
		compra_setCantidad(pCompra,atoi(cantidadStr));
		compra_setTotalCompra(pCompra,atof(totalCompraStr));
	}
	return pCompra;
}


void compra_delete(Compra* this){
	if(this != NULL){
		free(this);
	}
}

int compra_setCodigo(Compra* this,int codigoCompra){
	int retorno = ERROR;
	if(this != NULL){
		this->codigoCompra = codigoCompra;
		retorno = 0;
	}
	return retorno;
}

int compra_getCodigo(Compra* this,int* codigoCompra){
	int retorno = ERROR;
	if(this != NULL){
		*codigoCompra = this->codigoCompra;
		retorno = 0;
	}
	return retorno;
}

int compra_setDescripcion(Compra* this,char* descripcion){
	int retorno = ERROR;
	if(this != NULL){
		strcpy(this->descripcion, descripcion);
		retorno = 0;
	}
	return retorno;
}

int compra_getDescripcion(Compra* this,char* descripcion){
	int retorno = ERROR;
	if(this != NULL){
		strcpy(descripcion, this->descripcion);
		retorno = 0;
	}
	return retorno;
}

int compra_setOrigen(Compra* this,int origen){
	int retorno = ERROR;
	if(this != NULL){
		this->origen = origen;
		retorno = 0;
	}
	return retorno;
}

int compra_getOrigen(Compra* this,int* origen){
	int retorno = ERROR;
	if(this != NULL){
		*origen = this->origen;
		retorno = 0;
	}
	return retorno;
}

int compra_setPrecio(Compra* this,float precio){
	int retorno = ERROR;
	if(this != NULL){
		this->precioUnitario = precio;
		retorno = 0;
	}
	return retorno;
}

int compra_getPrecio(Compra* this,float* precio){
	int retorno = ERROR;
	if(this != NULL){
		*precio = this->precioUnitario;
		retorno = 0;
	}
	return retorno;
}

int compra_setCantidad(Compra* this,int cantidad){
	int retorno = ERROR;
	if(this != NULL){
		this->cantidad = cantidad;
		retorno = 0;
	}
	return retorno;
}

int compra_getCantidad(Compra* this,int* cantidad){
	int retorno = ERROR;
	if(this != NULL){
		*cantidad = this->cantidad;
		retorno = 0;
	}
	return retorno;
}

int compra_setTotalCompra(Compra* this,float totalCompra){
	int retorno = ERROR;
	if(this != NULL){
		this->totalCompra = totalCompra;
		retorno = 0;
	}
	return retorno;
}

int compra_getTotalCompra(Compra* this,float* totalCompra){
	int retorno = ERROR;
	if(this != NULL){
		*totalCompra = this->totalCompra;
		retorno = 0;
	}
	return retorno;
}

int mostrarInfoCompra(Compra* this){
	int retorno = ERROR;
	if(this != NULL){
		printf("Codigo de Compra: %d - Descripcion: %s - Origen: %d - Precio unitario: $ %.2f - Cantidad: %d -  Total Compra: $ %.2f\n",this->codigoCompra,
				this->descripcion,this->origen, this->precioUnitario,this->cantidad,this->totalCompra);
		retorno =0;
	}
	return retorno;
}
