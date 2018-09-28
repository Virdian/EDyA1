#include "btree.h"
#include <stdlib.h>

BTree btree_crear() {
  return NULL;
}

void btree_destruir(BTree nodo) {
  if (nodo != NULL) {
    btree_destruir(nodo->left);
    btree_destruir(nodo->right);
    free(nodo);
  }
}

BTree btree_unir(int dato, BTree left, BTree right) {
  BTree nuevoNodo = malloc(sizeof(BTNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->left = left;
  nuevoNodo->right = right;
  return nuevoNodo;
}

void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitante visit){

  if(orden == BTREE_RECORRIDO_IN){
    if(arbol->left != NULL) btree_recorrer(arbol->left, orden, visit);
    visit(arbol->dato);
    if(arbol->right != NULL) btree_recorrer(arbol->right, orden, visit);
  }

  if(orden == BTREE_RECORRIDO_PRE){
    visit(arbol->dato);
    if(arbol->left != NULL) btree_recorrer(arbol->left, orden, visit);
    if(arbol->right != NULL) btree_recorrer(arbol->right, orden, visit);
  }

  if(orden == BTREE_RECORRIDO_POST){
    if(arbol->left != NULL) btree_recorrer(arbol->left, orden, visit);
    if(arbol->right != NULL) btree_recorrer(arbol->right, orden, visit);
    visit(arbol->dato);
  }
}

int btree_suma(BTree tree){
  int suma = 0;

  if(tree != NULL) suma += tree->dato;
  if(tree->left != NULL) btree_suma(tree->left);
  if(tree->right != NULL) btree_suma(tree->right);

  return suma;
}

int btree_cantidad(BTree tree){
  int cant = 0;

  if(tree != NULL) cant++;
  if(tree->left != NULL) btree_cantidad(tree->left);
  if(tree->right != NULL) btree_cantidad(tree->right);

  return cant;
}
