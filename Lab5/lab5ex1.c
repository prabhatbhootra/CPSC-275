//lab5ex1.c

#include <stdio.h>
#include <string.h>
#define namelen 20
typedef struct{
  int part_no;
  char name[namelen + 1];
  float weight;
  int quantity;
} part;

part readpart(){
  part p;
  printf("Enter part number: \n");
  scanf("%d", &p.part_no);
  printf("Enter part name: \n");
  char s[namelen +1];
  scanf("%s", &s);
  strcopy(p.name, s);
  printf("Enter part weight: \n");
  scanf("%f", &p.weight);
  printf("Enter part quantity: \n");
  scanf("%d", &p.quantity);
  return p;
}

void printpart(part p){
  printf("Part number: %d\n", p.part_no);
  printf("Part name: %s\n", p.name);
  printf("Part weight: %f\n", p.weight);
  printf("Part quantity: %d\n", p.quantity);
}

void main(){
  part part1 = readpart();
  printpart(part1);
}

