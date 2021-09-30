#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_functions.h"
#include "structure.h"

print_error(int error_code)
{
  printf("Program exited with error %i\n", error_code);
  if (error_code == -1) printf("Error. Tried to read a non-existent line from file\n");
  if (error_code == -2) printf("Line didn not contain a correct keyword\n");
  if (error_code == -3) printf("Provided a parent without providing a child before\n");
  if (error_code == -4) printf("Provided a parent with the same gender\n");
  if (error_code == -5) printf("No clue what is wrong\n");
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
    if (line_char == '\n' || read_status == 0 || read_status == -1) 
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


/* third task */
int add_person(char *name, char *father, char *mother, forest* data_structure)
{
  forest* f = data_structure;
  int found = 0;

  while (found == 0)
  {
    tree* t = f->tree;
    if (t == NULL) break;
    while (found == 0)
    {
      branch* b = t->branch;
      if (b == NULL) break;
      while (found == 0)
      {
        if (strcmp(b->name, name) == 0)
        {
          branch *newOlderB = NULL;
          if (father != NULL)
            newOlderB = initBranch(father);
          if (mother != NULL)
          {
            if (newOlderB == NULL)
              newOlderB = initBranch(mother);
            else
              addToBranch(newOlderB, mother);
          }
          addToTree(t, newOlderB);
          found = 1;
          break;
        }
        if (b->next == NULL) break;
        b = b->next;
      }

      if (t->next == NULL) break;
      t = t->next;
    }
    if (f->next == NULL) break;
    f = f->next;
  }

  if (found == 0)
  {
    branch* newB = initBranch(name);

    tree* newT = initTree(newB);

    branch* newOlderB = NULL;
    if (father != NULL) newOlderB = initBranch(father);
    if (mother != NULL)
    {
      if (newOlderB == NULL) newOlderB = initBranch(mother);
      else addToBranch(newOlderB, mother);
    }

    if (newOlderB != NULL) addToTree(newT, newOlderB);

    addToForest(data_structure, newT);
  }
  return 0;
}


/* fourth task */
int print_persons(int fd, forest* data_structure)
{
  if (data_structure == NULL) return -6; /* TBA */
  forest* currFor = data_structure;
  while (currFor->next != NULL) currFor = currFor->next;
  while (1)
  {
    tree* currTree = currFor->tree;
    if (currTree == NULL) break;
    while (currTree->next != NULL) currTree = currTree->next;
    while (1)
    {
      branch* currBranch = currTree->branch;
      if (currBranch == NULL) break;
      while (1)
      {
        printf("%s\n", currBranch->name);
        if (currBranch->next == NULL) break;
        currBranch = currBranch->next;
      }
      if (currTree->prev == NULL) break;
      currTree = currTree->prev;
    }
    if (currFor->prev == NULL) break;
    currFor = currFor->prev;
    if (currFor->prev == NULL) break;
    printf("\n");
  }
  return 0;
}
