#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CIUDADES 100
char ciudades[MAX_CIUDADES][2][100];
char ciudadesViento[MAX_CIUDADES][4][100];

char* leerDataArch1();
void leerDataArch2();
void indicaCiudad();

int main() {
    indicaCiudad();
}

void indicaCiudad(){
    char entrada[100];
    char archivo[100] = "C:/Users/christian.campos/Desktop/scriptsDeC/ciudadesViento/ciudades.txt";
    char archivo2[100] = "C:/Users/christian.campos/Desktop/scriptsDeC/ciudadesViento/callesViento.txt";

    // Solicitar la entrada al usuario
    printf("Introduce una palabra: ");
    scanf("%s", entrada);
    char* id = leerDataArch1(archivo,entrada);
    //printf("%s", id);
    leerDataArch2(archivo2,id);

}

 char* leerDataArch1(char nombreArchivo[],char* entrada) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
    }

    // Declarar la matriz para almacenar los datos
    // 2 columnas: ID y nombre (hasta 100 caracteres cada uno)
    int num_ciudades = 0;  // Número actual de ciudades

    // Leer los datos del archivo
    while (num_ciudades < MAX_CIUDADES && fscanf(archivo, "%s %s", ciudades[num_ciudades][0], ciudades[num_ciudades][1]) == 2) {
        num_ciudades++;
    }

    // Cerrar el archivo
    fclose(archivo);


    // Imprimir los datos almacenados en la matriz
    for (int i = 0; i < num_ciudades; i++) {
        //printf("%s %s\n", ciudades[i][0], ciudades[i][1]);
        if(strcmp(ciudades[i][1],entrada)==0){
            //printf("%s %s",ciudades[i][0],ciudades[i][1]);
            return ciudades[i][0];
        }
    }
    return "0";
}

void leerDataArch2(char nombreArchivo[],char* id) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
    }

    int num_ciudades = 0;  // Número actual de ciudades

    // Leer los datos del archivo
    while (num_ciudades < MAX_CIUDADES && fscanf(archivo, "%s %s %s %s", ciudadesViento[num_ciudades][0], ciudadesViento[num_ciudades][1],ciudadesViento[num_ciudades][2], ciudadesViento[num_ciudades][3]) == 4) {
        num_ciudades++;
    }

    // Cerrar el archivo
    fclose(archivo);


    // Imprimir los datos almacenados en la matriz
    for (int i = 0; i < num_ciudades; i++) {
        //printf("%s %s\n", ciudades[i][0], ciudades[i][1]);
        if(strcmp(ciudadesViento[i][1],id)==0){
            printf("%s %s %s %s\n",ciudadesViento[i][0],ciudadesViento[i][1],ciudadesViento[i][2],ciudadesViento[i][3]);
        }
    }
}