/*
 * controlador.h
 *
 *  Created on: 15 nov. 2022
 *      Author: Ali Ansidey
 */

#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_

int cotrolador_cargarArchivo(char* path , LinkedList* pArrayListCompra);

int controlador_cargarCompraDesdeBinario(char* path , LinkedList* pArrayListCompra);

int controlador_imprimirLista(LinkedList* pArrayListCompra);

void* controlador_asignarTotal(void* this);

#endif /* CONTROLADOR_H_ */
