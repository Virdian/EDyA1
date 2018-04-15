#include "cslist.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

CSList cslist_crear() {
  return NULL;
}

void cslist_destruir(CSList lista) {
  if(cslist_vacia(lista)) return;
  CSNodo *nodoAEliminar;
  CSList temp = lista->sig;
  while (temp != lista) {
    nodoAEliminar = temp;
    temp = temp->sig;
    free(nodoAEliminar);
  }
  free(lista);
}

int cslist_vacia(CSList lista) {
  return lista == NULL;
}

CSList cslist_agregar_final(CSList lista, int dato) {
  CSNodo *nuevoNodo = malloc(sizeof(CSNodo));
  nuevoNodo->dato = dato;

  if (lista == NULL){
    nuevoNodo->sig = nuevoNodo;
    return nuevoNodo;
  }

  nuevoNodo->sig = lista->sig;
  lista->sig = nuevoNodo;

  return nuevoNodo;
}

CSList cslist_agregar_inicio(CSList lista, int dato) {
  CSNodo *nuevoNodo = malloc(sizeof(CSNodo));
  nuevoNodo->dato = dato;

  if (lista == NULL){
    nuevoNodo->sig = nuevoNodo;
    return nuevoNodo;
  }

  nuevoNodo->sig = lista->sig;
  lista->sig = nuevoNodo;
  return lista;
}

void cslist_recorrer(CSList lista, FuncionVisitante visit){
  if (lista == NULL) return;
  for (CSList temp = lista->sig; temp != lista ; temp = temp->sig){
    visit(temp->dato);
    }
    visit(lista->dato);
}

int cslist_longitud(CSList lista){
  if (lista == NULL){
    return 0;
  }
  int i;
  CSList temp = lista->sig;
  for(i = 1; temp != lista; temp = temp->sig, i++);
  return i;
}
// ----------------------------------------------------------------------------
/*
SList slist_concatenar(SList lista, SList listb){
  if (lista == NULL){
    return listb;
  }
  SList temp;
  for(temp = lista; temp->sig != NULL; temp = temp->sig);
  temp->sig = listb;
  return lista;
}

SList slist_insertar(SList lista, int dato, int pos){
  assert(pos >= 0);
  if (lista == NULL){
    lista = slist_agregar_inicio(lista, dato);
    return lista;
  }
  if(slist_longitud(lista) < pos){
    lista = slist_agregar_final(lista, dato);
    return lista;
  }
  int i = 1;
  SList temp = lista;
  for(; lista->sig != NULL && i != pos - 1; lista = lista->sig, i++);
  SNodo* nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig =  lista->sig;
  lista->sig = nuevoNodo;
  return temp;
}

void slist_eliminar(SList lista, int pos){
  if(lista == NULL || slist_longitud(lista) < pos){
    return;
  }
  int i = 1;
  for(; lista->sig != NULL && i != pos-1; lista = lista->sig, i++);

  SList temp = lista->sig;
  lista->sig = lista->sig->sig;
  free(temp);
}

int slist_contiene(SList lista, int dato){
  if(lista == NULL){
    return 0;
  }
  for(; lista->sig != NULL && lista->dato != dato; lista = lista->sig);
  if(lista->dato == dato){
      return 1;
    }
  return 0;
}
*/
/* for(; lista != NULL; lista = lista->sig){
    if(lista->dato == dato) return 1;
  }
  return 0;
*/
/*
int slist_indice(SList lista, int dato){
  if(lista == NULL){
    return -1;
  }
  int i = 1;
  for(; lista->sig != NULL && lista->dato != dato; lista = lista->sig, i++);
  if(lista->dato == dato){
      return i;
    }
  return -1;
}

SList slist_intersecar(SList lista, SList listb){
  if (slist_vacia(lista) || slist_vacia(listb)){
    return NULL;
  }
  SList listc = slist_crear();
  for(; lista != NULL; lista = lista->sig){
    SList temp = listb; // este SList temp es importante para reiniciar el puntero al comienzo de la listb
    for(;temp != NULL; temp = temp->sig){
      if(lista->dato == temp->dato){
        listc = slist_agregar_inicio(listc, lista->dato);
      }
    }
  }
  return listc;
}

SList slist_intersecar_custom(SList lista, SList listb,
                                                  FuncionComparante comparador){
  if (slist_vacia(lista) || slist_vacia(listb)){
    return NULL;
  }
  SList listc = slist_crear();
  for(; lista != NULL; lista = lista->sig){
    SList temp = listb; // este SList temp es importante para reiniciar el puntero al comienzo de la listb
    for(;temp != NULL; temp = temp->sig){
      if(comparador(lista->dato, temp->dato)){
        listc = slist_agregar_inicio(listc, lista->dato);
      }
    }
  }
  return listc;
}

void slist_ordenar(SList lista, FuncionComparante ordenador){
  if(slist_vacia(lista)) return;
  for(;lista != NULL; lista = lista->sig){
    for(SList temp = lista->sig; temp != NULL; temp = temp->sig){
      if(ordenador(lista->dato, temp->dato) == 1){
        int cambio = temp->dato;
        temp->dato = lista->dato;
        lista->dato = cambio;
      }
    }
  }
}

SList slist_reverso(SList lista){
  if(slist_vacia(lista)) return lista;
  SList temp1 = lista->sig;
  lista->sig = NULL;
  for(;temp1 != NULL;){
    SList temp2 = temp1;
    temp1 = temp1->sig;
    temp2->sig = lista;
    lista = temp2;
  }
  return lista;
}

SList slist_intercalar(SList lista, SList listb){
  if(lista == NULL) return listb;
  if(listb == NULL) return lista;

  int longa = slist_longitud(lista);
  int longb = slist_longitud(listb);

  if(longa < longb){
    SList temp = lista;
    lista = listb;
    listb = temp;
  }

  SList listc = slist_crear();
  for(; lista != NULL; lista = lista->sig){
    listc = slist_agregar_final(listc, lista->dato);
    if(listb != NULL){
    listc = slist_agregar_final(listc, listb->dato);
    listb = listb->sig;
    }
  }
  return listc;
}
*/
