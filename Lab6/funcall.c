#include <stdio.h>

void f1(int num1);
void f2(int num2);

void main(){
  int a = 10;
  int b = 20;
  f1(a);
  f2(b);
  printf("a:     %p      %d\n", &a, a);
  printf("b:     %p      %d\n", &b, b);
}

void f1(int num1){
  int a1;
  a1 = num1++;
  int *p;
  p = &num1;
  printf("num1:     %p      %d\n", p, *p);
  p = &a1;
  printf("a1:     %p      %d\n", p, *p);
  /* Your code to print num1’s address and value, and a1’s address and value.  Be sure to label the output e.g. “a1:    0x48484    7” */


}
void f2(int num2){
  int a2;
  a2 = num2++;
  int *i;
  i = &num2;
  printf("num1:     %p      %d\n", i, *i);
  i = &a2;
  printf("num1:     %p      %d\n", i, *i);
  /* Your code to print num2’s address and value, and a2’s address and value. */

}
