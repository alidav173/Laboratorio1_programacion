

#include "calculos.h"


int promedioJugadoresPorConfederacion(int* cantJugConfederacion, int* cantidadJugadores, float* promedio){
    int retorno = ERROR;
    if(cantJugConfederacion != NULL &&  cantidadJugadores != NULL && promedio != NULL){
        if(*cantidadJugadores >= 0){
            *promedio = (float)*cantJugConfederacion / *cantidadJugadores;
            retorno = 0;
        }
    }
    return retorno;
}

int sonMayoriaJugadoresEnEuropa(int* cantUEFA, int* cantAFC, int* cantCAF, int* cantCONCACAF,
int* cantCONMEBOL, int* cantOFC){
    int retorno = ERROR;
    if(cantUEFA != NULL && cantAFC != NULL && cantCAF != NULL && cantCONCACAF != NULL && cantCONMEBOL != NULL
    && cantOFC != NULL){
      if(*cantUEFA > 0 && *cantUEFA > *cantAFC && *cantUEFA > *cantCAF && *cantUEFA > *cantCONCACAF && *cantUEFA > *cantCONMEBOL
      && *cantUEFA > *cantOFC){
          retorno = 0;
      }
    }
    return retorno;
}


int calculoCostosMantenimiento(float *costo1, float* costo2, float* costo3, float* costoMant,float* recargoEuropa,
		float* costoTotal, int* sonMayoriaJugadoresEnEuropa){
    int retorno = ERROR;
    float incMantenimiento = 0.35; //recargo del 35% en el costo por mayoria de jugadores en Europa
    if(costo1 != NULL && costo2 != NULL && costo3 != NULL && sonMayoriaJugadoresEnEuropa != NULL){
    	*costoMant = *costo1 + *costo2 + *costo3;

    	if(*sonMayoriaJugadoresEnEuropa == 0){
    		*recargoEuropa = incMantenimiento * (*costoMant);
            *costoTotal = *costoMant + *recargoEuropa;

        }
        else{//para cuando la mayoria de los jugadores no son de la UEFA
    		*costoTotal = *costoMant;
        }
        retorno = 0;
    }
    return retorno;
}


