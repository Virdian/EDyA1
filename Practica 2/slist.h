#ifndef __SLIST_H__
#define __SLIST_H__

#include <stddef.h>

typedef void (*FuncionVisitante) (int dato);
typedef int (*FuncionComparante) (int dato1, int dato2);

typedef struct _SNodo {
  int dato;
  struct _SNodo *sig;
} SNodo;

typedef SNodo *SList;

/**
 * Devuelve una lista vacía.
 */
SList slist_crear();

/**
 * Destruccion de la lista.
 */
void slist_destruir(SList lista);

/**
 * Determina si la lista es vacía.
 */
int slist_vacia(SList lista);

/**
 * Agrega un elemento al final de la lista.
 */
SList slist_agregar_final(SList lista, int dato);

/**
 * Agrega un elemento al inicio de la lista.
 */
SList slist_agregar_inicio(SList lista, int dato);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void slist_recorrer(SList lista, FuncionVisitante visit);

/**
 * Retorna la cantidad de nodos en la lista
 */
 int slist_longitud(SList lista);

/**
 * Devuelve la concatenacion de dos listas (modificandolas).
 */
 SList slist_concatenar(SList lista, SList listb);

/**
 * Inserta un dato en una lista en una posicion arbitraria.
   Si la longitud de la lista es menor a la posicion dada. Agrega al final el dato
   Si la lista es vacia, agrega el dato al inicio.
 */
 SList slist_insertar(SList lista, int dato, int pos);

 /**
 * Borra de una lista un dato apuntado en una posicion arbitraria.
   Si la lista tiene menor longitud a la posicion o esta vacia. la funcion no hace nada.
 */
 void slist_eliminar(SList lista, int pos);

/**
* determina si un elemento esta en una lista dada.
  Si el dato se encuentra, la funcion retorna 1.
  caso contrario, 0.
*/
int slist_contiene(SList lista, int dato);

/**
* devuelve la posicion de la primera ocurrencia del elemento dato si el mismo esta
  en la lista dada, -1 en caso que no este.
*/
int slist_indice(SList lista, int dato);

/**
*devuelve una nueva lista con los elementos comunes (independientemente de la posicion)
 de dos listas dadas por parametro. Las listas originales no se modifican.
*/
SList slist_intersecar(SList lista, SList listb);

/**
 *trabaja como la anterior pero recibe un par ́ametro extra quees un puntero a
  una funcion de comparacion que permite definir la nocion de igualdad a ser
  usada al comparar elementos por igualdad.
*/
SList slist_intersecar_custom(SList lista, SList listb,
                                                  FuncionComparante comparador);

/**
*ordena una lista de acuerdo al criterio dado por una funcion de comparacion
 (que usa los mismos valores de retorno que strcmp()) pasada por parametro.
*/
void slist_ordenar(SList lista, FuncionComparante ordenador);

/**
 *obtiene el reverso de una lista
*/
void slist_reverso(lista); 

#endif /* __SLIST_H__ */
