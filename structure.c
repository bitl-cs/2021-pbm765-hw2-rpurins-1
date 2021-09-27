#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

forest* initForest(tree* tree)
{
  forest* f = malloc(sizeof(forest));
  f->tree = tree;
  f->next = NULL;
  f->prev = NULL;

  return f;
}

 void addToForest(forest *f, tree *t)
{
  forest *current = f;
  while (current->next != NULL)
  {
    current = current->next;
  }
  current->next = malloc(sizeof(forest));
  current->next->tree = t;
  current->next->next = NULL;
  current->next->prev = current;
}

tree* initTree(branch* branch)
{
  tree* t = malloc(sizeof(tree));
  t->branch = branch;
  t->next = NULL;
  t->prev = NULL;

  return t;
}

void addToTree(tree* t, branch* b)
{
  tree* current = t;
  while (current->next != NULL)
  {
    current = current->next;
  }
  current->next = malloc(sizeof(tree));
  current->next->branch = b;
  current->next->next = NULL;
  current->next->prev = current;
}

branch* initBranch(char *n)
{
  branch* b = malloc(sizeof(branch));
  strcpy(b->name, n);
  b->next = NULL;
  b->prev = NULL;

  return b;
}

void addToBranch(branch* b, char* name)
{
  branch* current = b;
  while (current->next != NULL)
  {
    current = current->next;
  }
  current->next = malloc(sizeof(branch));
  strcpy(current->next->name, name);
  current->next->next = NULL;
  current->next->prev = current;
}
