#include "matrix.h"
#include <stdio.h>


struct Matriz_{
	float** datos;

	int nfilas;
	int ncols;
};

Matriz* matriz_crear(int nfilas, int ncols){
	int i;
	Matriz* matriz = (Matriz*)malloc(sizeof(Matriz));
	matriz->datos = malloc(sizeof(float*) * nfilas);
	for(i = 0; i < nfilas; i++)
		matriz->datos[i] = malloc(sizeof(float) * ncols);
	matriz->nfilas = nfilas;
	matriz->ncols = ncols;

	return matriz;
}

void matriz_destruir(Matriz* matriz){
	int i;
	for(i = 0; i < matriz->nfilas; i++)
		free(matriz->datos[i]);

	free(matriz->datos);
	free(matriz);
}

float matriz_leer(Matriz* matriz, int nfilas, int ncols){
	return matriz->datos[nfilas-1][ncols-1];
}

void matriz_escribir(Matriz* matriz, int nfilas, int ncols, float dato){
	matriz->datos[nfilas-1][ncols-1] = dato;
}

int matriz_nfilas(Matriz* matriz){
	return matriz->nfilas;
}

int matriz_ncolumnas(Matriz* matriz){
return matriz->ncols;
}

void matriz_intercambiar_filas(Matriz* matriz, int fil1, int fil2){
	float* temp = matriz->datos[fil1-1];
	matriz->datos[fil1-1] = matriz->datos[fil2-1];
	matriz->datos[fil2-1] = temp;
}

void matriz_insertar_fila(Matriz* matriz, int pos){
	matriz->nfilas++;
	matriz->datos = realloc(matriz->datos, sizeof(float*) * (matriz->nfilas * 3));
	matriz->datos[matriz->nfilas - 1] = malloc(sizeof(float) * (matriz->ncols *3));

	int i;
	for(i = matriz->nfilas; pos < i; i--)
		matriz_intercambiar_filas(matriz, i, i-1);
	for(i = 1; i < matriz->ncols+1; i++)
		matriz_escribir(matriz, pos, i, 0);
}

Matriz* matriz_identidad(int n){
  int i, j;
  Matriz* matriz = matriz_crear(n, n);

  for(i = 0; i < n;i++)
    for(j = 0; j < n; j++){
      if(i == j) matriz->datos[i][j] = 1;
      else
        matriz->datos[i][j] = 0;
    }
  return matriz;
}

Matriz* matriz_concatenar(Matriz a, Matriz b){
  if(a.nfilas != b.ncols) return NULL;

  int i, j;
  int c = a.ncols + b.ncols;
  Matriz* new = matriz_crear(a.nfilas, c);

  for(i = 0; i < a.nfilas; i++)
    for(j = 0; j < c; j++){
      if(j < a.ncols) new->datos[i][j] = a.datos[i][j];
      new->datos[i][j] = b.datos[i][j - a.ncols];
    }

  return new;
}
