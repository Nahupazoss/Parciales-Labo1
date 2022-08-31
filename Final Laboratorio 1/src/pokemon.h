/*
 * pokemon.h
 *
 *  Created on: 30 ago. 2022
 *      Author: Rodri
 */

#ifndef POKEMON_H_
#define POKEMON_H_

typedef struct
{
	int numero;
	char nombre[50];
	char tipo[50];
	char tamanio[50];
	char ataqueCargado[50];
	int valorAtaque;
	int esVarioColor;
}ePokemon;
/************************************************/
ePokemon* pokemon_new();
/************************************************/
ePokemon* pokemon_newParametros(char* numero,char* nombre,char* tipo,char* tamanio,char* ataqueCargado,char* valorAtaque,char* esVarioColor);
/************************************************/
/************************************************/
int pokemon_setNum(ePokemon* this,int numero);

int pokemon_getNum(ePokemon* this,int* numero);
/************************************************/
int pokemon_setNombre(ePokemon* this,char* nombre);

int pokemon_getNombre(ePokemon* this,char* nombre);
/************************************************/
int pokemon_setTipo(ePokemon* this,char* tipo);

int pokemon_getTipo(ePokemon* this,char* tipo);
/************************************************/
int pokemon_setTamanio(ePokemon* this,char* tamanio);

int pokemon_getTamanio(ePokemon* this,char* tamanio);
/************************************************/
int pokemon_setAtaqueCargado(ePokemon* this,char* ataqueCargado);

int pokemon_getAtaqueCargado(ePokemon* this,char* ataqueCargado);
/************************************************/
int pokemon_setValorAtaque(ePokemon* this,int valorAtaque);

int pokemon_getValorAtaque(ePokemon* this,int* valorAtaque);
/************************************************/
int pokemon_setEsVarioColor(ePokemon* this,int esVarioColor);

int pokemon_getEsVarioColor(ePokemon* this,int* esVarioColor);
/************************************************/
void pokemon_mostrar(ePokemon* unPokemon);
int pokemon_eliminar(LinkedList* pArrayListPokemon);
/************************************************/
int participante_getEdad(ePokemon* this,int* edad);
/************************************************/
int participante_OrdenaNombre(void* pParticipanteUno , void* pParticipanteDos);
/***********************************************/
int pokemon_filterWater(void* pElemento);

int pokemon_valorDelAtaque(void* pElemento);
int pokemon_batallaWater(void* pElemetno);
int pokemon_batallaFire(void* pElemetno);
/************************************************/


#endif /* POKEMON_H_ */
