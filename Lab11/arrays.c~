//arrays.c

#include <stdio.h>
#define MAX 100
extern void addarray(int n, int x[], int y[], int z[]);

void main(){
  int a[MAX];
  int b[MAX];
  int c[MAX];
  int s;
  int i;
  //printf("%d\n", 2);
  scanf("%d", &s);
  for (i = 0; i < s; i++){
    scanf("%d", &a[i]);
  }
  for (i = 0; i < s; i++){
    scanf("%d", &b[i]);
  }
  addarray(s, a, b, c);
  for (i = 0; i < s; i++){
    printf("%d %d %d\n", a[i], b[i], c[i]);
  }
}
