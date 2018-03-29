#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//Ej 3
typedef struct {
	int* direccion;
	int capacidad;
} ArregloEnteros;

ArregloEnteros* arreglo_enteros_crear(int capacidad){
	ArregloEnteros* nuevo = malloc(sizeof(ArregloEnteros));
	nuevo->direccion = malloc(sizeof(int)*capacidad);
	nuevo->capacidad = capacidad;
	return nuevo;
}

void arreglo_enteros_destruir(ArregloEnteros* arreglo){
	free(arreglo->direccion);
	free(arreglo);
}

int arreglo_enteros_leer(ArregloEnteros* arreglo, int pos){
	assert(pos < arreglo->capacidad);
	return arreglo->direccion[pos];		
}

void arreglo_enteros_escribir(ArregloEnteros* arreglo, int pos, int dato){
	assert(pos < arreglo->capacidad);	
	arreglo->direccion[pos] = dato;
}

int arreglo_enteros_capacidad(ArregloEnteros* arreglo){
	return arreglo->capacidad;		
}

void arreglo_enteros_imprimir(ArregloEnteros* arreglo){
	int i = 0;
	for(; i < arreglo->capacidad ; i++)
		printf("%d\t", arreglo->direccion[i]);
	puts("");
}

//Ej 4
void arreglo_enteros_ajustar(ArregloEnteros* arreglo, int capacidad){
		
	arreglo->direccion = realloc(arreglo->direccion, sizeof(int)*capacidad);
	arreglo->capacidad = capacidad;
}	

void arreglo_enteros_insertar(ArregloEnteros* arreglo, int pos, int dato){
	//Si la posicion es mayor a la cantidad de espacios del arreglo, se insertara al final

	int cap = arreglo_enteros_capacidad(arreglo);

	arreglo_enteros_ajustar(arreglo, cap + 1);

	if(pos >= cap) arreglo->direccion[cap] = dato;
	else
		for(; cap > pos; cap--)
			arreglo->direccion[cap] = arreglo->direccion[cap - 1];

	arreglo->direccion[pos] = dato;
}

void arreglo_enteros_eliminar(ArregloEnteros* arreglo, int pos){
	assert(pos < arreglo->capacidad);

	int cap = arreglo_enteros_capacidad(arreglo);

	int i;
	for(i = pos; i < cap; i++)
		arreglo->direccion[i] = arreglo->direccion[i+1];

	arreglo_enteros_ajustar(arreglo, cap - 1);
}

int main(){
	ArregloEnteros* arr = arreglo_enteros_crear(10);
	int i = 0;
	
	for(; i < 10; i++)
		arreglo_enteros_escribir(arr, i, i+1);

	arreglo_enteros_imprimir(arr);
	
	arreglo_enteros_ajustar(arr, 9);
	
	arreglo_enteros_imprimir(arr);

	arreglo_enteros_insertar(arr, 6, 10);

	arreglo_enteros_imprimir(arr);

	arreglo_enteros_eliminar(arr, 5);

	arreglo_enteros_imprimir(arr);
	
	arreglo_enteros_destruir(arr);
	
	return 0;
}
