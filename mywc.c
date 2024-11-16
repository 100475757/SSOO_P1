//P1-SSOO-23/24
/*mywc.c*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> // para open
#include <unistd.h> // para close, read, write
#define BUFFER_SIZE 104857600   /*Tamaño de 100 MB en bytes*/


int main(int argc, char *argv[]) {
	/*Si hay menos de dos argumentos  (argv[0] -> nombre del programa, argv[1] -> archivo a analizar) imprimimos error y se devuelve -1*/
    if (argc != 2) {
        printf("Uso: ./mywc <nombre del fichero>\n");
        return -1;
    }

    int archivo = open(argv[1], O_RDONLY); /*Con open(char *name , int flags) se abre el archivo a analizar, utilizamos O_RDONLY para indicar que solo se va a leer el archivo*/
    if (archivo == -1) { /*Comprobamos que el archivo existe, en caso de que no, se devuelve -1*/
        printf("Error, el archivo  %s no se pudo abrir.\n", argv[1]);
        return -1;
    }

    int caracter = ' '; /*Con esta variable almacenamos los bytes leidos por la funcion read(int fd, char *buff, int nbytes)*/
    int ch_anterior = ' '; /*Con esta variable contaremos el nº de palabras que hay en el archivo*/
    int lineas = 0, palabras = 0, bytes = 0; /*Hacemos un contador de cada variable, y lo inicializamos a 0*/
    char *buffer = (char *) malloc(BUFFER_SIZE * sizeof(char));
    while ((caracter = read(archivo, buffer, BUFFER_SIZE)) > 0) {
        for (int i = 0; i < caracter; i++) {
            bytes++;  /*Conteo del numero de bytes*/
            
            if (buffer[i] == '\n') {  /*buffer[i]= byte actual en el bucle*/
                lineas++;  
            }

            if (buffer[i]== ' ' || buffer[i] == '\n' || buffer[i] == '\t') {
                if (ch_anterior != ' ' && ch_anterior != '\n' && ch_anterior != '\t') {
                    palabras++;   /* palabras aumenta si el caracter actual es un espacio y el ch_anterior no lo es */ 
                }
            }

            ch_anterior = buffer[i];  /* Actualizamos */
        }
    }


    /* Verificamos si el último caracter leído no es un espacio en blanco, tabulación o salto de línea*/
    if (ch_anterior != ' ' && ch_anterior != '\t' && ch_anterior != '\n') {
         palabras++; /* Incrementamos el contador de palabras */
    }

    if (close(archivo) == -1) {
    	printf("Hubo un error en el cierre del arhivo");
    	return -1;
    }

    printf("%d %d %d %s\n", lineas, palabras, bytes, argv[1]);
    free(buffer); /* Libera la memoria asignada con malloc()*/
    return 0; 
}