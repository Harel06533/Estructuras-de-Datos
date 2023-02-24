#include <stdlib.h>
#include <stdio.h>

#ifndef _DATE_H
#define _DATE_H

//Estructura
typedef struct {
  short year;
  short month;
  short day;
} DATE_STRUCT;

//Bool
#define true 1
#define false 0 

//Apuntador a estructura para poder modificar los valores de manera global
typedef DATE_STRUCT *Date;  

//Crea la fecha
Date dateCreate (short year, short month, short day); 

//Suma días a la fecha; Existe manejo de meses
void daysSum (Date date, short days);

//Resta días a la fecha; Existe manejo de meses
void daysSub (Date date, short days);

//Imprime la fecha en formato json
void printDate (Date date); 

//Libera la memoria
void dateDestroy (Date date);


#endif