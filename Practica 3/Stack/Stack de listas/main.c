#include <stdio.h>
#include <stdlib.h>
#include "stack_list.h"

static void imprimir_entero(int dato) {
  printf("%d ", dato);
}

int comparador(int dato1, int dato2){
  if(dato1 == dato2) return 1;
  return 0;
}

int ordenador(int dato1, int dato2){
  if(dato1 < dato2) return -1;
  if(dato1 == dato2)return 0;
  else return 1;
}

int main(int argc, char *argv[]) {
  Pila stack1, stack2;

  stack1 = pila_crear();
  stack2 = pila_crear();

  pila_push(stack1, 42);
  pila_push(stack1, 15);
  pila_push(stack1, 25);
  pila_push(stack1, 1);
  pila_push(stack1, 71);
  pila_push(stack1, 99);
  pila_push(stack1, 104);
  pila_push(stack1, 254);

  pila_pop(stack1);
  pila_pop(stack1);
  pila_pop(stack1);

  printf("stack1 esta vacio: %d \n", pila_es_vacia(stack1));
  printf("stack2 esta vacio: %d \n", pila_es_vacia(stack2));

  printf("top del stack: %d \n", pila_top(stack1));

  pila_imprimir(stack1);

  pila_destruir(stack1);
  pila_destruir(stack2);

  return 0;
}
