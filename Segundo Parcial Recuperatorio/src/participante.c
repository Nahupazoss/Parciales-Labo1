/*
 * participante.c
 *
 *  Created on: 4 ago. 2022
 *      Author: Rodri
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "utn.h"
#include "participante.h"
#include "parser.h"
#include "controler.h"

eParticipante* computer_new()
{
	return (eParticipante*)malloc(sizeof(eParticipante));
}
/***************************************************************************************/
eParticipante* participante_newParametros(char* idStr,char* nombre,char* edad,char* idDificultad,char* score)
{
	eParticipante* unParticipante;

	unParticipante = computer_new();

	if(unParticipante != NULL && idStr != NULL && nombre != NULL
	&& edad != NULL && idDificultad && score != NULL)
	{
		participante_setID(unParticipante, atoi(idStr));
		participante_setNombre(unParticipante, nombre);
		participante_setEdad(unParticipante, atoi(edad));
		paticipante_setIdDificultad(unParticipante,atoi(idDificultad));
		participante_setScore(unParticipante,atoi(score));
	}
	else
	{
		printf("\nNo se pudo asignar memoria..\n");
	}

	return  unParticipante;
}
/***************************************************************************************/
int participante_setID(eParticipante* this,int id)
{
	int retorno=-1;

		if(this != NULL && id > 0 )
		{
			retorno = 0;
			this->id = id;
		}

		return retorno;
}
/***************************************************************************************/
int participante_getID(eParticipante* this,int* id)
{
	int retorno=-1;

	if(this != NULL)
	{
		retorno = 0;
		*id = this->id;
	}

	return retorno;
}
/***************************************************************************************/
int participante_setNombre(eParticipante* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL && strlen(nombre) > 2 )
    {
        strcpy(this->nombre, nombre);

        retorno = 0;
    }

    return retorno;
}
/***************************************************************************************/
int participante_getNombre(eParticipante* this,char* nombre)
{
	int retorno=-1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);

		retorno = 0;
	}

	return retorno;
}
/***************************************************************************************/
int participante_setEdad(eParticipante* this,int edad)
{
	int retorno=-1;

		if(this != NULL && edad > 0 )
		{
			retorno = 0;
			this->edad = edad;
		}

		return retorno;
}
/***************************************************************************************/
int participante_getEdad(eParticipante* this,int* edad)
{
	int retorno=-1;

	if(this != NULL)
	{
		retorno = 0;
		*edad = this->edad;
	}

	return retorno;
}
/***************************************************************************************/
int paticipante_setIdDificultad(eParticipante* this,int idDificultad)
{
	int retorno=-1;

		if(this != NULL && idDificultad > 0  && idDificultad < 4)
		{
			retorno = 0;
			this->idDificultad = idDificultad;
		}

		return retorno;
}
/***************************************************************************************/
int participante_getIdDificultad(eParticipante* this,int* idDificultad)
{
	int retorno=-1;

	if(this != NULL)
	{
		retorno = 0;
		*idDificultad = this->idDificultad;
	}

	return retorno;
}
/***************************************************************************************/
int participante_setScore(eParticipante* this,int score)
{
	int retorno = -1;

	if(this != NULL && score > 0 )
	{
		retorno = 0;
		this->score = score;
	}
	return retorno;
}

int participante_getScore(eParticipante* this,int* score)
{
	int retorno = -1;

	if(this != NULL)
	{
		retorno = 0;
		*score = this->score;
	}
	return retorno;
}
/***************************************************************************************/
int participante_Dificultad(int idDificultad,char* tipo)
{
	int retorno = -1;

	if(tipo != NULL && idDificultad > 0)
	{
		switch(idDificultad)
		{
		case 1:
			strcpy(tipo,"Facil");
		break;
		case 2:
			strcpy(tipo,"Normal");
		break;
		case 3:
			strcpy(tipo,"Dificil");
		break;
		}
		retorno = 0;
	}

	return retorno;
}
/***************************************************************************************/
void participante_mostrar(eParticipante* unParticipante)
{
	int id;
	char nombre[50];
	int edad;
	int idDificultad;
	char dificultad[30];
	int score;

	if(unParticipante != NULL)
	{
		participante_getID(unParticipante, &id);
		participante_getNombre(unParticipante, nombre);
		participante_getEdad(unParticipante, &edad);
		participante_getIdDificultad(unParticipante, &idDificultad);
		participante_getScore(unParticipante, &score);
		participante_Dificultad(idDificultad,dificultad);

		printf("%d\t%s\t%d\t%s\t\t%d\n",id,nombre,edad,dificultad,score);
	}
	else
	{
		printf("\nError\n");
	}

}
/***************************************************************************************/
int participante_OrdenaNombre(void* pParticipanteUno , void* pParticipanteDos)
{
	int retorno = -1;
	char nombreEmpleadoUno[30];
	char nombreEmpleadoDos[30];
	eParticipante* participanteUno = NULL;
	eParticipante* participanteDos = NULL;

	if(pParticipanteUno != NULL && pParticipanteDos != NULL)
	{
		participanteUno = (eParticipante*)pParticipanteUno;
		participanteDos =  (eParticipante*)pParticipanteDos;

		if(participanteUno != NULL && participanteDos != NULL)
		{
			participante_getNombre(participanteUno, nombreEmpleadoUno);
			participante_getNombre(participanteDos, nombreEmpleadoDos);
			retorno = strcmp(nombreEmpleadoUno,nombreEmpleadoDos);
		}
	}

	return retorno;
}
/***************************************************************************************/
int participante_filterDificultad(void* pElemento)
{
	int retorno = -1;
	eParticipante* unParticipante = NULL;
	int dificultad;

	if(pElemento != NULL)
	{
		unParticipante = (eParticipante*)pElemento;

		if(unParticipante != NULL)
		{
			participante_getIdDificultad(unParticipante, &dificultad);

			if(dificultad == 1)
			{
				retorno = 1;
			}
			else
			{
				retorno = 2;
			}
		}
	}

	return retorno;
}
/***************************************************************************************/
int participante_filterDificultad2(void* pElemento)
{
	int retorno = -1;
	eParticipante* unParticipante = NULL;
	int dificultad;

	if(pElemento != NULL)
	{
		unParticipante = (eParticipante*)pElemento;

		if(unParticipante != NULL)
		{
			participante_getIdDificultad(unParticipante, &dificultad);

			if(dificultad == 2)
			{
				retorno = 1;
			}
			else
			{
				retorno = 2;
			}
		}
	}

	return retorno;
}
/***************************************************************************************/
int participante_filterDificultad3(void* pElemento)
{
	int retorno = -1;
	eParticipante* unParticipante = NULL;
	int dificultad;

	if(pElemento != NULL)
	{
		unParticipante = (eParticipante*)pElemento;

		if(unParticipante != NULL)
		{
			participante_getIdDificultad(unParticipante, &dificultad);

			if(dificultad == 3)
			{
				retorno = 1;
			}
			else
			{
				retorno = 2;
			}
		}
	}

	return retorno;
}
