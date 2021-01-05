#include <stdio.h>

int main(int argc, char *argv[])
{
  int i = 0;

  char *states[] = {"California", "Oregon", "Washington", "Texas"};
  
  states[1] = argv[9];
  for(i = 1; i < argc; i++)
  {
    printf("arg %d: %s\n", i, argv[i]);
  }



  int num_states = 4;

  for(i = 0; i < num_states; i++)
  {
    printf("states %d: %s\n", i, states[i]);
  }
}
