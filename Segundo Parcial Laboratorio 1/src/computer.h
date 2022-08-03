/*
 * computer.h
 *
 *  Created on: 29 jun 2022
 *      Author: Rodri
 */

#ifndef COMPUTER_H_
#define COMPUTER_H_

/*
 * computadoras.h
 *
 *  Created on: 28 jun 2022
 *      Author: Rodri
 */

#ifndef COMPUTADORAS_H_
#define COMPUTADORAS_H_

typedef struct
{
	int id;
	char descripcion[4000];
	float precio;
	int idTipo;
	int cuotas;
	int valorCuota;
}eComputer;
/************************************************/
/**
 * reserva espacio en memoria dinamica para un nuevo nodo(computadora)
 */
eComputer* computer_new();
/************************************************/
/**
 * se setean todos los parametros obtenidos por los seters
 */
eComputer* computer_newParametros(char* idStr,char* descripcion,char* precio,char* idtipo,char* cuotas);
/************************************************/

/**
 * setea(modifica) los id
 */
int computer_setID(eComputer* this,int id);
/**
 * obtiene los id y los coloca en la posicion de la estructura
 */
int computer_getID(eComputer* this,int* id);
/************************************************/

/**
 * setea(modifica) la descripcion
 */
int computer_setDescripcion(eComputer* this,char* descripcion);
/**
 * obtiene la descripcion y la coloca en la posicion de la estructura
 */
int computer_getDescripcion(eComputer* this,char* descripcion);
/************************************************/

/**
 * setea(modifica) el precio
 */
int computer_setPrecio(eComputer* this,float precio);
/**
 * obtiene el precio y lo coloca
 */
int computer_getPrecio(eComputer* this,float* precio);
/************************************************/

/**
 * setea(modifica) el idtipo
 */
int computer_setIdTipo(eComputer* this,int idTipo);
/**
 * obtiene el id tipo y lo coloca
 */
int computer_getIdTipo(eComputer* this,int* idTipo);
/************************************************/
/**
 *
 */
int computer_getCuotas(eComputer* this,int* cuotas);
/**
 *
 */
int computer_setCuotas(eComputer* this,int cuotas);
/************************************************/
/**
 * convierto el tipoid a un string para que al ingresar 1 o 2 se determine que clase de compu es
 */
int computer_tipoID(int id,char* tipo);
/************************************************/
int computer_setValorCuota(eComputer* this,int valorcuota);

int computer_getValorCuota(eComputer* this,int* valorCuenta);
/************************************************/
/**
 * muestro todos los datos obtenidos por los getters
 */
void computer_mostrar(eComputer* oneCompu);
/************************************************/
/**
 * aplico aumentos segun que tipo de compu sean
 */
int computer_Porcentajes(void* pElemento);
/************************************************/
int computer_OrdenaCuotas(void* pElementUno ,void* pElementDos);
/************************************************/
int computer_ValorAgregado(void* pElemento);
/************************************************/
#endif /* COMPUTADORAS_H_ */
#endif /* COMPUTER_H_ */
