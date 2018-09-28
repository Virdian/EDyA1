#include <stdio.h>
#include "msort.h"

#define NELEMS(a) (sizeof((a))/sizeof(int))

int main(void) {
  int arr[] = { 2, 1, 4, 3, 7, 8, 6 };
  int i;

	for (i  = 0; i < NELEMS(arr); ++i)
    printf("%d ", arr[i]);
  puts("");
	
  isort(arr, NELEMS(arr));

  for (i  = 0; i < NELEMS(arr); ++i)
    printf("%d ", arr[i]);
  puts("");

  return 0;
}
