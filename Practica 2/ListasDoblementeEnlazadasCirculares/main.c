#include <stdio.h>
#include <stdlib.h>
#include "dlist.h"

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

  DList lista = dlist_crear();

  lista = dlist_agregar_final(lista, 8);
  lista = dlist_agregar_inicio(lista, 1);
  lista = dlist_agregar_inicio(lista, 3);
  lista = dlist_agregar_inicio(lista, 5);
  lista = dlist_agregar_final(lista, 7);
  lista = dlist_agregar_inicio(lista, 6);
  lista = dlist_agregar_final(lista, 0);

  dlist_recorrer(lista, DLIST_RECORRIDO_HACIA_ATRAS, imprimir_entero);
  puts("");

  int n = dlist_longitud(lista);
  printf("%d\n", n);

  dlist_destruir(lista);

  return 0;
}
