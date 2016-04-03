#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

int main(int argc, char *argv[], char *envp[]) {

  kill(atoi(argv[1]), SIGKILL);
  
  return 0;
}
