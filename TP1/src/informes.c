/*
 * informes.c
 *
*  Created on: 15 sept. 2022
 *      Author: Ali Ansidey
 */


void mostrarPorcentajesPorConf(float* confAFC, float* confCAF,float* confCONCACAF, float* confCONMEBOL,
		float* confUEFA, float* confOFC){
		printf("Porcentaje UEFA %.2f \n",*confUEFA);
		printf("Porcentaje CONMEBOL %.2f \n",*confCONMEBOL);
		printf("Porcentaje CONCACAF %.2f \n",*confCONCACAF);
		printf("Porcentaje AFC %.2f \n",*confAFC);
		printf("Porcentaje OFC %.2f \n",*confOFC);
		printf("Porcentaje CAF %.2f \n",*confCAF);

}

void mostrarCostos(float* costoMantenimiento, float* recargo,float* costoTotal){
		printf("EL costo de mantenimiento era de %.2f y recibio un aumento de %.2f, su nuevo valor es de: %.2f \n",
				*costoMantenimiento, *recargo,*costoTotal);
}
