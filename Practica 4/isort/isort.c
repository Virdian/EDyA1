static void swap(int *p, int *q){
  int t = *p;
  *p = *q;
  *q = t;
}

void isort(int datos[], int tam){
	int i, j;

	for(j = 1; j < tam; j++){
		for(i = j; i > 0; i--){
			if(datos[i] < datos[i-1]) swap(&datos[i], &datos[i-1]);
		}
	}
}