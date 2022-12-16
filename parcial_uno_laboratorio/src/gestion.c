/*
 * gestion.c
 *
 *  Created on: 8 oct. 2022
 *      Author: Ali Ansidey
 */
#include "gestion.h"



int mostrarRecursoSegunTipo(recurso* listadoRecursos, int tamanio,tipo* listadoTipoRecursos,int tamanio_Tipo){
	int retorno = ERROR;
	int i,tipoId;
	if(listadoRecursos != NULL && listadoTipoRecursos != NULL && tamanio >0 && tamanio_Tipo >0){;
	utn_getNumero(&tipoId,"Ingrese el ID del tipo [1001 - LOCUCION / 1002 - ANIMACION / 1003 - ILUMINACION / 1004- DJ]\n",
					"Reingrese el ID del tipo [1001 - LOCUCION / 1002 - ANIMACION / 1003 - ILUMINACION / 1004- DJ]\n",1001,1004,3);
	for(i=0; i< tamanio; i++){
		if((*(listadoRecursos+i)).isEmpty != VACIO){
			mostrarRecursoPorTipo(*(listadoRecursos+i),listadoTipoRecursos,tamanio_Tipo,tipoId);
			}
		}
	retorno = 0;
}
	return retorno;
}



int mostrarEventoSegunFecha(evento* listadoEventos, int tamanioEvento){
	int retorno = ERROR;
	fecha fechaAbuscar;

	int i;
	if(listadoEventos !=NULL && tamanioEvento >0){
		ingresoFecha(&fechaAbuscar);
		for(i = 0; i<tamanioEvento; i++){
			if((*(listadoEventos+i)).isEmpty == LLENO){
				if(fechaAbuscar.dia == (*(listadoEventos+i)).fecha.dia && fechaAbuscar.mes == (*(listadoEventos+i)).fecha.mes &&
						fechaAbuscar.anio == (*(listadoEventos+i)).fecha.anio){
							mostrarEvento(*(listadoEventos+i));
							retorno = 0;
				}
			}
		}
	}
	return retorno;
}


int calcularMonto(int cantidad, float precioPorhora, float* resultado){
	int retorno = ERROR;
	if(resultado != NULL && cantidad >0){
		*resultado = cantidad * precioPorhora;
		retorno = 0;
	}
	return retorno;
}


int mostrarImporteTotalPorRecurso(evento* listadoEventos, int tamanioEvento,recurso* listadoRecursos, int tamanioRecurso, tipo* listadoTipoRecursos, int tamanio_Tipo){
	int retorno = ERROR;
	int flag = ERROR;
	int recursoID, i, indice;
	int cantidadHorasPorRecurso = 0;
	float precioPorhora = 0;
	float resultado =0;

	if(listadoEventos != NULL && listadoRecursos != NULL && listadoTipoRecursos !=NULL  && tamanioEvento >0 && tamanioRecurso >0 && tamanio_Tipo >0){
		mostrarlistadoRecursos(listadoRecursos,tamanioRecurso,listadoTipoRecursos,tamanio_Tipo);
		utn_getNumero(&recursoID,"Ingrese el ID del recurso\n",
							"Reingrese el ID del recurso\n",1,INT_MAX,3);
		indice = buscarRecursoPorId(listadoRecursos,tamanioRecurso,recursoID);
		while(indice == ERROR){
			mostrarlistadoRecursos(listadoRecursos,tamanioRecurso,listadoTipoRecursos,tamanio_Tipo);
					utn_getNumero(&recursoID,"Ingrese el ID del recurso\n",
										"Reingrese el ID del recurso\n",1,INT_MAX,3);
					indice = buscarRecursoPorId(listadoRecursos,tamanioRecurso,recursoID);
		}

		precioPorhora = (*(listadoRecursos+indice)).precioPorHora;
	for(i =0; i< tamanioEvento; i++){
		if((*(listadoEventos+i)).recursoId == recursoID){
			cantidadHorasPorRecurso += (*(listadoEventos+i)).cantidad;
		}
	}
	flag = calcularMonto(cantidadHorasPorRecurso,precioPorhora,&resultado);
	if(flag != ERROR){
		printf("\nEl importe total del recurso %s, con ID: %d, es: $%.2f\n",(*(listadoRecursos+indice)).descripcion,(*(listadoRecursos+indice)).idRecurso, resultado);
		retorno = 0;
	}
	}
	return retorno;
}




