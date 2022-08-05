/*
 * utn.h
 *
 *  Created on: 7 jun 2022
 *      Author: Rodri
 */



#ifndef UTN_H_
#define UTN_H_

/********************************************/
//
//Funciones de validacion utn
//
int esNumerica(char* cadena, int limite);
int getInt(int* pResultado);
int esFlotante(char* cadena);
int getFloat(float* pResultado);
int getString(char* cadena, int longitud);
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int esNombre(char* cadena,int longitud);
int getNombre(char* pResultado,int longitud);
int esDescripcion(char* cadena,int longitud);
int getDescripcion(char* pResultado, int longitud);
int getDni(char* pResultado, int longitud);
/********************************************/
//
//Funciones mias de validaciones//
//
/**
 * valida que lo ingresado sea un numero
 */
int validarNumero(char *numero);
/********************************************/
/**
 * se pide un numero entero, si se ingresa correctamente,el programa sigue,si no se ingresa
 * correctamente ese muestra un mensaje de error (sabe si es correcto o no ya que hace utilizacion de validar numero)
 */
int pedirEntero(char *mensaje,char *mensajeError);
/********************************************/
int menu();
/********************************************/
int menu_modificar();
/********************************************/
int menu_ordenar();
/********************************************/
void mensajeAviso();
/********************************************/
void mensajeAviso2();
/********************************************/
void mensajeAviso3();
/********************************************/
void mensajeAviso4();
/********************************************/

#endif /* UTN_H_ */
