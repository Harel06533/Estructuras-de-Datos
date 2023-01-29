/*
* Ejercicio - Escribir una función que guarde los apuntadores de una matriz y puedan imprimirse
*/

#include <stdio.h>

/*
* Función que imprime los valores de un arreglo de apuntadores
*/
void printPointerArr (char **arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("Value of address %p is %s\n", (arr + i), *(arr + i)); //Imprime la dirección de memoria y el valor que existe en la dirección
  }
}

int main () {
  char array[][10] = {"UNO", "DOS", "TRES", "CUATRO", "CINCO", "SEIS", "SIETE", "OCHO", "NUEVE", "DIEZ", "ONCE", "DOCE"};
  char *ptArr[12]; //Se declara un arreglo de apuntadores (Arreglo de arreglos)

  for (int i = 0; i < 12; i++) {
    *(ptArr + i) = *(array + i); //El valor del arreglo de apuntadores es el valor (Dirección) de la matríz
  }
  printPointerArr(ptArr, 12); //Imprimer
  return 0;
}


