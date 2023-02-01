/*
* Miércoles/Ejer2 - Función que recibe como parámetro otra función para ejecutarla
*/
#include <stdio.h>

/*
* Execute, recibe como parámetro un apuntador a función y ejecuta esa función
*/
void execute (void (*func)(void)) { 
  func();
}

/*
* Función de prueba
*/
void salute () {
  printf("Hello\n");
}

int main () {
  execute(salute);  //Se llama la funcion 'execute' y como argumento pasa la función a la que se apuntará 
  return 0;
}