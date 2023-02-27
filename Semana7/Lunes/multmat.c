/*
* Archivos en C - Multiplicación de matríces
* Utiliza los mismos algoritmos que Semana6/Lunes/ejer2.c 
* Los valores de los .txt son fijos, para obtener un result.txt diferente, es necesario modificarlos
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define rows 3
#define cols 3

/* Inicializa las matríces en 0 */
int **initMatrix (int r, int c) {
  int **matrix = malloc(r * sizeof(int *));
  for (int i = 0; i < r; i++) {
    matrix[i] = calloc(c, sizeof(int));
  }
  return matrix;
}

/* Lee los datos de los .txt y los guarda en una matríz */
void getValues (int **srcMat, FILE *sourceFile, int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      fscanf(sourceFile, "%d", &srcMat[i][j]);
    }
  }
}

/* Multiplica las matríces */
int **timesMatrix (int **m1, int **m2, int r, int c) {
  int **resultM = initMatrix(r, c);
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      for (int k = 0; k < c; k++) {
        resultM[i][j] += m1[i][k] * m2[k][j];
      }
    }
  }
  return resultM;
}

/* Llena el .txt con los valores dados */
void fileWrite (FILE *destFile, int **sourceMatrix, int r, int c) {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      fprintf(destFile, "%d ", sourceMatrix[i][j]);
    }
    fprintf(destFile, "\n");
  }
}

//MAIN 
int main () {
  srand(time(NULL));

  //Inicializar archivos para lectura o escribir
  FILE *file_a = fopen("matrix_a.txt", "r");
  FILE *file_b = fopen("matrix_c.txt", "r");
  FILE *res_file = fopen("result.txt", "w");

  //Valida los archivos
  if (file_a == NULL || file_b == NULL || res_file == NULL) {
    fprintf(stderr, "Error al crear o buscar archivos");
    return -1;
  }

  //Inicializa matríces en la memoria RAM
  int **matrix1 = initMatrix(rows, cols);
  int **matrix2 = initMatrix(rows, cols);

  //Obtener los valores de los .txt y guardarlos en las matríces
  getValues(matrix1, file_a, rows, cols);
  getValues(matrix2, file_b, rows, cols);

  //Multiplicar las matríces y guardarlas en un .txt
  int **resultMatrix = timesMatrix(matrix1, matrix2, rows, cols);
  fileWrite(res_file, resultMatrix, rows, cols);

  //Cerrar los buffers, se guardan los cambios en el almacenamiento
  fclose(file_a);
  fclose(file_b);
  fclose(res_file);

  return 0;
}