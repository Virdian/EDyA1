/* La mediana de un arreglo de números es el elemento m para el cual la mitad del resto de los
elementos del arreglo es mayor o igual que m y la otra mitad es menor o igual que m, si el número
de elementos es impar. Si es par, la mediana se define como el promedio del par de elementos m 1
y m 2 para el cual una mitad de los elementos restantes del arreglo es mayor o igual que m 1 y
m 2 y la otra mitad es menor o igual que m 1 y m 2 . Escriba una función que reciba un arreglo de
números y calcule su mediana:
 */
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(float arreglo[], size_t longitud) {
	
  for (int iter = 0 ; iter < longitud - 1 ; iter++) {
    for (int i = 0 ; i < longitud - iter - 1; i++) {
      if (arreglo[i] > arreglo[i + 1]) {
        float aux = arreglo[i];
        arreglo[i] = arreglo[i + 1];
        arreglo[i + 1] = aux;
      }
     }
   }
}

float devolvedor_de_mediana(float* array, int longitud){
  float* arreglo;
  float promedio = 0;  
  arreglo = malloc(sizeof(float)*longitud);
  for (int i = 0; i < longitud ; i++) {
	  arreglo[i] = array[i];
	  }
  
  bubble_sort(arreglo, longitud);
  
  if (longitud%2 != 0) {
    return arreglo[longitud/2];
  }
  
  promedio = (arreglo[longitud/2-1] + arreglo[longitud/2])/2;
  
  return promedio;
}

int main(){
	float* array;
	float* array2;
	int i;
	
	array = malloc(sizeof(float)*5);
	array2 = malloc(sizeof(float)*6);
	
	for( i = 0; i< 6; i++){
	  array[i] = i;	
	}
	
	printf("%f", devolvedor_de_mediana(array,6));
	
	return 0;
}