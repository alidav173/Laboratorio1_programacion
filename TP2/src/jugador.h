/*
 * jugador.h
 *
 *  Created on: 22 oct. 2022
 *      Author: Ali Ansidey
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "confederacion.h"

typedef struct{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	int idConfederacion;
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador;


//creo esta nueva estructura
typedef struct{
	int id;
	char nombre[50];
	char posicion[50];
	short numeroCamiseta;
	char nombreConf[50];
	float salario;
	short aniosContrato;
	short isEmpty;
}eJugador2;



/**
* @brief	Inicializa el campo del tipo isEmpty de la estructura tipo eJugador
* @param	array Puntero al array del tipo eJugador
* @param	tamanio  Define el tamanio del array del tipo eJugador
* @return	Retorna 0 (EXITO) si pudo inicializar el array y -1 (ERROR) si no se puede
*/
int inicializarArrayJugador(eJugador* array, int tamanio);


/**
* @brief	Busca el primer espacio libre en el array del tipo eJugador
* @param	array Puntero al array del tipo eJugador
* @param	tamanio  Define el tamanio del array del tipo eJugador
* @return	Retorna un numero mayor o igual a 0 si pudo conseguir un espacio y -1 (ERROR) si no se puede
*/
int findFirstSpaceJugador (eJugador* array, int tamanio);


/**
* @brief	Retorna el indice del elemento que se busca segun el ID
* @param	array Puntero al array del tipo eJugador
* @param	tamanio  Define el tamanio del array del tipo eJugador
* @param	id  es el elemento para buscar el elemento en el array tipo eJugador
* @return	Retorna un numero mayor o igual a 0 si pudo conseguir el elemento y -1 (ERROR) si no se puede
*/
int buscarJugadorPorId(eJugador* array, int tamanio, int id);



/**
* @brief	Retorna el indice del elemento que se busca segun el ID
* @param	array Puntero al array del tipo eJugador2
* @param	tamanio  Define el tamanio del array del tipo eJugador
* @param	id  es el elemento para buscar el elemento en el array tipo eJugador
* @return	Retorna un numero mayor o igual a 0 si pudo conseguir el elemento y -1 (ERROR) si no se puede
*/
int buscarJugadorPorId2(eJugador2* array, int tamanio, int id);

/**
* @brief	Carga un elemento tipo eJugador en el array de jugadores
* @param	array Puntero al array del tipo eJugador
* @param	tamanio  Define el tamanio del array del tipo eJugador
* @param	int* lastId  puntero al ultimo Id
* @return	Retorna 0 (EXITO) si pudo inicializar el array y -1 (ERROR) si no se puede
*/
int altaJugador(eJugador* array, int tamanio,eConfederacion* arrayConf,int tamanioConf, int* lastId);


/**
* @brief	Elimina logicamente un elemento del array tipo eJugador
* @param	arrayjugadores Puntero al array del tipo eJugador
* @param	tamanioArray  Define el tamanio del array del tipo eJugador
* @param	arrayConf Puntero al array del tipo eConfederacion
* @param	tamanio  Define el tamanio del array del tipo eConfederacion
* @return	Retorna 0 (EXITO) si pudo eliminar el jugador y -1 (ERROR) si no se puede
*/
int bajaJugador(eJugador* arrayjugadores, int tamanioArray, eConfederacion* arrayConf, int tamanio);


/**
* @brief	Modificas los campos de un elemento eJugador
* @param	arrayjugadores Puntero al array del tipo eJugador
* @param	tamanioArray  Define el tamanio del array del tipo eJugador
* @param	arrayConf Puntero al array del tipo eConfederacion
* @param	tamanio  Define el tamanio del array del tipo eConfederacion
* @return	Retorna 0 (EXITO) si pudo modificar el jugador y -1 (ERROR) si no se puede
*/
int modificarJugador(eJugador* arrayjugadores, int tamanioArray, eConfederacion* arrayConf, int tamanio);


/**
* @brief	Muestra los campos de un elemento tipo eJugador
* @param	array Puntero al array del tipo eJugador
* @param	array Puntero al array del tipo eConfederacion
* @param	tamanio  Define el tamanio del array del tipo eJugador
* @return	No retorna nada
*/
void mostrarJugador(eJugador jugador, eConfederacion* arrayConf, int tamanio);



/**
* @brief	Muestra los elementos del array tipo eJugador
* @param	arrayjugadores Puntero al array del tipo eJugador
* @param	tamanioArray  Define el tamanio del array del tipo eJugador
* @param	arrayConf Puntero al array del tipo eConfederacion
* @param	tamanio  Define el tamanio del array del tipo eConfederacion
* @return	No retorna nada
*/
void mostrarJugadores(eJugador* arrayjugadores,int tamanioArray, eConfederacion* arrayConf, int tamanio);


/**
* @brief	Muestra los elementos del array de jugadores segun el id de la Confederacion
* @param	arrayjugadores Puntero al array del tipo eJugador
* @param	tamanioArray  Define el tamanio del array del tipo eJugador
* @param	arrayConf Puntero al array del tipo eConfederacion
* @param	tamanio  Define el tamanio del array del tipo eConfederacion
* @param	idConf  id del tipo de Confederacion para hacer el criterio de filtro
* @return	No retorna nada
*/
void mostrarJugadoresPorConfederacion(eJugador* arrayjugadores,int tamanioArray, eConfederacion* arrayConf, int tamanio, int idConf);


/**
* @brief	Ordena un array del tipo Ejugador por el nombre
* @param	eJugador* arrayJug, array del tipo eJugador
* @param	int tamanio, tamanio del arrayJug
* @return	Si pudo ordenar retorna 0, sino -1
*/
int ordenarPornombreJugador(eJugador* arrayJug, int tamanio);


/**
* @brief	Muestra los elementos del array tipo eJugador con el nombre de la confederacion
* @param	arrayjugadores Puntero al array del tipo eJugador2
* @param	tamanioArray  Define el tamanio del array del tipo eJugador
* @return	No retorna nada
*/
void mostrarJugadores2(eJugador2* arrayjugadores,int tamanioArray);

/**
* @brief	Verifica si el array de jugadores se encuentra vacio
* @param	arrayjugadores Puntero al array del tipo eJugador
* @param	tamanioArray  Define el tamanio del array del tipo eJugador
* @return	Si esta vacia, retorna 0. Sino numero > 0.
*/
int listaVacia(eJugador* arrayJug, int tamanio);



#endif /* JUGADOR_H_ */
