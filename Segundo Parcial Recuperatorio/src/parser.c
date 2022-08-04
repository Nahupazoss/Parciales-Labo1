/*
 * parser.c
 *
 *  Created on: 29 jun 2022
 *      Author: Rodri
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "utn.h"
#include "controler.h"
#include "participante.h"

int parser_FromText(FILE* pFile , LinkedList* pArrayListParticipante)
{
	int retorno = -1;
	char id[20];
	char nombre[100];
	char edad[50];
	char idDificultad[20];
	char score[100];
	eParticipante* unParticipante = NULL;
;
	if(pFile != NULL && pArrayListParticipante !=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,edad,idDificultad,score);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,edad,idDificultad,score);

			unParticipante = participante_newParametros(id, nombre, edad, idDificultad, score);

			if(unParticipante != NULL)
			{
				ll_add(pArrayListParticipante, unParticipante);
			}
		}

		retorno = 0;

	}

	return retorno;
}
/***************************************************************************************/
int parser_guardarTexto(FILE* pFile , LinkedList* pArrayListParticipante)
{
	int retorno = -1;
	int i;
	int tam = ll_len(pArrayListParticipante);
	eParticipante* aux;
	int id;
	char nombre[100];
	int edad;
	int idDificultad;
	int score;


	if(pFile != NULL && pArrayListParticipante != NULL)
	{
		fprintf(pFile,"id,nombre,edad,idDificultad,score\n");

		for(i=0;i<tam;i++)
		{
			aux = (eParticipante*)ll_get(pArrayListParticipante, i);

			if(aux != NULL)
			{
				participante_getID(aux, &id);
				participante_getNombre(aux, nombre);
				participante_getEdad(aux, &edad);
				participante_getIdDificultad(aux, &idDificultad);
				participante_getScore(aux, &score);

				fprintf(pFile,"%d,%s,%d,%d,%d\n",id,nombre,edad,idDificultad,score);

				retorno = 0;
			}
		}
	}

	return retorno;
}
/***************************************************************************************/
