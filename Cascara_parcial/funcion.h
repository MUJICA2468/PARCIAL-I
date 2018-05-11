#ifndef FUNCION_H_INCLUDED
#define FUNCION_H_INCLUDED
typedef struct{
    char nombre[50];
    char apellido[50];
    int cuit;
    //----------------
    int id;
    int isEmpty;
}Funciones;
#endif // FUNCION_H_INCLUDED
int getInt(char* mensaje, char* mensajeError, int intentos, int minimo, int maximo, int* resultado);
int esEntero(char str[]);
int getString(char mensaje[], char imput[]);
int esLetras(char str[]);
int getStringLetras(char mensaje[], int cant,char imput[]);
int funciones_init(Funciones* arrayFunciones, int cant);
int funciones_buscarLibre(Funciones* arrayFunciones, int cant);
int funciones_proximoId(Funciones* arrayFunciones, int cant);
int funciones_buscarPorId(Funciones* arrayFunciones, int cant, int id);
//----------------------------------------------------------------------
int funciones_alta(Funciones* arrayFunciones, int cant, int id);
int funciones_baja(Funciones* arrayFunciones, int cant, int id);
int funciones_modificar(Funciones* arrayFunciones, int cant, int id);
int funciones_ordenar(Funciones* arrayFunciones, int cant, int orden);
int funciones_altaForzada(Funciones* arrayC,int limite,int id,char* cuit,char* nombre,char* apellido);
