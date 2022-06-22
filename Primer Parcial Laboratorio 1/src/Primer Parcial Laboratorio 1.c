/*
 ============================================================================
 Name        : Primer.c
 Author      : Nahuel Rodrigo Pazos
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//INFORMAR LA CANTIDAD DE SOLISTAS DE UN AÑO Y PAIS DETERMINADO
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "biblioteca.h"
#include "validaciones.h"

#define TAMDA 5
#define TAM 5
#define TAMTA 2

int main(void)
{
		setbuf(stdout,NULL);

		int indice = 2;
		int opcion;
		int contador = 0;

		eArtista listaArtista[TAMDA];
		eAlbum listaAlbum[TAM];
		eTipoArtista listaTipoArtista[TAMTA];
		eDiscografica listaDiscograficas[TAMDA];
		ePais listaPaises[TAM];
		inicializarVector(listaAlbum, TAM);

		do
		{
			opcion = menu();
			switch(opcion)
			{
			case 1:
				contador++;
				altaAlbum(listaAlbum,listaPaises, TAM, indice, contador, listaDiscograficas, listaArtista, TAMDA, listaTipoArtista, TAMTA);
			break;
			case 2:
				if(contador > 0)
				{
					modificar(listaAlbum,listaPaises, TAM);
				}
				else
				{
					printf("\nPrimero dar de alta (opcion 1)\n");
				}
			break;
			case 3:
				if(contador > 0)
				{
					darDeBaja(listaAlbum,listaPaises, TAM,listaDiscograficas,listaArtista,TAMDA,listaTipoArtista,TAMTA);
				}
				else
				{
					printf("\nPrimero dar de alta (opcion 1)\n");
				}
			break;
			case 4:
				if(contador >0)
				{
					informar(listaAlbum, TAM,contador);
				}
				else
				{
					printf("\nPrimero dar de alta (opcion 1)\n");
				}
			break;
			case 5:
				if(contador > 0)
				{
					listadoReal(listaAlbum, listaPaises, TAM, listaDiscograficas, listaArtista, TAMDA, listaTipoArtista, TAMTA, contador);
				}
				else
				{
					printf("\nPrimero dar de alta (opcion 1)\n");
				}
			break;
			case 6:
				printf("\nSALISTE...\n");
			break;
			default:
				printf("\nWrong option\n");
			break;
			}
		}while(opcion!=6);
}

