# Práctica 1 - Sistemas Operativos 23/24

Este proyecto es la práctica 1 de la asignatura de Sistemas Operativos (SSOO) del curso 2023/2024. 
El objetivo de esta práctica es implementar varios programas en C que realicen diferentes operaciones de 
lectura y escritura sobre archivos y directorios.

## Funcionalidad

El proyecto incluye tres programas:

1. **myishere.c**: Busca un archivo específico dentro de un directorio dado.
2. **mywc.c**: Cuenta el número de líneas, palabras y bytes en un archivo.
3. **myls.c**: Lista los archivos en un directorio.

## Compilación

Para compilar estos programas se debe hacer uso de `gcc`. Para compilar cada uno de los programas se debe escribir lo siguiente en la terminal:

1. **myishere.c**: gcc myishere.c -o myishere
2. **mywc.c**: gcc mywc.c -o mywc
3. **myls.c**: gcc myls.c -o myls

## Modos de Uso 

Para ejecutar estos programas se debe escribir lo siguiente en la terminal:

1. **myishere.c**: ./myishere **<nombre del directorio> <nombre del fichero>**
2. **mywc.c**: ./mywc <nombre del fichero>
3. **myls.c**: ./myls <nombre del directorio> ó ./myls (esto último lista los archivos en el directorio actual)
