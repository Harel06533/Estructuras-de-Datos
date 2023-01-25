//La función reverse requiere de otras funcionalidades ya dadas en las actividades
#include <stdio.h>

/*
* Función que obtiene el tamaño del String, esto para poder determinar un límite de iteración
*/
int len (char *string) {
  char *pointerString = string;
  while (*pointerString != '\0') {
    pointerString++;
  }
  return (pointerString - string);
}

/*
* Función que intercambia los valores de 2 caracteres, esto será útil para intercambiar los valores iniciales y finales
*/
void swapChar (char *char1, char *char2) {
  char currentChar = *char1;
  *char1 = *char2;
  *char2 = currentChar;
}

/*
* Función que reversa una String, utiliza la función ```len()`` y la función swapChar()
*/
void reverseString (char *string) {
  for (int i = 0; i < len(string) / 2; i++) {
    swapChar(string, (string + len(string) - i - 1)); //Cambia el valor de la dirección apuntada más el mismo pero en la última dirección disponible (--)
    string++; //len(string) va cambiando su valor puesto que el subíndice va aumentando y por ende, el punto de inicio cambiando
  }
}

int main () {
  char String[] = "Guadalajara";
  reverseString(String);
  printf("%s", String);
  return 0;
}