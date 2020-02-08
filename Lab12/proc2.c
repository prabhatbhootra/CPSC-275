//proc2.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define maxlen 500


void main (int argc, char *argv[]){
  char *message[maxlen];
  int count = 0;
  pid_t pid;
  pid = fork();
  if (pid != 0){
    while (count < argc){
      *message = "I am the parent.\n";
      printf("%s", *message);
    }
  } 
  else {
    while (count < argc){
      *message = "I am the child.\n";
      printf("%s", *message);
    }
  }
}
