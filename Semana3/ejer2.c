/*
* Función toLower que reduzca caractéres A-Z a minúsculas (a-z) 
*/

#include <stdio.h>

/*
* Pasa como argumento una string que iterará. Si es mayúscula, convierte a minúscula
*/
void toLower (char stringArray[][10], int n) {
  char currentElement;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 10;j++) { //Se requieren 2 dimensiones ya que se quiere acceder al CARACTÉR, no al elemento completo
      currentElement = *(*(stringArray + i) + j); //Obtiene el elemento actual
      if (currentElement >= 65 && currentElement <= 90) {
        currentElement += 32; //Suma 32 (Mayúscula a minúscula)
        *(*(stringArray + i) + j) = currentElement; //Regresa el valor del elemento
      }
    }
  }
}

//Main
int main () {
  char words[][10] = {"HOLA", "MUNDO", "Cruel5", "ADIÓS"};
  toLower(words, 4);

  //Print
  for (int i = 0; i < 4; i++) {
    printf("%s\n", *(words + i));
  }
  return 0;
}