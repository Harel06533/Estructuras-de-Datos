#ifndef _RECTANGLES_H
#define _RECTANGLES_H

//Estructura base
typedef struct {
  float base;
  float height;
} RECT_S;

//Tipo de Dato apuntador a estructura
typedef RECT_S *Rectangle;

//Tipo de dato booleano
typedef enum {true, false} bool;

//Crear rectangulo nuevo
Rectangle createRect (float base, float height);

//Retorna la base del rectangulo
float baseValue (Rectangle rect);

//Retorna la altura del rectangulo
float heightValue (Rectangle rect); 

//Retorna el área del rectangulo
float areaValue (Rectangle rect);

//Retorna el perímetro del Rectangulo 
float perimValue (Rectangle rect);

//Permite cambiar la base del rectangulo
void setNewBase (Rectangle rect, float value);

//Permite cambiar la altura del rectangul
void setNewHeight (Rectangle rect, float value);

#endif