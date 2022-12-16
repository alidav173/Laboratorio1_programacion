/*
 * recurso.h
 *
 *  Created on: 7 oct. 2022
 *      Author: Ali Ansidey
 */

#ifndef RECURSO_H_
#define RECURSO_H_


#include "tipo.h"

typedef struct{
	int idRecurso;
	char descripcion[21];
	float precioPorHora;
	int tipoId;//Clave forenea del tipo
	int isEmpty;

}recurso;


/**
* @brief	Inicializa un array del tipo recurso
* @param	array Puntero al array del tipo recurso
* @param	tamanio longitud del array del tipo recurso
* @return	Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no pudo inicializar
*/
int inicializarArrayRecurso(recurso* array, int tamanio);

/**
* @brief	Busca el primer espacio libre del array recurso
* @param	array Puntero al array del tipo recurso
* @param	tamanio longitud del array del tipo evento
* @return	Retorna el indice si esta ok, sino retorna ERROR(-1)
*/
int findFirstSpaceRecurso (recurso* array, int tamanio);

/**
* @brief	Da de alta a un recurso dentro del array del tipo recurso
* @param	listaRecursos Puntero al array del tipo recurso
* @param	tamanio longitud del array del tipo recurso
* @return	Retorna 0 (EXITO) si se da el alta y -1 (ERROR) si no
*/
int altaRecurso(recurso* listaRecursos, int tamanio, int* idRecurso);

/**
* @brief	Muestra en una impresion por pantalla, los atributos del recurso pasado por parametros.
* @param	recursoAmostrar Elemento del tipo recurso
* @param	tipoRecursos puntero al array del tipo tipo
* @param	tamanio longitud del array del tipo tipo
* @return	No retorna nada la funcion
*/
void mostrarRecurso(recurso recursoAmostrar,tipo* tipoRecursos, int tamanio);

/**
* @brief	Muestra en una impresion por pantalla, los atributos del recurso segun su tipo de recurso.
* @param	recursoAmostrar Elemento del tipo recurso
* @param	tipoRecursos puntero al array del tipo tipo
* @param	tamanio longitud del array del tipo tipo
* @param	idTipo del elemento tipo a mostrar
* @return	No retorna nada la funcion
*/
void mostrarRecursoPorTipo(recurso recursoAmostrar,tipo* tipoRecursos, int tamanio, int idTipo);

/**
* @brief	Busca en el array de recursos, un recurso con el id pasado por parametros
* @param	array Puntero al array del tipo recurso
* @param	tamanio longitud del array del tipo recurso
*  @param	id buscado del recurso, del tipo INT
* @return	Retorna el indice del recurso (EXITO) y -1 (ERROR) si no hay algun recurso con el Id
*/
int buscarRecursoPorId(recurso* array, int tamanio,int id);

/**
* @brief	Muestra por pantalla, el listado de los recursos en el array recurso
* @param	array Puntero al array del tipo recurso
* @param	tamanio longitud del array del tipo recurso
* @param	listadoTipoRecursos Puntero al array del tipo tipo
* @param	tamanio_Tipo longitud del array del tipo tipo
* @return	No retorna valor alguno
*/
void mostrarlistadoRecursos(recurso* array, int tamanio,tipo* listadoTipoRecursos,int tamanio_Tipo);

/**
* @brief	Modifica un campo del elemento Recurso
* @param	array Puntero al array del tipo recurso
* @param	tamanio longitud del array del tipo recurso
* @param	listadoTipoRecursos Puntero al array del tipo tipo
* @param	tamanio_Tipo longitud del array del tipo tipo
* @return	Retorna 0 si se pudo modificar el campo del recurso (EXITO) y -1 (ERROR) si no se pudo modificar
*/
int modificarRecurso(recurso* array, int tamanio, tipo* listadoTipoRecursos, int tamanio_Tipo, int* IdRecurso);

/**
* @brief	Da una baja logica a un elemento del tipo Recurso (recurso.isEmpty = VACIO)
* @param	array Puntero al array del tipo recurso
* @param	tamanio longitud del array del tipo recurso
* @param	listadoTipoRecursos Puntero al array del tipo tipo
* @param	tamanio_Tipo longitud del array del tipo tipo
* @return	Retorna 0 si se pudo dar de baja logica el recurso (EXITO) y -1 (ERROR) si no se pudo dar de baja
*/
int darDeBajaRecurso(recurso* array, int tamanio, tipo* listadoTipoRecursos, int tamanio_Tipo, int* IdRecurso);

/**
* @brief	Ordena el array de recursos segun el campo descripcion
* @param	array Puntero al array del tipo recurso
* @param	tamanio longitud del array del tipo recurso
* @return	No retorna nada la funcion
*/
void ordenarRecursosPorDescripcion (recurso* array, int tamanio);

/**
* @brief	Ordena el array de recursos segun el campo tipo de recurso
* @param	array Puntero al array del tipo recurso
* @param	tamanio longitud del array del tipo recurso
* @return	No retorna nada la funcion
*/
void ordenarRecursosPorTipo (recurso* array, int tamanio);

/**
* @brief	Muestra los elementos del tipo recurso, ordenados segun el campo descricion
* o el campo tipo de producto
* @param	array Puntero al array del tipo recurso
* @param	tamanio longitud del array del tipo recurso
* @param	listadoTipoRecursos Puntero al array del tipo tipo
* @param	tamanio_Tipo longitud del array del tipo tipo
* @return	Retorna 0 si se pueden mostrar los elementos (EXITO) y -1 (ERROR) si no se pueden mostrar
*/
int listarRecursos(recurso* array, int tamanio, tipo* listadoTipoRecursos, int tamanio_Tipo);


#endif /* RECURSO_H_ */
