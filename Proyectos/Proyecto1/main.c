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
  
  //Inicializar variables
  Cell sarsM[rows][columns];
  Cell *pSars = *sarsM;
  Cell currentCell;
  char enter;
  int index;
  int dayCount = 0;
  int randomP;
  int sickNum = 0;
  int restNum = 0;
  srand(time(NULL));

  //Mostrar al usuario
  clear();
  printf("===== SIMULADOR DE SarsCOV-2 =====\n");
  printf("Importante para el Usuario:\n");
  printf(ANSI_COLOR_YELLOW"S = NO VACUNADO - SANO - SIN CUBREBOCAS\n"ANSI_COLOR_RESET);
  printf(ANSI_COLOR_CYAN"s = NO VACUNADO - SANO - CON CUBREBOCAS\n"ANSI_COLOR_RESET);
  printf(ANSI_COLOR_BLUE"V = VACUNADO - SANO - SIN CUBREBOCAS\n"ANSI_COLOR_RESET);
  printf(ANSI_COLOR_GREEN"v = VACUNADO - SANO - CON CUBREBOCAS\n"ANSI_COLOR_RESET);
  printf(ANSI_COLOR_RED"E = ENFERMO - SIN CUBREBOCAS\n"ANSI_COLOR_RESET);
  printf(ANSI_COLOR_MAGENTA"e = ENFERMO - CON CUBREBOCAS\n"ANSI_COLOR_RESET);
  printf("r = RECUPERADO\n");

  printf("Presione Enter para continuar: ");
  scanf("%c", &enter);
  
  //Inicializar las propiedades de la matríz
  clear();
  initial(sarsM);
  printMatrix(sarsM);
  printf("Este es el tablero generado, Al continuar se elige un enfermo al azar para observar el comportamiento\n");
  printf("Presione Enter para continuar: ");
  scanf("%c", &enter);

  //Generar un enfermo random para observar su resultado. También aumenta el número de enfermos a 1
  while (true) {
    randomP = randomNumber((rows * columns) + 1);
    if ((pSars + randomP) -> isTaken) {
      sickNum++;
      (pSars + randomP) -> pstatus = 1;
      currentCell = *(pSars + randomP);
      break;
    }
  }

  //Imprimir enfermo y comenzar proceso
  clear();
  printMatrix(sarsM);
  printf("\nEsta es la celda que se ha enfermado: \n");
  printf("Id: %d\n", currentCell.id);
  printf("Edad: %d\n", currentCell.age);
  printf("Vacunas: ");
  (currentCell.isVaccinated) ? printf("VACUNADO\n") : printf("NO VACUNADO\n");
  printf("Cubrebocas: ");
  (currentCell.isFaceMasked) ? printf("UTILIZA\n") : printf("NO UTILIZA\n");
  printf("Presione Enter para comenzar el proceso: ");
  scanf("%c", &enter);

  clear();
  /*
  //Propiedades del paciente 0 y sus vecinos
  for (int i = 0; i < 3; i++) {
    index = (-31) + (30 * (i % 3));
    for (int j = 0; j < 3; j++) {
      checkNeighbor((pSars + randomP), (pSars + randomP + index));
      index += 1;
    }
  }
  */

  //Proceso. Se inicializa el paciente 0 con sus respectivos días enfermo como referencia
  while (true) {
    clear();

    //Iterar
    for (int i = 0; i < rows * columns; i++) {
      if ((pSars + i) -> pstatus == 1) {
        (pSars + i) -> days++;
        sickNum += checkNeighbor((pSars + i), ((pSars + i)  - 31));
        sickNum += checkNeighbor((pSars + i), ((pSars + i) - 30));
        sickNum += checkNeighbor((pSars + i), ((pSars + i) - 29));
        sickNum += checkNeighbor((pSars + i), ((pSars + i) - 1));
        sickNum += checkNeighbor((pSars + i), ((pSars + i) + 1));
        sickNum += checkNeighbor((pSars + i), ((pSars + i) + 29));
        sickNum += checkNeighbor((pSars + i), ((pSars + i) + 30));
        sickNum += checkNeighbor((pSars + i), ((pSars + i) + 31));
      }
    }
    //Información al usuario
    printMatrix(sarsM);
    printf("\nEnfermos = %d", sickNum);
    printf("\nRecuperados = %d", restNum);
    printf("\nDias: %d", dayCount);
    dayCount++;
    scanf("%c", &enter);
  }
  return 0;
}

