// P1-SSOO-23/24

/*myls.c*/



#include <stdio.h>	  	// para printf

#include <unistd.h>	  	// para llamar a getcwd

#include <sys/types.h> 	// para utilizar opendir, readdir y closedir

#include <dirent.h>		// para utilizar opendir, readdir y closedir

#include <sys/stat.h>	

#include <fcntl.h>

#include <stdlib.h>

#include <string.h> 

#include <linux/limits.h> // para PATH_MAX 



int main(int argc, char *argv[])

{

	DIR *dir;			/* DIR es un tipo de dato que contiene la informacion de un directorio */
	struct dirent *ent;      /* struct dirent contiene la informacion de un fichero del directorio */

	if (argc == 2)

	{/* si se pasa un argumento, abrimos el directorio pasado como argumento */

		dir = opendir(argv[1]);

	}

	else if (argc == 1)

	{/* si no se pasa ningun argumento, abrimos el directorio actual con getcwd */

		char buffer[PATH_MAX]; 	/* PATH_MAX: es una constante del sistema, maximo tamaño de un path */
					/* buffer es un array de char que contiene la ruta del directorio actual */
								

		if (getcwd(buffer, PATH_MAX) == NULL)

		{ 	/* Intentamos abrir el directorio actual */

			printf("Error al obtener el directorio actual\n");

			return -1;

		}

		dir = opendir(buffer); /* Aqui lo abrimos, pues no hay errores */

	}

	else

	{

		printf("Uso 1: ./myls <nombre del directorio>\n");
		printf("Uso 2: ./myls\n");
		return -1;

	}

	if (dir == NULL)

	{

		printf("Error al abrir el directorio\n");

		return -1;

	}

	while ((ent = readdir(dir)) != NULL)   /* readdir devuelve un puntero a struct dirent */

	{	/* leemos el contenido del directorio */

		printf("%s\n", ent->d_name); /* d_name es un array de char que contiene el nombre del fichero */	

	}

	closedir(dir); /* Cerramos el directorio */

	return 0;

}