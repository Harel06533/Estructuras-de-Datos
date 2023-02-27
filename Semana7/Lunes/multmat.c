/*
* Archivos en C - Multiplicación de matríces
VERSION 1.0.0 NO ES CORRECTA!!
* Utiliza los mismos algoritmos que Semana6/Lunes/ejer2.c 
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define rows 3
#define cols 3

//Genera un Número random entre un comienzo y un límite
int lrand (int start, int limit) {
  return ((rand() % limit) + start);
}

/* Genera una matriz en 0 o con números random */
int **fillMatrix (int r, int c, bool isRandom) {
  int **matrix = malloc(r * sizeof(int *));
  for (int i = 0; i < r; i++) {
    matrix[i] = calloc(c, sizeof(int));
    if (isRandom) {
      for (int j = 0; j < c; j++) {
        matrix[i][j] = lrand(0, 10);
      }
    }
  }
  return matrix;
}

/* Guarda los valores de las matríces en un archivo .txt */
void fileMatrix (int **matrix, int r, int c, FILE *destFile) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      fprintf(destFile, " %d ", matrix[i][j]);
    }
    fprintf(destFile, "\n");
  }
}

/* Multiplica 2 matríces y retorna el resultado */
int **timesMatrix (int r, int c, int **m1, int **m2) {
  int **resultM = fillMatrix(r, c, false);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      for (int k = 0; k < c; k++) {
        resultM[i][j] += m1[i][k] * m2[k][j];
      }
    }
  } 
  return resultM;
}

//Main
int main () {
  srand(time(NULL));
  
  //Inicializa los archivos como write para crear y sobreescribir
  FILE *file_a = fopen("matrix_a.txt", "w");
  FILE *file_b = fopen("matrix_c.txt", "w");
  FILE *file_c = fopen("result.txt", "w");

  //Validación
  bool isValid = (file_a != NULL && file_b != NULL && file_c != NULL);
  if (!isValid) {
    fprintf(stderr, "Error al llenar los archivos");
    return -1;
  }

  //Llena las matríces de manera lógica
  int **matrix1 = fillMatrix(rows, cols, true);
  int **matrix2 = fillMatrix(rows, cols, true);
  int **resultMatrix = timesMatrix(rows, cols, matrix1, matrix2);

  //Llena los archivos .txt con sus respectivas matríces
  fileMatrix(matrix1, rows, cols, file_a);
  fileMatrix(matrix2, rows, cols, file_b);
  fileMatrix(resultMatrix, rows, cols, file_c);

  //Cierra los archivos para guardarlos en el almacenamiento y cerrar el buffer
  fclose(file_a);
  fclose(file_b);
  fclose(file_c);

  //Salida correcta.
  printf("Se han hecho las operaciones de manera correcta");
  return 0;  
}