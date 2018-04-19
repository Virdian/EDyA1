#ifndef __STACK_H__
#define __STACK_H__
#define  MAX_PILA 13

#include <stddef.h>

typedef void (*FuncionVisitante) (int dato);
typedef int (*FuncionComparante) (int dato1, int dato2);

typedef struct _Pila {
  int datos[MAX_PILA];
  int top;
} *Pila;


/**
* Crea e inicializa una nueva pila vacıa.
**/
Pila pila_crear();

/**
* determina si la pila esta vacıa.
**/
int pila_es_vacia(Pila stack);

/**
* toma una pila y devuelve el elemento en la cima.
**/
int pila_top(Pila stack);

/**
* toma una pila y un elemento y agrega el elemento a la pila.
**/
void pila_push(Pila stack, int elem);

/**
* toma una pila y elimina el elemento de la cima.
**/
void pila_pop(Pila stack);

/**
*  toma una pila y la imprime en orden.
**/
void pila_imprimir(Pila stack);

/**
* libera la memoria requerida para la pila.
**/
void pila_destruir(Pila stack);


#endif /* __QUEUE_H__ */
