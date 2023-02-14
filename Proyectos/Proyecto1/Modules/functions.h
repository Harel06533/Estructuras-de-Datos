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
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*
=======
GLOBALS
=======
*/

//Colores
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

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

  /*
  * Esta sección es un while que loopea hasta que se haya cumplido con el porcentaje requerido de asientos a llenar.  
  * Iterará en un índice rándom, si no hay nada, lo llena y setea sus propiedades iniciales.
  * Dependiendo del cuarto del porcentaje (25%) que se encuentre, algunas propiedad varían. 
  */
  while (seatCounter != limitTaken) {
    randomIndex = randomNumber((rows * columns) + 1);
    if ((pointerMatrix + randomIndex) -> isTaken == false) {
      (pointerMatrix + randomIndex) -> isTaken = true;
      (pointerMatrix + randomIndex) -> pstatus = 0;
      (pointerMatrix + randomIndex) -> id = id;
      (pointerMatrix + randomIndex) -> age = randomNumber(91) + 1;
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
      if (currentCell.isTaken == false) {
        printf("  ");
      } else if (currentCell.isVaccinated == false && currentCell.pstatus == 0) {
        (currentCell.isFaceMasked == true) ? printf(CYAN"s "RESET) : printf(YELLOW"S "RESET);
      } else if (currentCell.isVaccinated == true && currentCell.pstatus == 0) {
        (currentCell.isFaceMasked) ? printf(GREEN"v "RESET) : printf(BLUE"V "RESET); 
      } else if (currentCell.pstatus == 1) {
        (currentCell.isFaceMasked) ? printf(MAGENTA"e "RESET) : printf(RED"E "RESET);
      } else if (currentCell.pstatus == 2) {
        printf("r ");
      }
    } 
    printf("\n");
  }
}

/*
* "INFECTAR" las celdas vecinas. Esta función corre en main
*/
int checkNeighbor (Cell *currentCell, Cell *compareCell) {
  int currentMasked = currentCell -> isFaceMasked;
  int compareMasked = compareCell -> isFaceMasked;
  int vaccinated = compareCell -> isVaccinated;
  int randProb = randomNumber(100);
  int prob;

  if (currentMasked == true) 
    prob = compareMasked ? (vaccinated ? 5 : 10) : (vaccinated ? 15 : 20);
   
  if (currentMasked == false) 
    prob = compareMasked ? (vaccinated ? 15 : 20) : (vaccinated ? 45 : 90);
  
  if (randProb < prob) {
    compareCell -> pstatus = 1;
    return 1;
  }
  return 0;
}

#endif