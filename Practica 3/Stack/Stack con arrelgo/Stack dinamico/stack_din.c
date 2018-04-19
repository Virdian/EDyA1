#include "stack_din.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

Pila pila_crear(){
  Pila nueva;
  nueva = malloc(sizeof(struct _Pila));
  nueva->datos = malloc(sizeof(int)*7);
  nueva->longi = 7;
  nueva->top = -1;
  return nueva;
}

void pila_destruir(Pila stack){
  free(stack->datos);
  free(stack);
}

int pila_es_vacia(Pila stack){
  assert(stack != NULL);
  return stack->top == -1;
}

void pila_imprimir(Pila stack){
  assert(pila_es_vacia(stack) == 0);
  for (int i = 0; i <= stack->top; i++) {
    printf("%d\t",stack->datos[i]);
  }
  puts("");
}

int pila_top(Pila stack){
  assert(pila_es_vacia(stack) == 0);
  return stack->datos[stack->top];
}

void pila_push(Pila stack, int elem){
  if (stack->top + 1 == stack->longi){ //  el valor maximo de stack->top es a lo sumo stack->longi - 1
    stack->longi++;
    stack->datos = realloc(stack->datos, sizeof(int)*stack->longi);
  }
  stack->top++;
  stack->datos[stack->top] = elem;
}

void pila_pop(Pila stack){
  assert(pila_es_vacia(stack) == 0);
  stack->top--;
}
