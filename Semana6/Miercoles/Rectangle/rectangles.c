#include "rectangles.h"
#include <stdlib.h>

//Crear rectangulo nuevo
Rectangle createRect (float base, float height) {
  Rectangle newR = malloc(sizeof(RECT_S));
  newR -> base = base;
  newR -> height = height;
}

//Retorna la base del rectangulo
float baseValue (Rectangle rect) {
  return (rect -> base);
}

//Retorna la altura del rectangulo
float heightValue (Rectangle rect) {
  return (rect -> height);
} 

//Retorna el área del rectangulo
float areaValue (Rectangle rect) {
  return (baseValue(rect) * heightValue(rect));
}

//Retorna el perímetro del Rectangulo 
float perimValue (Rectangle rect) {
  return ((baseValue(rect) * 2) + (heightValue(rect) * 2));
}

//Permite cambiar la base del rectangulo
void setNewBase (Rectangle rect, float value) {
  rect -> base = value;
}

//Permite cambiar la altura del rectangul
void setNewHeight (Rectangle rect, float value) {
  rect -> height = value;
}


