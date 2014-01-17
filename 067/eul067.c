#include <stdio.h>
#include <stdlib.h>

long biggest(int a, int b);

int main(int argc, char *argv[])
{



  long array[100][100];
/* Start with the row above the final row and move towards zero */ 
  int i = 13;

  while(i >= 0) {
    for (int j = 0; j <= i; ++j)
    {
      array[i][j] += biggest(array[i+1][j], array[i+1][j+1]);
    }
    i--;
  }

  printf("This SHOULD be this answer: %ld\n", array[0][0]);
  return 0;
}


long biggest(int a, int b)
{
    return a > b ? a : b;
}
