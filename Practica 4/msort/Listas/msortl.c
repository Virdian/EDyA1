#include "slist.h"

//esta funcion parte la lista, dejando la priimer parte en lista y a la segunda la retorna
SList slist_partir(SList lista){
	//si la lista tiene 0 o 1 elemento, ya esta ordenada y retorno
	if(slist_longitud(lista) < 2)
		return lista;

	//sino, busco donde es la mitad de la lista
	int longitud = slist_longitud(lista),
		mitad = (longitud-1) / 2;
	SList res2,
		temp = lista; 
	
	//avanzo hasta la mitad de la lista con temp
	int i = 0;
	for(; i < mitad ; temp = temp->sig, i++);
	//le digo a res2 que apunte a la mitad de la lista
	res2 = temp->sig;
	
	//corto la lista en la mitad, asi en lista queda solo la mitad
	temp->sig = NULL;
	return res2;
}

//toma dos listas ordenadas, y retorna la union ordenada
SList slist_unir(SList lista1, SList lista2){
	//me creo un temporal para cada lista
	//y una lista donde me armo la lista ordenada
	SList temp1 = lista1,
		temp2 = lista2,
		resultado = NULL;

	//avanzo siempre que las dos listas seas distintas de NULL
	while(temp1 != NULL && temp2 != NULL){
		//pongo el minimop dato primero
		if(temp1->dato < temp2->dato){
			resultado = slist_agregar_final(resultado, temp1->dato);
			temp1 = temp1->sig;
		}
		else{
			resultado = slist_agregar_final(resultado, temp2->dato);
			temp2 = temp2->sig;
		}
	}

	//termino de agregar los elementos que faltaron en el bucle
	for(; temp1 != NULL ; temp1 = temp1->sig)
		resultado = slist_agregar_final(resultado, temp1->dato);

	for(; temp2 != NULL ; temp2 = temp2->sig)
		resultado = slist_agregar_final(resultado, temp2->dato);

	//retorno la lista ordenada
	return resultado;
}

SList msortl(SList lista){
	//si la lista tiene menos de dos elementos entonces esta ordenada y la retorno
	if(slist_longitud(lista) < 2)
		return lista;

	//sino la parto a la mitad, queda la primer parte en lista y la segunda en res	
	SList res2 = slist_crear();
	res2 = slist_partir(lista);

	//hago la recursion a ambos lados
	lista = msortl(lista);
	res2 = msortl(res2);
	
	//uno las dos partes ordenadas en lista
	lista = slist_unir(lista, res2);
	return lista;
}