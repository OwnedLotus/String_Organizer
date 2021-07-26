/*
  This is just for segmenting the code and testing individual parts of the code.
  It is not in any way part of the original codebase or will it be executed with the main program.
*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
  int a;
  char ch;

  a = getc(stdin);

  if (a == 'a')
  {
    ch = a;
  }
  else
  {
    puts("Illegal character!");
  }

  printf("%c", ch);

  return 0;
}
