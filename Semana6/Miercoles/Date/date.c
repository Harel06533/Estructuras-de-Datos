/* No pregunten, realmente ni yo entiendo muy bien qué hice JKJAKSJAK */
#include "date.h"

//Arreglo de meses para calcular en base al mes asignado
const int dayMonth[12] = {
  31, //Enero
  28, //Febrero
  31, //Marzo
  30, //Abril
  31, //Mayo 
  30, //Junio
  31, //Julio
  31, //Agosto
  30, //Septiembre
  31, //Octubre
  30, //Noviembre
  31 //Diciembre
};

//Crea la fecha
Date dateCreate (short year, short month, short day) {
  Date date = malloc(sizeof(DATE_STRUCT));
  date -> year = year;
  date -> month = month;
  date -> day = day;
  return date;
}

/**
 * SUMA DÍAS A UNA FECHA
 * 1. Declara una variable para guardar el mes que se encuentra acutalmente la variable
 * 2. Si se da el caso de que la suma de días superen la cantidad de días del mes entonces:
 *  a. Checa que, si el mes es 12, regresa a 1 (Enero) y suma el año, o si no solo suma 1 al més
 *  b. Itera en el día actual y es menor que la suma total del día más los días a añadir
 *  c. Si se llega al máximo de días del mes actual, suma 1 a la variable dayLen
 *  d. Cambia el valor del día actual a dayLen, que es la cantidad de días después del último del mes
 *  e. Retorna para finalizar
 * 3. Si no se cumple solo la cantidad de días
*/
void daysSum (Date date, short days) {
  short currentMonth = dayMonth[date -> month - 1];

  if (date -> day + days > currentMonth) {
    (date -> month == 12) ? (date -> month = 1, date -> year++) : (date -> month++);
    short dayLen = 0;
    for (int i = date -> day; i <= date -> day + days; i++) {
      if (i > currentMonth) {
        dayLen++;
      }
    }
    date -> day = dayLen;
    return;
  }
  date -> day += days;
}

/**
 * RESTA DÍAS A UNA FECHA
 * 1. Declara el valor del més anterior, que es el més al que se regresará
 * 2. Si ocurre que la resta del día actuál menos los días sea menor o igual a 0 entonces:
 *  a. Checa si cambia el año
 *  b. Itera desde los días totales iniciales, hasta los días que se quieren restar
 *  c. Si pasa la marca de ser menor o igual al último día del mes pasado suma dayLen 
 *  d. El día cambia a el valor del mes pasado y se le resta los días que se indican en dayLen
 * 3. Si no, solamente resta los días 
*/
void daysSub (Date date, short days) {
  short lastMonth = dayMonth[date -> month - 1];

  if (date -> day - days <= 0) {
    (date -> month == 1) ? (date -> month = 12, date -> year--) : (date -> month--);
    short dayLen = 0;
    for (int i = lastMonth + date -> day; i > lastMonth + date -> day - days; i--) {
      if (i <= lastMonth) {
        dayLen++;
      }
    }
    date -> day = lastMonth - dayLen;
    return;
  }
  date -> day -= days;
}

//Imprime la fecha en formato json
void printDate (Date date) {
  printf("\n{\n\n");
  printf("'Year': %7.d\n", date -> year);
  printf("'Month': %7.d\n", date -> month);
  printf("'Day': %7.d\n", date -> day);
  printf("\n}\n");
} 

//Libera la memoria
void dateDestroy (Date date) {
  free (date);
}
