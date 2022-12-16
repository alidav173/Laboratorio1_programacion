#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
}Seleccion;



/** \brief Constructor no parametrizado del elemento Seleccion
 *
 * \param void
 * \return puntero a una estructura tipo Seleccion
 */
Seleccion* selec_new();

/** \brief Constructor  parametrizado del elemento Seleccion
 *
 * \param char* idStr
 * \param char* paisStr
 * \param char* confederacionStr
 * \param char* convocadosStr
 * \return puntero a una estructura tipo Seleccion
 */
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);


/** \brief Elimina a un elemento tipo Seleccion
 *
 * \param Seleccion* this
 * \return void
 */
void selec_delete(Seleccion* this);

/** \brief retorna el valor del campo Id de una seleccion
 *
 * \param Seleccion* this
 * \param int* id
 * \return -1 si no pudo obtener el id, y 0 si pudo (exito)
 */
int selec_getId(Seleccion* this,int* id);

/** \brief retorna el valor del campo pais de una seleccion
 *
 * \param Seleccion* this
 * \param char* pais
 * \return -1 si no pudo obtener el pais, y 0 si pudo (exito)
 */
int selec_getPais(Seleccion* this,char* pais);

/** \brief retorna el valor del confederacion de una seleccion
 *
 * \param Seleccion* this
 * \param char* confederacion
 * \return -1 si no pudo obtener la confederacion, y 0 si pudo (exito)
 */
int selec_getConfederacion(Seleccion* this,char* confederacion);

/** \brief setea el valor del campo convocados de una seleccion
 *
 * \param Seleccion* this
 * \param int convocados
 * \return -1 si no pudo setear, y 0 si pudo (exito)
 */
int selec_setConvocados(Seleccion* this,int convocados);

/** \brief retorna el valor de los convocados de una seleccion
 *
 * \param Seleccion* this
 * \param int* convocados
 * \return -1 si no pudo obtener el valor de los convocados, y 0 si pudo (exito)
 */
int selec_getConvocados(Seleccion* this,int* convocados);


/** \brief setea el valor del campo Id de una seleccion
 *
 * \param Seleccion* this
 * \param int id
 * \return -1 si no pudo setear, y 0 si pudo (exito)
 */
int selec_setId(Seleccion* this,int id);

/** \brief setea el valor del campo pais de una seleccion
 *
 * \param Seleccion* this
 * \param char* pais
 * \return -1 si no pudo setear, y 0 si pudo (exito)
 */
int selec_setPais(Seleccion* this,char* pais);

/** \brief setea el valor del campo confederacion de una seleccion
 *
 * \param Seleccion* this
 * \param char* confederacion
 * \return -1 si no pudo setear, y 0 si pudo (exito)
 */
int selec_setConfederacion(Seleccion* this,char* confederacion);

/** \brief Muestra todos los valores de los campos de una seleccion
 *
 * \param Seleccion* this
 * \return -1 si no pudo mostrar, y 0 si pudo (exito)
 */
int mostrarInfoSeleccion(Seleccion* this);

/** \brief Ordena los valores de una seleccion segun su confederacion
 *
 * \param void* this
 * \param void* this2
 * \return -1 si this < this2,1 si this > this2 y 0 si son iguales
 */
int seleccion_sortConfederacion(void* this, void* this2);

#endif // selec_H_INCLUDED
