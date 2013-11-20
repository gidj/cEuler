#include <stdio.h>

int main(int argc, char *argv[])
{
  int limit = 4000000;
  int a = 1;
  int b = 2;
  int temp = a + b;
  int fibgen(int, int, int);

  int sum = 0;
  
  fibgen(1, 2, 1000);
  return 0;
}

int fibgen(int a, int b, int n) {
  printf("%i\n", a);
  printf("%i\n", b);
  int temp = a + b; 
  while(temp <= n)
  {
    printf("%i\n", temp);
    a = b;
    b = temp;
    temp = a + b;
  }
  return 0;
}
