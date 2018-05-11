#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcion.h"
#include "informe.h"

#define LIBRE 1
#define OCUPADO 0

/**
** \brief
 *
 * \param mensaje char*
 * \param mensajeError char*
 * \param reIntentos int
 * \param minimo int
 * \param maximo int
 * \param resultado int*
 * \return int
 *
**/

/*
int getInt(char* mensaje,char* mensajeError,int reIntentos,int minimo,int maximo,int* resultado)
{
    int retorno = -1;
    char buffer[4096];
    long auxiliarLong;
    do
    {
        printf("%s",mensaje);
        scanf("%4095s",buffer);
        if(esEntero(buffer) == 0)
        {
            auxiliarLong = atol(buffer);
            if(auxiliarLong >= minimo && auxiliarLong <= maximo)
            {
                *resultado = (int)auxiliarLong;
                retorno = 0;
                break;
            }
        }
        printf("%s",mensajeError);
        reIntentos--;
    }while(reIntentos >= 0);
    return retorno;
}
*/
int getInt(char* mensaje,char* mensajeError,int reIntentos,int minimo,int maximo,int* resultado)
{
    int retorno = -1;
    char buffer[4096];
    long auxiliarLong;
    do
    {
        printf("%s",mensaje);
        scanf("%4095s",buffer);
        if(esEntero(buffer) == 0)
        {
            auxiliarLong = atol(buffer);
            if(auxiliarLong >= minimo && auxiliarLong <= maximo)
            {
                *resultado = (int)auxiliarLong;
                retorno = 0;
                break;
            }
        }
        printf("%s",mensajeError);
        reIntentos--;
    }while(reIntentos >= 0);
    return retorno;
}

int esEntero(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return -1;
       i++;
   }
   return 0;

}

int getString(char mensaje[], char imput[])
{
    printf("%s", mensaje);
    scanf("%s", imput);
    return 0;
}

int esLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
        return 1;
        i++;
    }
    return 0;
}

int getStringLetras(char mensaje[], int cant,char imput[])
{
    int retorno = -1;
    char aux[50];
    getString(mensaje, aux);
    //do{
        if(esLetras(aux)==0)
        {
            strcpy(imput, aux);
            //return 0;
        }
        //printf("%s", mensajeError);
    //}while(retorno!=-1);
    return retorno;
}

int funciones_init(Funciones* arrayFunciones, int cant)
{
    int retorno = -1;
    int i;
    if(cant > 0 && arrayFunciones != NULL)
    {
        for(i=0;i<cant;i++)
        {
            arrayFunciones[i].isEmpty = LIBRE;
        }
    }
    return retorno;
}

int funciones_buscarLibre(Funciones* arrayFunciones, int cant)
{
    int retorno = -1;
    int i;
    if(cant > 0 && arrayFunciones != NULL)
    {
        for(i=0;i<cant;i++)
        {
            if(arrayFunciones[i].isEmpty == LIBRE)
            {
                 retorno = i;
            }
        }
    }
    return retorno;
}

int funciones_proximoId(Funciones* arrayFunciones, int cant)
{
    int retorno = 0;
    int i;
    if(cant > 0 && arrayFunciones != NULL)
    {
        for(i=0;i<cant;i++)
        {
            if(arrayFunciones[i].isEmpty == OCUPADO)
            {
                if(arrayFunciones[i].id>retorno)
                {
                    retorno = arrayFunciones[i].id;
                }
            }
        }
    }
    return retorno+1;// Id a partir del 1. mayor a 0 'retorno+1 ... también si se quiere retorno+2'
}

int funciones_buscarPorId(Funciones* arrayFunciones, int cant, int id)
{
    int retorno = -1;
    int i;
    if(cant > 0 && arrayFunciones != NULL)
    {
        for(i=0;i<cant;i++)
        {
            if(arrayFunciones[i].isEmpty == OCUPADO && arrayFunciones[i].id == id)
            {
                retorno = i;
            }
        }
    }
    return retorno;
}

