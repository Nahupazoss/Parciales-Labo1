/*
 * computer.c
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

eComputer* computer_new()
{
	return (eComputer*)malloc(sizeof(eComputer));
}
/***************************************************************************************/
eComputer* computer_newParametros(char* idStr,char* descripcion,char* precio,char* idtipo,char* cuotas)
{
	eComputer* unaCompu;

	unaCompu = computer_new();

	if(unaCompu != NULL && idStr != NULL && descripcion != NULL
	&& precio != NULL && idtipo)
	{
		computer_setID(unaCompu, atoi(idStr));
		computer_setDescripcion(unaCompu, descripcion);
		computer_setPrecio(unaCompu, atof(precio));
		computer_setIdTipo(unaCompu, atoi(idtipo));
		computer_setCuotas(unaCompu, atoi(cuotas));
		computer_setValorCuota(unaCompu, 0);
	}
	else
	{
		printf("\nNo se pudo asignar memoria..\n");
	}

	return  unaCompu;
}
/***************************************************************************************/
int computer_setID(eComputer* this,int id)
{
	int retorno=-1;

		if(this != NULL && id > 0 )
		{
			retorno = 0;
			this->id = id;
		}

		return retorno;
}
/***************************************************************************************/
int computer_getID(eComputer* this,int* id)
{
	int retorno=-1;

	if(this != NULL)
	{
		retorno = 0;
		*id = this->id;
	}

	return retorno;
}
/***************************************************************************************/
int computer_setDescripcion(eComputer* this,char* descripcion)
{
    int retorno = -1;

    if(this != NULL && descripcion != NULL && strlen(descripcion) > 2 )
    {
        strcpy(this->descripcion, descripcion);

        retorno = 0;
    }

    return retorno;
}
/***************************************************************************************/
int computer_getDescripcion(eComputer* this,char* descripcion)
{
	int retorno=-1;

	if(this != NULL && descripcion != NULL)
	{
		strcpy(descripcion,this->descripcion);

		retorno = 0;
	}

	return retorno;
}
/***************************************************************************************/
int computer_setPrecio(eComputer* this,float precio)
{
	int retorno=-1;

		if(this != NULL && precio > 0 )
		{
			retorno = 0;
			this->precio = precio;
		}

		return retorno;
}
/***************************************************************************************/
int computer_getPrecio(eComputer* this,float* precio)
{
	int retorno=-1;

	if(this != NULL)
	{
		retorno = 0;
		*precio = this->precio;
	}

	return retorno;
}
/***************************************************************************************/
int computer_setIdTipo(eComputer* this,int idTipo)
{
	int retorno=-1;

		if(this != NULL && idTipo > 0 )
		{
			retorno = 0;
			this->idTipo = idTipo;
		}

		return retorno;
}
/***************************************************************************************/
int computer_getIdTipo(eComputer* this,int* idTipo)
{
	int retorno=-1;

	if(this != NULL)
	{
		retorno = 0;
		*idTipo = this->idTipo;
	}

	return retorno;
}
/***************************************************************************************/
int computer_setValorCuota(eComputer* this,int valorcuota)
{
	int retorno = -1;

	if(this != NULL && valorcuota > 0 )
	{
		retorno = 0;
		this->valorCuota = valorcuota;
	}
	return retorno;
}

int computer_getValorCuota(eComputer* this,int* valorcuota)
{
	int retorno = -1;

	if(this != NULL)
	{
		retorno = 0;
		*valorcuota = this->valorCuota;
	}
	return retorno;
}
/***************************************************************************************/
int computer_setCuotas(eComputer* this,int cuotas)
{
	int retorno = -1;

		if(this != NULL && cuotas > 0 )
		{
			this->cuotas = cuotas;
			retorno = 0;
		}

		return retorno;

}

int computer_getCuotas(eComputer* this,int* cuotas)
{
	int retorno = -1;

		if(this != NULL)
		{
			*cuotas = this->cuotas;
			retorno = 0;
		}
		return retorno;
}
/***************************************************************************************/
int computer_tipoID(int id,char* tipo)
{
	int retorno = -1;

	if(tipo != NULL && id > 0)
	{
		switch(id)
		{
		case 1:
			strcpy(tipo,"DESKTOP");
		break;
		case 2:
			strcpy(tipo,"LAPTOP");
		break;
		}
		retorno = 0;
	}

	return retorno;
}
/***************************************************************************************/
void computer_mostrar(eComputer* oneCompu)
{
	int id;
	char idDescripcion[10000];
	char descripcion[10000];
	float precio;
	int idTipo;
	int cuotas;

	if(oneCompu != NULL)
	{
		computer_getID(oneCompu, &id);
		computer_getDescripcion(oneCompu, descripcion);
		computer_getPrecio(oneCompu, &precio);
		computer_getIdTipo(oneCompu, &idTipo);
		computer_getCuotas(oneCompu, &cuotas);
		computer_tipoID(idTipo, idDescripcion);

		printf("%-4d\t%-100s\t\t$%-10.2f\t%-15s\t%-4d\n",id,descripcion,precio,idDescripcion,cuotas);

	}
	else
	{
		printf("\nError\n");
	}

}
/***************************************************************************************/
int computer_OrdenaCuotas(void* pElementUno ,void* pElementDos)
{
	int retorno = -1;
	int primerCuota;
	int segundaCuota;
	eComputer* computerUno = NULL;
	eComputer* computerDos = NULL;

	if(pElementUno != NULL && pElementDos != NULL)
	{
		computerUno = (eComputer*)pElementUno;
		computerDos =  (eComputer*)pElementDos;


		if(computerUno != NULL && computerDos != NULL)
		{
			computer_getCuotas(computerUno, &primerCuota);
			computer_getCuotas(computerDos, &segundaCuota);

			if( primerCuota > segundaCuota )
			{
				retorno = 1;
			}
			else
			{
				if(segundaCuota > primerCuota )
				{
					retorno = 0;
				}
				else
				{
					if(primerCuota == segundaCuota)
					{
						retorno = 2;
					}
				}
			}
		}
	}
	return retorno;
}
/***************************************************************************************/
int computer_ValorAgregado(void* pElemento)
{
	int retorno = -1;
	eComputer* unacompu = NULL;
	int cuotas;
	float precio;
	float resultado;

	if(pElemento != NULL)
	{
		unacompu = (eComputer*)pElemento;

		if(unacompu != NULL)
		{
			computer_getCuotas(unacompu, &cuotas);
			computer_getPrecio(unacompu, &precio);

			resultado = precio / cuotas;

			computer_setValorCuota(unacompu, resultado);

		}
	}


	return retorno;
}
