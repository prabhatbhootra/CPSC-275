//countlines.c

#include <stdio.h>
#define stringlen 500
void main(){
  char c;
  char str[stringlen];
  int lines = 0;
  int i = 0;
  c  = getchar();
  str[i]  = c;
  i++;
  while (c != EOF){
    putchar(c);
    
    c = getchar();
    str[i] = c;
    i++;
  }

  for (i = 0; i < stringlen; i++){
    if (str[i] == '\n'){
      lines++;
    }
  }
  
  printf("The file had %d lines.", lines);
}
