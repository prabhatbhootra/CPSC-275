//fib.c

#include <stdio.h>
#define maxlen 100
void main(){
  int a[maxlen];
  int *ip = a;
  int *jp;
  *ip = 0; 
  ip++;
  *ip = 1;
  for (ip = a + 2; ip <= a + 19; ip++){

    *ip = *(ip-1) + *(ip-2);
  }
  for (jp = a; jp <= a + 19; jp++){
    printf("%d, ", *jp);
  }
}

