#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define HISTORY_FILE "ucysh_history"
#define CHUNK 1024 /* read 1024 bytes at a time */

int main(int argc, char *argv[], char *envp[]) {
  char buf[CHUNK];
  size_t nread;
  
  char  history_file_path[100];
  char c;
  FILE *history_file = NULL;
  
  int i;
  sprintf(history_file_path, "%s/.%s\0", getenv("HOME"), HISTORY_FILE);
  printf("%s\n",history_file_path);
  history_file = fopen(history_file_path, "r");
  if(!history_file)
    {
      printf("No history file \n");
      exit(-1);
    }
  while ((nread = fread(buf, 1, sizeof buf, history_file)) > 0)
    fwrite(buf, 1, nread, stdout);
  
  fclose(history_file);
  return 0;
}
