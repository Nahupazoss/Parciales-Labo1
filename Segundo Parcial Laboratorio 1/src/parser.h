/*
 * parser.h
 *
 *  Created on: 29 jun 2022
 *      Author: Rodri
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_ComputerFromText(FILE* pFile , LinkedList* pArrayListComputer);
/********************************************/
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListComputer);
/********************************************/
int parser_guardarTexto(FILE* pFile , LinkedList* pArrayListComputer);
/********************************************/
int parser_guardarBinario(FILE* pFile , LinkedList* pArrayListComputer);

#endif /* PARSER_H_ */
