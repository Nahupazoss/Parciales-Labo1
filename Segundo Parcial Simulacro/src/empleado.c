/*
 * empleado.c
 *
 *  Created on: 28 jul. 2022
 *      Author: Rodri
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "utn.h"
#include "empleado.h"

eEmpleado* Empleado_new()
{
	return (eEmpleado*)malloc(sizeof(eEmpleado));
}


eEmpleado* Empleado_newParametros(char* idStr,char* nombre,char* empleo,char* edad,char* horasTrabajadas)
{
	eEmpleado* unEmpleado;

	unEmpleado = Empleado_new();

	if(unEmpleado != NULL && idStr != NULL && nombre != NULL
	&& empleo != NULL && edad && horasTrabajadas != NULL )
	{
		Empleado_setID(unEmpleado, atoi(idStr));
		Empleado_setNombre(unEmpleado, nombre);
		Empleado_setDedicacion(unEmpleado,0);
		Empleado_setEmpleo(unEmpleado,empleo);
		Empleado_setEdad(unEmpleado, atoi(edad));
		Empleado_setHorasTrabajadas(unEmpleado, atoi(horasTrabajadas));
	}
	else
	{
		printf("\nNo se pudo asignar memoria..\n");
	}

	return  unEmpleado;
}
/***************************************************************************************/
int Empleado_setID(eEmpleado* this,int id)
{
	int retorno = -1;

		if(this != NULL && id > 0 )
		{
			retorno = 0;
			this->id = id;
		}

		return retorno;
}
/***************************************************************************************/
int Empleado_getID(eEmpleado* this,int* id)
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
int Empleado_setNombre(eEmpleado* this,char* nombre)
{
    int retorno = -1;

    if(this != NULL && nombre != NULL && strlen(nombre) > 2 )
    {
        strcpy(this->nombre, nombre);

        retorno = 0;
    }

    return retorno;
}
/***************************************************************************************/
int Empleado_getNombre(eEmpleado* this,char* nombre)
{
	int retorno=-1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);

		retorno = 0;
	}

	return retorno;
}
/***************************************************************************************/
int Empleado_setDedicacion(eEmpleado* this,char* dedicacion)
{
    int retorno = -1;

    if(this != NULL && dedicacion != NULL && strlen(dedicacion) > 2 )
    {
        strcpy(this->dedicacion, dedicacion);

        retorno = 0;
    }

    return retorno;
}
/***************************************************************************************/
int Empleado_getDedicacion(eEmpleado* this,char* dedicacion)
{
	int retorno = -1;

	if(this != NULL && dedicacion != NULL)
	{
		strcpy(dedicacion,this->dedicacion);

		retorno = 0;
	}

	return retorno;
}
/***************************************************************************************/
int Empleado_setEmpleo(eEmpleado* this,char* empleo)
{
    int retorno = -1;

    if(this != NULL && empleo != NULL && strlen(empleo) > 2 )
    {
        strcpy(this->empleo, empleo);

        retorno = 0;
    }

    return retorno;
}
/***************************************************************************************/
int Empleado_getEmpleo(eEmpleado* this,char* empleo)
{
	int retorno=-1;

	if(this != NULL && empleo != NULL)
	{
		strcpy(empleo,this->empleo);

		retorno = 0;
	}

	return retorno;
}
/***************************************************************************************/
int Empleado_setEdad(eEmpleado* this,int edad)
{
	int retorno=-1;

		if(this != NULL && edad > 0 )
		{
			retorno = 0;
			this->edad = edad;
		}

		return retorno;
}
/***************************************************************************************/
int Empleado_getEdad(eEmpleado* this,int* edad)
{
	int retorno=-1;

	if(this != NULL)
	{
		retorno = 0;
		*edad = this->edad;
	}

	return retorno;
}
/***************************************************************************************/
int Empleado_setHorasTrabajadas(eEmpleado* this,int horas)
{
	int retorno=-1;

		if(this != NULL && horas > 0 )
		{
			retorno = 0;
			this->horasTrabajadas = horas;
		}

		return retorno;
}
/***************************************************************************************/
int Empleado_getHorasTrabajadas(eEmpleado* this,int* horas)
{
	int retorno=-1;

	if(this != NULL)
	{
		retorno = 0;
		*horas = this->horasTrabajadas;
	}

	return retorno;
}
/***************************************************************************************/
void Empleado_mostrar(eEmpleado* oneEmpleado)
{
	int id;
	char nombre[100];
	char empleo[50];
	char dedicacion[50];
	int edad;
	int horasTrabajadas;


	if(oneEmpleado != NULL)
	{
		Empleado_getID(oneEmpleado, &id);
		Empleado_getNombre(oneEmpleado, nombre);
		Empleado_getEmpleo(oneEmpleado, empleo);
		Empleado_getEdad(oneEmpleado, &edad);
		Empleado_getHorasTrabajadas(oneEmpleado, &horasTrabajadas);
		Empleado_getDedicacion(oneEmpleado, dedicacion);

		printf("%-4d\t%s\t%s\t%d\t%d\t%s\n",id,nombre,empleo,edad,horasTrabajadas,dedicacion);
	}
	else
	{
		printf("\nError\n");
	}
}
/***************************************************************************************/
int Empleado_OrdenaNombre(void* pEmpleadoUno , void* pEmpleadoDos)
{
	int retorno = -1;
	char nombreEmpleadoUno[30];
	char nombreEmpleadoDos[30];
	eEmpleado* EmpleadoUno = NULL;
	eEmpleado* EmpleadoDos = NULL;

	if(pEmpleadoUno != NULL && pEmpleadoDos != NULL)
	{
		EmpleadoUno = (eEmpleado*)pEmpleadoUno;
		EmpleadoDos =  (eEmpleado*)pEmpleadoDos;

		if(EmpleadoUno != NULL && EmpleadoDos != NULL)
		{
			Empleado_getNombre(EmpleadoUno, nombreEmpleadoUno);
			Empleado_getNombre(pEmpleadoDos, nombreEmpleadoDos);
			retorno = strcmp(nombreEmpleadoUno,nombreEmpleadoDos);
		}
	}

	return retorno;
}
/***************************************************************************************/
int Empleado_Dedicacion(void* pElemento)
{
	int retorno = -1;
	eEmpleado* unEmpleado = NULL;
	int HorasTrabajadas;

	if(pElemento != NULL)
	{
		unEmpleado = (eEmpleado*)pElemento;

		if(unEmpleado != NULL)
		{
			Empleado_getHorasTrabajadas(unEmpleado, &HorasTrabajadas);

			if(HorasTrabajadas >= 1 && HorasTrabajadas <= 200)
			{
				Empleado_setDedicacion(unEmpleado, "Estandar");
			}
			else
			{
				if(HorasTrabajadas >= 201 && HorasTrabajadas <= 300)
				{
					Empleado_setDedicacion(unEmpleado, "Sobre la media");
				}
				else
				{
					if(HorasTrabajadas > 300 )
					{
						Empleado_setDedicacion(unEmpleado, "Excesivo");
					}
				}
			}
		}

		retorno = 0;
	}



	return retorno;
}
/***************************************************************************************/
int Empleado_filter21(void* pElemento)
{
	int retorno = -1;

	eEmpleado* unEmpleado = NULL;
	int edad;

	if(pElemento != NULL)
	{
		unEmpleado = (eEmpleado*)pElemento;

		if(unEmpleado != NULL)
		{
			Empleado_getEdad(unEmpleado, &edad);

			if(edad < 21)
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
