//calltree.c

#include <stdio.h>

void funca(int l);
void funcb(int l);
void funcc(int l);

void main(){
  printf("main (Level 0)\n");
  int level = 0;
  funca(level);
  funcc(level);
}
void funca(int l){
  l++; 
  char indent[] = "    ";
  int i;
  for (i = 0; i < l; i++){
    printf("    ");
  }
  printf("funca    Level %d    %p\n", l, &l);
  funcb(l);
  funcc(l);
}
void funcb(int l){
  l++;
  char indent[] = "    ";
  int i;
  for (i = 0; i < l; i++){
    printf("    ");
  }
  printf("funcb    Level %d    %p\n", l, &l);
  funcc(l);
  funcc(l);
}
void funcc(int l){
  l++;
  char indent[] = "    ";
  int i;
  for (i = 0; i < l; i++){
    printf("    ");
  }
  printf("funcc    Level %d    %p\n", l, &l);
}

