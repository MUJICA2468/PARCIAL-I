#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcion.h"
#include "publicacion.h"
#include "informe.h"

#define OCUPADO 0
#define LIBRE 1

int publicacion_getInt(char* mensaje,char* mensajeError,int reIntentos,int minimo,int maximo,int* resultado)
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

int publicacion_esEntero(char str[])
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

int publicacion_getString(char mensaje[], char imput[])
{
    printf("%s", mensaje);
    scanf("%s", imput);
    return 0;
}

int publicacion_esLetras(char str[])
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

int publicacion_getStringLetras(char mensaje[], int cant,char imput[])
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

int publicaciones_init(Publicacion* arrayPublicaciones, int cant)
{
    int retorno = -1;
    int i;
    if(cant > 0 && arrayPublicaciones != NULL)
    {
        for(i=0;i<cant;i++)
        {
            arrayPublicaciones[i].isEmpty = LIBRE;
        }
    }
    return retorno;
}

int publicaciones_buscarLibre(Publicacion* arrayPublicaciones, int cant)
{
    int retorno = -1;
    int i;
    if(cant > 0 && arrayPublicaciones != NULL)
    {
        for(i=0;i<cant;i++)
        {
            if(arrayPublicaciones[i].isEmpty == LIBRE)
            {
                 retorno = i;
            }
        }
    }
    return retorno;
}

int publicaciones_proximoId(Publicacion* arrayPublicaciones, int cant)
{
    int retorno = 5;
    int i;
    if(cant > 0 && arrayPublicaciones != NULL)
    {
        for(i=0;i<cant;i++)
        {
            if(arrayPublicaciones[i].isEmpty == OCUPADO)
            {
                if(arrayPublicaciones[i].id>retorno)
                {
                    retorno = arrayPublicaciones[i].id;
                }
            }
        }
    }
    return retorno+1;// Id a partir del 1. mayor a 0 'retorno+1 ... también si se quiere retorno+2'
}

int publicaciones_buscarPorId(Publicacion* arrayPublicaciones, int cant, int id)
{
    int retorno = -1;
    int i;
    if(cant > 0 && arrayPublicaciones != NULL)
    {
        for(i=0;i<cant;i++)
        {
            if(arrayPublicaciones[i].isEmpty == OCUPADO && arrayPublicaciones[i].id == id)
            {
                retorno = i;
            }
        }
    }
    return retorno;
}

int publicaciones_alta(Publicacion* arrayPublicaciones, int cant,int idIdentificador)
{
    int retorno = -1;
    int i;
    int id;
    int aux = 0;
    if(cant > 0 && arrayPublicaciones != NULL)
    {
        i = publicaciones_buscarLibre(arrayPublicaciones, cant);
        if(i > 0 && i <= cant)
        {
            idIdentificador = publicaciones_buscarPorId(arrayPublicaciones, cant, aux);
            id = publicaciones_proximoId(arrayPublicaciones, cant);
            if(arrayPublicaciones[i].isEmpty == LIBRE)
            {
                getInt("\nIngrese su ID de cliente \n","ID INEXISTENTE o invalido",2,0,10,&idIdentificador);
                getStringLetras("\nIngrese Texto de aviso de su publicacion : \n",50,arrayPublicaciones[i].aviso);

                arrayPublicaciones[i].isEmpty = 0;
                arrayPublicaciones[i].id = id;
                return 0;
            }
        }else{
            printf("\nSIN ESPACIO \n");
        }
    }
    return retorno;
}

