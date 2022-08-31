/*
 * pokemon.c
 *
 *  Created on: 30 ago. 2022
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
//
ePokemon* pokemon_new()
{
	return (ePokemon*)malloc(sizeof(ePokemon));
}
/***************************************************************************************/
ePokemon* pokemon_newParametros(char* numero,char* nombre,char* tipo,char* tamanio,char* ataqueCargado,char* valorAtaque,char* esVarioColor)
{
	ePokemon* unPokemon;

	unPokemon = pokemon_new();

	if(unPokemon != NULL && numero != NULL && nombre != NULL
	&& tipo != NULL && tamanio && ataqueCargado != NULL && valorAtaque != NULL && esVarioColor != NULL)
	{
		pokemon_setNum(unPokemon, atoi(numero));
		pokemon_setNombre(unPokemon, nombre);
		pokemon_setTipo(unPokemon, tipo);
		pokemon_setTamanio(unPokemon, tamanio);
		pokemon_setAtaqueCargado(unPokemon, ataqueCargado);
		pokemon_setValorAtaque(unPokemon,atoi(valorAtaque));
		pokemon_setEsVarioColor(unPokemon,atoi(esVarioColor));
	}
	else
	{
		printf("\nNo se pudo asignar memoria..\n");
	}

	return  unPokemon;
}
/***************************************************************************************/
int pokemon_setNum(ePokemon* this,int numero)
{
	int retorno = -1;

		if(this != NULL && numero >= 0 )
		{
			retorno = 0;
			this->numero = numero;
		}

		return retorno;
}
/***************************************************************************************/
int pokemon_getNum(ePokemon* this,int* numero)
{
	int retorno = -1;

	if(this != NULL)
	{
		retorno = 0;
		*numero = this->numero;
	}

	return retorno;
}
/***************************************************************************************/
int pokemon_setNombre(ePokemon* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL && strlen(nombre) >= 2 )
    {
        strcpy(this->nombre, nombre);

        retorno = 0;
    }

    return retorno;
}
/***************************************************************************************/
int pokemon_getNombre(ePokemon* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL)
	{
		strcpy(nombre,this->nombre);

		retorno = 0;
	}

	return retorno;
}
/***************************************************************************************/
int pokemon_setTipo(ePokemon* this,char* tipo)
{
    int retorno = -1;

    if(this != NULL)
    {
        strcpy(this->tipo, tipo);

        retorno = 0;
    }

    return retorno;
}
/***************************************************************************************/
int pokemon_getTipo(ePokemon* this,char* tipo)
{
	int retorno=-1;

	if(this != NULL)
	{
		strcpy(tipo,this->tipo);

		retorno = 0;
	}

	return retorno;
}
/***************************************************************************************/
int pokemon_setTamanio(ePokemon* this,char* tamanio)
{
    int retorno = -1;

    if(this != NULL)
    {
        strcpy(this->tamanio, tamanio);

        retorno = 0;
    }

    return retorno;
}
/***************************************************************************************/
int pokemon_getTamanio(ePokemon* this,char* tamanio)
{
	int retorno=-1;

	if(this != NULL)
	{
		strcpy(tamanio,this->tamanio);

		retorno = 0;
	}

	return retorno;
}
/***************************************************************************************/
int pokemon_setAtaqueCargado(ePokemon* this,char* ataqueCargado)
{
    int retorno = -1;

    if(this != NULL)
    {
        strcpy(this->ataqueCargado, ataqueCargado);

        retorno = 0;
    }

    return retorno;
}
/***************************************************************************************/
int pokemon_getAtaqueCargado(ePokemon* this,char* ataqueCargado)
{
	int retorno=-1;

	if(this != NULL)
	{
		strcpy(ataqueCargado,this->ataqueCargado);

		retorno = 0;
	}

	return retorno;
}
/***************************************************************************************/
int pokemon_setValorAtaque(ePokemon* this,int valorAtaque)
{
	int retorno = -1;

		if(this != NULL && valorAtaque != 0)
		{
			retorno = 0;
			this->valorAtaque = valorAtaque;
		}

		return retorno;
}
/***************************************************************************************/
int pokemon_getValorAtaque(ePokemon* this,int* valorAtaque)
{
	int retorno = -1;

	if(this != NULL)
	{
		retorno = 0;
		*valorAtaque = this->valorAtaque;
	}

	return retorno;
}
/***************************************************************************************/
int pokemon_setEsVarioColor(ePokemon* this,int esVarioColor)
{
	int retorno = -1;

		if(this != NULL)
		{
			retorno = 0;
			this->valorAtaque = esVarioColor;
		}

		return retorno;
}
/***************************************************************************************/
int pokemon_getEsVarioColor(ePokemon* this,int* esVarioColor)
{
	int retorno = -1;

	if(this != NULL)
	{
		retorno = 0;
		*esVarioColor = this->esVarioColor;
	}

	return retorno;
}
/***************************************************************************************/
void pokemon_mostrar(ePokemon* unPokemon)
{
	int numero;
	char nombre[50];
	char tipo[50];
	char tamanio[50];
	char ataqueCargado[50];
	int valorAtaque;
	int esVarioColor;

	if(unPokemon != NULL)
	{
		pokemon_getNum(unPokemon, &numero);
		pokemon_getNombre(unPokemon, nombre);
		pokemon_getTipo(unPokemon, tipo);
		pokemon_getTamanio(unPokemon, tamanio);
		pokemon_getAtaqueCargado(unPokemon, ataqueCargado);
		pokemon_getValorAtaque(unPokemon, &valorAtaque);
		pokemon_getEsVarioColor(unPokemon, &esVarioColor);

		printf("%-5d\t%-20s\t%-15s\t%-15s\t%-15s\t%-10d\t%-10d\n",numero,nombre,tipo,tamanio,ataqueCargado,valorAtaque,esVarioColor);
	}

}
/***************************************************************************************/
int pokemon_eliminar(LinkedList* pArrayListPokemon)
{
	int retorno = -1;
	ePokemon* unPokemon = NULL;
	int i;
	int tam = ll_len(pArrayListPokemon);
	int numero;
	int numeroPokemon;

	if(pArrayListPokemon != NULL)
	{
		printf("Ingrese el numero de pokemon a eliminar:");
		scanf("%d",&numero);

		for(i=0;i<tam;i++)
		{
			unPokemon = (ePokemon*)ll_get(pArrayListPokemon,i);

			if(unPokemon != NULL)
			{
				pokemon_getNum(unPokemon,&numeroPokemon);

				if(numero == numeroPokemon)
				{
					ll_remove(pArrayListPokemon, i);
					printf("Se elimino con exito");
					break;
				}
			}
			else
			{
				printf("No se ha podido eliminar el pokemon");
			}
		}
		retorno = 1;
	}

	return retorno;
}
/***************************************************************************************/
int pokemon_filterWater(void* pElemento)
{
	int retorno = -1;
	ePokemon* unPokemon = NULL;
	char tipo[50];
	char water[50] = "Water";

	if(pElemento != NULL)
	{
		unPokemon = (ePokemon*)pElemento;

		if(unPokemon != NULL)
		{
			pokemon_getTipo(unPokemon, tipo);

			if(strcmp(tipo,water) == 0)
			{
				retorno = 1;
			}
			else
			{
				retorno = 2;
			}
		}
	}

	return retorno;
}
/***************************************************************************************/
int pokemon_valorDelAtaque(void* pElemento)
{
	int retorno = -1;
	ePokemon* pokemonUno = NULL;
	char tipo1[100];
	int valorAtaque;
	char fire[50] = "Fire";
	char ground[50] = "Ground";
	char grass[50] = "Grass";

	if(pElemento != NULL)
	{
		pokemonUno = (ePokemon*)pElemento;


		if(pokemonUno != NULL )
		{
			pokemon_getTipo(pokemonUno, tipo1);

			if(strcmp(tipo1,fire) == 0)
			{
				pokemon_getValorAtaque(pokemonUno, &valorAtaque);
				valorAtaque = valorAtaque * 1.10;
			}
			else
			{
				if(strcmp(tipo1,ground) == 0)
				{
					pokemon_getValorAtaque(pokemonUno, &valorAtaque);
					valorAtaque = valorAtaque * 1.10;
				}
				else
				{
					if(strcmp(tipo1,grass) == 0)
					{
						pokemon_getValorAtaque(pokemonUno, &valorAtaque);
						valorAtaque = valorAtaque * 1.10;
					}
				}
			}


		}
	}
	return retorno;
}
/***************************************************************************************/
int pokemon_batallaFire(void* pElemetno)
{
	int retorno = -1;

	ePokemon* unPokemon = NULL;
	char tipo[50];
	char fire[50] = "Fire";
	char tamanio[50];
	char ataqueCargado[50];
	int valorAtaque;

	if(pElemetno != NULL)
	{
		unPokemon = (ePokemon*)pElemetno;

		if(unPokemon != NULL)
		{
			pokemon_getTipo(unPokemon,tipo);
			pokemon_getTamanio(unPokemon,tamanio);
			pokemon_getAtaqueCargado(unPokemon,ataqueCargado);
			pokemon_getValorAtaque(unPokemon,&valorAtaque);

			if(strcmp(tipo,fire) == 0 && strcmp(tamanio,"XL") == 0 && strcmp(ataqueCargado,"Lanzallamas") == 0 && valorAtaque > 80)
			{
				retorno = 1;
			}
			else
			{
				retorno = 2;
			}
		}
	}
	return retorno;
}
/***************************************************************************************/
int pokemon_batallaWater(void* pElemetno)
{
	int retorno = -1;

	ePokemon* unPokemon = NULL;
	char tipo[50];
	char water[50] = "Water";
	char tamanio[50];
	char ataqueCargado[50];
	int valorAtaque;

	if(pElemetno != NULL)
	{
		unPokemon = (ePokemon*)pElemetno;

		if(unPokemon != NULL)
		{
			pokemon_getTipo(unPokemon,tipo);
			pokemon_getTamanio(unPokemon,tamanio);
			pokemon_getAtaqueCargado(unPokemon,ataqueCargado);
			pokemon_getValorAtaque(unPokemon,&valorAtaque);

			if(strcmp(tipo,water) == 0 && strcmp(tamanio,"L") == 0 && strcmp(ataqueCargado,"Hidrobomba") == 0 && valorAtaque > 80)
			{
				retorno = 1;
			}
			else
			{
				retorno = 2;
			}
		}
	}
	return retorno;
}
/***************************************************************************************/
