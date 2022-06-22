/*
 * biblioteca.c
 *
 *  Created on: 14 jun 2022
 *      Author: Rodri
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "biblioteca.h"
#include "validaciones.h"


/**************************************************************************/
/***********************HARDCODE Y LISTADO DE STRUC************************/
/**************************************************************************/

/**************************************************************************/
void hardcodeArtista(eArtista lista[],int tamanioDA)
{
	int id[]={1,2,3,4,5};
	char nombreArtista[][51]={"Keo","Khea","Duki","Lil Uzi","Drake"};
	int i=0;

	for(i=0;i<tamanioDA;i++)
	{
		lista[i].idArtista = id[i];
		strcpy(lista[i].nombreArtista,nombreArtista[i]);
	}
}
/**************************************************************************/
void hardcodeDiscografica(eDiscografica lista[],int tamanioDA)
{
	int id[]={1,2,3,4,5};
	char descripcion[][51]={"Warner","HBO","EPIC","Itunes","Juicy"};
	int i=0;

	for(i=0; i<tamanioDA; i++)
	{
		lista[i].idDiscografica = id[i];
		strcpy(lista[i].descripcion,descripcion[i]);
	}
}
/**************************************************************************/
void hardcodeTipoArtista(eTipoArtista lista[],int tam)
{
	int id[]={1,2};
	char descripcion2[][51]={"Solsita","Banda"};
	int i=0;

	for(i=0;i<tam;i++)
	{
		lista[i].idTipoArtista = id[i];
		strcpy(lista[i].descripcion2,descripcion2[i]);
	}
}
/**************************************************************************/
void hardcodePaises(ePais listaPaises[],int tamanio)
{
	int id[]={1,2,3,4,5};
	char descripcion[][51]={"Alemania","Argentina","Ucrania","Estados Unidos","Peru"};
	int i=0;

	for(i=0;i<tamanio;i++)
	{
		listaPaises[i].idPais = id[i];
		strcpy(listaPaises[i].descripcion,descripcion[i]);
	}
}
/**************************************************************************/
void listarArtistas(eArtista listaArtistas[],int tamanioDA)
{
	int i;

	hardcodeArtista(listaArtistas, tamanioDA);
	printf("\n===========================================================================");
	printf("\nCodigo \tArtistas\n");
	for(i = 0;i<tamanioDA;i++)
	{
		printf("\n %d\t  %s\n",listaArtistas[i].idArtista,listaArtistas[i].nombreArtista);
	}
	printf("\n===========================================================================");
	printf("\n");
}
/**************************************************************************/
void listarDiscograficas(eDiscografica listaDiscograficas[],int tamanioDA)
{
	int i;

	hardcodeDiscografica(listaDiscograficas, tamanioDA);
	printf("\n===========================================================================");
	printf("\nCodigo \tDiscograficas\n");
	for(i = 0;i<tamanioDA;i++)
	{
		printf("\n %d\t  %s\n",listaDiscograficas[i].idDiscografica,listaDiscograficas[i].descripcion);
	}
	printf("\n===========================================================================");
	printf("\n");
}
/**************************************************************************/
void listarPais(ePais listaPaises[],int tamanio)
{
	int i;
	hardcodePaises(listaPaises, tamanio);
	printf("\n===========================================================================");
	printf("\nCodigo  \tPaises\n");
	for(i = 0;i<tamanio;i++)
	{
		printf("\n %d\t       %s\n",listaPaises[i].idPais,listaPaises[i].descripcion);
	}
	printf("\n===========================================================================");
	printf("\n");
}
/**************************************************************************/
void listarTipoArtista(eTipoArtista listaTipoArtista[],int tamanio)
{
	int i;

	hardcodeTipoArtista(listaTipoArtista, tamanio);
	printf("\n===========================================================================");
	printf("\nCodigo  \tTipo Artista\n");
		for(i = 0;i<tamanio;i++)
		{
			printf("\n %d\t           %s\n",listaTipoArtista[i].idTipoArtista,listaTipoArtista[i].descripcion2);
		}
		printf("\n===========================================================================");
		printf("\n");
}
/**************************************************************************/




/**************************************************************************/
/***********************FUNCIONES GENERALES USADAS*************************/
/**************************************************************************/


