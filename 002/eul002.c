#include <stdio.h>

int main() 
{
	int limit = 4000000;
	int a = 1;
	int b = 2;
	int temp = a + b;
	
	int sum = 0;

	while(b < limit)
	{
		if(b % 2 == 0)
		{
			sum = sum + b;
		}
		
		temp = a + b;
		a = b;
		b = temp;
	}
	
	printf("This is the answer: %i\n", sum);

	return 0;
}

