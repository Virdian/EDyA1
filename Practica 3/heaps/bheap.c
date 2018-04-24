#include <stdio.h>
#include <assert.h>
#include "bheap.h"

BHeap bheap_crear(){
  BHeap new = malloc(sizeof(BHeap));
  int nelems = 0;
  return new;
}

int bheap_es_vacio(BHeap heap){
  if(heap->nelems == 0) return 1;
  return 0;
}

int bheap_minimo(BHeap heap){
  assert(bheap_es_vacio(heap) != 0);
  return heap->datos[0];
}

void bheap_hundir(BHeap heap){
  int s;
  int i = 0;
  if(heap->datos[i] > heap->datos[2*i+1]){
    s = heap->datos[i];
    heap->datos[i] = heap->datos[2*i+1];
    heap->datos[2*i+1] = s;
  }
  if(heap->datos[i] > heap->datos[2*i+2]){
    s = heap->datos[i];
    heap->datos[i] = heap->datos[2*i+2];
    heap->datos[2*i+2] = s;
  }
  i++;
  bheap_hundir(heap);
}

void bheap_eliminar_minimo(BHeap heap){
  heap->datos[0] = heap->datos[MAX_HEAP];

  bheap_hundir(heap);

}

void bheap_insertar(BHeap heap, int dato){
  heap->nelems++;

  int s;
  s = heap->datos[0];
  heap->datos[0] = dato;
  heap->datos[heap->nelems] = s;
  bheap_hundir(heap);
}


void bheap_imprimir(BHeap heap){

  printf("%d\n", heap->datos[0]);

  int i,j;
  for(j = 0; j < MAX_HEAP; j + (2*j+2)){
    for(i = j; i < (2*i+2); i++){
      printf("%d\t", heap->datos[i]);
    }
  }
}
