/*
=========
MODULOS
=========
*/
#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H

/*
=========
INCLUDES
=========
*/
#include "structs.h"
#include <time.h>
#include <stdlib.h>

/*
=======
GLOBALS
=======
*/

//Colores
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

/*
=========
FUNCIONES
AYUDA  
=========
*/

//Generar número random
float randomNumber (int limit) {return ((rand() % limit));}


/*
===========
INICIALIZAR
MATRÍZ
===========
*/
void initial (Cell matrix[rows][columns]) { 

  //Configuraciones 
  Cell *pointerMatrix = *(matrix); //Apuntador al elemento de la matríz
  float seatLimitP = 0.6; //El porcentaje de asientos ocupados
  int limitTaken = rows * columns * seatLimitP; //El total del porcentaje

  //Contadores
  int seatCounter = 0;  //Contador de asientos
  int id = 1; //ID, inicializado en 1
  int celstatCounter = 1; //Contador de las propiedades de celda
  int randomIndex; //Índice aleatorio

  //Inicializar en falso todos las celdas
  for (int i = 0; i < rows * columns; i++) {
    (pointerMatrix + i) -> isTaken = false;
  }

  //Iterar en alguna posición random y llenarla
  while (seatCounter != limitTaken) {
    randomIndex = randomNumber((rows * columns) + 1);
    if((pointerMatrix + randomIndex) -> isTaken == true) continue;

    if ((pointerMatrix + randomIndex) -> isTaken == false) {
      (pointerMatrix + randomIndex) -> isTaken = true;
      (pointerMatrix + randomIndex) -> pstatus = 0;
      (pointerMatrix + randomIndex) -> id = id;
      (pointerMatrix + randomIndex) -> age = randomNumber(91);
      (pointerMatrix + randomIndex) -> days = 0;

      if (celstatCounter <= limitTaken / 4) {
        (pointerMatrix + randomIndex) -> isFaceMasked = false;
        (pointerMatrix + randomIndex) -> isVaccinated = false;
      } else if (celstatCounter <= limitTaken / 2) {
        (pointerMatrix + randomIndex) -> isFaceMasked = true;
        (pointerMatrix + randomIndex) -> isVaccinated = false;
      } else if (celstatCounter <= (limitTaken / 2) + (limitTaken / 4)) {
        (pointerMatrix + randomIndex) -> isFaceMasked = false;
        (pointerMatrix + randomIndex) -> isVaccinated = true;
      } else if (celstatCounter <= limitTaken) {
        (pointerMatrix + randomIndex) -> isFaceMasked = true;
        (pointerMatrix + randomIndex) -> isVaccinated = true;
      }
      id++;
      celstatCounter++;
      seatCounter++;
    }
  }
}

/*
========
IMPRIMIR
========
*/
void printMatrix (Cell matrix[rows][columns]) {
  Cell *pointerMatrix = *(matrix);
  Cell currentCell;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      //Guardar la celda de manera efectiva
      currentCell = *(pointerMatrix + (i * columns) + j);
      if (currentCell.isTaken == false) 
        printf(" "); 

      if (currentCell.isVaccinated == false && currentCell.pstatus == 0 && currentCell.isFaceMasked == false) {
        printf("S ");
      } else if (currentCell.isVaccinated == false && currentCell.pstatus == 0 && currentCell.isFaceMasked == true) {
        printf("s ");
      } else if (currentCell.isVaccinated == true && currentCell.pstatus == 0 && currentCell.isFaceMasked == false) {
        printf("V ");
      } else if (currentCell.isVaccinated == true && currentCell.pstatus == 0 && currentCell.isFaceMasked == true) {
        printf("v ");
      } else if (currentCell.pstatus == 1 && currentCell.isFaceMasked == false) {
        printf("E ");
      } else if (currentCell.pstatus == 1 && currentCell.isFaceMasked) {
        printf("e ");
      } else if (currentCell.pstatus == 2) {
        printf("r ");
      }
    }
    printf("\n");
  }
}

#endif