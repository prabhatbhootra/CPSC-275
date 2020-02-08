//exer5.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main (){
  int pid;
  printf("Parent starting....\n");
  pid = fork();
  if (pid == 0){
    execl("child", "child", "5", (char *) 0);
    printf("Shouldn't have gotten here...\n");
  }
  else {
    printf("Process [%d]: parent in execution...\n", getpid());
    wait();
  }
}

