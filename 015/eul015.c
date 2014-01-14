#include <stdio.h>
#include <limits.h>

long long unsigned n_choose_r(long, long);
long long unsigned new_choose_r(long, long);
long long unsigned factorial(long);
long long unsigned lattice_value(long long unsigned a[][40], long, long);


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

  
  long long unsigned array[40][40] = {0};

  printf("Let's try 2, 2 (should be 6): %llu\n", lattice_value(array, 2, 2));
  printf("Let's try 3, 3 (should be 20): %llu\n", lattice_value(array, 3, 3));
  printf("Let's try 3, 4 (should be 35): %llu\n", lattice_value(array, 3, 4));
  printf("Let's try 20, 20 (should be the answer): %llu\n", lattice_value(array, 20, 20));







  for (int i = 0; i < 30; ++i)
  {
    printf("%llu\n", factorial(i));
  }

  printf("long long unsiged max: %llu\n", ULLONG_MAX);

  printf("5 choose 3: %llu\n", n_choose_r(5, 3));
  printf("5 choose 3, new: %llu\n", new_choose_r(5, 3));
  printf("9 choose 3: %llu\n", n_choose_r(9, 3));
  printf("9 choose 3, new: %llu\n", new_choose_r(9, 3));
  printf("15 choose 3: %llu\n", n_choose_r(15, 3));
  printf("15 choose 3, new: %llu\n", new_choose_r(15, 3));
  printf("This is the nunber of paths: %llu\n", new_choose_r(38, 19));
  return 0;
}

long long unsigned lattice_value(long long unsigned a[][40], long x, long y)
{
  if (a[x][y] > 0)
  {
    return a[x][y];
  }
  else if (x == 0 || y == 0)
  {
    a[x][y] = 1;
    a[y][x] = 1;
    return 1;
  }
  else
  {
    a[x][y] = lattice_value(a, x, y-1) + lattice_value(a, x-1, y);
    a[y][x] = a[x][y];
    return a[x][y];
  }
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

