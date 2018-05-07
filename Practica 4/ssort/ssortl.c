#include "slist.h"

static void swap(int *p, int *q){
  int t = *p;
  *p = *q;
  *q = t;
}

SList ssortl(SList list){
	SList temp, aux;
	int t;

	/*for(temp = list; temp->sig != NULL; temp = temp->sig){
		for(aux = list->sig; aux != NULL; aux = aux->sig){
			if(temp->dato > aux->dato){
				swap(&temp->dato, &aux->dato);
			}
		}
	}
	*/
	temp = list;
	aux = list->sig;

	while(temp->sig != NULL){
		while(aux != NULL){
			if(temp->dato > aux->dato) swap(&temp->dato, &aux->dato);
			aux = aux->sig;
		}
		temp = temp->sig;
	}
	return list;
}