int funciones_alta(Funciones* arrayFunciones, int cant, int id)
{
    int retorno = -1;
    int i;
    //int id;

    if(cant > 0 && arrayFunciones != NULL)
    {
        i = funciones_buscarLibre(arrayFunciones, cant);
        if(i > 0 && i <= cant)
        {

            id = funciones_proximoId(arrayFunciones, cant);
            if(arrayFunciones[i].isEmpty == LIBRE)
            {
                getStringLetras("\nIngrese Nombre : \n",50,arrayFunciones[i].nombre);
                getStringLetras("\nIngrese Apellido : \n",50,arrayFunciones[i].apellido);
                //getStringLetras("\nIngrese CUIT : \n",50,arrayFunciones[i].cuit);
                getInt("\nIngrese CUIT : \n", "\nCUIT INVALIDO \n", 2, 1,20 , &arrayFunciones[i].cuit);
                arrayFunciones[i].isEmpty = 0;
                arrayFunciones[i].id = id;
                return 0;
            }
        }else{
            printf("\nSIN ESPACIO \n");
        }
    }
    return retorno;
}

int funciones_baja(Funciones* arrayFunciones, int cant, int id)
{
    int retorno = -1;
    int i;
    if(cant > 0 && arrayFunciones != NULL)
    {
        printf("\nID a dar de baja \n");
        scanf("%d", &id);
            i = funciones_buscarPorId(arrayFunciones, cant, id);
            if(i>=0)
            {
                arrayFunciones[i].isEmpty = LIBRE;
                retorno = 0;
            }else{
            printf("\nID INEXISTENTE \n");
            }
    }
    return retorno;
}

int funciones_modificar(Funciones* arrayFunciones, int cant, int id)
{
    int retorno = -1;
    int opcion;
    int i;
    if(cant > 0 && arrayFunciones != NULL)
    {
        printf("ID?\n");
        scanf("%d", &id);
        do{
            i = funciones_buscarPorId(arrayFunciones, cant, id);
            if(i >= 0)
            {
                printf("\nQue desea modificar?\n");
                getInt("\n1- Modificar nombre \n2- Modificar apellido \n8- salir \n", "\nInvalido \n", 2, 0, 3, &opcion);
                switch(opcion)
                {
                    case 1:
                        getStringLetras("\nIngrese nuevo nombre \n", 3, arrayFunciones[i].nombre);
                    break;
                    case 2:
                        getStringLetras("\nIngrese nuevo nombre \n", 50, arrayFunciones[i].apellido);
                    break;
                }
            }
        }while(opcion!=3);
    }
    return retorno;
}

int funciones_ordenar(Funciones* arrayFunciones, int cant, int orden)
{
    Funciones aux;
    int retorno = -1;
    int i;
    int flagSwap = 0;
    if(cant > 0 && arrayFunciones != NULL)
    {
        do{
            flagSwap = 0;
            for(i=0;i<cant-1;i++)
            {
                if(arrayFunciones[i].isEmpty == OCUPADO && arrayFunciones[i+1].isEmpty == OCUPADO)
                {
                    if((strcmp(arrayFunciones[i].nombre, arrayFunciones[i+1].nombre)>0  && !orden) ||(strcmp(arrayFunciones[i].nombre, arrayFunciones[i+1].nombre)<0  && orden))
                    {
                        aux = arrayFunciones[i];
                        arrayFunciones[i] = arrayFunciones[i+1];
                        arrayFunciones[i+1] = aux;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }

    return retorno;
}

int funciones_altaForzada(Funciones* arrayC,int limite,int id,char* cuit,char* nombre,char* apellido)
{
    int retorno = -1;
    int i;
    int posPant;
    if(limite > 0 && arrayC != NULL)
    {
        i = funciones_buscarLibre(arrayC,limite);
        if(i >= 0)
        {

            posPant = funciones_buscarPorId(arrayC,limite,id);
            if(posPant>=0)
            {
                //arrayC[i].nombre = nombre;
                strcpy(arrayC[i].nombre,nombre);
                strcpy(arrayC[i].apellido,apellido);
                arrayC[i].cuit = *cuit;
                //TODO
                id = funciones_proximoId(arrayC, limite);
                arrayC[i].id = id; // relacion
                arrayC[i].isEmpty=0;

            }
        }
        retorno = 0;
    }
    return retorno;
}
