#include <stdio.h>
#include <stdlib.h>
#include "bheap.h"

int main(){

BHeap heapa = bheap_crear();

bheap_insertar(heapa, 4);
bheap_insertar(heapa, 7);
bheap_insertar(heapa, 6);
bheap_insertar(heapa, 11);
bheap_insertar(heapa, 9);
bheap_insertar(heapa, 2);

bheap_imprimir(heapa);

return 0;
}
