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
#else
#include <unistd.h>
#endif

void wait (int seconds) {
  #ifdef _WIN32
  Sleep(seconds * 1000);
  #else
  sleep(seconds);  
  #endif
}

void clear () {
  #ifdef _WIN32
  system("cls");
  #else
  system("clear");
  #endif
}


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
  printf(YELLOW"S = NO VACUNADO - SANO - SIN CUBREBOCAS\n"RESET);
  printf(CYAN"s = NO VACUNADO - SANO - CON CUBREBOCAS\n"RESET);
  printf(BLUE"V = VACUNADO - SANO - SIN CUBREBOCAS\n"RESET);
  printf(GREEN"v = VACUNADO - SANO - CON CUBREBOCAS\n"RESET);
  printf(RED"E = ENFERMO - SIN CUBREBOCAS\n"RESET);
  printf(MAGENTA"e = ENFERMO - CON CUBREBOCAS\n"RESET);
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

  //Proceso. Se inicializa el paciente 0 con sus respectivos días enfermo como referencia
  while (true) {
    clear();

    //Iterar
    for (int i = 0; i < rows * columns; i++) {
      if ((pSars + i) -> pstatus == 1 &&(pSars + i) -> days == 8) {
        (pSars + i) -> pstatus = 2;
        sickNum--;
        restNum++;
      } else if ((pSars + i) -> pstatus == 1) {
        Cell *currentPc = (pSars + i);
        currentPc -> days++;
        for (int k = 0; k < 8; k++) {
          if ((currentPc + *(nindex + k)) -> isTaken == false || (i + *(nindex + k)) % rows == 0 || i + *(nindex + k) >= 0 && i + *(nindex + k) <= (rows - 1) || i + *(nindex + k) % rows == (rows - 1) || (i + *(nindex + k) >= ((rows * columns) - rows - 1) && (i + *(nindex + k) <= (rows * columns) - 1))) {
            continue;
          } else {
            sickNum += checkNeighbor(currentPc, currentPc + *(nindex +k));
          }
        }
      }
    }
    //Información al usuario
    printMatrix(sarsM);
    printf("\nDias: %d", dayCount);
    dayCount++;
    scanf("%c", &enter);
  }
  return 0;
}

