/*
 * evento.h
 *
 *  Created on: 7 oct. 2022
 *      Author: Ali Ansidey
 */

#ifndef EVENTO_H_
#define EVENTO_H_
#include <stdio.h>
#include "fecha.h"
#include "recurso.h"
#include "cliente.h"

#define VACIO 0
#define LLENO 1
#define ERROR -1
#define MAX_HORAS 1000000 //Criterio aleatorio


typedef struct{
	int idEvento;
	int recursoId;//clave foranea del Recurso
	int idCliente; //clave foranea del cliente
	int cantidad;
	char localidad[31];
	fecha fecha; //estructura del tipo fecha
	int isEmpty;

}evento;

/**
* @brief	Inicializa un array del tipo Evento
* @param	array Puntero al array del tipo evento
* @param	tamanio longitud del array del tipo evento
* @return	Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no pudo inicializar
*/
int inicializarArrayEvento(evento* array, int tamanio);

/**
* @brief	Busca el primer espacio libre del array evento
* @param	array Puntero al array del tipo evento
* @param	tamanio longitud del array del tipo evento
* @return	Retorna el indice si esta ok, sino retorna ERROR(-1)
*/
int findFirstSpaceEvento(evento* array, int tamanio);

/**
* @brief	Busca en el array de eventos, un evento con el id pasado por parametros
* @param	array Puntero al array del tipo evento
* @param	tamanio longitud del array del tipo evento
*  @param	id buscado del evento, del tipo INT
* @return	Retorna el indice del evento (EXITO) y -1 (ERROR) si no hay algun evento con el Id
*/
int buscarEventoPorId(evento* array, int tamanio,int id);

/**
* @brief	Muestra en una impresion por pantalla, los atributos del evento pasado por parametros.
* @param	eventoAmostrar Elemento del tipo evento
* @return	No retorna nada la funcion
*/
void mostrarEvento(evento eventoAmostrar);

/**
* @brief	Da de alta a un evento dentro del array del tipo evento
* @param	listaEventos Puntero al array del tipo evento
* @param	tamanio longitud del array del tipo evento
* @param	arrayRecurso Puntero al array del tipo recurso
* @param	tamanioRecurso longitud del array del tipo recurso
* @param	arrayTipo Puntero al array del tipo tipo
* @param	tamanioTipo longitud del array del tipo tipo
* @return	Retorna 0 (EXITO) si se da el alta y -1 (ERROR) si no
*/
int altaEvento(evento* listaEventos, int tamanio, recurso* arrayRecurso, int tamanioRecurso, tipo* arrayTipo, int tamanioTipo, cliente* clientes, int tamanioCliente, int* idEvento);

/**
* @brief	Muestra todos los eventos de un array del tipo evento por pantalla.
* @param	array Puntero al array del tipo evento
* @param	tamanio longitud del array del tipo evento
* @return	No retorna nada la funcion
*/
void mostrarlistadoEventos(evento* array, int tamanio);

int mostrarEventoSegunCliente(evento eventoAmostrar, cliente* clientes,int tamanioClientes);


#endif /* EVENTO_H_ */
