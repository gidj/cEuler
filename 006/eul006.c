#include <stdio.h>
#include <stdlib.h>

typedef int long unsigned bigInt;
bigInt sum(bigInt, bigInt);
bigInt square(bigInt);
bigInt sumSquare(bigInt, bigInt);


int main(int argc, char *argv[]) {

  bigInt simsum, sqrsum, result, top, bottom;
  bottom = 1;
  top = 100;
  simsum = sum(bottom, top);
  sqrsum = sumSquare(bottom, top);

  result = square(simsum) - sqrsum;

  printf("This is the of %lu - %lu: %lu\n", square(simsum), sqrsum, result);

}

bigInt sum(bigInt first, bigInt last) {

  bigInt total = 0;

  for (first; first < last+1; first++)
  {
    total = total + first;
  }

  return total;
}


bigInt sumSquare(bigInt first, bigInt last) {

  bigInt total = 0;

  for (first; first < last+1; first++)
  {
    total = total + square(first);
  }
 
  return total;
}

bigInt square(bigInt num) {
  return num * num;
}
