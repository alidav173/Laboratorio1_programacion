/*
 * controlador.c
 *
 *  Created on: 15 nov. 2022
 *      Author: Ali Ansidey
 */
#include "compra.h"
#include "linkedList.h"
#include "parser.h"
#include "utn.h"
#define ERROR -1

int cotrolador_cargarArchivo(char* path, LinkedList* pArrayListCompra){
	int retorno = ERROR;
	FILE* pFile;
	pFile = fopen(path,"r");
	if(pFile != NULL){
		if(parser_compraFromText(pFile ,pArrayListCompra) != ERROR){
			puts("Se pudo cargar el archivo csv con exito\n");
			retorno = 0;
		}
		else{
			puts("Error al abrir el  archivo csv\n");
		}
	}
	fclose(pFile);
    return retorno;
}

int controlador_cargarCompraDesdeBinario(char* path , LinkedList* pArrayListCompra)
{
   int retorno = ERROR;
   FILE* pFile = fopen(path,"rb");
   if(pFile != NULL && pArrayListCompra != NULL){
	   parser_compraFromBinary(pFile, pArrayListCompra);
	   puts("Se pudo cargar el archivo binario con exito\n");
	   retorno = 0;
   }
   fclose(pFile);
   return retorno;
}

int controlador_imprimirLista(LinkedList* pArrayListCompra){
	int retorno = 0;
	int i;
	if(pArrayListCompra != NULL){
		Compra* auxCompra;
		for(i = 0; i < ll_len(pArrayListCompra); i++){
			auxCompra = ll_get(pArrayListCompra,i);
			mostrarInfoCompra(auxCompra);
		}
	}
	return retorno;
}

void* controlador_asignarTotal(void* this){
	void* retorno = NULL;
	int cantidad;
	float precio;
	float totalCompra;
	if(this != NULL){
		compra_getPrecio(this,&precio);
		compra_getCantidad(this,&cantidad);
		totalCompra = cantidad * precio;
		compra_setTotalCompra(this,totalCompra);
		retorno = this;
	}
	return retorno;
}

int controlador_filtrarPortipo(char* path ,LinkedList* pArrayListCompra){
	int retorno = ERROR;
	if(pArrayListCompra != NULL){


	}

	return retorno;
}

int funcionFiltro1(Compra* this){
	int retorno = ERROR;
	int origen;
	if(this != NULL){
		compra_getOrigen(this,&origen);
		if(origen == 1){
			retorno = 1;
		}
	}
	return retorno;
}

int funcionFiltro2(Compra* this){
	int retorno = ERROR;
	int origen;
	if(this != NULL){
		compra_getOrigen(this,&origen);
		if(origen == 2){
			retorno = 1;
		}
	}
	return retorno;
}

int funcionFiltro3(Compra* this){
	int retorno = ERROR;
	int origen;
	if(this != NULL){
		compra_getOrigen(this,&origen);
		if(origen == 3){
			retorno = 1;
		}
	}
	return retorno;
}

int controlador_guardarComprasModoTexto(char* path , LinkedList* pArrayListCompra){
	int retorno = ERROR;
	int i;
	int codigoCompra;
	char descripcion[30];
	int origen;
	float precio;
	int cantidad;
	float totalCompra;
	int esHeader = 1;
	FILE *pFile;
	pFile = fopen(path,"w");
	if(pArrayListCompra != NULL && pFile != NULL){
		Compra* auxCompra;
		for(i = 0; i < ll_len(pArrayListCompra);i++){
			auxCompra = ll_get(pArrayListCompra,i);
			compra_getCodigo(auxCompra,&codigoCompra);
			compra_getDescripcion(auxCompra,descripcion);
			compra_getOrigen(auxCompra,&origen);
			compra_getPrecio(auxCompra,&precio);
			compra_getCantidad(auxCompra,&cantidad);
			compra_getTotalCompra(auxCompra,&totalCompra);

    		if(esHeader == 1){
    			fprintf(pFile,"%s,%s,%s,%s,%s,%s\n","id","codigoCompra","descripcion","origen","precioUnitario","cantidad","totalCompra");
    			esHeader = 0;
    		}
    		fprintf(pFile,"%d,%s,%d,%s,%s,%d\n",codigoCompra,descripcion,origen,precio,cantidad,totalCompra);
    		retorno =0;
		}
    	printf("Se ha guardado el archivo csv con exito\n");
    	fclose(pFile);
	}

	return retorno;
}


