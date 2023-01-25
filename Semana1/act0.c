#include <stdio.h>

float calcularPromedio (int, float[], float[]);

int main (void) {

  float c1[3];  
  float c2[3];
  float promedio;
  
  for (int i = 0; i < 6; i++) {
    printf("Calificado %d: ", i + 1);
    (i < 3) ? scanf("%f", &c1[i]) : scanf("%f", &c2[i - 3]); //Determina dónde guarda las variables
  }

  promedio = calcularPromedio(3, c1, c2);

  if (!promedio) {
    printf("No pasa debido a reprobar 2 examenes");
  } else {
    (promedio >= 6) ? printf("El estudiante pasa con %.1f", promedio) : printf("El estudiante no pasa con %.1f", promedio); 
  }
  return 0;
}

float calcularPromedio (int fixed_size, float c1[], float c2[]) {

  float promedio = 0;
  int not_passed = 0;

  for (int i = 0; i < fixed_size * 2; i++) {
    if (not_passed == 2) {
      return 0;
    } 
    
   if (i < 3) {
      promedio += c1[i];
      if (c1[i] < 6) {
        not_passed++;
      }
    } else {
      promedio += c2[i - 3];
    }
  }
  return promedio / 6;
}