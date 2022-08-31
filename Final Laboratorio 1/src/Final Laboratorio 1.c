/*
 ============================================================================
 Name        : Final.c
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
#include "pokemon.h"

int main(void)
{
	setbuf(stdout,NULL);
	char archivo[10000];
	char auxArchivo[10] = "src/";
	int opcion = 0;
	int controlador;
	LinkedList* listPokemon = ll_newLinkedList();
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
			controller_loadFromText(auxArchivo, listPokemon);
		break;
		case 2:
			controller_List(listPokemon);
			pokemon_eliminar(listPokemon);
		break;
		case 3:
			controller_List(listPokemon);
		break;
		case 4:
			nuevall = ll_filter(listPokemon,pokemon_filterWater);
			controller_List(nuevall);
		break;
		case 5:
			controlador = controller_map(listPokemon);
			if(controlador == 0)
			{
				printf("\nEl aumento se aplico exitosamente\n");
			}
		break;
		case 6:
			pokemon_Batalla(listPokemon);
		break;
		case 7:
			controller_saveAsText("src/filtrado.csv", nuevall);
			printf("\nHas salido\n");
		break;
		default:
			printf("\nOpcion incorrecta\n");
		break;
		}

	}while(opcion != 7);

	ll_deleteLinkedList(listPokemon);

	return EXIT_SUCCESS;
}
