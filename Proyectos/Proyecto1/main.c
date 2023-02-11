/*
* === PROYECTO 1 ===
* HAREL ALEJANDRO OLGUÍN GAYTÁN
* ADRIÁN
*/

/*
=======
INCLUDE
=======
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Modules/structs.h"
#include "Modules/functions.h"

/*
==========
CHECAR 
SISTEMA
OPERATIVO
==========
*/
#ifdef _WIN32
#include <windows.h>
void wait (float seconds) {
  Sleep(seconds * 1000);
}
void clear () {
  system("cls");
}
#else
#include <unistd.h>
void wait (float seconds) {
  sleep(seconds);
}
void clear () {
  system("clear");
}
#endif

/*
===========
MAIN
===========
*/
int main () {
  //Variables
  Cell sarsMatrix[rows][columns];

  //Programa
  srand(time(NULL));
  initial(sarsMatrix); //Inicializar la matríz creada
  printMatrix(sarsMatrix);
  return 0;
}











