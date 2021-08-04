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


int main()
{
  char str_array[ITER][MAX];
  char r;
  char usingText;

  puts("Would you like to use a Text file?");
  puts("y/n: ");

  scanf(" %c", &usingText);
  

  if(usingText == 'y')
  {
    char fileName[260]; // 255 is the standard limit for file names 256 for endline character \n and 260 for the file type
    FILE* fp;
    size_t lines = 0;
    char ch;
    int i;

    puts("Please enter the Text file name:");

    scanf(" %s", &fileName);
    

    strcat(fileName, TEXT_APPEND);

    fp = fopen(fileName, "r");

    if (fp == NULL)
    {
      puts("File Failed to Open: File may not exist or was inputted incorrectly!");
      puts("Please Try Again!");

      return 0;
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
          for (int j = 0; j < MAX; j++)
          {
            while ((ch = fgetchar()) != EOF)
            {
              if (ch != '\n')
              {
                str_array[i][j] = ch;
              }
              else if (ch =='\n')
              {
                break;
              }
            }            
          } 
        }
      }
      else
      {
        puts("Too many arguments in file: Please modify original file or open a different file");
        return 0;
      }

      fclose(fp);
      free(fileName);
    }
  }
  else
  {
    puts("Please type in 10 statements!");

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
  char temp_array[MAX];
  int temp_int_array[ITER];
  int memory[ITER];
  
  bool isSwapped = false;  // a kind of bool that represents if the string has been swapped, if swapped it will switch to false "0" defined in stdbool.h
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
        isSwapped = true;
      }
      else
      {
        isSwapped = false;
      }

      if (isSwapped)
      {
        controller++;
      }  
    }
  }

  for (i = 0; i < ITER; i++)
  {
    puts(str_array[i]);
    printf("\n");
  }
}