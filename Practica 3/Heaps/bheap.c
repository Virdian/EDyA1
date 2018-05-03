#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
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
  assert(bheap_es_vacio(heap) == 0);
  return heap->datos[0];
}

int bheap_padre(int pos){
  if(pos%2 == 0){
    return (pos-2)/2;
  }
  return (pos -1)/2;
}

void bheap_flotar(BHeap heap, int pos){
  int padre = bheap_padre(pos);
  if(heap->datos[pos] < heap->datos[padre]){
    int s = heap->datos[pos];
    heap->datos[pos] = heap->datos[padre];
    heap->datos[padre] = s;
    bheap_flotar(heap, padre);
  }
}

void bheap_insertar(BHeap heap, int dato){
  assert( heap->nelems < MAX_HEAP);
  heap->datos[heap->nelems] = dato;
  bheap_flotar(heap, heap->nelems);
  heap->nelems++;
}



void bheap_hundir(BHeap heap, int pos){
  if( (pos*2 + 1) < heap->nelems && (pos*2 + 2) < heap->nelems){
    if (heap->datos[pos*2 + 1] > heap->datos[pos*2 + 2]){
      int s = heap->datos[pos*2 + 2];
      heap->datos[pos*2 + 2] = heap->datos[pos];
      heap->datos[pos] = s;
      bheap_hundir(heap, pos*2 + 2);
    }
    else{
      int s = heap->datos[pos*2 + 1];
      heap->datos[pos*2 + 1] = heap->datos[pos];
      heap->datos[pos] = s;
      bheap_hundir(heap, pos*2 + 1);
    }
  }
}


void bheap_eliminar_minimo(BHeap heap){
  heap->datos[0] = heap->datos[(heap->nelems) - 1];
  heap->nelems--;
  bheap_hundir(heap, 0);
}



void bheap_imprimir(BHeap heap){
  for(int i = 0; i < heap->nelems; i++){
    printf("%d ", heap->datos[i]);
  }
  puts("");
}

void bheap_destruir(BHeap heap){
  free(heap);
}
