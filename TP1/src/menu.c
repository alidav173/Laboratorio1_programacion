/*
 * menu.c
 *
 *  Created on: 15 sept. 2022
 *      Author: Alí Ansidey
 */


void mostrarMenuPrincipal(float* costoHospedaje, float* costoComida, float* costoTransporte,
		int* cantArqueros, int* cantDefensores, int* cantMedios, int* cantDelanteros){

	printf("\n Menu Principal \n");
	printf("1. Ingreso costos de mantenimiento \n");
	printf("Costos de hospedaje $%.2f\n",*costoHospedaje);
	printf("Costos de comida $%.2f\n",*costoComida);
	printf("Costos de transporte $%.2f\n",*costoTransporte);
	printf("2. Carga de jugadores \n");
	printf("Arqueros -> %d\n",*cantArqueros);
	printf("Defensores -> %d\n",*cantDefensores);
	printf("Mediocampistas -> %d\n",*cantMedios);
	printf("Delanteros -> %d\n",*cantDelanteros);
	printf("3. Realizar todos los calculos \n");
	printf("4. Informar todos los resultados \n");
	printf("5. Salir \n");
	printf("\n");
}
