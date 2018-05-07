static void swap(int *p, int *q) {
  int t = *p;
  *p = *q;
  *q = t;
}

//implementación de bsort utilizando for

void bsort(int datos[], int tam) {
  int ordenado = 0, i, j;

  for(j = 0; j < tam; j++){
    for (i = 0; i < tam - 1; ++i){
      if (datos[i] > datos[i + 1]) swap(&datos[i], &datos[i + 1]);
    }
  }
}

/*La minima cantidad de iteraciones necesarias para garantizar el
* funcionamiento del algoritmo es el tamaño del mismo.
*/