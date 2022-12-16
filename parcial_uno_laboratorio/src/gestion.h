/*
 * gestion.h
 *
 *  Created on: 8 oct. 2022
 *      Author: Ali Ansidey
 */

#ifndef GESTION_H_
#define GESTION_H_

#include "evento.h"
#include <stdio.h>
#include <limits.h>
#define VACIO 0
#define LLENO 1
#define ERROR -1

/**
* @brief	Muestra en una impresion por pantalla los recursos de un tipo determinado.
* @param	listadoRecursos Puntero al array del del tipo recurso
* @param	tamanio longitud del array del tipo recurso
* @param	listadoTipoRecursos Puntero al array del del tipo tipo
* @param	tamanio longitud del array del tipo tipo
* @return	Retorna 0 si muestra algun recurso (EXITO) y -1 (ERROR) si no muestra nada
*/
int mostrarRecursoSegunTipo(recurso* listadoRecursos, int tamanio,tipo* listadoTipoRecursos,int tamanio_Tipo);


/**
* @brief	Muestra los eventos segun una fecha seleccionada.
* @param	listadoEventos Puntero al array del del tipo evento
* @param	tamanioEvento longitud del array del tipo evento
* @return	Retorna 0 si muestra algun evento en la fecha (EXITO) y -1 (ERROR) si no muestra nada
*/
int mostrarEventoSegunFecha(evento* listadoEventos, int tamanioEvento);


/**
* @brief	Calcula el monto de dos parametros
* @param	cantidad es la cantidad de elementos
* @param	precioPorhora es el precio por hora del recurso
* @param	resultado puntero al resultado de la operacion
* @return	Retorna 0 si logra hacer el calculo (EXITO) y -1 (ERROR) si no logra hacerlo
*/
int calcularMonto(int cantidad, float precioPorhora, float* resultado);


/**
* @brief	Muestra por pantalla el importe total por un recurso determinado
* @param	listadoEventos es el puntero al array de Eventos
* @param	tamanioEvento es el tamanio del array eventos
* @param	listadoRecursos puntero al array de los recursos
* @param	tamanioRecurso es el tamanio del array recursos
* @param	listadoTipoRecursos puntero al array de los tipos de recursos
* @param	tamanio_Tipo es el tamanio del array tipos
* @return	Retorna 0 si logra hacer el calculo (EXITO) y -1 (ERROR) si no logra hacerlo
*/
int mostrarImporteTotalPorRecurso(evento* listadoEventos, int tamanioEvento,recurso* listadoRecursos, int tamanioRecurso, tipo* listadoTipoRecursos, int tamanio_Tipo);


/**
* @brief	Muestra por pantalla el importe total de un tipo y por la fecha seleccionada por el usuario
* @param	listadoEventos es el puntero al array de Eventos
* @param	tamanioEvento es el tamanio del array eventos
* @param	listadoRecursos puntero al array de los recursos
* @param	tamanioRecurso es el tamanio del array recursos
* @param	listadoTipoRecursos puntero al array de los tipos de recursos
* @param	tamanio_Tipo es el tamanio del array tipos
* @return	Retorna 0 si logra mostrar (EXITO) y -1 (ERROR) si no logra hacerlo
*/
int mostrarImporteTotalPorTipoyFecha(evento* listadoEventos, int tamanioEvento,recurso* listadoRecursos, int tamanioRecurso, tipo* listadoTipoRecursos, int tamanio_Tipo);


/**
* @brief	Muestra por pantalla los eventos de un cliente segun su ID
* @param	listadoEventos es el puntero al array de Eventos
* @param	tamanioEvento es el tamanio del array eventos
* @param	cliente* clientes puntero al array de los clientes
* @param	tamanioCliente es el tamanio del array clientes
* @return	Retorna 0 si logra mostrar (EXITO) y -1 (ERROR) si no logra hacerlo
*/
int mostrarEventosSegunCliente(evento* listadoEventos, int tamanioEvento, cliente* clientes, int tamanioCliente);

#endif /* GESTION_H_ */
