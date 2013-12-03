#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char *mode = "r";
char *filename;
int productOrZero(int*, int k);

int main(int argc, char *argv[])
{
  /*
   *  This program takes two arguments: the filename, and how many digits to 
   *  multiply per loop. This is a more general implementation for Project
   *  Euler problem 8.
   */

  if (argc != 3 )
  {
    printf("There aren't enough arguments.\n");
    printf("Usage: eul008 <filename> <num>\n");
    exit(EXIT_FAILURE);
  }

  filename = argv[1];

  FILE *file = fopen(filename, mode);
  assert(file);
  printf("The file was opened successfully\n");

  /*
   *  This loop iteratively gets a character in the opened file, tests to see 
   *  that it is a digit, and converts it to an integer via simple ASCII 
   *  subtraction. It finishes at the end of the file. The array that we store
   *  our values in is initialized to -10. This helps later.
   */

  int ch;
  int arr[1024];
  for (int i = 0; i < 1024; ++i)
  {
    arr[i] = -10;
  }

  int* a = arr;

  while( !feof(file) ) {
    ch = fgetc(file);
    if (ch != '\n')
    {
      *a = ch - '0';
      a++; 
    }
  }
  
  printf("Closing the file... ");
  fclose(file);
  printf("Done.\n");
  
  return 0;
}


int productOrZero(int a[], int k) {
   /*
    *This function does two things: it tests to see if the elements pointed to 
    *between index and index+(k-1) are zero; if not it multiplies them together
    *and returns the product. If one is found to be zero, it returns a negative
    *number which represents its position relative to index. 
    */

  long long product = 1;

  do {
    if (*(a+k-1) == 0)
    {
      return -k;
    } 
    else
    {
      product = *(a+k-1) * product;
      k--;
    }
  } while(k > 0);

  return product;
}
