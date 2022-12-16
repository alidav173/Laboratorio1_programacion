/*
 * fecha.c
 *
 *  Created on: 7 oct. 2022
 *      Author: Ali Ansidey
 */

#include "fecha.h"
#include "utn.h"

int ingresoFecha(fecha* fechaActual){
	int retorno = ERROR;
		if(fechaActual != NULL){
			int dia;
			int mes;
			int anio;
			utn_getNumero(&dia,"Ingrese el dia: \n","Reingrese el dia: \n",1,31,3);

			utn_getNumero(&mes,"Ingrese el mes: \n","Reingrese el mes: \n",1,12,3);

			utn_getNumero(&anio,"Ingrese el anio: \n","Reingrese el anio: \n",1,9999,3);

			while(mes == 2 && dia > 29){
				utn_getNumero(&dia,"Febrero tiene menos dias. Ingrese un dia : \n","Febrero tiene menos dias. Reingrese un dia valido: \n",1,29,3);

			}
			while((mes == 4 || mes == 6 ||mes == 9 ||mes == 11) && mes >30){
				utn_getNumero(&dia,"Este mes tiene menos de 31 dias. Ingrese un dia valido: \n","Este mes tiene menos de 31 dias. Reingrese un dia valido: \n",1,30,3);

			}
			(*(fechaActual)).dia = dia;
			(*(fechaActual)).mes = mes;
			(*(fechaActual)).anio = anio;

		retorno = 0;
		}

	return retorno;
}


int conversionFechaString(fecha fechaActual, char* fechaString){
	int retorno = ERROR;
	char diaEvento[2];
	char mesEvento[2];
	char anioEvento[4];
	if(fechaString!= NULL){
		itoa(fechaActual.dia, diaEvento,10);
		strcpy(fechaString,diaEvento);
		strcat(fechaString,"/");
		itoa(fechaActual.mes, mesEvento,10);
		strcat(fechaString,mesEvento);
		strcat(fechaString,"/");
		itoa(fechaActual.anio, anioEvento,10);
		strcat(fechaString,anioEvento);
		retorno = 0;
	}
return retorno;
}
