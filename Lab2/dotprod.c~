//dotprod.c

#include <stdio.h>
#define MaxSize 100

float dotproduct(int n, float x[], float y[]){
  int i = 0;
  float sum = 0.0;
  for (i = 0; i < n; i++){
    sum += x[i]*y[i];
  }
  return sum;
}

void main(){
  int j;
  int i = 0;
  float x[MaxSize];
  float y[MaxSize];
  printf("Enter number of elements in arrays:\n");
  scanf("%d", &j);
  printf("Enter %d numbers to be stored in first array separated by spaces:\n", j);
  for (i = 0; i < j; i++){
    scanf("%f", &x[i]);
  }
  printf("Enter %d numbers to be stored in second array separated by spaces:\n", j);
  for (i = 0; i < j; i++){
    scanf("%f", &y[i]);
  }
  printf("The dotproduct is %f.\n", dotproduct(j, x, y));
}
