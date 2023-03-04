/* Obtiene las matríces de los .bin y las multiplica, guarda el resultado en una nueva matríz y un nuevo archivo .bin */
#include <stdio.h>
#include "globals.h"
#include <stdlib.h>

/**
 * Obtiene los datos del archivo Binario
 *  1. Genera una matríz para retornar
 *  2. Guarda los datos del archivo en la matríz mediate fread(), con parámetros:
 *    a. La dirección de memoria destino (Arreglo)
 *    b. El tamaño de cada elemento
 *    c. La cantidad de elementos
 *    d. El archivo fuente
*/
int **m_getFromFile (FILE *file, int r, int c) {
  int **matrix = malloc(r * sizeof(int *));
  for (int i = 0; i < r; i++) {
    matrix[i] = malloc(c * sizeof(int));
    fread(matrix[i], sizeof(int), c, file);
  }
  return matrix;
}

/* Multiplica las matríces */
int **timesMatrix (int **m1, int **m2, int r, int c) {
  int **result = malloc(r * sizeof(int *));
  for (int i = 0; i < r; i++) {
    result[i] = calloc(c, sizeof(int));
    for (int j = 0; j < c; j++) {
      for (int k = 0; k < c; k++) {
        result[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
  return result;
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

/* Añade los datos de una matríz a un binario */
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

int main () {
  /* Archivos */
  FILE *binfile = fopen("entrada.bin", "rb"); 
  FILE *resultfile = fopen("salida.bin", "wb");

  /* Validación */
  if (binfile == NULL || resultfile == NULL) {
    fprintf(stderr, "No se pudo acceder a los archivos");
    return -1;
  }

  /* Matríces */
  int **matrix1;
  int **matrix2; 
  int **resultMatrix;

  /* Genera matríces */
  matrix1 = m_getFromFile(binfile, rows, cols);
  matrix2 = m_getFromFile(binfile, rows, cols);
  resultMatrix = timesMatrix(matrix1, matrix2, rows, cols);

  /* Imprime */
  printMatrix(matrix1, rows, cols);
  printf("\n");
  printMatrix(matrix2, rows, cols);
  printf("\n");
  printMatrix(resultMatrix, rows, cols);

  /* Añade a un archivo binario */
  m_fileAdd(resultfile, resultMatrix, rows, cols);

  fclose(binfile);
  fclose(resultfile);

  /* Libera memoria */
  m_Free(matrix1, rows, cols);
  m_Free(matrix2, rows, cols);
  m_Free(resultMatrix, rows, cols);
  return 0;
}