//warmup

#include <stdio.h>
#include <stdlib.h>
#define N 100

void main(){
  int *p_arr;
  p_arr = (int *) malloc(N*sizeof(int));
  int i;
  for (i = 0; i < N; i++){
    p_arr[i] = 2*i;
  }
  for (i = 0; i < N; i++){
    printf("%d\n", p_arr[i]);
  }
}
