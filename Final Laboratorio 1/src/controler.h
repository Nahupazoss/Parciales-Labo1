/*
 * controler.h
 *
 *  Created on: 29 jun 2022
 *      Author: Rodri
 */

#ifndef CONTROLER_H_
#define CONTROLER_H_

int controller_loadFromText(char* path , LinkedList* pArrayListPokemon);
/**************************************************************/
int controller_map(LinkedList* pArrayListPokemon);
/**************************************************************/
int controller_List(LinkedList* pArrayListPokemon);
/**************************************************************/
int controller_sort(LinkedList* pArrayListPokemon);
/**************************************************************/
int controller_saveAsText(char* path , LinkedList* pArrayListPokemon);
/**************************************************************/
int controller_saveAsBinary(char* path , LinkedList* pArrayListPokemon);
/**************************************************************/
int controller_filter(LinkedList* pArrayListPokemon);

#endif /* CONTROLER_H_ */
