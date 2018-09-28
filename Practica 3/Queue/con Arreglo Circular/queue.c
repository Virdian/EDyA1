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

int cola_es_vacia(Cola queue){
  assert(queue != NULL);
  if (queue->primero == -1) return 1;
  return 0;
}

int cola_primero(Cola queue){
  return queue->datos[queue->primero];
}

void cola_encolar(Cola queue, int elem){
  if (queue == NULL){
    queue = cola_crear();
  }
  if (cola_es_vacia(queue)){
    queue->primero++;
    queue->ultimo = 1;
    queue->datos[queue->primero] = elem;
  }
  else if(queue->primero != queue->ultimo){
    queue->datos[queue->ultimo] = elem;
    queue->ultimo = (queue->ultimo +1) % MAX_COLA;
  }
}

void cola_desencolar(Cola queue){
  assert(cola_es_vacia(queue) == 0);
  
  int pos;
  pos = queue->primero;
  queue->primero = (queue->primero +1) % MAX_COLA;
  if (queue->primero == queue->ultimo){
    queue->primero =-1;
  }
  queue->ultimo = ((queue->ultimo) +1) % MAX_COLA;
}

void cola_imprimir(Cola queue){
  if (queue->primero < queue->ultimo){
    for(int i = queue->primero; i < queue->ultimo; i++){
        printf("%d ", queue->datos[i]);
    }
    puts("");
 }
 if (queue->primero > queue-> ultimo){
   for(int i = queue->primero; i < MAX_COLA; i++){
     printf("%d ", queue->datos[i]);
   }
   puts("");
   for(int i = 0; i < queue->ultimo; i++){
     printf("%d ", queue->datos[i]);
   }
   puts("");
 }
}

void cola_destruir(Cola queue){
  free(queue);
}