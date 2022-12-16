/*
 * cliente.h
 *
 *  Created on: 23 nov. 2022
 *      Author: Ali Ansidey
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct{
	int idCliente;
	char nombre[30];
	char apellido[30];
	int telefono;

}cliente;




/**
* @brief	Muestra por pantalla, el listado de los clientes
* @param	array Puntero al array del tipo cliente
* @param	tamanio longitud del array del tipo cliente
* @return	Retorna 0 si todo ok, y ERROR (-1) si hay no puede mostrar
*/
int listarClientes(cliente* array, int tamanio);


/**
* @brief	Busca en el array de clientes, un cliente con el id pasado por parametros
* @param	array Puntero al array del tipo cliente
* @param	tamanio longitud del array del tipo cliente
*  @param	id buscado del cliente, del tipo INT
* @return	Retorna el indice del recurso (EXITO) y -1 (ERROR) si no hay algun recurso con el Id
*/
int buscarClientePorId(cliente* array, int tamanio,int id);

#endif /* CLIENTE_H_ */
