//add.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main (int argc, char *argv[]){
  int pid;
  pid = fork();
  if (pid == 0){
    execl("child1", "child1", argv[1], argv[2], (char *) 0);
  }
  else {
    printf("In else statement.\n");   
  }
}

