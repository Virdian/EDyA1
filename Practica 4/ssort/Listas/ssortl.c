#include "slist.h"

static void swap(int *p, int *q){
  int t = *p;
  *p = *q;
  *q = t;
}

void ssortl(SList list){
	for(SList temp = list; temp->sig != NULL; temp = temp->sig){
		SList min = temp;
		for(SList aux = temp->sig; aux != NULL; aux = aux->sig){
			if(aux->dato < min->dato) min = aux;
		}
		swap(&temp->dato, &min->dato);
	}
}