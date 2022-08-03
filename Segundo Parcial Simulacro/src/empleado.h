/*
 * empleado.h
 *
 *  Created on: 28 jul. 2022
 *      Author: Rodri
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

typedef struct
{
	int id;
	char nombre[4000];
	char empleo[100];
	char dedicacion[100];
	int edad;
	int horasTrabajadas;
}eEmpleado;
/************************************************/
/**
 * reserva espacio en memoria dinamica para un nuevo nodo(computadora)
 */
eEmpleado* Empleado_new();
/************************************************/
/**
 * se setean todos los parametros obtenidos por los seters
 */
eEmpleado* Empleado_newParametros(char* idStr,char* nombre,char* empleo,char* edad,char* horas);
/************************************************/
/**
 * setea(modifica) los id
 */
int Empleado_setID(eEmpleado* this,int id);
/**
 * obtiene los id y los coloca en la posicion de la estructura
 */
int Empleado_getID(eEmpleado* this,int* id);
/************************************************/

/**
 * setea(modifica) la descripcion
 */
int Empleado_setNombre(eEmpleado* this,char* nombre);
/**
 * obtiene la descripcion y la coloca en la posicion de la estructura
 */
int Empleado_getNombre(eEmpleado* this,char* nombre);
/************************************************/
int Empleado_setDedicacion(eEmpleado* this,char* dedicacion);
/**
 * obtiene la descripcion y la coloca en la posicion de la estructura
 */
int Empleado_getDedicacion(eEmpleado* this,char* dedicacion);
/************************************************/
int Empleado_setEmpleo(eEmpleado* this,char* nombre);
/**
 * obtiene la descripcion y la coloca en la posicion de la estructura
 */
int Empleado_getEmpleo(eEmpleado* this,char* nombre);

/**
 * setea(modifica) el precio
 */
int Empleado_setEdad(eEmpleado* this,int edad);
/**
 * obtiene el precio y lo coloca
 */
int Empleado_getEdad(eEmpleado* this,int* edad);
/************************************************/
/**
 * setea(modifica) el idtipo
 */
int Empleado_setHorasTrabajadas(eEmpleado* this,int horas);
/**
 * obtiene el id tipo y lo coloca
 */
int Empleado_getHorasTrabajadas(eEmpleado* this,int* horas);
/************************************************/
/**
 * muestro todos los datos obtenidos por los getters
 */
void Empleado_mostrar(eEmpleado* oneEmpleado);
/************************************************/
/**
 * aplico aumentos segun que tipo de compu sean
 */
int computer_Porcentajes(void* pElemento);
/************************************************/
int Empleado_OrdenaNombre(void* pEmpleadoUno , void* pEmpleadoDos);
/************************************************/
int computer_ValorAgregado(void* pElemento);
/************************************************/
int Empleado_Dedicacion(void* pElemento);
/************************************************/
int Empleado_filter21(void* pElemento);
/************************************************/
#endif /* EMPLEADO_H_ */
