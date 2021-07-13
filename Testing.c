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
