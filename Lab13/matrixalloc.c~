//matrixalloc.c

#include <stdio.h>
#include <stdlib.h>

void initmat(double *, int);

void main (int argc, char *argv[]){
  double *a;
  int n;
  n = atoi(argv[1]);
  a = (double *) malloc(n*n*sizeof(double));
  if (a == NULL)
    printf("Oops!\n");
  else{
    initmat(a, n);
    free(a);
  }
}

void initmat(double *mat, int n){
  int j;
  int k;
  for (j = 0; j < n; j++)
    for (k = 0; k < n; k++)
      mat[j*n + k] = j + k;
}
