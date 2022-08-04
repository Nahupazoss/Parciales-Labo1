/*
 * controler.c
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
#include "participante.h"
#include "parser.h"
//

int controller_loadFromText(char* path , LinkedList* pArrayListParticipantes)
{
	int retorno = -1;

	FILE* pArchivo = NULL;

	if(pArrayListParticipantes != NULL && path != NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL)
		{
			parser_FromText(pArchivo, pArrayListParticipantes);
			printf("\nCarga exitosa\n");
			retorno = 0;
		}
		else
		{
			printf("\nError con la carga\n");
		}

		fclose(pArchivo);
	}

	return retorno;
}
/******************************************************************************************************/
int controller_List(LinkedList* pArrayListParticipantes)
{
	int retorno = -1;
	int i;
	eParticipante* aux = NULL;
	int tam;

	printf("\n===================================================================================================\n");
	printf("ID\tNombre\t\t Edad\tDificultad\tScore\n");
	printf("===================================================================================================\n");
	if(pArrayListParticipantes != NULL)
	{
		tam = ll_len(pArrayListParticipantes);

		for(i=0;i<tam;i++)
		{
			aux = (eParticipante*)ll_get(pArrayListParticipantes, i);
			participante_mostrar(aux);

		}
	}
	else
	{
		printf("\nError\n");
	}


	return retorno;
}
/******************************************************************************************************/
int controller_saveAsText(char* path , LinkedList* pArrayListParticipante)
{
	int retorno = -1;
	FILE* pFile;

	if(path != NULL && pArrayListParticipante != NULL)
	{
		pFile = fopen(path,"w");

		if(pFile != NULL)
		{
			parser_guardarTexto(pFile, pArrayListParticipante);
			printf("\nGuardado con exito\n");
		}
		else
		{
			printf("\nERROR\n");
		}

		fclose(pFile);
		retorno = 0;
	}
	return retorno;
}
/******************************************************************************************************/
int controller_sort(LinkedList* pArrayListParticipante)
{
	int retorno = -1;
	int flag = 0;

	if(pArrayListParticipante != NULL)
	{
		ll_sort(pArrayListParticipante,participante_OrdenaNombre,0);
		flag = 1;

	}

	if(flag == 1)
	{
		printf("\nSe ordeno correctamente\n");
	}
	else
	{
		printf("\nERROR\n");
	}
    return retorno;
}
/******************************************************************************************************/
int controller_filter(LinkedList* pArrayListparticipante)
{
	int retorno = -1;
	LinkedList* nuevall = NULL;

	if(pArrayListparticipante != NULL)
	{
		nuevall = ll_filter(pArrayListparticipante,participante_filterDificultad);
		controller_List(nuevall);
		controller_saveAsText("src/filtrado.csv", nuevall);
	}

	return retorno;
}
