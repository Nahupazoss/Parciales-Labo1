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
#include "empleado.h"
#include "controler.h"

int parser_FromText(FILE* pFile , LinkedList* pArrayList)
{
	int retorno = -1;
	char id[20];
	char nombre[100];
	char empleo[50];
	char edad[10];
	char horas[10];

	eEmpleado* unEmpleado = NULL;
;
	if(pFile != NULL && pArrayList !=NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,empleo,edad,horas);

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,empleo,edad,horas);

			unEmpleado = Empleado_newParametros(id, nombre, empleo, edad, horas);

			if(unEmpleado != NULL)
			{
				ll_add(pArrayList, unEmpleado);
			}
		}

		retorno = 0;

	}
	return retorno;
}

int parser_guardarTexto(FILE* pFile , LinkedList* pArrayList)
{
	int retorno = -1;
	int i;
	int tam = ll_len(pArrayList);
	eEmpleado* aux;
	int id;
	char nombre[100];
	char empleo[50];
	char dedicacion[50];
	int edad;
	int horasTrabajadas;

	if(pFile != NULL && pArrayList != NULL)
	{
		fprintf(pFile,"id,nombre,empleo,edad,horas,dedicacion\n");

		for(i=0;i<tam;i++)
		{
			aux = (eEmpleado*)ll_get(pArrayList, i);

			if(aux != NULL)
			{
				Empleado_getID(aux, &id);
				Empleado_getNombre(aux, nombre);
				Empleado_getEmpleo(aux, empleo);
				Empleado_getEdad(aux, &edad);
				Empleado_getHorasTrabajadas(aux, &horasTrabajadas);
				Empleado_getDedicacion(aux, dedicacion);

				fprintf(pFile,"%d,%s,%s,%d,%d,%s\n",id,nombre,empleo,edad,horasTrabajadas,dedicacion);

				retorno = 0;
			}
		}
	}

	return retorno;
}
