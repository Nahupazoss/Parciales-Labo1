/*
 * controler.h
 *
 *  Created on: 29 jun 2022
 *      Author: Rodri
 */

#ifndef CONTROLER_H_
#define CONTROLER_H_

int controller_loadFromText(char* path , LinkedList* pArrayListComputer);
/**************************************************************/
int controller_map(LinkedList* pArrayList);
/**************************************************************/
int controller_ListComputer(LinkedList* pArrayListComputer);
/**************************************************************/
int controller_sort(LinkedList* pArrayList);
/**************************************************************/
int controller_saveAsText(char* path , LinkedList* pArrayListComputer);
/**************************************************************/
int controller_saveAsBinary(char* path , LinkedList* pArrayListComputer);

#endif /* CONTROLER_H_ */
