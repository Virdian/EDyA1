static void swap(int *p, int *q){
  int t = *p;
  *p = *q;
  *q = t;
}

void msort(int datos[], int tam, int primero, int ultimo){

}

void merge(int *arr, int size, int first, int middle, int last){
  
  int temp[size];
  for(int i = first; i<=last; i++){
   temp[i] = arr[i];
  }

  int i=first, j=middle+1, k=0;
  while(i<=middle && j<=last){
   if(temp[i] <= temp[j]){
    arr[k] = temp[i];
    i++;
   }
   else{
    arr[k]=temp[i];
    j++;
   }
   k++;
  }

  while(i<=middle){
   arr[k]=temp[i];
   k++;
   i++;
  }
}

void mergesort(int *arr, int size, int first, int last){
  
  if(first<last){
   int middle = ( first + last )/2;
   mergesort(arr,size,first,middle);
   mergesort(arr,size,middle+1,last);
   merge(arr,size,first,middle,last);
  }
}