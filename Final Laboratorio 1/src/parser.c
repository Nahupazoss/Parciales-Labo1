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
#include "controler.h"
#include "parser.h"
#include "utn.h"
#include "pokemon.h"

int parser_FromText(FILE* pFile , LinkedList* pArrayListPokemon)
{
	int retorno = -1;
	char numero[50];
	char nombre[50];
	char tipo[50];
	char tamanio[50];
	char ataqueCargado[50];
	char valorAtaque[50];
	char esVarioColor[50];
	ePokemon* unPokemon = NULL;
;
	if(pFile != NULL && pArrayListPokemon !=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVarioColor);

		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVarioColor);

			unPokemon = pokemon_newParametros(numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVarioColor);

			if(unPokemon != NULL)
			{
				ll_add(pArrayListPokemon, unPokemon);
			}
		}

		retorno = 0;

	}

	return retorno;
}
/***************************************************************************************/
int parser_guardarTexto(FILE* pFile , LinkedList* pArrayListPokemon)
{
	int retorno = -1;
	int i;
	int tam = ll_len(pArrayListPokemon);
	ePokemon* aux;
	int numero;
	char nombre[100];
	char tipo[100];
	char tamanio[50];
	char ataqueCargado[50];
	int valorAtaque;
	int esVarioColor;

	if(pFile != NULL && pArrayListPokemon != NULL)
	{
		fprintf(pFile,"numero,nombre,tipo,tamanio,ataquecargado,valorataque,esvariocolor\n");

		for(i=0;i<tam;i++)
		{
			aux = (ePokemon*)ll_get(pArrayListPokemon, i);

			if(aux != NULL)
			{
				pokemon_getNum(aux, &numero);
				pokemon_getNombre(aux, nombre);
				pokemon_getTipo(aux, tipo);
				pokemon_getTamanio(aux, tamanio);
				pokemon_getAtaqueCargado(aux, ataqueCargado);
				pokemon_getValorAtaque(aux, &valorAtaque);
				pokemon_getEsVarioColor(aux, &esVarioColor);

				fprintf(pFile,"%d,%s,%s,%s,%s,%d,%d\n",numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVarioColor);

				retorno = 0;
			}
		}
	}

	return retorno;
}
/***************************************************************************************/
