#ifndef __QUEUE_H__
#define __QUEUE_H__


#include <stddef.h>

typedef void (*FuncionVisitante) (int dato);
typedef int (*FuncionComparante) (int dato1, int dato2);

typedef struct _Cola {
int datos[MAX_COLA];
int primero, ultimo;
} *Cola;


/**
* Crea e inicializa una nueva cola vacıa.
**/
Cola cola_crear();

/**
* determina si la cola esta vacıa.
**/
int cola_es_vacia(Cola queue);

/**
* toma una cola y devuelve el elemento en la primera posicion
**/
int cola_primero(Cola queue);

/**
* toma una cola y un elemento y agrega el elemento al fin de la cola.
**/
void cola_encolar(Cola queue, int elem);

/**
* toma una cola y elimina su primer elemento.
**/
void cola_desencolar(Cola queue);

/**
* toma una cola y la imprime en orden.
**/
void cola_imprimir(Cola queue);

/**
* libera la memoria requerida para la cola.
**/
void cola_destruir(Cola queue);


#endif /* __QUEUE_H__ */
