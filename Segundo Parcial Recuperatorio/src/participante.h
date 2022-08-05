/*
 * participante.h
 *
 *  Created on: 4 ago. 2022
 *      Author: Rodri
 */

#ifndef PARTICIPANTE_H_
#define PARTICIPANTE_H_

typedef struct
{
	int id;
	char nombre[50];
	int edad;
	int idDificultad;
	int score;
}eParticipante;
/************************************************/
eParticipante* participante_new();
/************************************************/
eParticipante* participante_newParametros(char* idStr,char* nombre,char* edad,char* idDificultad,char* score);
/************************************************/
/************************************************/
int participante_setID(eParticipante* this,int id);

int participante_getID(eParticipante* this,int* id);
/************************************************/
int participante_setNombre(eParticipante* this,char* nombre);

int participante_getNombre(eParticipante* this,char* nombre);
/************************************************/
int participante_setEdad(eParticipante* this,int edad);

int pariticipante_getEdad(eParticipante* this,int* edad);
/************************************************/
int paticipante_setIdDificultad(eParticipante* this,int idDificultad);

int participante_getIdDificultad(eParticipante* this,int* idDificultad);
/************************************************/
int participante_getScore(eParticipante* this,int* score);

int participante_setScore(eParticipante* this,int score);
/************************************************/
void participante_mostrar(eParticipante* unParticipante);
/************************************************/
int participante_getEdad(eParticipante* this,int* edad);
/************************************************/
int participante_OrdenaNombre(void* pParticipanteUno , void* pParticipanteDos);
/***********************************************/
int participante_filterDificultad(void* pElemento);
int participante_filterDificultad2(void* pElemento);
int participante_filterDificultad3(void* pElemento);
/************************************************/


#endif /* PARTICIPANTE_H_ */
