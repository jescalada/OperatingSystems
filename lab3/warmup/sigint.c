#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int sig) {
  printf("I will run forever\n");
}

int main(int argc, char* argv[]) {
  signal(SIGINT, sigint_handler);
  while(1) {
    sleep(1);
  }
  return 0;
}