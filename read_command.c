#include "shell.h"

/**
 * read_command - Read a command from the user
 * @c: Buffer to store the user input
 * @size: Size of the buffer
 *
 * Description:
 * This function reads a command from the user using fgets, and handles
 * possible errors, such as reaching the end of the input or encountering
 * a read error.
 *
 * Parameters:
 * @c: Buffer to store the user input.
 * @size: Size of the buffer.
 */

void read_command(char *c, size_t size)
{
  if(fgets(c, size, stdin) == NULL)
  {
    if(feof(stdin))
    {
      printf("\n");
      exit(EXIT_SUCCESS);
    }
    else
    {
      printf("Error reading user input.\n");
      exit(EXIT_FAILURE);
    }
  }
  c[strcspn(c, "\n")] = '\0';
}
