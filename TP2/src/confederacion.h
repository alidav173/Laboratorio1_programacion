/*
 * confederacion.h
 *
 *  Created on: 22 oct. 2022
 *      Author: Ali Ansidey
 */

#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_


typedef struct{
	int id;
	char nombre[50];
	char region[50];
	int anioCreacion;
}eConfederacion;


/**
* @brief	Muestra los campos de un elemento tipo eConfederacion
* @param	eConfederacion confederacion
* @return	Si puede mostrar los campos 0, si no puede -1
*/
int mostrarConfederacion(eConfederacion confederacion);


/**
* @brief	Muestra los elementos del array tipo eConfederacion
* @param	eConfederacion* array Puntero al array del tipo eConfederacion
* @param	tamanio  Define el tamanio del array del tipo eConfederacion
* @return	Si puede mostrar los elementos 0, si no puede -1
*/
int listarConfederaciones(eConfederacion* array, int tamanio);


/**
* @brief	Compara dos cadenas de string pasadas por parametro
* @param	char* nombre1 nombre1 en string
* @param	char* nombre2 nombre2 en string
* @return	Si nombre1 > nombre2, retorna 1
* 			Si nombre1 < nombre2, retorna -1
* 			Si nombre1 ==  nombre2, retorna 0
*/
int compararPorNombre(char* nombre1, char* nombre2);


/**
* @brief	Ordena un array del tipo eConfederacion por el nombre
* @param	eConfederacion* arrayConf, array de la confederacion
* @param	int tamanio, tamanio del arrayConf
* @return	Si pudo ordenar retorna 0, sino -1
*/
int ordenarPornombre(eConfederacion* arrayConf, int tamanio);


/**
* @brief	Retorna el indice del elemento que se busca segun el ID
* @param	eConfederacion* array, array de la confederacion
* @param	tamanio  Define el tamanio del array del tipo eJugador
* @param	id  es el elemento para buscar el elemento en el array tipo eConfederacion
* @return	Retorna un numero mayor o igual a 0 si pudo conseguir el elemento y -1 (ERROR) si no se puede
*/
int buscarConfPorId(eConfederacion* array, int tamanio, int id);


#endif /* CONFEDERACION_H_ */
