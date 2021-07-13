#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define iter 10
#define max 100

char Menu();
void Original(char str_array[iter][max]);
void Ascii(char str_array[iter][max]);
void Increase(char str_array[iter][max]);
void WordSize(char str_array[iter][max]);
//char* ClearString(char* inputString);

int main()
{
  puts("Please type in 10 statements!");

  char str_array[iter][max];
  char r;

  size_t m = 100;

  for (int i = 0; i < iter; i++)
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

  putchar('\n');

  return ch;
}

void Original(char str_array[iter][max])
{
  for (int i = 0; i < iter; i++)
  {
    puts(str_array[i]);
    printf(" ");
  }
}

void Ascii(char str_array[iter][max])
{
  int i, j;
  char temp[max];

  for ( i = 0; i < iter; i++)
  {
    for ( j = i + 1; j < iter; j++)
    {
      if(strcmp( str_array[i], str_array[j]) > 0)
      {
        strcpy(temp,str_array[i]);
        strcpy(str_array[i],str_array[j]);
        strcpy(str_array[j],temp);
      }
    }
  }

  for (int i = 0; i < iter; i++)
  {
    puts(str_array[i]);
    printf(" ");
  }
}

void Increase(char str_array[iter][max])
{
  int i = 0;
  int j = 0;
  char temp_array[max];
  
  for(i = 0; i < iter; i++)
    {
      for(j = 0; j < iter - i - 1; j++)
        {
          if(strlen(str_array[j]) > strlen(str_array[j + 1]))
          {
            strcpy(temp_array, str_array[j]);
            strcpy(str_array[j], str_array[j + 1]);
            strcpy(str_array[j + 1], temp_array);
          }
      }
  }
    
  for (int i = 0; i < iter; i++)
  {
    puts(str_array[i]);
    printf(" ");
  }
}

void WordSize(char str_array[iter][max])
{
  int i, j;
  char temp_array[max];
  int temp_int_array[iter];
  int memory[iter];
  
  int swapped = false;  // a kind of bool that represents if the string has been swapped, if swapped it will switch to false "0" defined in stdbool.h
  int controller = 0;

  for (i = 0; i < iter; i++)
  {
    for (j = 0; j < max; j++)
    {
      if (str_array[i][j] == ' ' || str_array[i][j] == '\n')
      {
        memory[i] = j;

        break;
      } 
    }
  }

  for(i = 0; i < iter; i++)
  {
    for (j = 10; j <= 1 + controller ; j--)
    {
      if(memory[j] > memory[j + 1])
      {
        temp_int_array[i] = memory[j];
        strcpy(temp_array, str_array[j]);

        memory[j] = memory[j + 1];
        strcpy(str_array[j], str_array[j + 1]);

        memory[j + 1] = temp_int_array[j];
        strcpy(str_array[j + 1], temp_array);
        swapped = true;
      }
      else
      {
        swapped = false;
      }

      if (swapped)
      {
        controller++;
      }
      
    }
  }

  for (i = 0; i < iter; i++)
  {
    puts(str_array[i]);
  }
}