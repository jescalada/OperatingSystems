#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
  int N = 5;
  pid_t pid;
  for (int i = 0; i < N; i++) {
    pid = fork();
    if (pid < 0) {
      fprintf(stderr, "Fork failed\n");
      return 1;
    }
    else if (pid == 0) {
      printf("I am child with PID %d\n", getpid());
      exit(0);
    }
  }
  for (int i = 0; i < N; i++) {
    wait(NULL);
  }
  printf("I am parent and I reaped all children\n");
  return 0;
}