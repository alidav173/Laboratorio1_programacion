/*
 * informes.h
 *
*  Created on: 15 sept. 2022
 *      Author: Ali Ansidey
 */

#ifndef INFORMES_H_
#define INFORMES_H_

#include <stdio.h>

/**
 * @brief	Muestra por pantalla los promedios de jugadores por confederacion
 * @param	confAFC Puntero al promedio de jugadores AFC
 * @param	confCAF Puntero al promedio de jugadores CAF
 * @param	confCONCACAF Puntero al promedio de jugadores CONCACAF
 * @param	confCONMEBOL Puntero al promedio de jugadores CONMEBOL
 * @param	confUEFA Puntero al promedio de jugadores UEFA
 *  @param	confOFC Puntero al promedio de jugadores OFC
 * @return	Retorna void
 */
void mostrarPorcentajesPorConf(float* confAFC, float* confCAF,float* confCONCACAF,
		float* confCONMEBOL, float* confUEFA, float* confOFC);


/**
 * @brief	Muestra por pantalla los costos de mantenimiento, el recargo si la mayoría de jugadores juega en Europa
 * y el costo total con recargo.
 * @param	costoMantenimiento Puntero al costo de mamtenimiento
 * @param	recargo Puntero al recargo del 35% si la mayoria de los jugadores juega en Europa
 * @param	costoTotal Puntero al costo total, donde incluye el recargo
 * @return	Retorna void
 */
void mostrarCostos(float* costoMantenimiento, float* recargo,float* costoTotal);

#endif /* INFORMES_H_ */
