/*
* Ejercicio 1 - Semana 3 / 'Retornar el valor mayor en una matriz'
*/
#include <stdio.h>

//Globales de columnas y filas
#define rows 3 
#define cols 3 

//Declaración de la matríz global
int matArr[rows][cols] = {{1, 2, 3}, {-1, -2, 0}, {2, 4, -1}};

/*
* Función que retorna el valor mayor en una matriz
*/
int max (int matrix[rows][cols]) {
  int maxValue;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (*(*(matrix + i) + j) > maxValue) { //El contenido de la matríz es una dirección por lo que '**' es requerido
        maxValue = *(*(matrix + i) + j); //Iguala el valor mayor actual por el nuevo encontrado en la matriz
      } 
    }
  }
  return maxValue;
}

//Main
int main () {
  printf("Largest number is = %d", max(matArr));
  return 0;
}