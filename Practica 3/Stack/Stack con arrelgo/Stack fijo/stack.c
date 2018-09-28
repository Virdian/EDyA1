#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

Pila pila_crear(){
  Pila nueva;
  nueva = malloc(sizeof(struct _Pila));
  nueva->top = -1;
  return nueva;
}

int pila_es_vacia(Pila stack){
  assert(stack != NULL);
  return stack->top == -1;
}

int pila_top(Pila stack){
  assert(pila_es_vacia(stack) == 0);
  return stack->datos[stack->top];
}

void pila_push(Pila stack, int elem){
  if(stack->top == (MAX_PILA -1)) return;
  //assert(stack->top < (MAX_PILA -1));
  stack->top++;
  stack->datos[stack->top] = elem;
}

void pila_pop(Pila stack){
  if(pila_es_vacia(stack) == 1) return;
  //assert(pila_es_vacia(stack) == 0);
  stack->top--;
}

void pila_imprimir(Pila stack){
  assert(pila_es_vacia(stack) == 0);
  for (int i = 0; i <= stack->top; i++) {
    printf("%d\t",stack->datos[i]);
  }
  puts("");
}

void pila_destruir(Pila stack){
  free(stack);
}