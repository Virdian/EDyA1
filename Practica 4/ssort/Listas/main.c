#include <stdio.h>
#include <stdlib.h>
#include "ssortl.h"
#include "slist.h"

static void imprimir_entero(int dato) {
  printf("%d ", dato);
}

int main(void){

	SList list = slist_crear();

	list = slist_agregar_final(list, 2);
  list = slist_agregar_inicio(list, 7);
  list = slist_agregar_final(list, 9);
  list = slist_agregar_inicio(list, 8);
  list = slist_agregar_inicio(list, 5);
  

  slist_recorrer(list, imprimir_entero);
  puts("");

  ssortl(list);

  slist_recorrer(list, imprimir_entero);
  puts("");

  slist_destruir(list);

  return 0;
}
