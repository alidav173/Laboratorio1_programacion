/*
 * funciones.h
 *
 *  Created on: 15 sept. 2022
 *      Author: Ali Ansidey
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#define ERROR -1
#define TAM_MAX 22

#include <stdio.h>
#include"utn.h"

/**
 * @brief	Le solicita los costos de hospedaje, comida y transporte al usuario
 * @param	pCostoHospedaje Puntero del costo de hospedaje
 * @param	pCostoComida Puntero del costo de comida
 * @param	pCostoTransporte Puntero del costo de transporte
 * @return	Retorna 0 si se pudieron cargar los costos y -1 si no.
 */
int ingresoCostosMantenimiento(float *pCostoHospedaje,float *pCostoComida,float *pCostoTransporte);


/**
 * @brief	Carga la informacion de los jugadores que estaran en la seleccion
 * @param	cantidadJugadores Puntero a la cantidad de jugadores totales (maximo 22)
 * @param	cantArqueros Puntero a la cantidad de arqueros (maximo 2)
 * @param	cantDefensores Puntero a la cantidad de defensores (maximo 8)
 * @param	cantMedios Puntero a la cantidad de mediocampos (maximo 8)
 * @param	cantDelanteros Puntero a la cantidad de delanteros (maximo 4)
 * @param	conferacionAFC Puntero a la cantidad de jugadores AFC
 * @param	conferacionCAF Puntero a la cantidad de jugadores CAF
 * @param	conferacionCONCACAF Puntero a la cantidad de jugadores CONCACAF
 * @param	conferacionCONMEBOL Puntero a la cantidad de jugadores CONMEBOL
 * @param	conferacionUEFA Puntero a la cantidad de jugadores UEFA
 * @param	conferacionOFC Puntero a la cantidad de jugadores OFC
 * @param	arrayCamisetas Puntero al array de camisetas de los jugadores
 * @param	indexArray Puntero al indice del array de Camisetas
 * @param	tamanio del array de Camisetas
 * @return	Retorna 0 si se pudieron cargar los jugadores y -1 si no.
 */
int cargaJugadores(int* cantidadJugadores,int* cantArqueros, int* cantDefensores, int* cantMedios, int* cantDelanteros,
		int* conferacionAFC, int* conferacionCAF, int* conferacionCONCACAF, int* conferacionCONMEBOL, int* conferacionUEFA, int* conferacionOFC,
		int* arrayCamisetas, int* indexArray, int tamanio);


/**
 * @brief	Carga la posicion de los jugadores que estaran en la seleccion
 * @param	cantArqueros Puntero a la cantidad de arqueros (maximo 2)
 * @param	cantDefensores Puntero a la cantidad de defensores (maximo 8)
 * @param	cantMedios Puntero a la cantidad de mediocampos (maximo 8)
 * @param	cantDelanteros Puntero a la cantidad de delanteros (maximo 4)
 * @return	Retorna 0 si se pudo cargar los jugadores por posicion y -1 si no.
 */
int cargaPosicion(int* cantArqueros, int* cantDefensores, int* cantMedios, int* cantDelanteros);


/**
 * @brief	Carga la confederacion de los jugadores que estaran en la seleccion
 * @param	conferacionAFC Puntero a la cantidad de jugadores AFC
 * @param	conferacionCAF Puntero a la cantidad de jugadores CAF
 * @param	conferacionCONCACAF Puntero a la cantidad de jugadores CONCACAF
 * @param	conferacionCONMEBOL Puntero a la cantidad de jugadores CONMEBOL
 * @param	conferacionUEFA Puntero a la cantidad de jugadores UEFA
 * @param	conferacionOFC Puntero a la cantidad de jugadores OFC
 * @return	Retorna 0 si se pudo cargar los jugadores por confederacion y -1 si no.
 */
int cargaConfederacion(int* conferacionAFC, int* conferacionCAF, int* conferacionCONCACAF, int* conferacionCONMEBOL,
		int* conferacionUEFA, int* conferacionOFC);


/**
 * @brief	Carga la informacion de las camisetas que estaran en la seleccion

 * @param	numero de camiseta del jugador. Se pide al usuario
 * @param	indexArray Puntero al indice del array de Camisetas
 * @param	arrayCamisetas Puntero al array de camisetas de los jugadores
 * @param	tamanio del array de Camisetas
 * @return	Retorna 0 si se pudo cargar la camiseta y -1 si no.
 */
int cargaCamisetaJugador(int nroCamiseta,int* index, int* arrayCamisetas, int tamanio);

#endif /* FUNCIONES_H_ */
