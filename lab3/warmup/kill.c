#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char* argv[]) {
  pid_t pid;
  pid = fork();
  if (pid < 0) {
    fprintf(stderr, "Fork failed\n");
    return 1;
  }
  else if (pid == 0) {
    printf("I am child with PID %d\n", getpid());
    sleep(100);
    exit(0);
  }
  else {
    printf("I am parent and I am going to sleep for 1 second\n");
    sleep(1);
    kill(pid, SIGKILL);
    printf("I am parent and I killed child with PID %d\n", pid);
  }
  return 0;
}