int modificarPaises(ePais listaPaises[],int tamanio)
{
	int opcion;
	listarPais(listaPaises, tamanio);
	opcion = pedirFecha("\nElija su nuevo Pais:", "ERROR", 1, 5);
	return opcion;
}
/**************************************************************************/
void listaModificar(eAlbum listaAlbum[],ePais listaPaises[],int tamanio,int i)
{
    int opcion;

    do{
        opcion = pedirEntero("\n1-Cambiar Titulo\n2-Cambiar Fecha\n3-Cambiar importe\n4-Cambiar pais\n5-Salir\nOpcion: ", "\nError ingrese un numero\n");

        switch( opcion )
        {
        case 1:
            validarCadena("Ingrese el titulo del Album ",listaAlbum[i].titulo);
        break;
        case 2:
            printf("Ingrese su fecha de publicacion \n");
            listaAlbum[i].fechaDePublicacion.dia = pedirFecha("Dia: ","Error dia invalido\n",1,31);
            listaAlbum[i].fechaDePublicacion.mes = pedirFecha("Mes: ","Error mes invalido\n",1,12);
            listaAlbum[i].fechaDePublicacion.anio= pedirFecha("Año: ","Error año invalido\n",1800,2022);
        break;
        case 3:
            listaAlbum[i].importe = pedirNumFlotante("Importe: ","Error importe invalido\n",1,10000);
         break;

        case 4:
        	listarPais(listaPaises, tamanio);
        	listaAlbum[i].pais = pedirFecha("\nNuevo Pais:", "ERROR", 1, 5);
        break;
        case 5:
        	printf("\nSaliendo de modificar...\n\n");
        break;
        default:
            printf("\nLa opcion ingresada es incorrecta...\n");
        break;
        }
    }while( opcion != 5 );

}
/**************************************************************************/

