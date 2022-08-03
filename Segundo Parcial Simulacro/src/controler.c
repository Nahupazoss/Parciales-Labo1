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
#include "empleado.h"



int controller_loadFromText(char* path , LinkedList* pArrayListEmpleado)
{
	int retorno = -1;

	FILE* pArchivo = NULL;

	if(pArrayListEmpleado != NULL && path != NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL)
		{
			parser_FromText(pArchivo, pArrayListEmpleado);
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
int controller_List(LinkedList* pArrayListEmpleado)
{
	int retorno = -1;
	int i;
	eEmpleado* aux = NULL;
	int tam;

	printf("\n===================================================================================================\n");
	printf("ID\tNombre\tEmpleo\tEdad\tHoras\tDedicacion\n");
	printf("===================================================================================================\n");
	if(pArrayListEmpleado != NULL)
	{
		tam = ll_len(pArrayListEmpleado);

		for(i=0;i<tam;i++)
		{
			aux = (eEmpleado*)ll_get(pArrayListEmpleado, i);
			Empleado_mostrar(aux);

		}
	}
	else
	{
		printf("\nError\n");
	}


	return retorno;
}
/******************************************************************************************************/
int controller_saveAsText(char* path , LinkedList* pArrayListEmpleado)
{
	int retorno = -1;
	FILE* pFile;

	if(path != NULL && pArrayListEmpleado != NULL)
	{
		pFile = fopen(path,"w");

		if(pFile != NULL)
		{
			parser_guardarTexto(pFile, pArrayListEmpleado);
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
int controller_sort(LinkedList* pArrayList)
{
	int retorno = -1;
	int flag = 0;

	if(pArrayList != NULL)
	{
		ll_sort(pArrayList,Empleado_OrdenaNombre,1);
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
int controller_map(LinkedList* pArrayList)
{
	int retorno = -1;

	if(pArrayList != NULL)
	{
		ll_map(pArrayList,Empleado_Dedicacion);
	}

	return retorno;
}
/******************************************************************************************************/
int controller_filter(LinkedList* pArrayList)
{
	int retorno = -1;
	LinkedList* nuevall;


	if(pArrayList != NULL)
	{
		nuevall = ll_filter(pArrayList,Empleado_filter21);
		controller_List(nuevall);
		ll_deleteLinkedList(nuevall);
	}

	return retorno;
}
