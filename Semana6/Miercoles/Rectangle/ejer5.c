/*
* --Miércoles Tipos de datos abstractos -- Rectangulos.
*/
#include <stdio.h>
#include "rectangles.h"

int main () {
  Rectangle r1 = createRect(10, 20);

  //Mostrar valores iniciales
  printf("Base del rectángulo: %.2f\n", baseValue(r1));
  printf("Altura del rectángulo: %.2f\n", heightValue(r1));
  printf("Área del rectángulo: %.2f\n", areaValue(r1));
  printf("Perímetro del rectángulo: %.2f\n", perimValue(r1));

  //Cambiar datos
  setNewBase(r1, 12);
  setNewHeight(r1, 15);

  //Mostrar datos nuevos
  printf("Base nueva del rectángulo: %.2f\n", baseValue(r1));
  printf("Altura nueva del rectángulo: %.2f\n", heightValue(r1));

  return 0;
}
