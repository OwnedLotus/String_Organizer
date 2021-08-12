/*
  This is just for segmenting the code and testing individual parts of the code.
  It is not in any way part of the original codebase or will it be executed with the main program.
*/
#include <stdio.h>
#include <stdlib.h>

void QuickSort(int* arr);

int main(int argc, char const *argv[])
{
  int* arr;
  arr = malloc(5);

  arr[0] = 1;
  arr[1] = 83;
  arr[2] = 32;
  arr[3] = 2;
  arr[4] = 100;

  QuickSort(arr);
}

void QuickSort(int* arr)
{
  
}