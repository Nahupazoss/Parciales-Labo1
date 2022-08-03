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
#include "computer.h"
#include "parser.h"
#include "controler.h"

int parser_ComputerFromText(FILE* pFile , LinkedList* pArrayListComputer)
{
	int retorno = -1;
	char id[20];
	char descripcion[10000];
	char precio[10];
	char idTipo[10];
	char cuotas[10];

	eComputer* oneComputer = NULL;
;
	if(pFile != NULL && pArrayListComputer !=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,descripcion,precio,idTipo,cuotas);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,descripcion,precio,idTipo,cuotas);

			oneComputer = computer_newParametros(id, descripcion, precio, idTipo, cuotas);

			if(oneComputer != NULL)
			{
				ll_add(pArrayListComputer, oneComputer);
			}
		}

		retorno = 0;

	}
	return retorno;
}

int parser_guardarTexto(FILE* pFile , LinkedList* pArrayListComputer)
{
	int retorno = -1;
	int i;
	int tam = ll_len(pArrayListComputer);
	eComputer* aux;
	int id;
	char descripcion[100];
	float precio;
	int idTipo;
	int cuotas;
	int valorCuotas;

	if(pFile != NULL && pArrayListComputer != NULL)
	{
		fprintf(pFile,"id,descripcion,precio,idTipo,cuotas,valorCuota\n");

		for(i=0;i<tam;i++)
		{
			aux = (eComputer*)ll_get(pArrayListComputer, i);

			if(aux != NULL)
			{
				computer_getID(aux, &id);
				computer_getDescripcion(aux, descripcion);
				computer_getPrecio(aux, &precio);
				computer_getIdTipo(aux, &idTipo);
				computer_getCuotas(aux, &cuotas);
				computer_getValorCuota(aux, &valorCuotas);

				fprintf(pFile,"%d,%s,%.0f,%d,%d,%d\n",id,descripcion,precio,idTipo,cuotas,valorCuotas);

				retorno = 0;
			}
		}
	}
	return retorno;
}
