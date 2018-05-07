static void swap(int *p, int *q){
  int t = *p;
  *p = *q;
  *q = t;
}

void ssort(int datos[], int tam){
	int i, j;

	for(j = 0; j < tam - 1; j++){
		for(i = 1; i < tam; i++){
			if(datos[j] > datos[i+j]) swap(&datos[j], &datos[i+j]);
		}
	}
}