#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Estructura de cada nodo individual de la lista */
typedef struct node {
  int value;
  struct node *next;
} primenum;

/* Estructura de la lista enlazada completa */
typedef struct linkedlist {
  primenum *firstValue, *lastValue;
} List;

/* Tipo de Dato abstracto booleano */
typedef enum _myBool {
  false,
  true
} bool;

/**
 * Checa que un número sea primo en base a un comienzo
 * 1. Itera a partir del comienzo, y mientras el cuadrado iterado no sea menor que el valor (raíz cuadrada) sigue de 1 en 1
 * 2. Si el valor es divisble con el iterador, entonces no es primo, por lo que regresa falso
 * 3. Retorna verdadero al salir de la iteración.
*/
bool isPrime (int start, int value) {
  for (int i = start; i * i <= value; i++) {
    if (value % i == 0) {
      return false;
    }
  }
  return true;
}

/**
 * Añade nodos a una lista enlazada
 * 1. Crea un nuevo nodo, inicializa su apuntador siguiente en NULL y su valor con el parámetro ingresado
 * 2. Si la lista no está inicializada, la inicializa y finaliza la función.
 * 3. Si no, entonces el siguiente nodo apuntado por el último valor se iguala con el nuevo nodo creado
 * 4. El último elemento de la lista se mueve al siguiente.
*/
void addToList (List *list, int value) {
  primenum *node = malloc(sizeof(primenum));
  node -> next = NULL;
  node -> value = value;
  if (list -> firstValue == NULL) {
    list -> firstValue = node;
    list -> lastValue = node;
    return;
  }
  list -> lastValue -> next = node;
  list -> lastValue = list -> lastValue -> next;
}

/* En base a un límite, añade los números primos a la lista enlazada */
void genPrimeList (List *list, int limit) {
  for (int i = 2; i < limit; i++) {
    if (isPrime(2, i)) {
      addToList(list, i);
    }
  }
}

/* Imprime los valores de la lista */
void printList (List *list) {
  primenum *ptr = malloc(sizeof(primenum));
  ptr = list -> firstValue;
  while (ptr != NULL) {
    printf("%d\n", ptr -> value);
    ptr = ptr -> next;
  }
}

/* Main */
int main () {

  /* Tomar tiempo de ejecución del algorítmo */
  clock_t start, end; 

  /* Inicializa la lista con sus dos valores Nulos */
  List primeList = {NULL, NULL};
  int limit;

  /* Valida que el usuario ingrese un dato correcto */
  do {
    printf("Cantidad de numeros primos a imprimir (no menor a 1): ");
    scanf("%d", &limit);
  } while (limit < 1);

  /* Genera e imprime la lista */
  start = clock();
  genPrimeList(&primeList, limit);
  printList(&primeList);
  end = clock();

  /* Imprime el tiempo tomado */
  printf("\n\nTiempo de algoritmo fue de : %5.2f", ((double)(end - start)) / CLOCKS_PER_SEC);
  return 0;
}