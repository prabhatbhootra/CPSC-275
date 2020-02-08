//fibp.c
#include <stdio.h>
#define max 100

void main(){
  int *a[max];
  int b[max];
  int **ap = *a;
  int *bp = b;
  while (ap <= *(a + 99)){
    **ap = *bp++;
    *ap++;
  }
  bp = b;
  *bp = 0;
  *bp++;
  *bp = 1;
  for (bp = b + 2; bp <= b + 99; bp++){
    *bp = (*bp - 1) + (*bp - 2);
  }
  ap = *a;
  while (ap <= *(a + 99)){
    printf("%d, ", *ap++);
  }
}
   
    
 
