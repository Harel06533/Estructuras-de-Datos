/**
 * Multiplicacion de matrices (VERSION CON ARREGLOS UNIDIMENSIONALES)
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

//Genera un número random en base a un comienzo y un límite
int lrand (int start, int limit) {return ((rand() % limit) + start);} 

/**
 * Versión del genRandMatrix() para arreglos unidimiensionales
 * 1. Declara un arreglo de tamaño r * c y lo inicializa en 0
 * 2. Si la variable de isRandom es verdadera entonces llena los valores con números aleatorios
*/
int* arrayAlloc (int r, int c, bool isRandom) {
  int *array = calloc(r * c, sizeof(int));
  if (isRandom) {
    for (int i = 0; i < r * c; i++) {
      array[i] = lrand(0, 10);
    }
  }
  return array;
}

/**
 * Operación de Matrices con arreglos unidimensionales
 * Utiliza la misma lógica de 3 fors anidadados
 * 1. Declara un arreglo inicializado en 0
 * 2. El resultado en [i][j] = el valor k de la fila * el valor k de la columna (Aunque este último avanza constante mente)
 * 3. Retorna el resultado
*/
int *timesArray (int *m1, int *m2, int r, int c) {
  int *result = arrayAlloc(r, c, false);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      for (int k = 0; k < c; k++) {
        *(result + (i * c) + j) += ((*(m1 + (i * c) + k)) * (*(m2 + (k * c) + j)));
      }
    }
  }
  return result;
}

//Imprimir arreglo
void printArr (int *array, int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf("%d ", *(array + (c * i) + j));
    }
    printf("\n");
  }
}

//Main
int main () {
  srand(time(NULL));
  int rows, cols;
  int *array1;
  int *array2;
  int *resultArray;

  //Datos del usuario
  printf("Introduzca las filas para ambos arreglos: ");
  scanf("%d", &rows);
  printf("Introduzca las columnas para ambos arreglos: ");
  scanf("%d", &cols);

  //Inicializar los arreglos
  array1 = arrayAlloc(rows, cols, true);
  array2 = arrayAlloc(rows, cols, true);
  resultArray = timesArray(array1, array2, rows, cols);

  //Imprimir datos
  printf("\nArreglo 1:\n");
  printArr(array1, rows, cols);
  printf("\nArreglo 2:\n");
  printArr(array2, rows, cols);
  printf("\nResultado de multiplicación:\n");
  printArr(resultArray, rows, cols);
  return 0;
}