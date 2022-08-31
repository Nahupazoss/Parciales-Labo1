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
#include "controler.h"
#include "parser.h"
#include "utn.h"
#include "pokemon.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPokemon)
{
	int retorno = -1;

	FILE* pArchivo = NULL;

	if(pArrayListPokemon != NULL && path != NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL)
		{
			parser_FromText(pArchivo, pArrayListPokemon);
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
int controller_List(LinkedList* pArrayListPokemon)
{
	int retorno = -1;
	int i;
	ePokemon* aux = NULL;
	int tam;

	printf("\n===================================================================================================\n");
	printf("Numero\tNombre\t\t Tipo\tTamanio\tAtaque Cargado\tValor Ataque\tEs Vario Color\n");
	printf("===================================================================================================\n");
	if(pArrayListPokemon != NULL)
	{
		tam = ll_len(pArrayListPokemon);

		for(i=0;i<tam;i++)
		{
			aux = (ePokemon*)ll_get(pArrayListPokemon,i);
			pokemon_mostrar(aux);
		}

	}
	else
	{
		printf("\nError\n");
	}


	return retorno;
}
/******************************************************************************************************/
int controller_saveAsText(char* path , LinkedList* pArrayListPokemon)
{
	int retorno = -1;
	FILE* pFile;

	if(path != NULL && pArrayListPokemon != NULL)
	{
		pFile = fopen(path,"w");

		if(pFile != NULL)
		{
			parser_guardarTexto(pFile, pArrayListPokemon);
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
/*int controller_sort(LinkedList* pArrayListParticipante)
{
	int retorno = -1;
	int flag = 0;

	if(pArrayListParticipante != NULL)
	{
		//ll_sort(pArrayListParticipante,participante_OrdenaNombre,0);
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
}*/
/******************************************************************************************************/
int controller_map(LinkedList* pArrayList)
{
	int retorno = -1;

	if(pArrayList != NULL)
	{
		ll_map(pArrayList,pokemon_valorDelAtaque);
		retorno = 0;
	}

	return retorno;
}
/******************************************************************************************************/
/*int controller_filter(LinkedList* pArrayListparticipante)
{
	int retorno = -1;
	int opcion;

	if(pArrayListparticipante != NULL)
	{
		do
		{
			printf("12312312");
			scanf("%d",&opcion);
			switch(opcion)
			{
			case 1:
				ll_filter(pArrayListparticipante, participante_filterDificultad);
			break;
			case 2:
				ll_filter(pArrayListparticipante, participante_filterDificultad2);
			break;
			case 3:
				ll_filter(pArrayListparticipante, participante_filterDificultad3);
			break;
			}

		}while(opcion != 3);
	}

	return retorno;
}*/
