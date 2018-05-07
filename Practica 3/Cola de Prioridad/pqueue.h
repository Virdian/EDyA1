#ifndef __PQUEUE_H__
#define __PQUEUE_H__

/*
* determina si la cola esta vacıa
*/
int cola_prioridad_es_vacia(PCola);

/*
* obtiene el elemento prioritario
*/
int cola_prioridad_obtener_minimo (PCola);

/*
* quita el elemento prioritario
*/
void cola_prioridad_eliminar_minimo(PCola);

/*
* inserta un elemento con determinada prioridad
*/
void cola_prioridad_insertar(PCola, int);

#endif /* __PQUEUE_H__ */