#include <stdio.h>
#include <stdlib.h>
#include "ssortl.h"
#include "slist.h"

static void imprimir_entero(int dato) {
  printf("%d ", dato);
}

int main(void){

	SList list = slist_crear();

	list = slist_agregar_final(list, 4);
  list = slist_agregar_inicio(list, 3);
  list = slist_agregar_final(list, 1);
  list = slist_agregar_inicio(list, 0);
  list = slist_agregar_inicio(list, 2);
  

  slist_recorrer(list, imprimir_entero);
  puts("");

  ssortl(list);

  slist_recorrer(list, imprimir_entero);
  puts("");

  slist_destruir(list);

  return 0;
}