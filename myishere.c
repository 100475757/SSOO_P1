//P1-SSOO-23/24 

/*myishere.c*/

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <string.h>



int main(int argc, char *argv[]) {
    /* Comprobamos que se proporcionan suficientes argumentos */
    /* argv[0] -> programa, argv[1] -> directorio a buscar, argv[2] -> archivo a encontrar */
    if (argc != 3 ) {
        printf("Uso: %s <nombre del directorio> <nombre del fichero>\n", argv[0]);
        return -1;
    }

    /* Abrimos el directorio recibido como argumento */
    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        printf("Error al abrir el directorio %s\n", argv[1]);
        return -1;
    }

    /* Buscamos el fichero en el directorio */
    struct dirent *ent;
    int found = 0;  /* Bandera para saber si lo hemos encontrado o no */
    while (!found && (ent = readdir(dir)) != NULL) { 
        /* Comparamos el nombre del fichero con el nombre de la entrada */
        if (strcmp(ent->d_name, argv[2]) == 0) {
            found = 1;
        }
    }


    // Mostramos  el resultado
    if (found) { /*Si hemos encontrado el fichero (found) comentamos en que directorio esta el fichero */
        printf("File %s is in directory %s\n", argv[2], argv[1]);
    } else {	/*Si no lo hemos encontrado comentamos que el el fichero no esta en el directorio*/
        printf("File %s is not in directory %s\n", argv[2], argv[1]);
    }

    /* Cerramos el directorio */
    closedir(dir);


    return 0;
}
