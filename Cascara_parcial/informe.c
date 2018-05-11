#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcion.h"
#include "publicacion.h"
//#include "informe.h"

#define OCUPADO 0
int informe_listarUser(Funciones* arrayFunciones, int cant)
{
    int retorno = -1;
    int i;
    for(i=0;i<cant;i++)
    {
        if(arrayFunciones[i].isEmpty == OCUPADO)
        {
            printf("\nNombre : %s \nApellido : %s \nCUIT: %d \nID : %d \n", arrayFunciones[i].nombre, arrayFunciones[i].apellido,arrayFunciones[i].cuit, arrayFunciones[i].id);
            retorno = 0;
        }
    }
    return retorno;
}

int informe_listaPubli(Publicacion* arrayPublicaciones, int cant)
{
    int retorno = -1;
    int i;
    for(i=0;i<cant;i++)
    {
        if(arrayPublicaciones[i].isEmpty == OCUPADO)
        {
            printf("\nID: %d \nAviso: %s \nIdentificador\n", arrayPublicaciones[i].id,  arrayPublicaciones[i].aviso);
            retorno = 0;
        }
    }
    return retorno;
}

int informe_imprimirClientes(Publicacion* arrayPublicaciones, Funciones* arrayFunciones, int cant)
{
    int retorno = -1;
    int i;
    //int contador = 0;
    int acum = 0;
    for(i=0;i<cant;i++)
    {
        if(arrayFunciones[i].isEmpty == OCUPADO)
        {
                    acum++;
                    printf("\nNombre : %s \nApellido : %s \nCUIT: %d \nID : %d \n", arrayFunciones[i].nombre, arrayFunciones[i].apellido,arrayFunciones[i].cuit, arrayFunciones[i].id);
                    //retorno = 0;
                    //continue;
        }
        if(arrayPublicaciones[i].isEmpty == OCUPADO){

                printf("\nCantidad de avisos: %d \n", acum);

        }
    }
    return retorno;
}


/*
int informar_ConsultaFacturacion(Funciones* arrayC,int limiteC,int limiteP, char* cuit)
{
    //Se deberá ingresar el cuit del cliente y
    //listar el importe a pagar por cada contratación.
    int retorno = -1;
    int i;
    int indexPantalla;

    if(arrayC != NULL && limiteP > 0)
    {
        retorno = -2;
        for(i=0;i<limiteC;i++)
        {
            if(!arrayC[i].isEmpty && !strcmp(arrayC[i].cuit,cuit))
            {
                indexPantalla = pantalla_buscarPorId(arrayP,limiteP,arrayC[i].idPantalla);
                printf("\nID: %d - Valor: %.2f",

                       arrayC[i].id,
                       arrayC[i].dias*arrayP[indexPantalla].precio);
                retorno = 0;
            }
        }
    }

    return retorno;
}

int informar_ListarCantidadFuncionesesImporte(Funciones* arrayC,int limiteC)
{
    Lista de cada cliente con cantidad de Funcioneses e importe
    a pagar por cada una.



    int retorno = -1;
    int i;
    int indexPantalla;
    char ultimoCuit[50]="-";
    if(arrayC != NULL && arrayP != NULL && limiteC > 0 && limiteP > 0)
    {
        retorno = -2;
        cont_ordenarCuit(arrayC,limiteC,0);
        for(i=0;i<limiteC;i++)
        {
            if(!arrayC[i].isEmpty && strcmp(arrayC[i].cuit,ultimoCuit) != 0)
            {
                strcpy(ultimoCuit,arrayC[i].cuit);

                printf("\n\nINFO DEL CUIT - %s -",ultimoCuit);
                informar_ConsultaFacturacionTotal(arrayC,limiteC,arrayP,limiteP,ultimoCuit);
            }
        }
    }

    return retorno;
}

int informar_ConsultaFacturacionTotal(Funciones* arrayC,int limiteC,int limiteP, char* cuit)
{
    //Se deberá ingresar el cuit del cliente y
    //listar el importe a pagar por cada contratación.
    int retorno = -1;
    int i;
    int indexPantalla;
    int contador=0;
    float acumulador=0;

    if(arrayC != NULL && arrayP != NULL && limiteC > 0 && limiteP > 0)
    {
        retorno = -2;
        for(i=0;i<limiteC;i++)
        {
            if(!arrayC[i].isEmpty && !strcmp(arrayC[i].cuit,cuit))
            {
                indexPantalla = pantalla_buscarPorId(arrayP,limiteP,arrayC[i].idPantalla);

                contador++;
                acumulador += arrayC[i].dias*arrayP[indexPantalla].precio;
                retorno = 0;
            }
        }
    }

    printf("\nCantidad Funcioneses: %d - Total: %.2f",

                       contador,
                       acumulador);
    return retorno;
}

int cont_altaForzada(Contratacion* arrayC,int limite,
              Pantalla* pantallas, int lenPantallas,
              int idPantalla,char* archivo,char* cuit,int dias)
{
    int retorno = -1;
    int i;
    int posPant;
    if(limite > 0 && arrayC != NULL)
    {
        i = buscarLugarLibre(arrayC,limite);
        if(i >= 0)
        {

            posPant = pantalla_buscarPorId(pantallas,lenPantallas,idPantalla);
            if(posPant>=0)
            {
                arrayC[i].dias = dias;
                strcpy(arrayC[i].cuit,cuit);
                strcpy(arrayC[i].archivo,archivo);
                //TODO
                arrayC[i].idPantalla = idPantalla; // relacion
                arrayC[i].isEmpty=0;
                arrayC[i].id = proximoId();
            }
        }
        retorno = 0;
    }
    return retorno;
}
*/
