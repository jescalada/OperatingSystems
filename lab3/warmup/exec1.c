#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
  // Create a child process to run the ls command
  pid_t pid;
  pid = fork();

  if (pid < 0) {
    fprintf(stderr, "Fork failed\n");
    return 1;
  }
  else if (pid == 0) {
    // Child process runs the ls command
    char *args[] = {"/bin/ls", "-l", NULL};
    execvp(args[0], args);
  }
  else {
    // Parent process reaps the child
    // waitpid(pid, NULL, 0); is a more flexible version of wait(NULL);
    wait(NULL);
    printf("I have reaped the child\n");
  }
  printf("Exiting...\n");
  return 0;
}