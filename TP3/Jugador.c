
/*
 * jugador.h
 *
 *  Created on: 03 Nov. 2022
 *      Author: Ali Ansidey
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugador.h"
#include "Seleccion.h"

#define ERROR -1

Jugador* jug_new(){
	Jugador* pJugador;

	pJugador = (Jugador*) malloc(sizeof(Jugador));

	return pJugador;
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr){
	Jugador* pJugador;

	pJugador = jug_new();

	if(pJugador != NULL){
		if(idStr != NULL && nombreCompletoStr != NULL && edadStr != NULL && posicionStr != NULL && nacionalidadStr !=NULL && idSelccionStr != NULL){
			jug_setId(pJugador,atoi(idStr));
			jug_setNombreCompleto(pJugador,nombreCompletoStr);
			jug_setEdad(pJugador,atoi(edadStr));
			jug_setPosicion(pJugador,posicionStr);
			jug_setNacionalidad(pJugador,nacionalidadStr);
			jug_setIdSeleccion(pJugador,atoi(idSelccionStr));
		}
	}
	return pJugador;
}

//funcion modificada en los parametros
void jug_delete(Jugador* this){
	if(this != NULL){
		free(this);
	}
}

int jug_setId(Jugador* this,int id){
	int retorno = ERROR;
	if(this != NULL){
		this->id = id;
		retorno = 0;
	}
	return retorno;
}

int jug_getId(Jugador* this,int* id){
	int retorno = ERROR;
	if(this != NULL){
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto){
	int retorno = ERROR;
	if(this != NULL){
		strcpy(this->nombreCompleto, nombreCompleto);
		retorno = 0;
	}
	return retorno;
}

int jug_getNombreCompleto(Jugador* this,char* nombreCompleto){
	int retorno = ERROR;
	if(this != NULL){
		strcpy(nombreCompleto, this->nombreCompleto);
		retorno = 0;
	}
	return retorno;
}

int jug_setPosicion(Jugador* this,char* posicion){
	int retorno = ERROR;
	if(this != NULL){
		strcpy(this->posicion, posicion);
		retorno = 0;
	}
	return retorno;
}

int jug_getPosicion(Jugador* this,char* posicion){
	int retorno = ERROR;
	if(this != NULL){
		strcpy(posicion,this->posicion);
		retorno = 0;
	}
	return retorno;
}

int jug_setNacionalidad(Jugador* this,char* nacionalidad){
	int retorno = ERROR;
	if(this != NULL){
		strcpy(this->nacionalidad, nacionalidad);
		retorno = 0;
	}
	return retorno;
}

int jug_getNacionalidad(Jugador* this,char* nacionalidad){
	int retorno = ERROR;
	if(this != NULL ){
		strcpy(nacionalidad,this->nacionalidad);
		retorno = 0;
	}
	return retorno;
}

int jug_setEdad(Jugador* this,int edad){
	int retorno = ERROR;
	if(this != NULL){
		this->edad = edad;
		retorno = 0;
	}
	return retorno;
}

int jug_getEdad(Jugador* this,int* edad){
	int retorno = ERROR;
	if(this != NULL){
		*edad = this->edad;
		retorno = 0;
	}
	return retorno;
}

int jug_setIdSeleccion(Jugador* this,int idSeleccion){
	int retorno = ERROR;
	if(this != NULL){
		this->idSeleccion = idSeleccion;
		retorno = 0;
	}
	return retorno;
}

int jug_getSIdSeleccion(Jugador* this,int* idSeleccion){
	int retorno = ERROR;
	if(this != NULL){
		*idSeleccion = this->idSeleccion;
		retorno = 0;
	}
	return retorno;
}


//otras funciones agregadas

int mostrarInfoJugador(Jugador* this){
	int retorno = ERROR;
	char nombre[100];
	char posicion[30];
	char nacionalidad[30];
	int id, idSeleccion, edad;

	if(this != NULL){
		 jug_getId(this,&id);
		 jug_getNombreCompleto(this,nombre);
		 jug_getEdad(this,&edad);
		 jug_getPosicion(this,posicion);
		 jug_getNacionalidad(this,nacionalidad);
		 jug_getSIdSeleccion(this,&idSeleccion);
		 printf("|%*d|%*s|%*d|%*s|%*s|%*d|\n",10,id,30,nombre,10,edad,30,posicion,30,nacionalidad,20,idSeleccion);
		retorno =0;
	}
	return retorno;
}

int mostrarInfoJugadorYseleccion(Jugador* this, char* paisSeleccion){
	int retorno = ERROR;
	char nombre[100];
	char posicion[30];
	char nacionalidad[30];
	char pais[30];
	int id,edad,idSeleccion;

	if(this != NULL && paisSeleccion != NULL){
		jug_getId(this,&id);
		jug_getNombreCompleto(this,nombre);
		jug_getEdad(this,&edad);
		jug_getPosicion(this,posicion);
		jug_getNacionalidad(this,nacionalidad);
		jug_getSIdSeleccion(this,&idSeleccion);
		strcpy(pais,paisSeleccion);

		printf("|%*d|%*s|%*d|%*s|%*s|%*s|\n",10,id,30,nombre,10,edad,30,posicion,30,nacionalidad,30,pais);
		retorno =0;
		}

		return retorno;
	}



int jugador_sortNombre(void* this, void* this2){
	int retorno = 0;
	char nombre1[100];
	char nombre2[100];
		//
		if(jug_getNombreCompleto((Jugador*) this,nombre1) == 0 && jug_getNombreCompleto((Jugador*) this2,nombre2) == 0){
			if(stricmp(nombre1,nombre2)>0){
				retorno = 1;
			}
			if(stricmp(nombre1,nombre2)<0){
				retorno = -1;
			}
		}


	return retorno;
}


int jugador_sortNacionalidad(void* this, void* this2){
	int retorno = 0;
	char nacionalidad1[100];
	char nacionalidad2[100];
		//
		if(jug_getNacionalidad((Jugador*) this,nacionalidad1) == 0 && jug_getNacionalidad((Jugador*) this2,nacionalidad2) == 0){
			if(strcmp(nacionalidad1,nacionalidad2)>0){
				retorno = 1;
			}
		    if(strcmp(nacionalidad1,nacionalidad2)<0){
				retorno = -1;
			}
		}


	return retorno;
}

int jugador_sortEdad(void* this, void* this2){
	int retorno = 0;
	int edad1;
	int edad2;
		if(jug_getEdad((Jugador*) this,&edad1) == 0 && jug_getEdad((Jugador*) this2,&edad2) == 0){
			if(edad1 > edad2){
				retorno = 1;
			}
			if(edad1 < edad2){
				retorno = -1;
			}
		}


	return retorno;
}

