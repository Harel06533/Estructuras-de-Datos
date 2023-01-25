// Actividad 1 - Función 'length' ** Harel Alejandro Olguín Gaytán ** Isaac De la Cruz López

#include <stdio.h>

int length (char *);

int main (void) {
  char String[] = "Hola Mundo :)";
  printf("El tamaño del string '%s' es de %d", String, length(String));
  return 0;
}

int length (char *string) {
  char *stringPointer = string; //Apunta al valor en la dirección de memoria dada por el parametro

  //Checa que exista contenido dentro de la dirección de memoria apuntada, y mientras lo haya, suma el tamaño
  while (*stringPointer) {
    stringPointer++;
  }
  return (stringPointer - string); //Retorna la dirección final menos la primera, eso es la diferencia entre ambas que es el tamaño
}

        