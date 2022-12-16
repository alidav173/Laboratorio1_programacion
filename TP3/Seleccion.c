

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seleccion.h"
#define ERROR -1


Seleccion* selec_new(){
	Seleccion* pSeleccion;
		pSeleccion = (Seleccion*) malloc(sizeof(Seleccion));
	return pSeleccion;
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr){
	Seleccion* pSeleccion;
	pSeleccion = selec_new();

	if(pSeleccion != NULL){
		if(idStr != NULL && paisStr != NULL && confederacionStr != NULL && convocadosStr != NULL){
			selec_setId(pSeleccion,atoi(idStr));
			selec_setPais(pSeleccion,paisStr);
			selec_setConfederacion(pSeleccion,confederacionStr);
			selec_setConvocados(pSeleccion,atoi(convocadosStr));
		}
	}
	return pSeleccion;
}

//funcion modificada en los parametros
void selec_delete(Seleccion* this){
	if(this != NULL){
		free(this);
	}
}

int selec_getId(Seleccion* this,int* id){
	int retorno = ERROR;
	if(this != NULL && id != NULL){
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int selec_getPais(Seleccion* this,char* pais){
	int retorno = ERROR;
	if(this != NULL && pais != NULL){
		strcpy(pais,this->pais);
		retorno =0;
	}
	return retorno;
}

int selec_getConfederacion(Seleccion* this,char* confederacion){
	int retorno = ERROR;
	if(this != NULL && confederacion != NULL){
		strcpy(confederacion, this->confederacion);
		retorno =0;
	}
	return retorno;
}

int selec_getConvocados(Seleccion* this,int* convocados){
	int retorno = ERROR;
	if(this != NULL && convocados != NULL){
		*convocados = this->convocados;
		retorno =0;
	}
	return retorno;
}

int selec_setConvocados(Seleccion* this,int convocados){
	int retorno = ERROR;
	if(this != NULL){
		this->convocados = convocados;
		retorno = 0;
	}
	return retorno;
}

int mostrarInfoSeleccion(Seleccion* this){
	int retorno = ERROR;
	char pais[30];
	char confederacion[30];
	int id,convocados;
	if(this != NULL){
		selec_getId(this,&id);
		selec_getPais(this,pais);
		selec_getConfederacion(this,confederacion);
		 selec_getConvocados(this,&convocados);
		 printf("|%*d|%*s|%*s|%*d|\n",10,id,30,pais,30,confederacion,12,convocados);
		retorno =0;
	}
	return retorno;
}


int seleccion_sortConfederacion(void* this, void* this2){
	int retorno = 0;
	char confederacion1[100];
	char confederacion2[100];
		if(selec_getConfederacion((Seleccion*) this,confederacion1) == 0 && selec_getConfederacion((Seleccion*) this2,confederacion2) == 0){
			if(strcmp(confederacion1,confederacion2)>0){
				retorno = 1;
			}
			 if(strcmp(confederacion1,confederacion2)<0){
				retorno = -1;
			}
		}
	return retorno;
}


//SETTERS UTILIZADOS PARA PODER UTILIZAR EL CONSTRUCTOR PARAMETRIZADO

int selec_setId(Seleccion* this,int id){
	int retorno = ERROR;
	if(this != NULL){
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int selec_setPais(Seleccion* this,char* pais){
	int retorno = ERROR;
	if(this != NULL && pais != NULL){
		strcpy(this->pais,pais);
		retorno = 0;
	}
	return retorno;
}

int selec_setConfederacion(Seleccion* this,char* confederacion){
	int retorno = ERROR;
	if(this != NULL && confederacion != NULL){
		strcpy(this->confederacion, confederacion);
		retorno = 0;
	}
	return retorno;
}



