/* Creación y manipulación de listas enlazadas */
#include <stdio.h>

/* TDA de fecha, su última propiedad es un apuntador a la estructura. */
typedef struct datestr {
  int day;
  int month;
  int year;
  struct datestr *next;
} Date;

/* Bool */
typedef enum myBool {false, true} bool;

/* Inserta una nueva instancia de Date en una lista enlazada */
void listInsert (Date **start, Date *instance);

/* Imprime TODOS los valores existentes en la lista enlazada */
void printDates (Date *date); 
  
/* Main */
int main () {
  /* Instancias de 'Date' */
  Date d1 = {3, 9, 2003};
  Date d2 = {12, 12, 2012};
  Date d3 = {10, 2, 2009};

  /* Valor inicial (Se inicializará con el valor que le demos, este será el primero de la lista enlazada) */
  Date *start = NULL;
  
  /* Inserta nuevos valores a la lista */
  listInsert(&start, &d1);
  listInsert(&start, &d2);
  listInsert(&start, &d3);

  /* Imprime esos valores */
  printDates(start);
  return 0;
}

/** Inserta un valor 'Date' a una lista enlazada
 *  1. Declara un apuntador al inicio actual de la lista
 *  2. Si la lista está vacía, es decir no hay posición inicial, la comienza y finaliza;
 *  3. Entra a un while para checar si la siguiente posición es NULL:
 *    a) Si la siguiente posición es NULL, iguala esa siguiente posición a la instancia actuál, esto significa que enlazo la siguiente posición a la posición actuál de la lista
 *    b) Si no se cumple la condición, sigue iterando y moviendose a la siguiente posición;
*/
void listInsert (Date **start, Date *instance) {
  Date *curr = *start;
  if (curr == NULL) {
    *start = instance;
    return;
  }

  while (true) {
    if (curr -> next == NULL) {
      curr -> next = instance;
      break;
    }
    curr = curr -> next;
  }
}

/**
 * Imprime los datos de la lista enlazada.
 * 1. Declara un apuntador nuevo que vale la dirección de memoria actual.
 * 2. Mientras el valor de ese apuntador no sea NULL: 
 *  a) Imprime el valor actual 
 *  b) Cambia el valor del apuntador al siguiente que apunta la lista.
*/
void printDates (Date *date) {
  Date *ptr = date;
  while (ptr != NULL) {
    printf("{\n\t'Day': %d\n\t'Month': %d\n\t'Year': %d\n}", ptr -> day, ptr -> month, ptr -> year);
    ptr = ptr -> next;
  }
}
