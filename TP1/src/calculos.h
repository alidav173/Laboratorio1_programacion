/*
 * funciones.h
 *
 *  Created on: 15 sept. 2022
 *      Author: Ali Ansidey
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

#define ERROR -1
#define TAM_MAX 22

#include <stdio.h>
#include"utn.h"


/**
 * @brief	Calcula el promedio de Jugadores por confederacion
 * @param	cantJugConfederacion Puntero de la cantidad de jugadores de una confederacion definida
 * @param	cantidadJugadores Puntero de la cantidad de jugadores totales de la seleccion
 * @param	promedio Puntero al espacio de memoria donde se guarda el resultado de la funcion
 * @return	Retorna 0 si se obtuvo el promedio y -1 si no.
 */
int promedioJugadoresPorConfederacion(int* cantJugConfederacion, int* cantidadJugadores, float* promedio);


/**
 * @brief	Comprueba si la cantidad de jugadores en ligas europeas es mayor al resto
 * @param	cantUEFA Puntero al espacio de memoria jugadores en Europa
 * @param	cantAFC Puntero al espacio de memoria jugadores en AFC
 * @param	cantCAF Puntero al espacio de memoria jugadores en CAF
 * @param	cantCONCACAF Puntero al espacio de memoria jugadores en CONCACAF
 * @param	cantCONMEBOL Puntero al espacio de memoria jugadores en CONMEBOL
 * @param	cantOFC Puntero al espacio de memoria jugadores en OFC
 * @return	Retorna 0 si son mayoria los jugadores y -1 si no.
 */
int sonMayoriaJugadoresEnEuropa(int* cantUEFA, int* cantAFC, int* cantCAF, int* cantCONCACAF, int* cantCONMEBOL, int* cantOFC);


/**
 * @brief	Solicita los 3 costos para calcular el total. Si sonMayoriaJugadoresEuropa es 0, se hace un recargo
 * del 35% al costo total calcalado.
 * @param	costo1 Puntero al costo1
 * @param	costo2 Puntero al costo2
 * @param	costo3 Puntero al costo3
 * @param	pResultado Puntero al espacio de memoria donde se dejara el resultado del costo de Mantenimiento
 * @param	recargoEuropa Puntero del costo extra (recargo)
 * @param	pResultado Puntero al espacio de memoria donde se dejara el resultado del costo de Mantenimiento total
 * @param	sonMayoriaJugadoresEnEuropa Puntero al resultado si con mayoria de jugadores en Europa
 * @return	Retorna 0 si se obtuvo el resultado y -1 si no.
 */
int calculoCostosMantenimiento(float *costo1, float* costo2, float* costo3, float* costoMant,float* recargoEuropa,
		float* costoTotal, int* sonMayoriaJugadoresEnEuropa);

#endif /* CALCULOS_H_ */
