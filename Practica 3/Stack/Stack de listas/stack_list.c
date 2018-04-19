#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

Pila pila_crear(){
  Pila nueva;
  nueva = malloc(sizeof(struct _Pila));
  nueva->datos = NULL;
  nueva->top = -1;
  return nueva;
}

void slist_destruir(SList lista){
  SNodo *nodoAEliminar;
  while (lista != NULL) {
    nodoAEliminar = lista;
    lista = lista->sig;
    free(nodoAEliminar);
  }
}

void pila_destruir(Pila stack){
  slist_destruir(stack->datos);
  free(stack);
}

int pila_es_vacia(Pila stack){
  assert(stack != NULL);
  return stack->top == -1;
}

void pila_imprimir(Pila stack){
  assert(pila_es_vacia(stack) == 0);
  SList temp = stack->datos;
  for(; temp != NULL; temp = temp->sig) {
    printf("%d ",temp->dato);
  }
  puts("");
}

SList slist_agregar_inicio(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = lista;
  return nuevoNodo;
}

void pila_push(Pila stack, int elem){ // es como agregar al inicio
  stack->datos = slist_agregar_inicio(stack->datos, elem);
  stack->top++;
}

int pila_top(Pila stack){
  assert(pila_es_vacia(stack) == 0);
  return stack->datos->dato;
}

SList list_eliminar(SList lista){
  SList temp = lista;
  lista = lista->sig;
  free(temp);
  return lista;
}

void pila_pop(Pila stack){
  assert(pila_es_vacia(stack) == 0);
  stack->datos = list_eliminar(stack->datos);
  stack->top--;
}

/*
SList list_reverso(SList list){
  Pila temp = pila_crear();
  for(;list != NULL; list = list->sig){
    pila_push(temp, list->dato);
  }
  SList lista = temp->datos;
  pila_destruir(temp);
  return lista;
}
*/
