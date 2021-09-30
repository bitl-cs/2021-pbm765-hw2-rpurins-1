#include <stdio.h>
#include "my_functions.h"
#include "functions.h"

void testTask1();

int main()
{
  testTask1();
  return 0;
}

void testTask1()
{
  char buffer[256];
  
  assertInt("Line 1 int", 0, read_line(0, buffer));
  assertString("Line 1 str", "Son son", buffer);
  clearStr(buffer);

  assertInt("Line 2 int", -2, read_line(0, buffer));

  assertInt("Line 3 int", 2, read_line(0, buffer));
  assertString("Line 3 str", "Father", buffer);
  clearStr(buffer);

  assertInt("Line 4 int", 1, read_line(0, buffer));
  assertString("Line 1 str", "Mother", buffer);
  clearStr(buffer);

  assertInt("Line 5 int", 0, read_line(0, buffer));
  assertString("Line 5 str", "Father", buffer);
  clearStr(buffer);

  assertInt("Line 6 int", -2, read_line(0, buffer));

  assertInt("Line 7 int", 1, read_line(0, buffer));
  assertString("Line 7 str", "Granny", buffer);
  clearStr(buffer);

  assertInt("Line 8 int", -2, read_line(0, buffer));

  assertInt("Line 9 int", 0, read_line(0, buffer));
  assertString("Line 9 str", "OtherSon", buffer);
  clearStr(buffer);

  assertInt("Line 10 int", 1, read_line(0, buffer));
  assertString("Line 10 str", "OtherMother", buffer);
  clearStr(buffer);

  assertInt("Line 11 int", 2, read_line(0, buffer));
  assertString("Line 11 str", "OtherFather", buffer);
  clearStr(buffer);

  assertInt("Empty/no line", -1, read_line(0, buffer));
  assertInt("Empty/no line", -1, read_line(0, buffer));
}
