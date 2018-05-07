#include <stdio.h>
#include <stdlib.h>
#include "bheap.h"

int main(){

BHeap heapa = bheap_crear();

printf("esta heapa vacio: %d\n", bheap_es_vacio(heapa));

bheap_insertar(heapa, 4);
bheap_insertar(heapa, 7);
bheap_insertar(heapa, 6);
bheap_insertar(heapa, 11);
bheap_insertar(heapa, 9);
bheap_insertar(heapa, 2);

bheap_imprimir(heapa);

printf("esta heapa vacio: %d\n", bheap_es_vacio(heapa));
printf("Minimo elemento del heapa: %d\n", bheap_minimo(heapa));

bheap_eliminar_minimo(heapa);
bheap_eliminar_minimo(heapa);
bheap_eliminar_minimo(heapa);

bheap_imprimir(heapa);

bheap_destruir(heapa);

return 0;
}
