#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

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
  Cola queue1, queue2;
  queue1 = cola_crear();
  queue2 = cola_crear();

  printf("esta vacia queue1? %d \n", cola_es_vacia(queue1));





  cola_destruir(queue1);
  cola_destruir(queue2);

  return 0;
}
