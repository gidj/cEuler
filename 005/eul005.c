#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[])
{
  int unsigned long high = 20;
  int unsigned long gcd(int unsigned long, int unsigned long);

  if (argc == 2)
  {
    high = strtol(argv[1], (char **)NULL, 10);
  }

  int unsigned long lcm = 1;
  int unsigned long i;
  for (i = 1; i <= high; ++i)
  {
    lcm = (lcm * i) / gcd(lcm, i);
  }

  printf("This is the least common multiple: %lu\n", lcm);

  return 0;
}

int unsigned long gcd(int unsigned long a, int unsigned long b) {
  if (b == 0)
  {
    return a;
  } else if (a > b) {
    return gcd(b, a%b);
  } else {
    return gcd(a, b%a);
  }

}
