#include "pqueue.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Cola PCola

int cola_prioridad_es_vacia(PCola queue){
	cola_es_vacia(queue);
}

int cola_prioridad_obtener_minimo(PCola){
	assert(cola_prioridad_es_vacia(queue));
}

void cola_prioridad_eliminar_minimo(PCola);

void cola_prioridad_insertar(PCola, int);