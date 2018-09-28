#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <stdlib.h>

typedef struct Matriz_ Matriz;

/*
** Crea una nueva matriz
*/
Matriz* matriz_crear(int nfilas, int ncols);

/*
** Destruye una matriz
*/
void matriz_destruir(Matriz* matriz);

/*
** Obtiene el dato guardado en la posición dada de la matriz
*/
double matriz_leer(Matriz* matriz, int nfilas, int ncols);

/*
** Modifica el dato guardado en la posición dada de la matriz
*/
void matriz_escribir(Matriz* matriz, int nfilas, int ncols, double dato);

/*
** Obtiene número de filas de la matriz
*/
int matriz_nfilas(Matriz* matriz);

/*
** Obtiene número de columnas de la matriz
*/
int matriz_ncolumnas(Matriz* matriz);

/*
** Intercambia dos filas dadas
*/
void matriz_intercambiar_filas(Matriz* matriz, int fil1, int fil2);

/*
** Inserta una nueva fila en la posición dada y la llena de 0's
*/
void matriz_insertar_fila(Matriz* matriz, int pos);

#endif /* __MATRIX_H__ */