//////////////////////////////////////////////////////////////////////////////////////////////////////
void inicializarVector(eAlbum listaAlbum [],int tamanio)
{
	int i;
	if(listaAlbum != NULL)
	{
		for(i=0;i<tamanio;i++)
		{
			listaAlbum[i].estado = 0;
			listaAlbum[i].idAlbum = 0;
		}
	}

}
//////////////////////////////////////////////////////////////////////////////////////////////////////
int buscarLibre(eAlbum listaAlbum[],int tamanio)
{
	int index = -1;
	int i;

	for(i=0;i<tamanio;i++)//1
	{
		if(listaAlbum[i].estado == 0)
		{
			index = i;//1
			break;
		}
	}
	return index;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void pedir_Datos(eAlbum listaAlbum[],ePais listaPaises[], int tamanio,int indice,eDiscografica listaDiscograficas[],eArtista listaArtista[],int tamanioDA,eTipoArtista listaTipoArtista[],int tamanioTA)
{

        printf("\n================================COMPLETAR================================\n\n");

        listarArtistas(listaArtista, tamanioDA);
        printf("\nEliga un artista x su id:");
        scanf("%d",&listaAlbum[indice].artista);

        listarTipoArtista(listaTipoArtista, tamanioTA);
        printf("\nEliga si es artista o banda x su id:");
        scanf("%d",&listaAlbum[indice].tipoArtista);

        listarDiscograficas(listaDiscograficas, tamanioDA);
        printf("\nEliga una discografica x su id:");
        scanf("%d",&listaAlbum[indice].discografica);

        listarPais(listaPaises, tamanio);
        printf("\nEliga un pais x su id:");
        scanf("%d",&listaAlbum[indice].pais);

		printf("Ingrese el titulo del album:");
		fflush(stdin);
		scanf("%[^\n]",listaAlbum[indice].titulo);

		printf("Fecha de publicacion del album:\n");
		listaAlbum[indice].fechaDePublicacion.anio = pedirFecha("Año del album:", "Año invalido,reingresar año\n", 1800, 2022);

		listaAlbum[indice].fechaDePublicacion.mes = pedirFecha("Mes del album:", "Mes invalido,reingresar mes\n",1 ,12);

		listaAlbum[indice].fechaDePublicacion.dia = pedirFecha("Dia del album:", "Dia invalido,reingresar dia\n",1 ,31);


		printf("Ingrese el valor de importe: ");
		scanf("%f",&listaAlbum[indice].importe);

		printf("\n============================================================================\n");

}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void altaAlbum(eAlbum listaAlbum[],ePais listaPaises[],int tamanio,int indice,int contador,eDiscografica listaDiscograficas[],eArtista listaArtista[],int tamanioDA,eTipoArtista listaTipoArtista[],int tamanioTA)
{
	indice = buscarLibre(listaAlbum,tamanio);

	if(indice != -1)
	{
		pedir_Datos(listaAlbum,listaPaises, tamanio, indice, listaDiscograficas, listaArtista, tamanioDA, listaTipoArtista, tamanioTA);

		listaAlbum[indice].estado = 1;
		listaAlbum[indice].idAlbum = contador;
	}
	else
	{
		printf("Full list!!!");
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
float precioTotal(eAlbum listaAlbum[],int tamanio)
{
	float retorno=0;
	int i;

	for(i=0;i<tamanio;i++)
	{
		if(listaAlbum[i].estado == 1)
		{
			retorno = retorno+listaAlbum[i].importe;
		}
	}
	return retorno;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
float precioPromedio(eAlbum listaAlbum [],int tamanio, int cantidad)
{

	float retorno;
	float can;

	can = precioTotal(listaAlbum,tamanio);

	retorno=can/cantidad;

	return retorno;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
float superaElPromedio(eAlbum listaAlbum [],int tamanio, int cantidad)
{
	float retorno=0;
	float promedio;
	int i;

	promedio = precioPromedio(listaAlbum,tamanio,cantidad);

	for(i=0;i<tamanio;i++)
	{
		if(listaAlbum[i].estado == 1)
		{
			if (listaAlbum[i].importe < promedio)
			{
				retorno++;
			}
		}
	}

	return retorno;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
int albumFechaPosterior(eAlbum listaAlbum[],int tamanio,int contadorAnio)
{
	int i;
	int retorno=0;

	for(i=0;i<tamanio;i++)
	{
		if(listaAlbum[i].fechaDePublicacion.anio > 1999 && listaAlbum[i].estado == 1)
		{
			retorno=contadorAnio++;
		}

	}
	printf("La cantidad de albumes con fecha posterior al año 1999 es de: %d albumes\n",contadorAnio);
	return retorno;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
int darDeBaja(eAlbum listaAlbum[],ePais listaPaises[], int tamanio,eDiscografica listaDiscograficas[],eArtista listaArtista[],int tamanioDA,eTipoArtista listaTipoArtista[],int tamanioTA)
{
	int auxId;
	int i;
	int retorno;

	retorno = 1;

	mostrarAlbums(listaAlbum, listaPaises, tamanio, listaDiscograficas, listaArtista, tamanioDA, listaTipoArtista, tamanioTA);

	printf("\nID a dar de baja:");//lamar funcion
	scanf("%d",&auxId);

		for(i=0 ; i < tamanio ; i++)
		{
			if(auxId == listaAlbum[i].idAlbum && listaAlbum[i].estado == 1)
			{
				retorno = 0;
				listaAlbum[i].estado = -1;
			}
			else
			{
				if(auxId != listaAlbum[i].idAlbum && listaAlbum[i].estado != 1 )
				{
					printf("\nID NO ENCONTRADO...\n");
					break;
				}
			}

		}
		printf("\n===========================================================================\n");

		return retorno;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
int modificar(eAlbum listaAlbumes [],ePais listaPaises[],int tamanio)
{
    int i;
    int mis;
    int retorno=-1;

    printf("Ingrese Codigo: ");
    scanf("%d", &mis);

    for(i=0;i<tamanio;i++)
    {
        if(mis == listaAlbumes[i].idAlbum)
        {
            retorno = 1;
            listaModificar(listaAlbumes,listaPaises,tamanio,i);
        }
    }
    return retorno;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void informar(eAlbum listaAlbum[],int tamanio,int contador)
{
	float precio;
	float promedio;
	float promedioSuperior;
	int contadorAnio=0;

	printf("\n================================INFORMACION==================================\n");
			precio = precioTotal(listaAlbum, tamanio);
			printf("El precio total es de: $%.2f\n",precio);

			promedio = precioPromedio(listaAlbum, tamanio, contador);
			printf("El precio promedio es de: $%.2f\n",promedio);

			promedioSuperior = superaElPromedio(listaAlbum, tamanio, contador);
			printf("La cantidad de albumes que no superan el promedio es:%2.f albumes\n",promedioSuperior);

			albumFechaPosterior(listaAlbum,tamanio,contadorAnio);
			printf("===========================================================================");
			printf("\n\n");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrarAlbums(eAlbum listaAlbum[],ePais listaPaises[], int tamanio,eDiscografica listaDiscograficas[],eArtista listaArtista[],int tamanioDA,eTipoArtista listaTipoArtista[],int tamanioTA)
{
	int i,j,k,l,m;
	printf("\n=================================Albums==================================\n");
	printf("ID\tTITULO\tDISCOGRAFICA\tARTISTA\tTIPO DE ARTISTA\tPRECIO\tPAIS\n");
	printf("=========================================================================\n");
	for(i=0;i<tamanio;i++)
	{
		if(listaAlbum[i].estado == 1 )
		{
		 for(j=0;j<tamanioDA;j++)
		 {
			 if(listaAlbum[i].discografica == listaDiscograficas[j].idDiscografica)
			 {
				 for(k=0;k<tamanioDA;k++)
				 {
					 if(listaAlbum[i].artista == listaArtista[k].idArtista)
					 {
						 for(l=0;l<tamanioTA;l++)
						 {
							 if(listaAlbum[i].tipoArtista == listaTipoArtista[l].idTipoArtista)
							 {
								for(m=0;m<tamanio;m++)
								{
									if(listaAlbum[i].pais == listaPaises[m].idPais)
									{
										printf("%d\t%s\t    %s\t   %s\t  %s\t$%.0f\t%s\n",listaAlbum[i].idAlbum,listaAlbum[i].titulo,listaDiscograficas[j].descripcion,listaArtista[k].nombreArtista,listaTipoArtista[l].descripcion2,listaAlbum[i].importe,listaPaises[m].descripcion);
									}
								}
							 }
						 }
					 }
				 }
			 }
		 }
		}
	}
	printf("=========================================================================");
	printf("\n\n");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
int ordenamintoAlbumsTituloImporte(eAlbum listaAlbum[],int tamanio)
{
    int retorno = -1;
    int i, j;
    eAlbum aux;

    for(i=0;i<tamanio;i++)
    {
    	if(listaAlbum[i].estado == 1)
    	{
    		for(j= i+1;j<tamanio;j++)
    		{
    			if(strcmp(listaAlbum[i].titulo,listaAlbum[j].titulo) > 0)
    			{
    				aux = listaAlbum[i];
    				listaAlbum[i] = listaAlbum[j];
    				listaAlbum[j] = aux;
    				retorno = 0;
    			}
    			else
    			{
    				if(strcmp(listaAlbum[i].titulo,listaAlbum[j].titulo) == 0)
    				{
    					if(listaAlbum[i].importe < listaAlbum[j].importe)
    					{
    						aux = listaAlbum[i];
    						listaAlbum[i] = listaAlbum[j];
    						listaAlbum[j] = aux;
    					}
    				}
    			}

    		}
    	}
    }
    return retorno;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrarNoSuperaPromedio(eAlbum listaAlbum [],int tamanio, int cantidad)
{
    float promedio;
    int i;

    promedio = precioPromedio(listaAlbum,tamanio,cantidad);

    for(i=0;i<tamanio;i++)
    {
        if(listaAlbum[i].estado == 1)
        {
            if (listaAlbum[i].importe < promedio)
            {
                printf("%s\n",listaAlbum[i].titulo);
            }
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void albumnesDeUnArtista(eAlbum *listaAlbum,eArtista *listaArtista,int tamanioDA)
{
	int i;
	int auxId;
	int flag=0;

	printf("============================Lista de artistas============================");
	listarArtistas(listaArtista, tamanioDA);
	printf("Eliga un artista o banda por id:");
	scanf("%d",&auxId);

	for(i=0;i<tamanioDA;i++)
	{
		if(listaAlbum[i].artista==auxId && listaAlbum[i].estado==1)
		{
			printf("\nTitulo del album: %s",listaAlbum[i].titulo);
			flag=1;
		}
	}
	if(flag == 0)
	{
		printf("El artista o banda elegida no tiene albumes ingresados");
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
int albumPorFecha(eAlbum *listaAlbum, int tamanio)
{
	int auxAnio[tamanio];
	int i,j;

	for(i=0; i<tamanio; i++) //recorro auxiliar de anios
	{
		auxAnio[i] = -1; //inicializo
	}

	for(i=0; i<tamanio; i++)
	{
		if(listaAlbum[i].estado == 1)
		{
			auxAnio[i] = listaAlbum[i].fechaDePublicacion.anio;
		}
	}

	for(i=0; i<tamanio-1; i++)
	{
		for(j=i+1; j<tamanio; j++)
		{
			if(auxAnio[i] == auxAnio[j])
			{
				auxAnio[j]=-1; //borro repetidos
			}
		}
	}

	if(listaAlbum!=NULL && tamanio > 0)
	{
		printf("\n==============================ALBUMES POR FECHA==============================");

		for(i=0; i<tamanio; i++)//aux
		{
			if(auxAnio[i] != -1)
			{
				printf("\nAÑO: %d",auxAnio[i]);

				for(j=0; j<tamanio; j++)
				{
					if(listaAlbum[j].estado == 1 && auxAnio[i] == listaAlbum[j].fechaDePublicacion.anio)
					{
						printf("\t%s",listaAlbum[j].titulo);
					}
				}
			}
		}
		printf("\n===========================================================================");
		printf("\n\n");
		return 0;
	}
	return -1;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
void albumsBaratos(eAlbum *listaAlbum,int tamanio)
{
	int i;
	int min;
	int flag=0;

	for(i=0;i<tamanio;i++)
	{
		if(listaAlbum[i].estado==1)
		{
			if(flag == 0||listaAlbum[i].importe < min)
			{
				flag = 1;
				min = listaAlbum[i].importe;
			}
		}
	}

	for(i=0;i<tamanio;i++)
	{
		if(listaAlbum[i].importe==min)
		{
			printf("\nTitulo:%s",listaAlbum[i].titulo);
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void paisQueNoSeaArgentina(eAlbum listaAlbum[],ePais listaPaises[],int tamanio)
{
	int i,j;
	int flag = 0;

		for(i=0;i<tamanio;i++)
		{
			if(listaAlbum[i].estado==1 && listaAlbum[i].pais != 2)
			{
				for(j=0;j<tamanio;j++)
					{
						if(listaPaises[j].idPais == listaAlbum[i].pais)
						{
							printf("TITULO:%s\tPAIS:%s\n",listaAlbum[i].titulo,listaPaises[j].descripcion);
							flag = 1;
						}
					}
			}

		}
		if(flag==0)
		{
			printf("\nNo hay albumes que no sean distintos a Argentina\n");
		}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void albumsDeArgentinaPorFecha(eAlbum listaAlbum[],ePais listaPaises[],int tamanio)
{
	int i,j;
	int auxFecha;

	printf("\nIngrese el año de los albums de argentina a mostrar:");
	scanf("%d",&auxFecha);

	for(i=0;i<tamanio;i++)
	{
		if(listaAlbum[i].estado == 1 && listaAlbum[i].pais == 2 && auxFecha == listaAlbum[i].fechaDePublicacion.anio )
		{
			for(j=0;j<tamanio;j++)
			{
				if(listaAlbum[i].pais == listaPaises[j].idPais)
				{
					printf("AÑO:%d\tTITULO:%s\tPAIS:%s\n",listaAlbum[i].fechaDePublicacion.anio,listaAlbum[i].titulo,listaPaises[j].descripcion);
				}
			}
		}

	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
//INFORMAR LA CANTIDAD DE SOLISTAS DE UN AÑO Y PAIS DETERMINADO
void cantidadSolistas(eAlbum listaAlbum[],ePais listaPais[],int tamanio)
{

	int auxFecha;
	int auxPais;
	int i;
	int contadorSolistas = 0;

	printf("\nIngrese el año:");
	scanf("%d",&auxFecha);

	listarPais(listaPais, tamanio);
	printf("\nIngrese el id del pais a buscar:");
	scanf("%d",&auxPais);

	for(i=0;i<tamanio;i++)
	{
		if(listaAlbum[i].estado == 1 && listaAlbum[i].tipoArtista == 1 && listaAlbum[i].fechaDePublicacion.anio == auxFecha && auxPais == listaAlbum[i].pais)
		{
			contadorSolistas++;
		}
	}
	printf("\nAÑO:%d\tCantidad de solistas:%d",auxFecha,contadorSolistas);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void albumsBandaDistintoArgentina(eAlbum listaAlbum[],ePais listaPaises[], int tamanio,eDiscografica listaDiscograficas[],eArtista listaArtista[],int tamanioDA,eTipoArtista listaTipoArtista[],int tamanioTA)
{
	int i,j,k,l,m;
	printf("\n=================================Albums==================================\n");
	printf("ID\tTITULO\tDISCOGRAFICA\tARTISTA\tTIPO DE ARTISTA\tPRECIO\tPAIS\tAÑO\tMES\tDIA\n");
	printf("=========================================================================\n");
	for(i=0;i<tamanio;i++)
	{
		if(listaAlbum[i].estado == 1 && listaAlbum[i].tipoArtista == 2 && listaAlbum[i].pais != 2)
		{
		 for(j=0;j<tamanioDA;j++)
		 {
			 if(listaAlbum[i].discografica == listaDiscograficas[j].idDiscografica)
			 {
				 for(k=0;k<tamanioDA;k++)
				 {
					 if(listaAlbum[i].artista == listaArtista[k].idArtista)
					 {
						 for(l=0;l<tamanioTA;l++)
						 {
							 if(listaAlbum[i].tipoArtista == listaTipoArtista[l].idTipoArtista)
							 {
								for(m=0;m<tamanio;m++)
								{
									if(listaAlbum[i].pais == listaPaises[m].idPais)
									{
										printf("%d\t%s\t    %s\t   %s\t  %s\t$%.0f\t%s\t%d\t%d\t%d\n",listaAlbum[i].idAlbum,listaAlbum[i].titulo,listaDiscograficas[j].descripcion,listaArtista[k].nombreArtista,listaTipoArtista[l].descripcion2,listaAlbum[i].importe,listaPaises[m].descripcion,listaAlbum[i].fechaDePublicacion.anio,listaAlbum[i].fechaDePublicacion.mes,listaAlbum[i].fechaDePublicacion.dia);
									}
								}
							 }
						 }
					 }
				 }
			 }
		 }
		}
	}
	printf("=========================================================================");
	printf("\n\n");
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void listadoReal(eAlbum listaAlbum[],ePais listaPaises[],int tamanio,eDiscografica listaDiscograficas[],eArtista listaArtista[],int tamanioDA,eTipoArtista listaTipoArtista[],int tamanioTA,int contador)
{
	int opcionListar;
	int contadorAnio=0;

		do
		{
			opcionListar = listado();

			switch(opcionListar)
			{
			case 1:
				listarDiscograficas(listaDiscograficas, tamanioDA);
			break;
			case 2:
				listarTipoArtista(listaTipoArtista, tamanioTA);
			break;
			case 3:
				listarArtistas(listaArtista, tamanioDA);
			break;
			case 4:
				mostrarAlbums(listaAlbum,listaPaises,tamanio,listaDiscograficas,listaArtista,tamanioDA,listaTipoArtista,tamanioTA);
			break;
			case 5:
				ordenamintoAlbumsTituloImporte(listaAlbum, tamanio);
				mostrarAlbums(listaAlbum,listaPaises,tamanio,listaDiscograficas,listaArtista,tamanioDA,listaTipoArtista,tamanioTA);
			break;
			case 6:
				albumFechaPosterior(listaAlbum,tamanio,contadorAnio);
			break;
			case 7:
				 printf("\nAlbumes que no superan el Promedio: \n");
				 mostrarNoSuperaPromedio(listaAlbum,tamanio,contador);
			break;
			case 8:
				albumnesDeUnArtista(listaAlbum, listaArtista, tamanioDA);
			break;
			case 9:
				albumPorFecha(listaAlbum, tamanio);
			break;
			case 10:
				albumsBaratos(listaAlbum, tamanio);
			break;
			case 11:
				listarPais(listaPaises, tamanio);
			break;
			case 12:
				paisQueNoSeaArgentina(listaAlbum, listaPaises, tamanio);
			break;
			case 13:
				albumsDeArgentinaPorFecha(listaAlbum, listaPaises, tamanio);
			break;
			case 14:
				cantidadSolistas(listaAlbum,listaPaises ,tamanio);
			break;
			case 15:
				albumsBandaDistintoArgentina(listaAlbum,listaPaises,tamanio,listaDiscograficas,listaArtista,tamanioDA,listaTipoArtista,tamanioTA);
			break;
			case 16:
				printf("\nSaliste del listado...\n");
			break;
			default:
				printf("\nWrong option...");
			break;
			}

		}while(opcionListar != 16);

}
//////////////////////////////////////////////////////////////////////////////////////////////////////
