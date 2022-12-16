/*
 ============================================================================
 Name        : TP1.c
 Author      : Ali Ansidey
 Version     :1.0
 Copyright   : Todos los derechos reservados
 Description :Trabajo practico 1 Laboratorio de programacion 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "funciones.h"
#include "informes.h"

#define SALIDA 5
#define TAM_MAX 22 //tamanio maximo de array Camisetas

int main(void) {
	setbuf(stdout, NULL);

	//costos
	float costoHospedaje =0;
	float costoComida = 0;
	float costoTransporte = 0;
	float costoMantenimiento = 0;
	float recargoCostoMantenimiento = 0;
	float costoTotal = 0;

	//cantidad de jugadores por posicion
	int cantArqueros= 0;
	int cantDefensores = 0;
	int cantMedios = 0;
	int cantDelanteros = 0;
	int cantidadJugadores =0;
	int camisetas[TAM_MAX];

	//cantidad de jugadores por confederacion
	int conferacionAFC =0;
	int conferacionCAF =0;
	int conferacionCONCACAF =0;
	int conferacionCONMEBOL =0;
	int conferacionUEFA =0;
	int conferacionOFC =0;

	//promedio de jugadores por confederacion
	float promJugAFC = 0;
	float promJugCAF = 0;
	float promJugCONCACAF = 0;
	float promJugCONMEBOL = 0;
	float promJugUEFA = 0;
	float promJugOFC = 0;

	int flag1 =ERROR;
	int flag2 = ERROR;
	int flag3 =ERROR;
	int opcionMenu;
	int mayoriaJugadoresEuropa = ERROR;
	int indexArrayCamisetas=0;

	mostrarMenuPrincipal(&costoHospedaje,&costoComida, &costoTransporte,
			&cantArqueros, &cantDefensores, &cantMedios, &cantDelanteros);
	utn_getNumero(&opcionMenu,"Ingrese una opcion: \n","Reingrese una opcion: \n",1,5,3);

	while(opcionMenu != SALIDA){
		switch(opcionMenu){
		case 1:// ingreso los costos de mantenimiento
			flag1 = ingresoCostosMantenimiento(&costoHospedaje,&costoComida,&costoTransporte);
			break;
		case 2:// cargo los datos de los jugadores
			if(flag1 !=ERROR){
				flag2 = cargaJugadores(&cantidadJugadores,&cantArqueros,&cantDefensores,&cantMedios,&cantDelanteros,
						&conferacionAFC,&conferacionCAF,&conferacionCONCACAF,&conferacionCONMEBOL,&conferacionUEFA,&conferacionOFC,
						camisetas,&indexArrayCamisetas,TAM_MAX);
			}
			else{
				puts("No se pueden cargar los jugadores sin cargar los costos de mantenimieto \n");
			}
			break;
		case 3://Realizar todos los calculos, sin imprimirlos
			promedioJugadoresPorConfederacion(&conferacionAFC,&cantidadJugadores,&promJugAFC);
			promedioJugadoresPorConfederacion(&conferacionCAF,&cantidadJugadores,&promJugCAF);
			promedioJugadoresPorConfederacion(&conferacionCONCACAF,&cantidadJugadores,&promJugCONCACAF);
			promedioJugadoresPorConfederacion(&conferacionCONMEBOL,&cantidadJugadores,&promJugCONMEBOL);
			promedioJugadoresPorConfederacion(&conferacionUEFA,&cantidadJugadores,&promJugUEFA);
			promedioJugadoresPorConfederacion(&conferacionOFC,&cantidadJugadores,&promJugOFC);

			mayoriaJugadoresEuropa = sonMayoriaJugadoresEnEuropa(&conferacionUEFA,&conferacionAFC,&conferacionCAF,
					&conferacionCONCACAF,conferacionCONMEBOL,&conferacionOFC);

			flag3=  calculoCostosMantenimiento(&costoHospedaje,&costoComida,&costoTransporte,&costoMantenimiento,&recargoCostoMantenimiento,
					&costoTotal,&mayoriaJugadoresEuropa);

			break;
		case 4://imprimir todos los calculos
			mostrarPorcentajesPorConf(&promJugAFC,&promJugCAF,&promJugCONCACAF,&promJugCONMEBOL,
					&promJugUEFA,&promJugOFC);

			if(flag3 != ERROR){
				mostrarCostos(&costoMantenimiento,&recargoCostoMantenimiento,&costoTotal);
			}
			break;
		case 5:
			break;
		}
		mostrarMenuPrincipal(&costoHospedaje,&costoComida, &costoTransporte,
						&cantArqueros, &cantDefensores, &cantMedios, &cantDelanteros);
		utn_getNumero(&opcionMenu,"Ingrese una opcion: \n","Reingrese una opcion: \n",1,5,3);
	}
	puts("\n Ha salido del sistema\n");
	return 0;
}
