/*
* Ejercicio 1 /S4 - Miércoles: Apuntadores void y casteo
*/

#include <stdio.h>

/*
=============
FUNCIONES
FORMATOS
=============
*/

/*
=== PRINT CHAR ===
*/
void printChar (void *arr, char *format) { //Apuntador a void y formato
  printf(format, *((char *) arr)); //Se castea el apuntador a void como char
  printf("\n");
}

/*
=== PRINT SHORT ===
*/
void printShort (void *arr, char *format) {
  printf(format, *((short *) arr));
  printf("\n");
}

/*
=== PRINT INT ===
*/
void printInt (void *arr, char *format) {
  printf(format, *((int *) arr));
  printf("\n");
}

/*
=== PRINT LONG ===
*/
void printLong (void *arr, char *format) {
  printf(format, *((long *) arr));
  printf("\n");
}

/*
=== PRINT FLOAT ===
*/
void printFloat (void *arr, char *format) {
  printf(format, *((float *) arr));
  printf("\n");
}

/*
=== PRINT DOUBLE ===
*/
void printDouble (void *arr, char *format) {
  printf(format, *((double *) arr));
  printf("\n");
}

//Main
int main () {
  char arr[] = {'A', 'B', 100, 20, 0x4E, 50, 60, 'M', 'D', 0x25, 040};

  //Imprimir todos los elementos del arreglo con sus Formatos
  for (int i = 0; i < sizeof(arr); i++) { //Dado a que es un arreglo de char, sizeof() nos el tamaño exacto
    printf("Number of Iteration = %d\n", i + 1);
    printChar((arr + i), "%c");
    printChar((arr + i), "%d"); //Char pero en ASCII
    printShort((arr + i), "%d");
    printInt((arr + i), "%d");
    printLong((arr + i), "%d");
    printFloat((arr + i), "%d");
    printDouble((arr + i), "%d");
    printf("\n");
  }
  return 0;
}