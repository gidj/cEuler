#include <stdio.h>

long long unsigned n_choose_r(long, long);
long long unsigned new_choose_r(long, long);
long long unsigned factorial(long);


int main(int argc, char *argv[])
{
  /* The key insight to this problem is to recognize that the number of paths
   * to any paricular node is the sum of the paths that go to its parent nodes.
   * Since each node can be reached by only two parents in a square matrix,
   * this problem maps directly to Pascal's triangle. Therefore solving the 
   * problem is a matter of generating the appropriate point in the triangle.
   * 
   * Any arbitrary element of Pascal's triangle can be generated directly 
   * by x choose y, where x is the row and y is the index of the element
   * in that row. */

  for (int i = 0; i < 30; ++i)
  {
    printf("%llu\n", factorial(i));
  }

  printf("5 choose 3: %llu\n", n_choose_r(5, 3));
  printf("5 choose 3, new: %llu\n", new_choose_r(5, 3));
  printf("9 choose 3: %llu\n", n_choose_r(9, 3));
  printf("9 choose 3, new: %llu\n", new_choose_r(9, 3));
  printf("15 choose 3: %llu\n", n_choose_r(15, 3));
  printf("15 choose 3, new: %llu\n", new_choose_r(15, 3));
  printf("This is the nunber of paths: %llu\n", new_choose_r(38, 19));
  return 0;
}

long long unsigned factorial(long n)
{
  if (n <= 0) { return 1; }
  long long unsigned result = n;
  while(--n > 1) { result *= n; }
  return result;
}

long long unsigned n_choose_r(long n, long r)
{
  return (factorial(n) / ((factorial(r) * factorial(n - r))));
}

long long unsigned new_choose_r(long n, long r)
{
  long long unsigned numer = 1;
  long long unsigned denom = factorial(n - r);

  while(n > r) {
    numer *= n--;
  }

  printf("Numer: %llu / Denom: %llu\n", numer, denom);
  return (numer / denom);
}

