#include <string.h>

typedef struct branch
{
  char name[256];
  struct branch* next;
  struct branch* prev;
} branch;

typedef struct tree
{
  branch* branch;
  struct tree* next;
  struct tree* prev;
} tree;


typedef struct forest
{
  tree* tree;
  struct forest* next;
  struct forest* prev;
} forest;

branch* initBranch(char* name);
void addToBranch(branch* g, char* name);

tree* initTree(branch* b);
void addToTree(tree* t, branch* g);

forest* initForest(tree* t);
void addToForest(forest* f, tree* t);
