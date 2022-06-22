/*
 * validaciones.h
 *
 *  Created on: 22 jun 2022
 *      Author: Rodri
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

/**************************************************************************/
/**************************FUNCIONES VALIDACIONES**************************/
/**************************************************************************/
/**
 *	Se pide el ingreso de un numero flotante y se verifica que este dentro de los rangos minimo y maximo.si no esta dentro
 *	del rango se muestra un mensaje de error
 */
float pedirNumFlotante(char mensaje[],char mensajeError[], int min, int max);
/**************************************************************************/
/**
 *
 */
void validarCadena(char mensaje[], char cadena[]);
/**************************************************************************/
/**
 *	se pide el ingreso de un numero
 */
int pedirEntero(char mensaje[],char mensajeError[]);
/**************************************************************************/
/**
 *	Se pide el ingreso de un numero y se valida si esta dentro de los rangos de minimo y maximo. si no esta dentro
 *	del rango se muestra un mensaje de error
 */
int pedirFecha(char mensaje[],char mensajeError[],int min,int max);
/**************************************************************************/
/**	Deberia ser void pero si la hago void no se porque no me funciona correctamente
 *
 */
int menu();
/**************************************************************************/
/**	Deberia ser void pero si la hago void no se porque no me funciona correctamente
 * Se muestran todas las opciones disponibles.
 */
int	subMenu();
/**************************************************************************/
/**	Deberia ser void pero si la hago void no se porque no me funciona correctamente
 * Se muestran todas las opciones disponibles.
 */
int listado();
/**************************************************************************/
/**
 * Se muestran las opciones posibles de ingresar y luego se pide y se guardan los datos ingresados
 */
void listaModificar(eAlbum listaAlbum[],ePais listaPaises[],int tamanio,int i);
/**************************************************************************/


#endif /* VALIDACIONES_H_ */
