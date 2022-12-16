#include "LinkedList.h"
#include "Seleccion.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;


/** \brief Constructor no parametrizado del elemento Jugador
 *
 * \param void
 * \return puntero a una estructura tipo Jugador
 */
Jugador* jug_new();


/** \brief Constructor  parametrizado del elemento Jugador
 *
 * \param char* idStr
 * \param char* nombreCompletoStr
 * \param char* edadStr
 * \param char* posicionStr
 * \param char* nacionalidadStr
 * \param char* idSelccionStr
 * \return puntero a una estructura tipo Jugador
 */
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);


/** \brief Elimina a un elemento tipo Jugador
 *
 * \param Jugador* this
 * \return void
 */
void jug_delete(Jugador*  this);


/** \brief setea el valor del campo id de un jugador
 *
 * \param Seleccion* this
 * \param int id
 * \return -1 si no pudo setear, y 0 si pudo (exito)
 */
int jug_setId(Jugador* this,int id);


/** \brief retorna el valor del campo Id de un jugador
 *
 * \param Seleccion* this
 * \param int* id
 * \return -1 si no pudo obtener el id, y 0 si pudo (exito)
 */
int jug_getId(Jugador* this,int* id);


/** \brief setea el valor del campo nombreCompleto de un jugador
 *
 * \param Seleccion* this
 * \param char* nombreCompleto
 * \return -1 si no pudo setear, y 0 si pudo (exito)
 */
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);

/** \brief retorna el valor del campo nombreCompleto de un jugador
 *
 * \param Seleccion* this
 * \param char* nombreCompleto
 * \return -1 si no pudo obtener el nombre, y 0 si pudo (exito)
 */
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);


/** \brief setea el valor del campo posicion de un jugador
 *
 * \param Seleccion* this
 * \param char* posicion
 * \return -1 si no pudo setear, y 0 si pudo (exito)
 */
int jug_setPosicion(Jugador* this,char* posicion);

/** \brief retorna el valor del campo posicion de un jugador
 *
 * \param Seleccion* this
 * \param char* posicion
 * \return -1 si no pudo obtener la posicion, y 0 si pudo (exito)
 */
int jug_getPosicion(Jugador* this,char* posicion);


/** \brief setea el valor del campo nacionalidad de un jugador
 *
 * \param Seleccion* this
 * \param char* nacionalidad
 * \return -1 si no pudo setear, y 0 si pudo (exito)
 */
int jug_setNacionalidad(Jugador* this,char* nacionalidad);


/** \brief retorna el valor del nacionalidad de un jugador
 *
 * \param Seleccion* this
 * \param char* nacionalidad
 * \return -1 si no pudo obtener la nacionalidad, y 0 si pudo (exito)
 */
int jug_getNacionalidad(Jugador* this,char* nacionalidad);


/** \brief setea el valor del campo edad de un jugador
 *
 * \param Seleccion* this
 * \paramint edad
 * \return -1 si no pudo setear, y 0 si pudo (exito)
 */
int jug_setEdad(Jugador* this,int edad);


/** \brief retorna el valor de la edad de un jugador
 *
 * \param Seleccion* this
 * \param int* edad
 * \return -1 si no pudo obtener la edad, y 0 si pudo (exito)
 */
int jug_getEdad(Jugador* this,int* edad);


/** \brief setea el valor del IdSeleccion  de un jugador
 *
 * \param Seleccion* this
 * \param int idSeleccion
 * \return -1 si no pudo setear, y 0 si pudo (exito)
 */
int jug_setIdSeleccion(Jugador* this,int idSeleccion);


/** \brief retorna el valor del id de la seleccion de un jugador
 *
 * \param Seleccion* this
 * \param int* idSeleccion
 * \return -1 si no pudo obtener el id de la seleccion, y 0 si pudo (exito)
 */
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);


//otras funciones agregadas

/** \brief Muestra todos los valores de los campos de un jugador
 *
 * \param Jugador* this
 * \return -1 si no pudo mostrar, y 0 si pudo (exito)
 */
int mostrarInfoJugador(Jugador* this);


/** \brief Ordena los valores de un jugador segun su nombre
 *
 * \param void* this
 * \param void* this2
 * \return -1 si this < this2,1 si this > this2 y 0 si son iguales
 */
int jugador_sortNombre(void* this, void* this2);


/** \brief Ordena los valores de un jugador segun su nacionalidad
 *
 * \param void* this
 * \param void* this2
 * \return -1 si this < this2,1 si this > this2 y 0 si son iguales
 */
int jugador_sortNacionalidad(void* this, void* this2);


/** \brief Ordena los valores de un jugador segun su edad
 *
 * \param void* this
 * \param void* this2
 * \return -1 si this < this2,1 si this > this2 y 0 si son iguales
 */
int jugador_sortEdad(void* this, void* this2);


/** \brief Muestra todos los valores de los campos de un jugador
 * incluyendo la seleccion.
 *
 * \param Seleccion* this
 * \param char* paisSeleccion
 * \return -1 si no pudo mostrar, y 0 si pudo (exito)
 */
int mostrarInfoJugadorYseleccion(Jugador* this, char* paisSeleccion);

#endif // jug_H_INCLUDED
