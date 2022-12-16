/*
 * tipo.h
 *
 *  Created on: 7 oct. 2022
 *      Author: Ali Ansidey
 */

#ifndef TIPO_H_
#define TIPO_H_

#include <stdio.h>
#include <float.h>
#include "utn.h"
#define VACIO 0
#define LLENO 1
#define ERROR -1

typedef struct{
	int idTipo;
	char descripcion[31];
}tipo;

/**
* @brief	Muesta los elementos del array tipo
* @param	array Puntero al array del tipo tipo
* @param	tamanio longitud del array del tipo tipo
* @return	Retorna 0 (EXITO) si se pueden mostrar y -1 (ERROR) si no se pueden mostrar
*/
int listarTipos(tipo* array, int tamanio);

/**
* @brief	Busca en el array de tipo, un tipo con el id pasado por parametros
* @param	array Puntero al array del tipo tipo
* @param	tamanio longitud del array del tipo tipo
*  @param	id buscado del tipo, del tipo INT
* @return	Retorna el indice del tipo (EXITO) y -1 (ERROR) si no hay algun tipo con el Id
*/
int buscarTipoPorId(tipo* array, int tamanio,int id);



/**
* @brief	Muestra en String la descripcion del tipo del elemento
* @param	array Puntero al array del tipo tipo
* @param	tamanio longitud del array del tipo tipo
* @param	id buscado del tipo, del tipo INT
* @param	Puntero al array String donde  se guarda la descripcion
* @return	Retorna el indice del tipo (EXITO) y -1 (ERROR) si no hay algun tipo con el Id
*/
int mostrarTipoString(tipo* array, int tamanio,int id, char* tipoString);

#endif /* TIPO_H_ */
