#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcion.h"
#include "informe.h"
#include "publicacion.h"

#define CANTF 5
#define CANTP 5
int main()
{
    Funciones arrayFunciones[CANTF];
    Publicacion arrayPublicaciones[CANTP];
    int opcion;
    int auxIdUser=0;
    //int auxIdPub=0;

    //identificador = arrayPublicaciones.identificador;
    //int auxIdPubli = 0;
    /*
    funciones_altaForzada(arrayFunciones, CANTF, 0, "34445","robert","emanuel");
    funciones_altaForzada(arrayFunciones, CANTF, 0, "34445","roberto","emanuel");
    funciones_altaForzada(arrayFunciones, CANTF, 0, "34445","rober","emanuel");
    informe_listarUser(arrayFunciones, CANTF);
    */

    funciones_init(arrayFunciones, CANTF);
    publicaciones_init(arrayPublicaciones, CANTP);
    do{

        getInt("\n1- alta \n2- baja \n3- listar \n4- modificar \n5- ordenar segun orden alfabetico\n6- Alta de publicaciones \n7- Informar clientes\n9- SALIR \n", "\nINVALIDO \n", 2,0, 9, &opcion);
        switch(opcion){

            case 1:
            funciones_alta(arrayFunciones, CANTF, auxIdUser);
            break;
            case 2:
            funciones_baja(arrayFunciones, CANTF, auxIdUser);
            break;
            case 3:
            informe_listarUser(arrayFunciones, CANTF);
            break;
            case 4:
            funciones_modificar(arrayFunciones, CANTF, auxIdUser);
            break;
            case 5:
            funciones_ordenar(arrayFunciones, CANTF, 0);
            break;
            case 6:
            publicaciones_alta(arrayPublicaciones, CANTP, auxIdUser);
            informe_listaPubli(arrayPublicaciones, CANTP);
            break;
            case 7:
            informe_imprimirClientes(arrayPublicaciones, arrayFunciones, CANTP);
            break;
        }
    }while(opcion!=9);
    return 0;
}
