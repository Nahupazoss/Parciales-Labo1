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
#include "computer.h"
#include "parser.h"
#include "controler.h"


int controller_loadFromText(char* path , LinkedList* pArrayListComputer)
{
	int retorno = -1;

	FILE* pArchivo = NULL;

	if(pArrayListComputer != NULL && path != NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL)
		{
			parser_ComputerFromText(pArchivo, pArrayListComputer);
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

int controller_ListComputer(LinkedList* pArrayListComputer)
{
	int retorno = -1;
	int i;
	eComputer* aux = NULL;
	int tam;

	printf("\n===================================================================================================\n");
	printf("ID\tDESCRIPCION PC\t\t\t\t\t\t\t\t\t\t\t\t\tPRECIO\t\tTIPO DE PC\tCUOTAS\n");
	printf("===================================================================================================\n");
	if(pArrayListComputer != NULL)
	{
		tam = ll_len(pArrayListComputer);

		for(i=0;i<tam;i++)
		{
			aux = (eComputer*)ll_get(pArrayListComputer, i);
			computer_mostrar(aux);

		}
	}
	else
	{
		printf("\nError\n");
	}


	return retorno;
}

int controller_saveAsText(char* path , LinkedList* pArrayListComputer)
{
	int retorno = -1;
	FILE* pFile;

	if(path != NULL && pArrayListComputer != NULL)
	{
		pFile = fopen(path,"w");

		if(pFile != NULL)
		{
			parser_guardarTexto(pFile, pArrayListComputer);
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

int controller_sort(LinkedList* pArrayList)
{
	int retorno = -1;
	int flag = 0;

	if(pArrayList != NULL)
	{
		ll_sort(pArrayList,computer_OrdenaCuotas,1);
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

int controller_map(LinkedList* pArrayList)
{
	int retorno = -1;

	if(pArrayList != NULL)
	{
		ll_map(pArrayList,computer_ValorAgregado);
	}

	return retorno;
}
