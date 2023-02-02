/*
* Ejercicio 3 - Miércoles : Apuntador a función, funciones lineares y cuadráticas, arreglos de funciones
*/

#include <stdio.h>
#include <math.h>

//Bool
typedef enum{true = 1, false = 0} bool;

//Apuntador a función como tipo de dato
typedef double (*Function2D) (double); //Declara un tipo de dato que es un apuntador a función, este retorna un double 

/*
* Funciones matemáticas
*/
// f(x) = 4x - 2
double x_Func1 (double value_x) {
  return ((4 * value_x) - 2);
}

// f(x) = 3x^2 - 2x + 4
double x_Func2 (double value_x) {
  return ((3 * pow(value_x, 2)) - (2 * value_x) + 4);
}

// f(x) = 6sqrt(x) + 2
double x_Func3 (double value_x) {
  return ((6 * sqrt(value_x)) + 2);
}

/*
* Determina si es linear
*/
bool isLinear (Function2D C_func, double num1, double num2) { //Como parámetro debe pasar un apuntador a función
  double value1 = C_func(num1); //Se puede evaluar la función parámetro
  double value2 = C_func(num2);
  if (value2 / value1 >= 1.99 && value2 / value1 <= 2.01) { //Rango para determinar si es lineal
    return true;
  }
  return false;
}

/*
* Determina si es Cuadrática
*/
bool isQuadratic (Function2D C_func, double num1, double num2) {
  double value1 = C_func(num1);
  double value2 = C_func(num2);
  if (value2 / value1 >= 3.98 && value2 / value1 <= 4.02) { //Rango para determinar si es cuadrática
    return true;
  }
  return false;
}

int main () {
  Function2D funcArray[] = {x_Func1, x_Func2, x_Func3}; //Arreglo de apuntadores a función
  for (int i = 0; i < 3; i++) {
    //Muchos else, siento que se puede mejorar...
    if (isLinear(funcArray[i], 10000, 20000)) { //Se reemplazan los parámetros, pasa la función del arreglo y sus respectivos argumentos
      printf("Es Lineal. No es Cuadrática\n");
    } else if (isQuadratic(funcArray[i], 10000, 20000)) {
      printf("No es Lineal. Es cuadrática\n"); 
    } else {
      printf("No es Lineal. No es cuadrática\n");
    }
  }
  return 0;
}
