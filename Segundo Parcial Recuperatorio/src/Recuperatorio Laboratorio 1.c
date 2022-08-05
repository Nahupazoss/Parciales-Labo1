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
#include "participante.h"

int main(void)
{
	setbuf(stdout,NULL);
	char archivo[10000];
	char auxArchivo[10] = "src/";
	int opcion = 0;
	int opcion2 = 0;

	LinkedList* listParticipante = ll_newLinkedList();
	LinkedList* nuevall = NULL;

	do
	{
		opcion = menu();

		switch(opcion)
		{
		case 1:
			printf("\nIngrese el nombre del archivo:");
			getString(archivo, 1000);
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
			utn_getNumero(&opcion2, "\nIngrese la dificultad a filtrar:", "\nERROR", 1, 3, 3);
			switch(opcion2)
			{
			case 1:
				nuevall = ll_filter(listParticipante, participante_filterDificultad);
			break;
			case 2:
				nuevall = ll_filter(listParticipante, participante_filterDificultad2);
			break;
			case 3:
				nuevall = ll_filter(listParticipante, participante_filterDificultad3);
			break;
			}
		break;
		case 5:
			controller_saveAsText("src/filtrado.csv", nuevall);
		break;
		case 6:
			printf("\nHas salido\n");
		break;
		default:
			printf("\nOpcion incorrecta\n");
		break;
		}

	}while(opcion != 6);

	ll_deleteLinkedList(listParticipante);

	return EXIT_SUCCESS;
}
