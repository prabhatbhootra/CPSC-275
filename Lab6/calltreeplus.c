//calltreeplus.c

#include <stdio.h>

int funca(int l);
int funcb(int l);
int funcc(int l);

void main(){
  printf("main (Level 0)\n");
  int level = 0;
  funca(level);
  funcc(level);
}
int funca(int l){
  int d = 0;
  l++; 
  char indent[] = "    ";
  int i;
  for (i = 0; i < l; i++){
    printf("    ");
  }
  printf("funca    Level %d    %p\n", l, &l);
  d += (funcb(l) + 1);
  d += (funcc(l) + 1);
  printf(" Descendants of funca: %d\n", d);
  return d;
}
int funcb(int l){
  int d = 0;
  l++;
  char indent[] = "    ";
  int i;
  for (i = 0; i < l; i++){
    printf("    ");
  }
  printf("funcb    Level %d    %p\n", l, &l);
  
  d += (funcc(l) + 1);
  d += (funcc(l) + 1);
  
  printf(" Descendants of funcb: %d\n", d);
  return d;
}
int funcc(int l){
  int d = 0;
  l++;
  char indent[] = "    ";
  int i;
  for (i = 0; i < l; i++){
    printf("    ");
  }
  printf("funcc    Level %d    %p\n", l, &l);
  printf(" Descendants of funcc: %d\n", d);
  return d;
}

