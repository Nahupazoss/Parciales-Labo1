/*
 * controler.h
 *
 *  Created on: 29 jun 2022
 *      Author: Rodri
 */

#ifndef CONTROLER_H_
#define CONTROLER_H_

int controller_loadFromText(char* path , LinkedList* pArrayListParticipante);
/**************************************************************/
int controller_map(LinkedList* pArrayListParticipante);
/**************************************************************/
int controller_List(LinkedList* pArrayListParticipante);
/**************************************************************/
int controller_sort(LinkedList* pArrayListParticipante);
/**************************************************************/
int controller_saveAsText(char* path , LinkedList* pArrayListParticipante);
/**************************************************************/
int controller_saveAsBinary(char* path , LinkedList* pArrayListParticipante);
/**************************************************************/
int controller_filter(LinkedList* pArrayListParticipante);

#endif /* CONTROLER_H_ */
