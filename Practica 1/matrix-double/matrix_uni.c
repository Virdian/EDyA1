#include "matrix.h"

struct Matriz_ {
	double* datos;

	int nfilas;
	int ncols;
};

Matriz* matriz_crear(int nfilas, int ncols){
	Matriz* matriz = malloc(sizeof(Matriz));
	matriz->datos = malloc(sizeof(double) * nfilas * ncols);
	matriz->nfilas = nfilas;
	matriz->ncols = ncols;

	return matriz;
}

void matriz_destruir(Matriz* matriz){
	free(matriz->datos);
	free(matriz);
}

double matriz_leer(Matriz* matriz, int nfilas, int ncols){
	int pos = (nfilas * matriz->ncols - 1) - (matriz->ncols - ncols);
	return matriz->datos[pos];
}

void matriz_escribir(Matriz* matriz, int nfilas, int ncols, double dato){
	int pos = (nfilas * matriz->ncols - 1) - (matriz->ncols - ncols);
	matriz->datos[pos] = dato;
}

int matriz_nfilas(Matriz* matriz){
	return matriz->nfilas;
}

int matriz_ncolumnas(Matriz* matriz){
	return matriz->ncols;
}

void matriz_intercambiar_filas(Matriz* matriz, int fil1, int fil2){
	int pos1 = fil1 * matriz->ncols - matriz->ncols;
	int pos2 = fil2 * matriz->ncols - matriz->ncols;
	int i, n, temp;

	for(i = pos1, n = 0; i < pos2; i++, n++){
		temp = matriz->datos[i];
		matriz->datos[i] = matriz->datos[pos2 + n];
		matriz->datos[pos2 + n] = temp;
	}
}

void matriz_insertar_fila(Matriz* matriz, int fil){
	matriz->nfilas++;
	matriz->datos = realloc(matriz->datos, sizeof(double) * matriz->ncols * matriz->nfilas);

	int i;
	for(i = matriz->nfilas; fil < i; i--)
		matriz_intercambiar_filas(matriz, i - 1, i);

	for(i = 1; i < matriz->ncols; i++)
		matriz_escribir(matriz, fil, i,0);
}
