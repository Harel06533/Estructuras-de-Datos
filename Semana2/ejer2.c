#include <stdio.h>
#include <math.h> //Raíz Cuadrada

typedef struct {
  float x, y;
} Vector2;

void toUnit (Vector2 *vector) {
  float value_X = vector -> x; //Variables que se regresarán a la dirección de memoria
  float value_Y = vector -> y;

  vector -> x = value_X / (sqrt(pow(value_X, 2) + pow(value_Y, 2))); //El valor final de la dirección será la operación de vector = V / |V|
  vector -> y = value_Y / (sqrt(pow(value_X, 2) + pow(value_Y, 2)));
}

int main () {
  Vector2 vectors = {3, 4};

  toUnit(&vectors);
  printf("%.1f, %.1f", vectors.x, vectors.y); //0.6 y 0.8
  return 0;
}