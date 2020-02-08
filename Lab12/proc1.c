//proc1.c

#include <stdio.h>

void main(){
  printf("First\n");
  sleep(10);
  fork();
  sleep(10);
  printf("Second\n");
}
