/* Funciones Insert, Found, Display, Destroy */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Limite de tamaño de la Lista */
#define LIMIT 20

/* Estructura del Nodo individual */
typedef struct STRUCTNODE {
  int value;
  struct STRUCTNODE *next;
} Node;

/* Estructura de una lista enlazada de Nodos */
typedef struct STRLIST {
  Node *head, *last;
} List;

/* TDA booleano */
typedef enum myBool {false, true} bool;

/* Funciones número random, insertar, checar existencia, imprimir y destruir */
int lrand(int start, int end);
void lappend (List *list, int value);
bool listExist (List list, int value);
void printList (List list);
void destroy (List *list);

/* Cómo se inicializa la lista */
#define initList {NULL, NULL};

/* Main */
int main () {
  List myList = initList;
  int randNum;
  srand(time(NULL));

  /* Si el número no existe entonces lo agrega a la lista */
  for (int i = 0; i < LIMIT; i++) {
    randNum = lrand(0, LIMIT);
    if (!listExist(myList, randNum)) { 
      lappend(&myList, randNum);
    }
  }

  printList(myList);
  destroy(&myList);
  return 0;
}

/* Genera un número random entre un inicio y un final */
int lrand (int start, int end) {
  return ((rand() % end) + start);
}

/* Inserta un valor a una lista, esta checa si la lista existe, y si no, la crea con el valor */
void lappend (List *list, int value) {
  Node *current = malloc(sizeof(Node));
  current -> value = value;
  current -> next = NULL;

  if(list -> head == NULL) {
    list -> head = current;
    list -> last = list -> head;
    return;
  }

  list -> last -> next = current;
  list -> last = list -> last -> next;
}

/* Itera en una lista y checa si existe un valor, si existe, inmediatamente retorna verdadero */
bool listExist (List list, int value) {
  Node *current = malloc(sizeof(Node));
  current = list.head;
  while (current != NULL) {
    if (current -> value == value) {
      return true;
    }
    current = current -> next;
  }
  return false;
}

/* Imprime los valores de una lista enlazada */
void printList (List list) {
  Node *pointer = list.head;
  while (pointer -> next != NULL) {
    printf("%d\n", pointer -> value);
    pointer = pointer -> next;
  }
}

/* Destruye los nodos para liberar memoria */
void destroy (List *list) {
  Node *toDestroy = list -> head;
  Node *nextNode;
  while (toDestroy != NULL) {
    nextNode = toDestroy;
    toDestroy = toDestroy -> next;
    free(nextNode);
  }
}