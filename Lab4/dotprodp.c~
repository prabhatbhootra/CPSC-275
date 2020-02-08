//dotprodp.c

#include <stdio.h>
#define maxlen 100

int getinput(float a[], float b[]){
  int s;
  float *ip;
  printf("Enter size of vectors:\n");
  scanf("%d", &s);
  if (s > maxlen){
    return -1;
  }
  printf("Enter %d numbers to be stored in first array separated by spaces:\n", s);
  for (ip = &a[0]; ip < &a[s]; ip++){
    scanf("%f", ip);
  }
  printf("Enter %d numbers to be stored in second array separated by spaces:\n", s);
  for (ip = &b[0]; ip < &b[s]; ip++){
    scanf("%f", ip);
  }
  return s;
  
}

float dotproduct(int n, float a[], float b[]){
  float dp = 0;
  float *ap;
  ap = &a[0];
  float *bp;
  bp = &b[0];
  while ((ap < &a[n]) && (bp < &b[n])){
    dp += (*ap)*(*bp);
    ap++;
    bp++;
  }
  if (n > 0){
    return dp;
  }
  else {
    return 0.0;
  }
}

void main(){
  float x[maxlen];
  float y[maxlen];
  int sz = getinput(x, y);
  if (sz == -1){
    printf("Vector size out of bounds.\n");
  }
  else { 
    float ans = dotproduct(sz, x, y);
    printf("%0.1f\n", ans);
  }
}
