#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int unsigned long dividend;
  int unsigned long answer;
  int unsigned long largestFactor(int unsigned long, int unsigned long, int unsigned long);

  if (argc > 1)
  {
    printf("%s\n", argv[1] );
    dividend = atoi(argv[1]);
    printf("%lu\n", dividend);
  } else {
    dividend = 600851475143;
  }

  answer = largestFactor(dividend, 2, 1);

  printf("The largest prime factor of %lu is: %lu \n", dividend, answer);
  return 0;
}

int unsigned long
largestFactor(int unsigned long divd, int unsigned long divr, int unsigned long largest)
{
  if (divr > divd)
  {
    return largest;
  } else if (divd % divr == 0) {
    return largestFactor((divd / divr), divr, divr);
  } else {
    return largestFactor(divd, divr+1, largest);
  }
}
