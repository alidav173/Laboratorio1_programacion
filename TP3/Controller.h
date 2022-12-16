
#include "Seleccion.h"
#include "Jugador.h"

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);

/** \brief Alta de jugadores
 *
 * \param pArrayListJugador LinkedList*
 * \return 0 si puedo agregar al jugador, y -1 sino se puede agregar
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador);

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return 0 si puedo editar al jugador, y -1 sino se puede editar
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador);

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return 0 si puedo eliminar al jugador, y -1 sino se puede eliminar
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador);

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return 0 si puedo listar los jugadores, y -1 sino se puede listar
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador);

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return 0 si puede ordenar los jugadores, y -1 si no se pudo ordenar
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador);

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);

/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);

/** \brief Modificar datos de la seleccion
 *
 * \param path char*
 * \param LinkedList* pArrayListSeleccion
 * \return 0 si puedo editar la seleccion, y -1 sino se puede editar
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);

/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return 0 si puedo listar la seleccion, y -1 sino se puede listar
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return 0 si puedo ordenar la seleccion, y -1 sino se puede ordenar
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);

/** \busca un jugador por ID seleccionado por el usuario
 *
 * \param LinkedList* pArrayListJugador
 * \param int id
 * \return indice si lo pudo encortrar, sino devuelve -1
 *
 */
int buscarJugadorPorId(LinkedList* pArrayListSeleccion, int id);

/** \busca una seleccion por ID seleccionado por el usuario
 *
 * \param LinkedList* pArrayListJugador
 * \param int id
 * \return indice si lo pudo encortrar, sino devuelve -1
 *
 */
int buscarSeleccionPorId(LinkedList* pArrayListSeleccion, int id);

/** \Suma a un jugador a una seleccion de la lista de selecciones
 *
 * \param LinkedList* pArrayListJugador
 * \param LinkedList* pArrayListSeleccion
 * \return indice si lo pudo convocar, sino devuelve -1
 *
 */
int controller_convocarJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);

/** \brief Listar jugadores convocados
 *
 * \param LinkedList* pArrayListJugador
 * \param LinkedList* pArrayListSeleccion
 * \return indice si puede listar los convocados, sino devuelve -1
 *
 */
int controller_listarConvocados(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);

/** \Elimina  a un jugador a una seleccion de la lista de selecciones convocadas
 *
 * \param LinkedList* pArrayListJugador
 * \param LinkedList* pArrayListSeleccion
 * \return indice si lo pudo eliminar, sino devuelve -1
 *
 */
int controller_quitarDeLaSeleccion(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);

/** \brief Guarda los datos de los jugadores convocados dependiendo de la confederacion seleccionada
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \param pArrayListSeleccion LinkedList*
 * \param pArrayListJugadorConvConf LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresConvocadosPorConfederacion(char* path , LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion, LinkedList* pArrayListJugadorConvConf);


/** \brief Guarda los id de los jugadores en un archivo binario.
 *
 * \param path char*
 * \return int
 *
*/
int controller_cargarIdDesdeBinario(char* path,int* lastId);


/** \Guardar el ultimo id en un archivo binario
 * \param path char*
 * \param int* lastId
 * \return error si no puede guardar el ID, sino 0 (exito)
 *
 */
int controller_guardarIdModoBinario(char* path, int* lastId);




int controller_listarJugadores2(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion);

