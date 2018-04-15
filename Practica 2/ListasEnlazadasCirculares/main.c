#include <stdio.h>
#include <stdlib.h>
#include "cslist.h"

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

  CSList lista = cslist_crear();

  lista = cslist_agregar_final(lista, 8);
  lista = cslist_agregar_inicio(lista, 1);
  lista = cslist_agregar_inicio(lista, 3);
  lista = cslist_agregar_inicio(lista, 5);
  lista = cslist_agregar_final(lista, 7);
  lista = cslist_agregar_inicio(lista, 6);
  lista = cslist_agregar_final(lista, 0);

  cslist_recorrer(lista, imprimir_entero);
  puts("");

  int n = cslist_longitud(lista);
  printf("%d\n", n);

  cslist_destruir(lista);

  return 0;
}
