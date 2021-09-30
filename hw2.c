#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "my_functions.h"
#include "functions.h"
#include "structure.h"

int main(int argc, char const *argv[])
{
  int status = 0;
  forest* data_structure = initForest(initTree(NULL));

  status = read_persons(0, data_structure);
  if (status != 0)
  {
    print_error(status); /* Just return in case of error */
    return -1;
  }
  status = print_persons(1, data_structure);
  if (status != 0)
  {
    print_error(status); /* Another error case */
    return -1;
  }

  return 0;
}
