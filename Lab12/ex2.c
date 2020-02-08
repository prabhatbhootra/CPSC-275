//ex2

#include <stdio.h>
#include <unistd.h>

void main (int argc, char *argv[]){
  char *message;
  pid_t p = fork();
  int i;
  for (i = 0; i < atoi(argv[1]); i++){
    if (p){
      message = "I am the parent.\n";
    }
    else {
      message = "I am the child.\n";
    }
    printf("%s\n", message);
  }
}
