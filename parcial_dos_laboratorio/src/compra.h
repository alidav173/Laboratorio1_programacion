/*
 * compra.h
 *
 *  Created on: 14 nov. 2022
 *      Author: Ali Ansidey
 */

#ifndef COMPRA_H_
#define COMPRA_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int codigoCompra;
	char descripcion[30];
	int origen;
	float precioUnitario;
	int cantidad;
	float totalCompra;
}Compra;


Compra* compra_new();

Compra* compra_newParametros(char* codigoCompraStr,char* descripcionStr,char* origenStr, char* precioUnitarioStr, char* cantidadStr, char* totalCompraStr);

void compra_delete(Compra* this);

int compra_setCodigo(Compra* this,int codigoCompra);

int compra_getCodigo(Compra* this,int* codigoCompra);

int compra_setDescripcion(Compra* this,char* descripcion);

int compra_getDescripcion(Compra* this,char* descripcion);

int compra_setOrigen(Compra* this,int origen);

int compra_getOrigen(Compra* this,int* origen);

int compra_setPrecio(Compra* this,float precio);

int compra_getPrecio(Compra* this,float* precio);

int compra_setCantidad(Compra* this,int cantidad);

int compra_getCantidad(Compra* this,int* cantidad);

int compra_setTotalCompra(Compra* this,float totalCompra);

int compra_getTotalCompra(Compra* this,float* totalCompra);

int mostrarInfoCompra(Compra* this);

#endif /* COMPRA_H_ */
