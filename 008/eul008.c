#include <stdio.h>
#include <stdlib.h>

FILE *inputf;
char *mode = "r";





long long productOrZero(char* index, int k) {
   /*
    *This function does two things: it tests to see if the elements pointed to 
    *between index and index+(k-1) are zero; if not it multiplies them together
    *and returns the product. If one is found to be zero, it returns a negative
    *number which represents its position relative to index. 
    */

  long long product = 1;

  do {
    if ((int) *(index+k-1) == 0)
    {
      return -k;
    } 
    else
    {
      product = ((int) *(index+k-1)) * product;
      k--;
    }
  } while(k > 0);

  return product;
}
