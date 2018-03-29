#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

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

  SList lista = slist_crear();
  SList listb = slist_crear();
  SList vacia = slist_crear();
  SList listc = slist_crear();

  lista = slist_agregar_inicio(lista, 3);
  lista = slist_agregar_inicio(lista, 2);
  lista = slist_agregar_inicio(lista, 1);
  lista = slist_agregar_final(lista, 4);
  lista = slist_agregar_final(lista, 8);

  listb = slist_agregar_inicio(listb, 5);
  listb = slist_agregar_inicio(listb, 6);
  listb = slist_agregar_inicio(listb, 4);
  listb = slist_agregar_final(listb, 8);
  listb = slist_agregar_final(listb, 8);

  slist_recorrer(lista, imprimir_entero);
  puts("");
  slist_recorrer(listb, imprimir_entero);
  puts("");

  //listb = slist_insertar(listb, 20, 3);
  int longi = slist_longitud(lista);
  printf("Longitud de la lista: %d\n",longi);


  //lista = slist_concatenar(lista, listb);
  //slist_eliminar(lista, 3);

  //slist_recorrer(lista, imprimir_entero);
  //puts("");
  //printf("esta el 20 en la lista? %d\n", slist_contiene(lista, 20));
  //printf("en que posi esta 40 en la lista vacia? %d\n", slist_indice(vacia, 40));

  listc = slist_intersecar(lista, listb);
  slist_recorrer(listc, imprimir_entero);
  puts("");

  listc = slist_intersecar_custom(lista, listb, comparador);
  slist_recorrer(listc, imprimir_entero);
  puts("");

  SList desordenada = slist_crear();
  desordenada = slist_agregar_inicio(desordenada, 88);
  desordenada = slist_agregar_inicio(desordenada, 1);
  desordenada = slist_agregar_inicio(desordenada, 5);
  desordenada = slist_agregar_inicio(desordenada, 20);
  desordenada = slist_agregar_inicio(desordenada, 4);
  desordenada = slist_agregar_inicio(desordenada, 42);

  printf("Lista desordenada\n");
  slist_recorrer(desordenada, imprimir_entero);
  puts("");

  slist_ordenar(desordenada, ordenador);
  printf("Lista Ordenada\n");
  slist_recorrer(desordenada, imprimir_entero);
  puts("");


  slist_destruir(lista);
  slist_destruir(listb);
  slist_destruir(listc);
  slist_destruir(vacia);
  slist_destruir(desordenada);

  return 0;
}
