/*
* Ejercicio - Crear una función sortnames() que acomode una matriz de strings
*
*Este me costó mucho trabajo asi que ahí va un contador de Seg faults
*segmentationFaults = 38
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Función que intercambia dos strings; Requiere <string.h>
void swapStrings (char *string1, char *string2, char *aux) {
  strcpy(aux, string1); //Dado a que los parámetros son apuntadores, al pasarlos a otra función pasan ya como dirección automáticamente
  strcpy(string1, string2);
  strcpy(string2, aux);
}

//Función que acomoda los nombres en órden alfabético
void sortNames (char arrayNames[][10], int length) {
  char *auxValue = (char*) malloc(length); //Es necesario pre-alocar la memoria puesto que si no, el programa intentaría acceder a una memoria inusable (Más de la mitad de los seg-faults :c)
  int comparasion;
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length - 1 - i ; j++) {
      comparasion = strcmp(*(arrayNames + j), *(arrayNames + j + 1)); //Compara el valor actual con el siguiente
      if (comparasion > 0) { //Función strcmp(s1, s2), compara 2 strings, si s1 > s2 retorna 1; si s1 < s2 retorna -1; si s1 == s2 retorna 0 
        swapStrings(*(arrayNames + j), *(arrayNames + j + 1), auxValue);
      }
    }
  }
  free(auxValue); //Libera la alocación de la memoria
}

//Función que imprime los valores
void printNames (void *charMat, int length) {
  char *charPointer = charMat; //Define el tipo de dato del apuntador void
  for (int i = 0; i < length; i++) {
    printf("%s\n", charPointer); //'%s' Da formato string, lo que asume que se imprimirá de varias direcciónes de memoria
    charPointer += length;
  } 
}

int main () {
  char names[10][10] = {"José", "Juán", "Gaby", "María", "Karla", "Luis", "Antonio", "Cecilia", "Roberto", "Francisco"};
  printNames(names, 10);
  printf("\n");
  sortNames(names, 10);
  printNames(names, 10);
  return 0;
}

// Tomé ayuda de esta página -> https://pencilprogrammer.com/c-programs/sort-names-in-alphabetical-order/