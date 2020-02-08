//magic.c
#include <stdio.h>
#define max 205
#define maxn 100
 
int magic(int n, int a[maxn][maxn]){
  int arr[max] = {0};
  int i, j = 0;
  int ai = 0;
  int flag = 1;
  //rows
  for (i = 0; i < n; i++){
    for (j = 0; j < n; j++){
      arr[ai] += a[i][j];
    }
    ai = ai+1;
  }
  //columns
  for (i = 0; i < n; i++){
    for (j = 0; j < n; j++){
      arr[ai] += a[j][i];
    }
    ai = ai+1;
  }
  //diagonal 1
  for (i = 0; i < n; i++){
    arr[ai] += a[i][i];
  }
  ai = ai+1;
  //diagonal 2
  for (i = n-1; i >= 0; i--){
    arr[ai] += a[i][i];
  }
  ai += 1;
  for (i = 0; i < ai-1; i++){
    if (arr[i+1] != arr[i]){
      flag = 0;
    }
  }
  return flag;
}

void main(){
  int o, i, j = 0;
  
  printf("Enter order of magic square:\n");
  scanf("%d", &o);
  int ms[maxn][maxn];
  printf("Enter rows on separate lines:\n");
  for (i = 0; i < o; i++){
    for (j = 0; j < o; j++){
      scanf("%d", &ms[i][j]);
    }
  }
  if (magic(o, ms) == 1){
    printf("It's a magic square!\n");
  }
  else {
    printf("It's not a magic square!\n");
  }
}
    
  
  

