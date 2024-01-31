#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
  char *args[] = {"/bin/ls", "-l", NULL};
  execvp(args[0], args);
  return 0;
}