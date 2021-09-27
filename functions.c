#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_functions.h"

print_error(int error_code)
{
  printf("Program exited with error %i\n", error_code);
  if (error_code == -1) printf("Out of bounds. Tried to read a non-existent line from file.\n");
  if (error_code == -2) printf("Line didn't contain a valid keyword.\n");
  if (error_code == -3) printf("Provided a parent without providing a child before.\n");
  if (error_code == -4) printf("Provided a parent with the same gender.\n");
  if (error_code == -5) printf("Some random error, that should never have happened :D\n");
}


/* firs task*/
int read_line(int fd, char *buffer)
{
  int read_status;
  char keyword[256];
  int keyword_counter = 0;
  int write_in_keyword = 1;
  char name[256];
  int name_counter = 0;
  char line_char;
  int ret_val = -2;

  while (1)
  {
    read_status = read(fd, &line_char, 1);
    if (line_char == '\n' && keyword_counter == 0)
      continue;
    if (line_char == '\n' || read_status == 0 || read_status == -1) /* EOF */
    {
      if (keyword_counter == 0)
        return -1;
      break;
    }
    if (line_char == ' ' && write_in_keyword == 1)
    {
      write_in_keyword = 0;
      keyword[keyword_counter] = '\0';
    }
    else
    {
      if (write_in_keyword)
      {
        keyword[keyword_counter] = line_char;
        keyword_counter++;
      }
      else
      {
        name[name_counter] = line_char;
        name_counter++;
      }
    }
  }
  name[name_counter] = '\0';

  if (str_length(keyword) == 4 && str_find("NAME", keyword) == 0)
  {
    ret_val = 0;
  }
  else if (str_length(keyword) == 6 && str_find("MOTHER", keyword) == 0)
  {
    ret_val = 1;
  }
  else if (str_length(keyword) == 6 && str_find("FATHER", keyword) == 0)
  {
    ret_val = 2;
  }
  if (ret_val != -2)
  {
    str_copy(name, buffer);
  }

  return ret_val;
}
