// Program that forks a child process using the fork system call.
// The parent reaps the dead child before exiting.

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
  pid_t pid;
  pid = fork();
  if (pid < 0) {
    fprintf(stderr, "Fork failed\n");
    return 1;
  }
  else if (pid == 0) {
    printf("I am child\n");
  }
  else {
    wait(NULL);
    printf("I am parent\n");
  }
  return 0;
}
