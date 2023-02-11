/*
===============
DEFINICIÓN DE
ESTRUCTURAS
Y TIPOS DE 
DATOS
===============
*/
#ifndef _STRUCTS_H
#define _STRUCTS_H

/*
====
BOOL
====
*/

/*
======
CELDAS
======
*/

//Globals
#define rows 30
#define columns 30
#define true 1
#define false 0

//Estructura
typedef struct {
  //bools
  int isTaken; //Lugar ocupado o no
  int isVaccinated; // Está o no vacunado
  int isFaceMasked; //Utiliza cubrebocas

  //Enteros
  int days; //Días enfermo
  int id; //Identificador - ÚNICO
  int age; // Edad
  int pstatus; //Estatus del paciente 0: SANO, 1: ENFERMO, 2: RECUPERADO
} Cell;

#endif