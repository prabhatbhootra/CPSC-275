//makeshift.c

#include <stdio.h>
#define max 100

void shift(int n, int a[], int s, char c){
  int r[max];
  int i = 0;
  if (c = "L"){
    for (i = 0, i < n, i++){
      a[i] = a[(i+s)%n];
    }
  }
  else {
    for (i = 0, i < n, i++){
      a[i] = a[(i+(n-1))%n];
    }
  }
  for (i = 0; i < n; i++){
   printf(a[i]);
  }
}

void main(){
  int i, n = 0;
  int a[max];
  int s;
  char c;
  printf("Enter array size:\n");
  scanf("%d", &n);
  printf("Enter elements of array to be shifted separated by spaces:\n");
  for (i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  printf("Enter shift distance:\n");
  scanf("%d", &s);
  printf("Enter direction:\n");
  scanf("%c", &c);
  shift(n, a, s, c);
}
  
