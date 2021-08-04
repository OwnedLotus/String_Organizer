/*
  This is just for segmenting the code and testing individual parts of the code.
  It is not in any way part of the original codebase or will it be executed with the main program.
*/
#include <stdio.h>

int main(int argc, char const *argv[])
{
  FILE *fp;
  int ch;

  fp = fopen("Strings.txt", "r");

  if (fp == NULL)
  {
    printf("Error File Read");
  }
  fscanf(fp, "%d", &ch);
  

  printf(" %d", ch);
  fclose(fp);
  return 0;
}
