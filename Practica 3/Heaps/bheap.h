#ifndef __BHEAP_H__
#define __BHEAP_H__
#define MAX_HEAP 11

typedef struct _BHeap {
  int datos[MAX_HEAP];
  int nelems;
} *BHeap;



//ESTAMOS USANDO MIN HEAPS: ¡EL MENOR ELEMENTO ESTA EN LA RAIZ!
/*
* crea un heap vacıo
*/
BHeap bheap_crear();

/*
* determina si el heap esta vacıo
*/
int bheap_es_vacio(BHeap heap);

/*
* toma un heap y devuelve el menor elemento
*/
int bheap_minimo(BHeap heap);

/*
* toma un heap y borra su menor elemento
*/
void bheap_eliminar_minimo(BHeap heap);

/*
* acomoda el heap de arriba para abajo
*/
void bheap_hundir(BHeap heap, int pos);

/*
* calcula el padre del elemento en cierta posicion
*/
int bheap_padre(int pos);

/*
* acomoda el heap de abajo para arriba
*/
void bheap_flotar(BHeap heap, int pos);
/*
* toma un heap y agrega un elemento
*/
void bheap_insertar(BHeap heap, int dato);

/*
* toma un heap e imprime sus elementos utilizando el orden ‘Primero por Extension’
*/
void bheap_imprimir(BHeap heap);

/*
* Destruye un heap
*/
void bheap_destruir(BHeap heap);

#endif /* __BHEAP_H__ */
