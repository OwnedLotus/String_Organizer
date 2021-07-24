#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define ITER 10
#define MAX 100
#define TEXT_APPEND ".txt" 

char Menu();
void Original(char str_array[ITER][MAX]);
void Ascii(char str_array[ITER][MAX]);
void Increase(char str_array[ITER][MAX]);
void WordSize(char str_array[ITER][MAX]);

bool useTxt();

int main()
{
  char str_array[ITER][MAX];
  char r;
  RESTART: bool usingText = useTxt();

  if(usingText == true)
  {
    char fileName[260]; // 255 is the standard limit for file names 256 for endline character \n and 260 for the file type
    FILE* fp;
    size_t lines = 0;
    char ch;

    puts("Please enter the Text file name:");

    gets(fileName);
    strcat(fileName, TEXT_APPEND);

    fp = fopen(fileName, 'r');

    if (fp == NULL)
    {
      puts("File Failed to Open: File may not exist or was inputted incorrectly!");
      puts("Please Try Again!");

      goto RESTART;
    }
    else
    {      
      while (ch != EOF)
      {
        if (ch == '\n')
        {
          lines++;
        }
        ch = fgetc(fp);
      }
      
      if(lines <= 10)
      {
        rewind(fp);

        for (int i = 0; i < lines; i++)
        {
         fgets(MAX, MAX, fp);//Needs to be adjusted
        }
      }
      else
      {
        puts("Too Many Arguments in file: Please Modify Original File or open a different file");
        goto RESTART;
      }

      fclose(fp);
      free(fileName);
    }
  }
  else
  {
    puts("Please type in 10 statements!");    

    size_t m = 100;

    for (int i = 0; i < ITER; i++)
    {
      printf("%d: ", i + 1);
      gets(str_array[i]);
    }
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
        free(str_array);
        return 0; 
        break;
      
      default:
        puts("Error: Answer not accepted!");
        puts("Please choose an option!");
        break;
    }
  }
  
  return 0;

  File_Read_Error:
  perror("Error:");
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
    printf(" ");
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
    printf(" ");
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
    printf(" ");
  }
}

void WordSize(char str_array[ITER][MAX])
{
  int i, j;
  char temp_array[MAX];
  int temp_int_array[ITER];
  int memory[ITER];
  
  int swapped = false;  // a kind of bool that represents if the string has been swapped, if swapped it will switch to false "0" defined in stdbool.h
  int controller = 0;

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

  for(i = 0; i < ITER; i++)
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

  for (i = 0; i < ITER; i++)
  {
    puts(str_array[i]);
  }
}

//a method that prompts the user if they want to use a txt file
bool useTxtFile()
{
  bool isUsingFile = false;

  puts("Would you like to process the strings from a text file? y/n");

  int input = getchar();

  if (input = 'y')
  {
    return isUsingFile = true;
  }
  else
  {
    return isUsingFile = false; 
  }
}