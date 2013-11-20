#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 1;
	int sum = 0;

	while(i < 1000) 
	{ 
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
			printf("%d\n", i);
		}
		i++;
	}
	printf("The sum is: %d\n", sum);

	return 0;
}



