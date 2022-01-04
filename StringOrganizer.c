#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ITER 10
#define MAX 100
//#define TEXT_APPEND ".txt" 

char Menu();
void Original(char str_array[ITER][MAX]);
void Ascii(char str_array[ITER][MAX]);
void Increase(char str_array[ITER][MAX]);
void WordSize(char str_array[ITER][MAX]);

int main()
{
  char str_array[ITER][MAX];
  char r;
  //char usingText;

  puts("Please type in 10 statements!");

  for (int i = 0; i < ITER; i++)
  {
    printf("%d: ", i + 1);
    gets(str_array[i]);
  }

  while (1)
  {
    r = Menu();

    switch (r)
    {
      case 'a':
        Original(str_array);
        break;

      case 'b':
        Ascii(str_array);
        break;
        
      case 'c':
        Increase(str_array);
        break;

      case 'd':
        WordSize(str_array);
        break;

      case 'q':
        puts("Goodbye!");
        return 0; 
        break;
      
      default:
        puts("Error: Answer not accepted!");
        puts("Please choose an option!");
        break;
    }
  }
  
  return 0;
}

char Menu()
{
  int a;
  char ch;

  puts("Please Choose an Option: ");
  puts("a:    Print the original list of statements");
  puts("b:    Print the statements in ASCII sequence");
  puts("c:    Print the statements in increasing length");
  puts("d:    Print the statements in the order of the longest word");
  puts("q:    Quit");

  inputs:a = getchar();

  if (a == 'a' || a=='b' || a=='c' || a=='d' || a=='q') 
  {
    ch = a;
  }
  else
  {
    puts("Given input was rejected! Please try again!");

    goto inputs;
  }

  printf("Debug output: %c", ch); // debug print shows what is given
  putchar('\n'); //Have not decided how the spacing will work

  return ch;
}

void Original(char str_array[ITER][MAX])
{
  for (int i = 0; i < ITER; i++)
  {
    puts(str_array[i]);
    printf("\n");
  }
}

void Ascii(char str_array[ITER][MAX])
{
  int i, j;
  char temp[MAX];

  for ( i = 0; i < ITER; i++)
  {
    for ( j = i + 1; j < ITER; j++)
    {
      if(strcmp( str_array[i], str_array[j]) > 0)
      {
        strcpy(temp,str_array[i]);
        strcpy(str_array[i],str_array[j]);
        strcpy(str_array[j],temp);
      }
    }
  }

  for (int i = 0; i < ITER; i++)
  {
    puts(str_array[i]);
    printf("\n");
  }
}

void Increase(char str_array[ITER][MAX])
{
  int i = 0;
  int j = 0;
  char temp_array[MAX];
  
  for(i = 0; i < MAX; i++)
    {
      for(j = 0; j < ITER - i - 1; j++)
      {
        if(strlen(str_array[j]) > strlen(str_array[j + 1]))
        {
          strcpy(temp_array, str_array[j]);
          strcpy(str_array[j], str_array[j + 1]);
          strcpy(str_array[j + 1], temp_array);
        }
      }
    }
    
  for (int i = 0; i < ITER; i++)
  {
    puts(str_array[i]);
    printf("\n");
  }
}

void WordSize(char str_array[ITER][MAX])
{
  int i, j;
  int temp_int;
  int memory[ITER];
  char temp_array[MAX];
  
  bool isSwapped = false;
  int controller = 0;

  //Working as intended
  for (i = 0; i < ITER; i++)
  {
    for (j = 0; j < MAX; j++)
    {
      if (str_array[i][j] == ' ' || str_array[i][j] == '\n')
      {
        memory[i] = j;

        break;
      } 
    }
  }

  //Not working as intended
  for(i = 0; i < ITER; i++)
  {
    for (j = 0; i < ITER; i++)
    {
      if(memory[j] > memory[j + 1])
      {
        temp_int = memory[j];
        strcpy(temp_array, str_array[j]);

        memory[j] = memory[j + 1];
        strcpy(str_array[j], str_array[j + 1]);

        memory[j + 1] = temp_int;
        strcpy(str_array[j + 1], temp_array);
      }
    }
  }

  for (i = 0; i < ITER; i++)
  {
    puts(str_array[i]);
    printf("\n");
  }
}