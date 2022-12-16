/*
 * recurso.c
 *
 *  Created on: 7 oct. 2022
 *      Author: Ali Ansidey
 */

#include "recurso.h"
#include "tipo.h"


int inicializarArrayRecurso(recurso* array, int tamanio){
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


int findFirstSpaceRecurso (recurso* array, int tamanio){
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


int altaRecurso(recurso* listaRecursos, int tamanio, int* idRecurso){
	int retorno = ERROR;
	int flag1 = ERROR;
	int flag2 = ERROR;
	int flag3 = ERROR;
	int indice = ERROR;
	char descripcion[21];
	float precioPorHora;
	int tipoId;
	if(listaRecursos != NULL && tamanio >0){
		indice = findFirstSpaceRecurso (listaRecursos,tamanio);
		flag1 = utn_getNombre(descripcion,21,"Ingrese la descripcion del recurso: \n","Reingrese la descripcion del recurso: \n",3);
		flag2 = utn_getNumeroFlotante(&precioPorHora,"Ingrese el precio del recurso: \n","Reingrese el precio del recurso: \n",1,FLT_MAX,3);
		flag3 = utn_getNumero(&tipoId,"Ingrese el ID del tipo [1001 - LOCUCION / 1002 - ANIMACION / 1003 - ILUMINACION / 1004- DJ]\n",
				"Reingrese el ID del tipo [1001 - LOCUCION / 1002 - ANIMACION / 1003 - ILUMINACION / 1004- DJ]\n",1001,1004,3);

		if(flag1 != ERROR && flag2 != ERROR && flag3 != ERROR && indice != ERROR){
			recurso recursoNuevo;
			recursoNuevo.idRecurso =*idRecurso;
			strcpy(recursoNuevo.descripcion,descripcion);
			recursoNuevo.precioPorHora = precioPorHora;
			recursoNuevo.tipoId =tipoId;
			recursoNuevo.isEmpty= LLENO;
			*(listaRecursos+indice) = recursoNuevo;
			(*idRecurso)++;
			retorno =0;
		}
		else{
			puts("\n No se pudo dar de alta al recurso!!!\n");
		}
	}
	return retorno;
}

void mostrarRecurso(recurso recursoAmostrar,tipo* tipoRecursos, int tamanio){
	char descripcionTipo[31];
	int i;
	if(tipoRecursos != NULL && tamanio >0){
		for(i =0; i < tamanio; i++){
			if(recursoAmostrar.tipoId == ((tipoRecursos+i))->idTipo){
				strcpy(descripcionTipo,(*(tipoRecursos+i)).descripcion);
				break;
			}
		}
		printf("Id: %d\t Descripcion:%s\t Precio por hora: $%.2f\t Tipo de recurso: %s\n",recursoAmostrar.idRecurso,
					recursoAmostrar.descripcion,recursoAmostrar.precioPorHora,descripcionTipo);
	}
}

void mostrarRecursoPorTipo(recurso recursoAmostrar,tipo* tipoRecursos, int tamanio, int idTipo){
	char descripcionTipo[31];
	int i;
	if(tipoRecursos != NULL && tamanio >0 && (recursoAmostrar.tipoId == idTipo)){
		for(i =0; i < tamanio; i++){
			if(recursoAmostrar.tipoId == (*(tipoRecursos+i)).idTipo){
				strcpy(descripcionTipo,(*(tipoRecursos+i)).descripcion);
				break;
			}
		}
		printf("Id: %d\t Descripcion:%s\t Precio por hora: $%.2f\t Tipo de recurso: %s\n",recursoAmostrar.idRecurso,
					recursoAmostrar.descripcion,recursoAmostrar.precioPorHora,descripcionTipo);
	}
}


int buscarRecursoPorId(recurso* array, int tamanio,int id){
	int retorno = ERROR;
	int i;
	if(array != NULL && tamanio >0 && id != ERROR){
		for(i =0; i < tamanio; i++){
			if((*(array+i)).idRecurso == id){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

void mostrarlistadoRecursos(recurso* array, int tamanio,tipo* listadoTipoRecursos,int tamanio_Tipo){
	int i;
	if(array != NULL && listadoTipoRecursos != NULL && tamanio >0 && tamanio_Tipo >0){;
		for(i=0; i< tamanio; i++){
			if((*(array+i)).isEmpty != VACIO){
				mostrarRecurso(*(array+i),listadoTipoRecursos,tamanio_Tipo);
			}
		}
	}

}



int modificarRecurso(recurso* array, int tamanio, tipo* listadoTipoRecursos, int tamanio_Tipo, int* IdRecurso){
	int retorno = ERROR;
	int indice = ERROR;
	int id;
	int opcion;
	float precioPorHora;
	char descripcion[21];
	if(array != NULL && tamanio >0){
		mostrarlistadoRecursos(array,tamanio,listadoTipoRecursos,tamanio_Tipo);
		utn_getNumero(&id,"Ingrese el id del recurso a modificar: \n","Reingrese el id del recurso a modificar: \n",1,*IdRecurso,3);
		indice = buscarRecursoPorId(array,tamanio,id);
		if(indice != ERROR){
			utn_getNumero(&opcion,"Ingrese la opcion a modificar [1 - precio por hora / 2- descripcion]: \n",
					"Ingrese la opcion a modificar [1 - precio por hora / 2- descripcion]: \n",1,2,3);
			switch(opcion){
			case 1:
				utn_getNumeroFlotante(&precioPorHora,"Ingrese el precio del recurso: \n",
						"Reingrese el precio del recurso: \n",1,FLT_MAX,3);
				(*(array+indice)).precioPorHora = precioPorHora;
				retorno =0;
				break;
			case 2:
				utn_getNombre(descripcion,21,"Ingrese la descripcion del recurso: \n","Reingrese la descripcion del recurso: \n",3);
				strcpy((*(array+indice)).descripcion,descripcion);
				retorno =0;
				break;
			}
		}
	}
	return retorno;
}

int darDeBajaRecurso(recurso* array, int tamanio, tipo* listadoTipoRecursos, int tamanio_Tipo, int* IdRecurso){
	int retorno = ERROR;
	int id, indice;
	char opcion;
	if(array != NULL && tamanio >0){
		mostrarlistadoRecursos(array,tamanio,listadoTipoRecursos,tamanio_Tipo);
		utn_getNumero(&id,"Ingrese el id del recurso a modificar: \n","Reingrese el id del recurso a modificar: \n",1,*IdRecurso,3);
		indice = buscarRecursoPorId(array,tamanio,id);
		if(indice != ERROR){
			utn_getNombre(&opcion,2,"Desea dar de baja al recurso [S/N]\n","Desea dar de baja al recurso [S/N]\n",3);
			strMayuscula(&opcion);
			while(opcion!= 'S' && opcion != 'N'){
				utn_getNombre(&opcion,2,"Desea dar de baja al recurso [S/N]\n","Desea dar de baja al recurso [S/N]\n",3);
				strMayuscula(&opcion);
			}
			if(opcion =='S'){
				(*(array+indice)).isEmpty = VACIO;
				printf("Se dio de baja al recurso con id %d",(*(array+indice)).idRecurso);
				retorno =0;
			}
		}
	}
	return retorno;
}

void ordenarRecursosPorDescripcion (recurso* array, int tamanio)
{
	if(array != NULL && tamanio >0){
		recurso auxiliarRecurso;
		  for (int i = 0; i < tamanio - 1; i++)
		    {
		      for (int j = i + 1; j < tamanio; j++)
			{
		    	  if (strcmp((*(array+i)).descripcion,(*(array+j)).descripcion) > 0)
			    {
		    		  auxiliarRecurso = *(array+i);
		    		  *(array+i) = *(array+j);
		    		  *(array+j) = auxiliarRecurso;
			    }
			}
		    }
	}
}

void ordenarRecursosPorTipo (recurso* array, int tamanio)
{

	if(array != NULL && tamanio >0){
		recurso auxiliarRecurso;
		  for (int i = 0; i < tamanio - 1; i++)
		    {
		      for (int j = i + 1; j < tamanio; j++)
			{
		    	  if ((*(array+i)).tipoId > (*(array+j)).tipoId )
			    {
		    		  auxiliarRecurso = *(array+i);
		    		  *(array+i) = *(array+j);
		    		  *(array+j) = auxiliarRecurso;
			    }
			}
		    }
	}

}


int listarRecursos(recurso* array, int tamanio, tipo* listadoTipoRecursos, int tamanio_Tipo){
	int retorno = ERROR;
	int opcion;
	if(array != NULL && listadoTipoRecursos != NULL && tamanio >0 && tamanio_Tipo >0){
		//ordeno por tipo
		utn_getNumero(&opcion,"Ingrese la opcion a modificar [1 - orden por tipo / 2- orden por descripcion]:\n",
				"Ingrese la opcion a modificar [1 - orden por tipo / 2- orden por descripcion]:\n",1,2,3);
		switch(opcion){
		case 1:
			ordenarRecursosPorTipo (array,tamanio);
			retorno = 0;
			break;
		case 2:
			ordenarRecursosPorDescripcion (array,tamanio);
			retorno =0;
			break;
		}
		mostrarlistadoRecursos(array,tamanio,listadoTipoRecursos,tamanio_Tipo);
	}
	return retorno;
}




