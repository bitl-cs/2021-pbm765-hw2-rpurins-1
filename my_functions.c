#include <stdio.h>
#include "my_functions.h"

/* TASK 3 */
int str_length(char *mystring)
{
  int i = 0;
  char c = mystring[i];
  while (c != '\0')
  {
    i++;
    c = mystring[i];
  }

  return i;
}

/* TASK 4 */
void str_copy(char *source, char *destination)
{
  if (str_length(source) == 0)
  {
    *destination = '\0';
    return;
  }
  while (*source != '\0')
  {
    *destination++ = *source++;
  }
  *destination++ = '\0';
}

/* TASK 5 */
int str_find(char *needle, char *haystack)
{
  int i = 0;
  int nLen = str_length(needle);
  int hLen = str_length(haystack);

  if (nLen > hLen)
  {
    return -1;
  }

  int j;
  while (haystack[i + nLen - 1] != '\0')
  {
    int found = 1;
    for (j = 0; j < nLen; j++)
    {
      if (haystack[i + j] != needle[j])
      {
        found = 0;
        break;
      }
    }
    if (found == 1)
    {
      return i;
    }
    i++;
  }

  return -1;
}

/* TASK 6 */
int get_unnamed_argument(int index, int argc, char **argv, char *result)
{
  if (index > argc)
  {
    return -1;
  }

  int i;
  int counter = -1;
  for (i = 0; i < argc; i++)
  {
    if (str_length(argv[i]) == 2 && str_find("--", argv[i]) == 0)
    {
      return -1;
    }
    if (str_find("=", argv[i]) == -1)
    {
      counter++;
    }

    if (index == counter)
    {
      str_copy(argv[i], result);
      return str_length(result);
    }
  }

  return -1;
}

/* TASK 7 */
int get_named_argument(int index, int argc, char **argv, char *result)
{
  if (index > argc)
  {
    return -1;
  }

  int i;
  int counter = -1;
  for (i = 0; i < argc; i++)
  {
    if (str_length(argv[i]) == 2 && str_find("--", argv[i]) == 0)
    {
      return -1;
    }

    if (str_find("=", argv[i]) != -1)
    {
      counter++;
    }

    if (index == counter)
    {
      str_copy(argv[i], result);
      return str_length(result);
    }
  }

  return -1;
}



/* These just make life a little bit better and does not make it seem so sad */
void assertInt(char *name, int a, int b)
{
  if (a != b)
  {
    printf("%s was incorrect. Was: %i, Supposed to be: %i\n", name, b, a);
  }
}

void assertString(char *name, char *str1, char *str2)
{
  if (strcmp(str1, str2) != 0)
  {
    printf("%s was incorrect. Was: %s, Supposed to be: %s\n", name, str2, str1);
  }
}

void clearStr(char *str)
{
  str_copy("", str);
}
