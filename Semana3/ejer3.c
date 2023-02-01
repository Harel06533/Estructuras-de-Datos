/*
* Ejercicio 1 - Miércoles: Igualar un apuntador a función como función y ejecutar con sus respectivos parámetros
*/
#include <stdio.h>

/*
* Imprime el doble del número ingresado 
*/
void printDoubled (int _num) {
  printf("Doubled number = %d\n", _num * 2);
}

/*
* Imprime el triple del número ingresado
*/
void printTriple (int _num) {
  printf("Tripled number = %d\n", _num * 3);
}

/*
* Suma 2 números (Notese que aquí se espera retornar un entero)
*/
int add (int a, int b) {
  return a + b;
}

/*
* Retorna una resta de 2 números
*/
int sub (int a, int b) {
  return a - b;
}

int main () {
  void (*function_A) (int) = 0; //Apuntador que recibe enteros y retorna nada
  int (*function_B) (int, int) = 0; //Funciones de operadores, recibe enteros retorna enteros

  //Funciones void con parámetros enteros
  function_A = printDoubled; //El apuntador a función iguala su valor a la dirección de una función (Parámetros y valor retornado especificados)
  function_A(10);
  function_A = printTriple;
  function_A(25);

  //Funciones int con parámetros int y printf aparte
  function_B = add; //De igual manera, pero 'function_b' está hecha para recibir y retornar enteros
  printf("Add result = %d\n", function_B(4, 4));
  function_B = sub;
  printf("Subtract result = %d\n", function_B(10, 9));
  return 0;
}