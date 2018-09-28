#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void matriz_imprimir(Matriz* matriz){
  int i, j;
	for(i = 1; i <= matriz_nfilas(matriz); i++){
		for(j = 1; j <= matriz_ncolumnas(matriz); j++){
			printf("%f\t", matriz_leer(matriz, i, j));
		}
		puts("");
	}

	puts("");
}

int main()
{
	int i, j;

	Matriz* matriz = matriz_crear(4, 3);
// recordar usar -lm cuando compilo, para linkear la libreria de math
	for(i = 1; i <= matriz_nfilas(matriz); i++)
		for(j = 1; j <= matriz_ncolumnas(matriz); j++)
			matriz_escribir(matriz, i, j, i*j + (sqrt((double) i*j + 0.42)));
			//matriz_escribir(matriz, i, j, 4);
	matriz_imprimir(matriz);

	matriz_intercambiar_filas(matriz, 2, 3);

	matriz_imprimir(matriz);

	matriz_insertar_fila(matriz, 4);

	matriz_imprimir(matriz);

	matriz_destruir(matriz);

	return 0;
}
