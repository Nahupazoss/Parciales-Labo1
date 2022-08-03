/*
 ============================================================================
 Name        : simulacro.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "empleado.h"
#include "controler.h"
//1
int main(void)
{
	setbuf(stdout,NULL);
	int opcion = 0;
	char archivo[20];
	char auxArchivo[10] = "src/";


	LinkedList* listEmpleado = ll_newLinkedList();

	do
	{
		opcion = menu();

		switch(opcion)
		{
		case 1:
			printf("\nIngrese el nombre del archivo:");
			getString(archivo, 20);
			strcat(auxArchivo,archivo);
			controller_loadFromText(auxArchivo, listEmpleado);
		break;
		case 2:
			controller_sort(listEmpleado);
			controller_List(listEmpleado);
		break;
		case 3:
			controller_saveAsText("src/resultados.csv", listEmpleado);
		break;
		case 4:
			controller_map(listEmpleado);
		break;
		case 5:
			controller_filter(listEmpleado);
		break;
		case 6:
			printf("\nHas salido");
		break;
		}

	}while(opcion != 6);

	ll_deleteLinkedList(listEmpleado);

	return EXIT_SUCCESS;
}
