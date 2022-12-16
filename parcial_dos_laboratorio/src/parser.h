/*
 * parser.h
 *
 *  Created on: 14 nov. 2022
 *      Author: Ali Ansidey
 */

#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea los datos de la compra desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListCompra LinkedList*
 * \return int
 */
int parser_compraFromText(FILE* pFile , LinkedList* pArrayListCompra);


/** \brief Parsea los datos de la compra desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListCompra LinkedList*
 * \return int
 *
 */
int parser_compraFromBinary(FILE* pFile , LinkedList* pArrayListCompra);

#endif /* PARSER_H_ */
