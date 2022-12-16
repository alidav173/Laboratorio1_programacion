/*
 * calculos.h
 *
 *  Created on: 27 oct. 2022
 *      Author: Ali Ansidey
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

/**
* @brief	calcula el promedio de los numeros pasados por parametros
* @param	salarios suma de los numeros para calcular el promedio
* @param	cantidad cantidad de elementos para realizar el promedio
* @param	promedio puntero al promedio que se calcula en la funcion
* @return	Retorna 0 (EXITO) si se obtiene el promedio y -1 (ERROR) si no se obtuvo resultado
*/
int calcularPromedio(float salarios,int cantidad,float* promedio);


/**
* @brief	calcula el porcentaje de los numeros pasados por parametros
* @param	numero1 elemtento del cual se calcula el porcentaje
* @param	numero2 cantidad de elementos totales para calcular el porcentaje
* @param	porcentaje puntero al porcentaje que se calcula en la funcion
* @return	Retorna 0 (EXITO) si se obtiene el porcentaje y -1 (ERROR) si no se obtuvo resultado
*/
int porcentajePorTipo(int numero1, int numero2, float* porcentaje);

#endif /* CALCULOS_H_ */