int mostrarImporteTotalPorTipoyFecha(evento* listadoEventos, int tamanioEvento,recurso* listadoRecursos, int tamanioRecurso, tipo* listadoTipoRecursos, int tamanio_Tipo){
	int retorno = ERROR;
	int tipoId, i,j;
	float resultado;
	float montoTotal=0;
	char fechaString[10];
	char tipoString[31];
	fecha fechaAbuscar;
	if(listadoEventos != NULL && listadoRecursos != NULL && listadoTipoRecursos !=NULL  && tamanioEvento >0 && tamanioRecurso >0 && tamanio_Tipo >0){
		ingresoFecha(&fechaAbuscar);
		conversionFechaString(fechaAbuscar,fechaString);
		utn_getNumero(&tipoId,"Ingrese el ID del tipo [1001 - LOCUCION / 1002 - ANIMACION / 1003 - ILUMINACION / 1004- DJ]\n",
									"Reingrese el ID del tipo [1001 - LOCUCION / 1002 - ANIMACION / 1003 - ILUMINACION / 1004- DJ]\n",1001,1004,3);
		for(i = 0; i< tamanioEvento; i++){
			if((*(listadoEventos+i)).fecha.dia == fechaAbuscar.dia && (*(listadoEventos+i)).fecha.mes == fechaAbuscar.mes &&
					(*(listadoEventos+i)).fecha.anio == fechaAbuscar.anio){
					for(j = 0; j < tamanioRecurso; j++){
						if((*(listadoEventos+i)).recursoId == (*(listadoRecursos+j)).idRecurso &&
								(*(listadoRecursos+j)).tipoId == tipoId){
							calcularMonto((*(listadoEventos+i)).cantidad,(*(listadoRecursos+j)).precioPorHora ,&resultado);
							montoTotal+=resultado;
							retorno = 0;
						}
				}
			}
		}
		mostrarTipoString(listadoTipoRecursos,tamanio_Tipo,tipoId,tipoString);
	printf("\nEl importe total de los eventos en la fecha: %s, y el tipo:  %s, es: $%.2f\n",fechaString,tipoString,montoTotal);
}
return retorno;

}

//Ultima funcion agregada del tp
int mostrarEventosSegunCliente(evento* listadoEventos, int tamanioEvento, cliente* clientes, int tamanioCliente){
	int retorno = ERROR;
	int i,idCliente;
	int flag = ERROR;
	if(listadoEventos !=NULL && clientes != NULL && tamanioEvento >0 && tamanioCliente >0){
		listarClientes(clientes,tamanioCliente);
		utn_getNumero(&idCliente,"Ingrese el id del cliente: \n",
										"Reingrese el id del cliente: \n",1,4,3);
				flag = buscarClientePorId(clientes,tamanioCliente,idCliente);
				while(flag == ERROR){
							utn_getNumero(&idCliente,"Ingrese el id del cliente: \n",
											"Reingrese el id del cliente: \n",1,4,3);
							flag = buscarClientePorId(clientes,tamanioCliente,idCliente);
						}
		for(i = 0; i<tamanioEvento; i++){
			if((*(listadoEventos+i)).isEmpty == LLENO){
				if(idCliente == (*(listadoEventos+i)).idCliente){
					mostrarEventoSegunCliente((*(listadoEventos+i)),clientes,tamanioCliente);
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

