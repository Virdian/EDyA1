#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

Cola cola_crear(){
  Cola nueva;
  nueva = malloc(sizeof(struct _Cola));
  nueva->primero = -1;
  nueva->ultimo = -1;
  return nueva;
}

void cola_destruir(Cola queue){
  free(queue);
}

int cola_es_vacia(Cola queue){
  if (queue->primero == -1) return 1;
  return 0;
}

int cola_primero(Cola queue){
  return queue->datos[queue->primero];
}
