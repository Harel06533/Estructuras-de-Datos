/* Caputra los valores de una matríz y los guarda en un archivo .bin 
* IMPORTANTE: 
* 1. Los archivos .c utilizan funciones duplicadas, esto puede ser un área para mejorar
* 2. Los (FILE *) Son apuntadores a una posición en un archivo, en este caso binario. Esto es importante ya que:
*   a. Si una función avanzó n cantidad de elementos, al volver a correrla, se inicializa desde la posición actuál y no desde el inicio
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "globals.h"


/* Genera un número aleatorio entre un comienzo y un límite */
int lrand (int start, int limit) {
  return ((rand() % limit) + start);
}

/* Genera los valores de una matríz */
int **genMatrix (int r, int c, bool isRandom) {
  int **matrix = malloc(r * sizeof(int *));
  for (int i = 0; i < r; i++) {
    matrix[i] = calloc(c, sizeof(int));
    for (int j = 0; j < c; j++) {
      if (isRandom) {
        matrix[i][j] = lrand(0, 10);
      } else {
        printf("Fila %d, Valor %d: ", i + 1, j + 1);
        scanf("%d", &matrix[i][j]);
      }
    }
  }
  return matrix;
}

/**
 * Llena los archivos bin con los datos de una matríz
 *  1. Itera por cada renglón
 *  2. Utiliza fwrite para cada renglón, ya que internamente, hay una nueva iteración en la función. Parámetros:
 *    a. La dirección de memoria donde se sacarán los valores (arreglo en este caso)
 *    b. El tamaño de cada elemento, 4Bytes para entero
 *    c. La cantidad de elementos que se van a obtener
 *    d. El archivo destino
*/
void m_fileAdd (FILE *file, int **matrix, int r, int c) {
  for (int i = 0; i < r; i++) {
    fwrite(matrix[i], sizeof(int), c, file);
  }
}

/* Liberar memoria de matríces */
void m_Free (int **matrix, int r, int c) {
  for (int i = 0; i < r; i++) {
    free(matrix[i]);
  }
  free(matrix);
}

/* Imprimir para debuggear */
void printMatrix (int **matrix, int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

/* MAIN */
int main () {

  /* Inicializa el archivo */
  FILE *binfile = fopen("entrada.bin", "wb");

  /* Validaciones */
  if (binfile == NULL) {
    fprintf(stderr, "No se pudo abrir el archivo");
    return -1;
  }

  /* Variables */
  int **matrix1;
  int **matrix2;

  int userOpt;
  bool isSelected;

  /* Información del usuario */
  printf("Deseas llenar los valores de las matrices?\n1. Si\n2. No\nopcion: ");
  scanf("%d", &userOpt);

  /* Ternario que identifica si el usuario desea llenar las matríces o no */
  isSelected = (userOpt == 1) ? false : true;
  srand(time(NULL));

  /* Genera las matríces */
  matrix1 = genMatrix(rows, cols, isSelected);
  matrix2 = genMatrix(rows, cols, isSelected);

  printMatrix(matrix1, rows, cols);
  printf("\n");
  printMatrix(matrix2, rows, cols);

  /* Añade a los archivos, las matríces */
  m_fileAdd(binfile, matrix1, rows, cols);
  m_fileAdd(binfile, matrix2, rows, cols);

  /* Liberar espacios */
  fclose(binfile);
  m_Free(matrix1, rows, cols);
  m_Free(matrix2, rows, cols);
  return 0;
}