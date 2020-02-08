//grzst.c
#include <stdio.h>
#include <string.h>

#define len 25
#define wordsnum 1000

void main(){
  int i = 0;
  int j = 0;
  int k;
  int a;
  char c;
  char s[len+1];
  char words[wordsnum][len+1];
  c = getchar();
  while (c != EOF && i < len && j <wordsnum){
    if (c != '\n'){
      words[j][i] = c;
      i++;
    }
    else{
      j++;
      i = 0;
    }
    c = getchar();
  }
  sort(words, j);
  for (k = 0; k < j; k++){
    for (a = 0; a < len; a++){
      printf("%c", words[k][a]);
    }
    printf("\n");
  }
  /*
  char a[len] = {'g', 'r', 'o', 's', 't'};              //test compare
  char b[len] = {'b', 'e', 'o', 't', 'o', 'o'};           //test compare
  char d[len] = {'r', 'a', 'b', 's', 'o'};               //test compare
  printf("%d\n", compare(a, b));   //test compare          1
  printf("%d\n", compare(b, d));   //test compare          0
  printf("%d\n", compare("abdeof", "kjdshf"));             0
  */
}

int compare(char a[], char b[]){
  float aratio;
  float acount = 0.0;
  float aconsonants = 0.0;
  float bratio;
  float bcount = 0.0;
  float bconsonants = 0.0;

  int c = 0;
  int d = 0;
  while (a[c] != '\0'){
    acount = acount + 1.0;
    if (a[c] != 'a' && a[c] != 'e' && a[c] != 'i' && a[c] != 'o' && a[c] != 'u'){
        aconsonants = aconsonants + 1.0;
    }
    c++;
  }

  aratio = aconsonants/acount;
  /*printf("Word 1 ratio: %f\n", aratio);  */

  while (b[d] != '\0'){
    bcount = bcount + 1.0;
    if (b[d] != 'a' && b[d] != 'e' && b[d] != 'i' && b[d] != 'o' && b[d] != 'u'){
        bconsonants = bconsonants + 1.0;
    }
    d++;
  }
  bratio = bconsonants/bcount;
  /*printf("Word 2 ratio: %f\n", bratio); */

  if (aratio > bratio){
    return 1;
  }
  else{
   return 0;
  }
}

void sort(char a[][], int n){
  int i;
  int j;
  char x[len+1];
  for (j = 1; j < n; j++){
    strcpy(x, a[j]);
    i = j-1;
    while (i >= 0 && compare(a[i], x)){
        strcpy(a[i+1], a[i]);
        i--;
    }
    strcopy(a[i+1], x);
  }
}













