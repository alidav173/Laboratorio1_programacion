/*
 * funciones.c
 *
 *  Created on: 15 sept. 2022
 *      Author: Ali Ansidey
 */

#include "funciones.h"

int ingresoCostosMantenimiento(float *pCostoHospedaje,float *pCostoComida,float *pCostoTransporte){
	int retorno =-1;
	int flag1 =-1;
	int flag2 =-1;
	int flag3 =-1;
	if(pCostoHospedaje !=NULL && pCostoComida != NULL && pCostoTransporte != NULL){
		flag1= utn_getNumeroFlotante(pCostoHospedaje,"Ingrese el costo de hospedaje: \n","Reingrese el costo de hospedaje: \n",0,FLT_MAX,3);
		flag2= utn_getNumeroFlotante(pCostoComida,"Ingrese el costo de la comida: \n","Reingrese el costo de la comida: \n",0,FLT_MAX,3);
		flag3= utn_getNumeroFlotante(pCostoTransporte,"Ingrese el costo del transporte: \n","Reingrese el costo del transporte: \n",0,FLT_MAX,3);

		if(flag1!= ERROR && flag2!= ERROR && flag3!= ERROR){//si todos los costos se cargaron bien, retorno 0
			retorno =0;
		}
	}
	return retorno;
}



int cargaJugadores(int* cantidadJugadores,int* cantArqueros, int* cantDefensores, int* cantMedios, int* cantDelanteros,
		int* conferacionAFC, int* conferacionCAF, int* conferacionCONCACAF, int* conferacionCONMEBOL, int* conferacionUEFA, int* conferacionOFC,
		int* arrayCamisetas, int* indexArray, int tamanio){
	int retorno = ERROR;
	int flag1 = ERROR;
	int flag2 = ERROR;
	int flag3 = ERROR;
	int flag4 = ERROR;
	int camisetaAux;

	if(*cantidadJugadores<TAM_MAX){
		flag1 = utn_getNumero(&camisetaAux,"Ingrese el numero de camiseta [entre 1 y 99]:\n",
				"Reingrese el numero de camiseta [entre 1 y 99]: \n",1,99,3);
		flag2=cargaCamisetaJugador(camisetaAux,indexArray,arrayCamisetas, tamanio);
		if(flag2 != ERROR){
			flag3 = cargaPosicion(cantArqueros,cantDefensores,cantMedios,cantDelanteros);
		}
		if(flag3 != ERROR){
		    flag4 = cargaConfederacion(conferacionAFC,conferacionCAF,conferacionCONCACAF,conferacionCONMEBOL,conferacionUEFA,conferacionOFC);
		*cantidadJugadores+=1;
			retorno = 0;
		}
	}
	else{
	    puts("No se pueden cargar mas jugadores. \n");
	}
	return retorno;
}



int cargaPosicion(int* cantArqueros, int* cantDefensores, int* cantMedios, int* cantDelanteros){
	int retorno = ERROR;
	int flag1;
	int posicionAux;
	if(cantArqueros !=NULL && cantDefensores !=NULL && cantMedios != NULL && cantDelanteros != NULL){
		flag1 = utn_getNumero(&posicionAux,"Ingrese la posicion: [1- arquero/ 2- defensor/ 3- medio/ 4- delantero]\n",
				"Reigrese la posicion: [1- arquero/ 2- defensor/ 3- medio/ 4- delantero]\n",1,4,3);

		switch(posicionAux){
		case 1:
			if(*cantArqueros<2){
				*cantArqueros+=1;
				retorno =0;
			}
			else{
				puts("No se pueden cargar mas arqueros \n");
			}
			break;
		case 2:
			if(*cantDefensores<8){
				*cantDefensores+=1;
				retorno =0;
			}
			else{
				puts("No se pueden cargar mas defensores \n");
			}
			break;
		case 3:
			if(*cantMedios<8){
				*cantMedios+=1;
				retorno =0;
			}
			else{
				puts("No se pueden cargar mas mediocampistas \n");
			}
			break;
		case 4:
			if(*cantDelanteros<4){
				*cantDelanteros+=1;
				retorno =0;
			}
			else{
				puts("No se pueden cargar mas delanteros \n");
			}
			break;
		}
	}
	return retorno;
}



int cargaConfederacion(int* conferacionAFC, int* conferacionCAF, int* conferacionCONCACAF, int* conferacionCONMEBOL, int* conferacionUEFA, int* conferacionOFC){
	int retorno = ERROR;
	int flag1;
	int confederacionAux;
	if(conferacionAFC !=NULL && conferacionCAF !=NULL && conferacionCONCACAF != NULL && conferacionCONMEBOL != NULL && conferacionUEFA !=NULL && conferacionOFC !=NULL){
		flag1 = utn_getNumero(&confederacionAux,"Ingrese la confederacion: [1- AFC/ 2- CAF/ 3- CONCACAF/ 4- CONMEBOL / 5 - UEFA / 6 -OFC]\n",
				"Ingrese la confederacion: [1- AFC/ 2- CAF/ 3- CONCACAF/ 4- CONMEBOL / 5 - UEFA / 6 -OFC]\n",1,6,3);

		switch(confederacionAux){
		case 1:
			*conferacionAFC+=1;
			break;
		case 2:
			*conferacionCAF+=1;
			break;
		case 3:
			*conferacionCONCACAF+=1;
			break;
		case 4:
			*conferacionCONMEBOL+=1;
			break;
		case 5:
			*conferacionUEFA+=1;
			break;
		case 6:
			*conferacionOFC+=1;
			break;
		}
		retorno =0;
	}
	return retorno;
}



int cargaCamisetaJugador(int nroCamiseta,int* index, int* arrayCamisetas, int tamanio){
	int retorno = ERROR;
	int flag1 = ERROR;
	if(arrayCamisetas != NULL && index!= NULL && tamanio >0){
		if(*index < tamanio){
			for(int i =0;i <= *index; i++){
				if(arrayCamisetas[i] == nroCamiseta){
					flag1 = 1;
					printf("\nNo se puede repetir el numero de camiseta\n");
					break;
				}
				else{
					flag1 =0;
				}
			}
			if(flag1 != ERROR && flag1 != 1){
				arrayCamisetas[*index] = nroCamiseta;
				*index +=1;
				retorno = 0;
			}
		}
	}
	return retorno;
}

