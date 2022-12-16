/*
 * informes.h
 *
 *  Created on: 26 oct. 2022
 *      Author: Ali Ansidey
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include "confederacion.h"
#include "jugador.h"


/**
* @brief	Ordena un array del tipo Jugador segun el nombre del la confederacion o el nombre del jugador
* 			como segundo factor de orden
* @param	arrayjugadores Puntero al array del tipo eJugador2
* @param	tamanioArray  Define el tamanio del array del tipo eJugador
* @param	arrayConf Puntero al array del tipo eConfederacion
* @param	tamanio  Define el tamanio del array del tipo eConfederacion
* @return	retorna 0 si pudo ordenar, y -1(ERROR) si no pudo ordenar
*/
int  ordenarJugadorPorConfYnombre (eJugador2* arrayjugadores,int tamanioArray, eConfederacion* arrayConf, int tamanio);


/**
* @brief	Muestra un array del tipo Jugador ordenado alfabeticamente
* @param	arrayjugadores Puntero al array del tipo eJugador
* @param	tamanioArray  Define el tamanio del array del tipo eJugador
* @param	arrayConf Puntero al array del tipo eConfederacion
* @param	tamanio  Define el tamanio del array del tipo eConfederacion
* @return	Retorna 0 (EXITO) si se puede listar y -1 (ERROR) si no se puede
*/
int listarJugadoresOrdendosAlfabeticamente (eJugador2* arrayjugadores,int tamanioArray, eConfederacion* arrayConf, int tamanio);


/**
* @brief	Muestra un elemento del tipo Confederacion y los juegadores pertenecientes
* a la misma
* @param	arrayjugadores Puntero al array del tipo eJugador
* @param	tamanioArray  Define el tamanio del array del tipo eJugador
* @param	arrayConf Puntero al array del tipo eConfederacion
* @param	tamanio  Define el tamanio del array del tipo eConfederacion
* @return	Retorna 0 (EXITO) si se puede mostrar y -1 (ERROR) si no se puede
*/
int mostrarConfederacionesYjugadores(eJugador* arrayjugadores,int tamanioArray, eConfederacion* arrayConf, int tamanio);


/**
* @brief	Muestra el total y los promedios de los salarios de los jugadores
* @param	arrayjugadores Puntero al array del tipo eJugador
* @param	tamanioArray  Define el tamanio del array del tipo eJugador
* @return	Retorna 0 (EXITO) si se puede mostrar y -1 (ERROR) si no se puede
*/
int mostrarTotalYpromedioDeSalarios(eJugador* arrayjugadores,int tamanioArray);


/**
* @brief	Muestra un elemento del tipo Confederacion con la mayor cantidad de
* anios de contrato
* @param	arrayjugadores Puntero al array del tipo eJugador
* @param	tamanioArray  Define el tamanio del array del tipo eJugador
* @param	arrayConf Puntero al array del tipo eConfederacion
* @param	tamanio  Define el tamanio del array del tipo eConfederacion
* @return	Retorna 0 (EXITO) si se puede mostrar y -1 (ERROR) si no se puede
*/
int confederacionMayorCantAniosContrato(eJugador* arrayjugadores,int tamanioArray, eConfederacion* arrayConf, int tamanio);


/**
* @brief	Muestra un elemento del tipo Confederacion y el porcentaje
* de jugadores pertenecientes a la misma
* @param	arrayjugadores Puntero al array del tipo eJugador
* @param	tamanioArray  Define el tamanio del array del tipo eJugador
* @param	arrayConf Puntero al array del tipo eConfederacion
* @param	tamanio  Define el tamanio del array del tipo eConfederacion
* @return	Retorna 0 (EXITO) si se puede mostrar y -1 (ERROR) si no se puede
*/
int mostrarPorcentajeJugadoresPorConfederacion(eJugador* arrayjugadores,int tamanioArray, eConfederacion* arrayConf, int tamanio);


/**
* @brief	Muestra la region con mas jugadores
* @param	arrayjugadores Puntero al array del tipo eJugador
* @param	tamanioArray  Define el tamanio del array del tipo eJugador
* @param	arrayConf Puntero al array del tipo eConfederacion
* @param	tamanio  Define el tamanio del array del tipo eConfederacion
* @return	Retorna 0 (EXITO) si se puede mostrar y -1 (ERROR) si no se puede
*/
int mostrarRegionConMasJugadores(eJugador* arrayjugadores,int tamanioArray, eConfederacion* arrayConf, int tamanio);

/**
* @brief	De un jugador original copia los datos y setea el nombre de la confederacion
* @param	eJugador jugadorOriginal, jugador original
* @param	eConfederacion* arrayConf array del tipo eConfederacion
* @param	int tamanio, tamanio del array arrayConf
* @return	retorna un eJugador2
*/
eJugador2 copiarJugador(eJugador jugadorOriginal, eConfederacion* arrayConf, int tamanio);


/**
* @brief	Copio los jugadores del arrayjugadores al pArray, seteando
* el nombre de la confederacion
* @param	eJugador* arrayjugadores Puntero al array del tipo eJugador
* @param	tamanioArray  Define el tamanio del array del tipo eJugador
* @param	arrayConf Puntero al array del tipo eConfederacion
* @param	tamanio  Define el tamanio del array del tipo eConfederacion
* @param	eJugador2* pArray, nueva lista donde se copia y setea la arrayjugadores
* @return	retorna 0 si pudo ordenar, y -1(ERROR) si no pudo ordenar
*/
int copiarEstructuraSeteada(eJugador* arrayjugadores,int tamanioArray, eConfederacion* arrayConf, int tamanio, eJugador2* pArray);


#endif /* INFORMES_H_ */
