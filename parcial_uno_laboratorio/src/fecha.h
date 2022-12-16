/*
 * fecha.h
 *
 *  Created on: 7 oct. 2022
 *      Author: Ali Ansidey
 */

#ifndef FECHA_H_
#define FECHA_H_

#include <stdio.h>
#include "utn.h"
#define ERROR -1

typedef struct{
	int dia;
	int mes;
	int anio;
}fecha;


/**
* @brief	Toma un elemento del tipo fecha y carga los datos en los atributos de la estructura
* @param	fechaActual Puntero al array del tipo fecha
* @return	Retorna 0 (EXITO) si se pueden cargar los atributos y -1 (ERROR) si no pudo cargar
*/
int ingresoFecha(fecha* fechaActual);


/**
* @brief	Pasa un elemento del tipo fecha a un elemento tipo String
* @param	fechaActual Puntero al array del tipo fecha
* @param	fechaString Puntero a una array de caracteres
* @return	Retorna 0 (EXITO) si pudo obtener la fecha y copiarla en el fechaString y -1 (ERROR) si no pudo
*/
int conversionFechaString(fecha fechaActual, char* fechaString);

#endif /* FECHA_H_ */
