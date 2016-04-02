#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#define HISTORY_FILE "ucysh_history"

int main() {

  char* input, shell_prompt[100];
  char history_file_path[100];
  FILE *history_file = NULL;
  int i=0; 
  /* Configure readline to auto-complete paths when the tab key is hit. */
  rl_bind_key('\t', rl_complete);

  
  setenv ("HOME", getenv("PWD") , 1);
    
  using_history();
  
  sprintf(history_file_path, "%s/.%s\0", getenv("HOME"), HISTORY_FILE);
  history_file = fopen(history_file_path, "w");
  if(!history_file)
    {
      printf("Failed to open history file\n");
      exit(-1);
    }

  // TODO change i
  for(i=0;i<5;i++) {
    /* Create prompt string from user name and current working directory. */
    snprintf(shell_prompt, sizeof(shell_prompt), "ucysh:%s> ",getcwd(NULL, 1024));
    /* Display prompt and read input (NB: input must be freed after use)...*/
    input = readline(shell_prompt);
    
    /* Check for EOF. */
    if (!input)
      break;
    
    /* Add input to history. */
    add_history(input);
    append_history(1, history_file_path);
    

    /* Free input. */
    free(input);
  }

  fclose(history_file);
  remove(history_file_path);
  return 0;
}
