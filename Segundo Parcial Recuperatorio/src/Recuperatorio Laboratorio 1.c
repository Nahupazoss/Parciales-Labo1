/*
 ============================================================================
 Name        : Recuperatorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "LinkedList.h"
#include "controler.h"
#include "parser.h"
#include "utn.h"

int main(void)
{
	setbuf(stdout,NULL);
	char archivo[200];
	char auxArchivo[10] = "src/";
	int opcion = 0;

	LinkedList* listParticipante = ll_newLinkedList();

	do
	{
		opcion = menu();

		switch(opcion)
		{
		case 1:
			printf("\nIngrese el nombre del archivo:");
			getString(archivo, 200);
			strcat(auxArchivo,archivo);
			controller_loadFromText(auxArchivo, listParticipante);
		break;
		case 2:
			controller_sort(listParticipante);
		break;
		case 3:
			controller_List(listParticipante);
		break;
		case 4:
			controller_filter(listParticipante);
		break;
		case 5:
			printf("\nHas salido\n");
		break;
		default:
			printf("\nOpcion incorrecta\n");
		break;
		}

	}while(opcion != 5);

	ll_deleteLinkedList(listParticipante);

	return EXIT_SUCCESS;
}
