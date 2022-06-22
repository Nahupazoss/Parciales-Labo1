/*
 * validaciones.c
 *
 *  Created on: 22 jun 2022
 *      Author: Rodri
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "biblioteca.h"
#include "validaciones.h"

/**************************************************************************/
/************************FUNCIONE DE VALIDACIONES**************************/
/**************************************************************************/
int validarNumero(char numero[])//crear funcion
{
    int retorno=1;
    int len;
    if(numero!= NULL){
        len=strlen(numero);
        for(int i=0;i<len;i++){ //"51"
            if(!isdigit(numero[i])){
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}
/**************************************************************************/
int pedirEntero(char mensaje[],char mensajeError[])//crear funcion
{
    int retorno;
    char numero[1000];
    printf(mensaje);
    scanf("%s",numero);
    while(!validarNumero(numero)){
        printf(mensajeError);
        printf(mensaje);
        scanf("%s",numero);
    }
    retorno=atoi(numero);
    return retorno;
}
/**************************************************************************/
int menu()
{
	int opcion;

	opcion = pedirEntero("1-ALTA\n2-MODIFICAR\n3-BAJA\n4-INFORMAR\n5-LISTADO\n6-SALIR\nOPCION:", "ERROR\n");

	return opcion;
}
/**************************************************************************/
int	subMenu()
{
	int opcion1;

	opcion1 = pedirEntero("\nCHANGE:\n1-Titulo\n2-Importe:\n3-Año:\n4-Mes:\n5-Dia:\n6-OUT\nOpcion:","ERROR\n");
	return opcion1;
}
/**************************************************************************/
int listado()
{
	int opcion2;

	opcion2 = pedirEntero("\n=================================LISTAR=================================="
			"\n1-Todas las discograficas\n2-Todos los tipos de Artistas musicales"
			"\n3-Todos Los artistas\n4-Todos los albumes\n5-Todos los albumes ordenados por importe y titulo"
			"\n6-Todos los albumes cuya fecha de publicacion es posterior al 31/12/1999"
			"\n7-Todos los albumes que no superas el promedio de los importes"
			"\n8-Todos los albumes de un artista determinado\n9-Todos los albumes de cada año"
			"\n10-El o los albumes mas baratos"
			"\n11-Listar todos los paises\n12-Listar todos los albumes que no son de argentina"
			"\n13-Listar todos los albumes de argentina\n14-Informar la cantidad de solistas de un año y pais determinado"
			"\n15-Listar todas las bandas de paises extranjeros"
			"\n16-Salir"
			"\n========================================================================="
			"\nOPCION:","Error,opcion no valida\n");
	return opcion2;
}
/**************************************************************************/
float pedirNumFlotante(char mensaje[],char mensajeError[], int min, int max)//crear funcion
{
    float numero;

    printf(mensaje);
    scanf("%f",&numero);

    while(numero > max || numero < min)
    {
        printf(mensajeError);
        printf(mensaje);
        scanf("%f",&numero);
    }
    return numero;
}
/**************************************************************************/
void validarCadena(char mensaje[], char cadena[])
{
    char aux[1024];
    int cantidad;
    do
    {
        printf(mensaje);
        fflush(stdin);
        scanf("%[^\n]",aux);
        cantidad = strlen(aux);

    }while(cantidad > 50);

    strcpy(cadena,aux);
}
/**************************************************************************/
int pedirFecha(char mensaje[],char mensajeError[],int min,int max)//crear funcion
{
    int numero;

    printf(mensaje);
    scanf("%d",&numero);

    while(numero > max || numero < min)
    {
    	printf(mensajeError);
    	printf(mensaje);
    	scanf("%d",&numero);
    }
    return numero;
}
/**************************************************************************/

