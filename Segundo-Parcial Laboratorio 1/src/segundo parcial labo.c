/*
 ============================================================================
 Name        : segundo.c
 Author      : Nahuel Pazos
 Version     : 1K
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "utn.h"
#include "computer.h"
#include "controler.h"

int main(void)
{
	setbuf(stdout,NULL);
	int opcion = 0;
	char archivo[10000];
	char auxArchivo[10] = "src/";
	int flag = 0;

	LinkedList* listComputer = ll_newLinkedList();

	do
	{
		opcion = menu();

		switch(opcion)
		{
		case 1:
			printf("\nIngrese el nombre del archivo:");
			getString(archivo, 10000);
			strcat(auxArchivo,archivo);
			controller_loadFromText(auxArchivo, listComputer);
			flag = 1;
		break;
		case 2:
			if(flag == 1)
			{
				controller_sort(listComputer);
			}
			else
			{
				if(flag == 0)
				{
					printf("\nPrimero cargar el archivo(opcion 1)\n");
				}
			}
		break;
		case 3:
			if(flag == 1)
			{
				controller_ListComputer(listComputer);
			}
			else
			{
				if(flag == 0)
				{
					printf("\nPrimero cargar el archivo(opcion 1)\n");
				}
			}
		break;
		case 4:
			if(flag == 1)
			{
				controller_map(listComputer);
			}
			else
			{
				if(flag == 0)
				{
					printf("\nPrimero cargar el archivo(opcion 1)\n");
				}
			}
		break;
		case 5:
			controller_saveAsText("src/mapeado.csv", listComputer);
		break;
		case 6:
			printf("\nSaliste\n");
		break;
		default:
		break;
		}

	}while(opcion != 6);

	return EXIT_SUCCESS;
}
