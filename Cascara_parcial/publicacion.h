#ifndef PUBLICACION_H_INCLUDED
#define PUBLICACION_H_INCLUDED
typedef struct{
    char aviso[64];
    //------------
    //int identificador = 0;
    int id;
    int numeroRubro;
    int isEmpty;
}Publicacion;
#endif // PUBLICACION_H_INCLUDED
int getInt(char* mensaje, char* mensajeError, int intentos, int minimo, int maximo, int* resultado);
int esEntero(char str[]);
int getString(char mensaje[], char imput[]);
int esLetras(char str[]);
int getStringLetras(char mensaje[], int cant,char imput[]);
int publicaciones_init(Publicacion* arrayPublicaciones, int cant);
int publicaciones_buscarLibre(Publicacion* arrayPublicaciones, int cant);
int publicaciones_proximoId(Publicacion* arrayPublicaciones, int cant);
int publicaciones_buscarPorId(Publicacion* arrayPublicaciones, int cant, int id);
//----------------------------------------------------------------------
int publicaciones_alta(Publicacion* arrayPublicaciones, int cant, int idIdentificador);
