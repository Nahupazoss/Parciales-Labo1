/*
 * biblioteca.h
 *
 *  Created on: 14 jun 2022
 *      Author: Rodri
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

/**************************************************************************/
typedef struct
{
	int idDiscografica;
	char descripcion[51];

}eDiscografica;
/**************************************************************************/
typedef struct
{
	int idArtista;
	char nombreArtista[51];
}eArtista;
/**************************************************************************/
typedef struct
{
	int idTipoArtista;
	char descripcion2[51];
}eTipoArtista;//(1 solista // 2 bandas)
/**************************************************************************/
typedef struct
{
	int dia;
	int mes;
	int anio;
}eFecha;
/**************************************************************************/
typedef struct
{
	int idPais;
	char descripcion[51];
}ePais;
/**************************************************************************/
typedef struct
{
	int idAlbum;
	char titulo[51];
	eFecha fechaDePublicacion;           //////principal
	float importe;
	int artista;
	int tipoArtista;
	int discografica;
	int estado;
	int pais;
}eAlbum;
/**************************************************************************/
/**************************FUNCIONES HARDCODE******************************/
/**************************************************************************/
/**Toda la estructura de eArtista hardcodeada segun los datos que le asigne
 *
 */
void hardcodeArtista(eArtista lista[],int tamanioDA);
/**************************************************************************/
/**Toda la esctructura de eTipoArtista hardcodeada segun los datos que le asigne
 *
 */
void hardcodeTipoArtista(eTipoArtista lista[],int tam);
/**************************************************************************/
/**
 * Toda la esctructura de eArtista hardocdeada segun los datos que le asigne
 */
void listarArtistas(eArtista listaArtistas[],int tamanio);
/**************************************************************************/
/**Muestra los codigos y discograficas asignadas en el hardcode
 *
 */
void listarDiscograficas(eDiscografica listaDiscograficas[],int tamanioDA);
/**************************************************************************/
/**Toda la estructura de paises harcodeada segun los datos que le asigne
 *
 */
void hardcodePaises(ePais listaPaises[],int tamanio);
/**************************************************************************/
/**Lista todos los paises
 *
 */
void listarPais(ePais listaPaises[],int tamanio);
/**************************************************************************/



/**************************************************************************/
/**************FUNCIONES UTILIZADAS PARA LAS CONSIGNAS*********************/
/**************************************************************************/
/**
 *	se verifica que el estado de lo que va a mostrar sea activo y luego se muestra el titulo e importe de cada uno de los albumes ingresados
 * @param listaAlbum
 * @param tamanio
 */
///
void mostrarAlbums(eAlbum listaAlbum[],ePais listaPaises[], int tamanio,eDiscografica listaDiscograficas[],eArtista listaArtista[],int tamanioDA,eTipoArtista listaTipoArtista[],int tamanioTA);
/**************************************************************************/
/**
 *
 */
void albumsDeArgentinaPorFecha(eAlbum listaAlbum[],ePais listaPaises[],int tamanio);
/**************************************************************************/
/**
 *	Ordena por doble criterio mediante el burbujeo , en este caso ordena  alfabeticamente y si se reptien x importe de mayor a menor
 * @param listaAlbum
 * @param tamanio
 */
int ordenamintoAlbumsTituloImporte(eAlbum listaAlbum[],int tamanio);
/**************************************************************************/
/**
 *	Muestra todos los titulos de los albumes los cuales no superan el promedioTotal
 * @param listaAlbum
 * @param tamanio
 */
void mostrarNoSuperaPromedio(eAlbum listaAlbumes [],int tamanio, int cantidad);
/**************************************************************************/
/**
 *	recorre un auxiliar de una determinada fecha y se inicializa en 1 , los repetidos se borran y luego se muestran
 *	los años que fueron ingresados con sus determinados albumes
 * @param listaAlbum
 * @param tamanio
 */
int albumPorFecha(eAlbum *listaAlbum, int tamanio);
/**************************************************************************/
/**
 *	Se verifica que el estado este activo y luego utilizo bandera para que en el primer importe sea el minimo ,
 *	en los proximos importes se comenzara a comparar los importes ingresados con ese primer importe que sera el minimo si hay uno menor al primero,
 *	sera el nuevo minimo
 * @param listaAlbum
 * @param tamanio
 */
void albumsBaratos(eAlbum *listaAlbum,int tamanio);
/**************************************************************************/
/**
 * inicializa todos los datos de eAlbum en 0
 * @param listaAlbum declaracion del main que se pasa a eAlbum
 * @param tamanio los espacios asignados con un define
 */
