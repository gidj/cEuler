#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
  int unsigned long num1 = 999;
  int unsigned long num2 = 999;
  int unsigned long palin = 1;
  bool ispalindrome(int unsigned long);
  int unsigned long largestPalindrome(int unsigned long, int unsigned long, int unsigned long);

  if (argc > 1) {
    num1 = strtol(argv[1], (char **)NULL, 10);
    num2 = num1;
  } 

  printf("%lu, %lu\n", num1, num2);
  palin = largestPalindrome(num1, num2, palin);

  printf("The number %lu is the largest palindrome\n", palin);

  return 0;
}

bool 
ispalindrome(int unsigned long num)
{
  int unsigned long reverse = 0;
  int unsigned long temp = num;

  do {
    reverse = reverse * 10;
    reverse += temp % 10;
    temp = temp / 10;
  } while (temp > 0);

  printf("%lu, %lu\n", num, reverse);
  printf("%d\n", (num == reverse));
  return (num == reverse);
}

int unsigned long
largestPalindrome(int unsigned long a, int unsigned long b, int unsigned long palin)
{
  if (a < 1) {
    return palin;
  }

  if (b < 1){
    return largestPalindrome(a-1, a-2, palin);
  }

  int unsigned long temp = a*b;

  if (temp < palin) {
    if ((a-1)*(a-1) < palin) {
      return palin;
    } else { 
      return largestPalindrome(a-1, a-2, palin);
    }
  }

  if (ispalindrome(temp)) {
    if (temp > palin) {
      palin = temp;
      printf("New palindrome! %lu\n", palin);

      if ((a-1)*(a-2) < palin) {
        return palin;
      } else {
        return largestPalindrome(a-1, a-2, palin);
      }
    }
  }
  
  return largestPalindrome(a, b-1, palin);
}

  
  
