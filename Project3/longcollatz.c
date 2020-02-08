//longcollatz.c

#include <stdio.h>
#include <stdlib.h>
long long longcollatz(long long *n);

void main (int argc, char *argv[]){
  long long x = atoll(argv[1]);
  printf("%llu \n", longcollatz(&x));    
}

