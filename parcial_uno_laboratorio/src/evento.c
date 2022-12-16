/*
 * evento.c
 *
 *  Created on: 7 oct. 2022
 *      Author: Ali Ansidey
 */

#include "evento.h"
#include "cliente.h"
#include "fecha.h"


int inicializarArrayEvento(evento* array, int tamanio){
    int retorno = ERROR;
    int i;
    if(array != NULL && tamanio >0){
        for(i = 0; i < tamanio; i++){
        	(*(array+i)).isEmpty = VACIO;
        }
        retorno = 0;
    }
    return retorno;
}


int findFirstSpaceEvento(evento* array, int tamanio){
	int index = ERROR;
	int i;
	for(i = 0; i < tamanio; i++){
		if((*(array+i)).isEmpty == VACIO){
			index = i;
			break;
		}
	}
return index;
}

int buscarEventoPorId(evento* array, int tamanio,int id){
	int retorno = ERROR;
	int i;
	if(array != NULL && tamanio >0 && id != ERROR){
		for(i =0; i < tamanio; i++){
			if((*(array+i)).idEvento == id){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

void mostrarEvento(evento eventoAmostrar){
	char fecha[10];
	conversionFechaString(eventoAmostrar.fecha,fecha);
		printf("Id evento: %d\t Id del recurso: %d\t Id del cliente: %d\t Cantidad de horas: %d\t Localidad: %s\t fecha: %s\n",eventoAmostrar.idEvento,
				eventoAmostrar.recursoId,eventoAmostrar.idCliente,eventoAmostrar.cantidad,eventoAmostrar.localidad,fecha);


}

int mostrarEventoSegunCliente(evento eventoAmostrar, cliente* clientes,int tamanioClientes){
		int retorno = ERROR;
		int i;
		char fecha[10];
		conversionFechaString(eventoAmostrar.fecha,fecha);
		if(clientes != NULL && tamanioClientes >0){
			for(i = 0; i < tamanioClientes;i++){
				if(eventoAmostrar.idCliente == (*(clientes+i)).idCliente){
					printf("Id evento: %d\t Id del recurso: %d\t Id del cliente: %d\t  Nombre Cliente:  %s\t Apellido Cliente:  %s\t Cantidad de horas: %d\t Localidad: %s\t fecha: %s\n",eventoAmostrar.idEvento,
							eventoAmostrar.recursoId,eventoAmostrar.idCliente,(*(clientes+i)).nombre,(*(clientes+i)).apellido,eventoAmostrar.cantidad,eventoAmostrar.localidad,fecha);
					retorno = 0;
					break;
				}
			}
		}
return retorno;
}


int altaEvento(evento* listaEventos, int tamanio, recurso* arrayRecurso, int tamanioRecurso, tipo* arrayTipo, int tamanioTipo, cliente* clientes, int tamanioCliente, int* idEvento){
	int retorno = ERROR;
	int flag1 = ERROR;
	int flag2 = ERROR;
	int flag3 = ERROR;
	int flag4 = ERROR;
	int indice, idRecurso, idCliente;
	char localidad[31];
	int cantidadhoras;

	if(listaEventos != NULL && arrayRecurso != NULL && tamanio >0 && tamanioRecurso >0){
		mostrarlistadoRecursos(arrayRecurso,tamanioRecurso,arrayTipo,tamanioTipo);
		indice = findFirstSpaceEvento (listaEventos,tamanio);
		utn_getNumero(&idRecurso,"Ingrese el id del recurso: \n",
						"Reingrese el id del recurso: \n",1,INT_MAX,3);
		flag1 = buscarRecursoPorId(arrayRecurso,tamanioRecurso,idRecurso);
		while(flag1 == ERROR){
			utn_getNumero(&idRecurso,"Ingrese el id del recurso: \n",
							"Reingrese el id del recurso: \n",1,INT_MAX,3);
			flag1 = buscarRecursoPorId(arrayRecurso,tamanioRecurso,idRecurso);
		}

		listarClientes(clientes, tamanioCliente);
		utn_getNumero(&idCliente,"Ingrese el id del cliente: \n",
								"Reingrese el id del cliente: \n",1,4,3);
				flag2 = buscarClientePorId(clientes,tamanioCliente,idCliente);
		while(flag2 == ERROR){
					utn_getNumero(&idCliente,"Ingrese el id del cliente: \n",
									"Reingrese el id del cliente: \n",1,4,3);
					flag2 = buscarClientePorId(clientes,tamanioCliente,idCliente);
				}
		flag3 = utn_getNumero(&cantidadhoras,"Ingrese la cantidad de horas: \n",
				"Reingrese la cantidad de horas: \n",1,MAX_HORAS,3);

		flag4 = utn_getNombre(localidad,31,"Ingrese la localidad: \n","Reingrese la localidad: \n",3);

		if(flag1 != ERROR && flag2 != ERROR && flag3 != ERROR && flag4 != ERROR && indice != ERROR){
			evento eventoNuevo;
			eventoNuevo.idEvento = *idEvento;
			eventoNuevo.recursoId = idRecurso;
			eventoNuevo.idCliente = idCliente;
			eventoNuevo.cantidad = cantidadhoras;
			strcpy(eventoNuevo.localidad,localidad);
			//ver esta linea
			ingresoFecha(&eventoNuevo.fecha);
			eventoNuevo.isEmpty = LLENO;
			*(listaEventos+indice) = eventoNuevo;
			mostrarEvento(eventoNuevo);
			retorno =0;
			(*idEvento)++;
		}
		else{
			puts("\nNo se pudo agregar el evento!!!!\n");
		}

	}
	return retorno;
}


void mostrarlistadoEventos(evento* array, int tamanio){
	int i;
	if(array != NULL && tamanio >0){;
		for(i=0; i< tamanio; i++){
			if( (*(array+i)).isEmpty != VACIO){
				mostrarEvento(*(array+i));
			}
		}
	}

}

