#include "shell.h"

int main(void)
{
  char c[150];

  while(1)
  {
    _prompt();
    read_command(c, sizeof(c));
    exec_command(c);
  }

  return(0);
}