void inicializarVector(eAlbum listaAlbum [],int tamanio);
/**************************************************************************/
/**
 *	Busca todos los estados en 0
 * @param listaAlbum
 * @param tamanio
 */
int buscarLibre(eAlbum listaAlbum[],int tamanio);
/**************************************************************************/
/**
 *	Pido y guardo todos los datos mediante printf y scanf
 * @param listaAlbum
 * @param tamanio
 */
void pedir_Datos(eAlbum listaAlbum[],ePais listaPaises[], int tamanio,int indice,eDiscografica listaDiscograficas[],eArtista listaArtista[],int tamanioDA,eTipoArtista listaTipoArtista[],int tamanioTA);
/**************************************************************************/
/**
 *	Una vez encontrados los estados en 0 , pedido y guardado de datos , inicializo aquellos estados en 1
 * @param listaAlbum
 * @param tamanio
 */
void altaAlbum(eAlbum listaAlbum[],ePais listaPaises[],int tamanio,int indice,int contador,eDiscografica listaDiscograficas[],eArtista listaArtista[],int tamanioDA,eTipoArtista listaTipoArtista[],int tamanioTA);
/**************************************************************************/
/**
 *	Saco el precio total de todos los dado de alta
 * @param listaAlbum
 * @param tamanio
 */
float precioTotal(eAlbum listaAlbum[],int tamanio);
/**************************************************************************/
/**
 *	Saco el promedio de todos los dado en alta mediante el precio total dividido la cantidad
 * @param listaAlbum
 * @param tamanio
 */
float precioPromedio(eAlbum listaAlbum [],int tamanio, int cantidad);
/**************************************************************************/
/**
 *	Saco el promedio inferior preguntando si el importe es inferior al promedioTotal
 * @param listaAlbum
 * @param tamanio
 */
float superaElPromedio(eAlbum listaAlbum [],int tamanio, int cantidad);
/**************************************************************************/
/**
 * Cuenta todos los albumes que sean posteriores a una fecha determinada
 * @param listaAlbum
 * @param tamanio
 */
int albumFechaPosterior(eAlbum listaAlbum[],int tamanio,int contadorAnio);
/**************************************************************************/
/**
 *	Se pide el ingreso de un id que ya fue ingresado y se verifica de que exista y ese id este activo ,
 *	 una vez encontrado todo se realiza la baja asignandole un -1
 * @param listaAlbum
 * @param tamanio
 */
int darDeBaja(eAlbum listaAlbum[],ePais listaPaises[], int tamanio,eDiscografica listaDiscograficas[],eArtista listaArtista[],int tamanioDA,eTipoArtista listaTipoArtista[],int tamanioTA);
/**************************************************************************/
/**Realiza todos los llamados a las funciones determinadas y muestra mediante un printf los resultados de las funciones que se llamaron
 *
 */
void informar(eAlbum listaAlbum[],int tamanio,int contador);
/**************************************************************************/
/** *	Se pide un id a modificar y se verifica que exista una vez encontrado se hace el llamado a la funcion llamada	la cual pide el ingreso de los nuevos datos elegidos
 * @param listaAlbum
 * @param tamanio
 */
int modificar(eAlbum listaAlbumes [],ePais listaPaises[],int tamanio);
/**************************************************************************/
/**Contiene un listado donde se muestran todas las opciones luego se elige la opcion y muestra cada una de las funciones ingresadas en cada caso
 *
 * @param listaAlbum
 * @param tamanio
 */
void listadoReal(eAlbum listaAlbum[],ePais listaPaises[],int tamanio,eDiscografica listaDiscograficas[],eArtista listaArtista[],int tamanioDA,eTipoArtista listaTipoArtista[],int tamanioTA,int contador);
/**************************************************************************/
/**recorro dos for uno de ealbum y otro de epais y si se cumplen las condiciones del if muestro mensaje
 *
 */
void paisQueNoSeaArgentina(eAlbum listaAlbum[],ePais listaPaises[],int tamanio);
/**************************************************************************/
void cantidadSolistas(eAlbum listaAlbum[],ePais listaPais[],int tamanio);
/**************************************************************************/
void albumsBandaDistintoArgentina(eAlbum listaAlbum[],ePais listaPaises[], int tamanio,eDiscografica listaDiscograficas[],eArtista listaArtista[],int tamanioDA,eTipoArtista listaTipoArtista[],int tamanioTA);
#endif /* BIBLIOTECA_H_ */
