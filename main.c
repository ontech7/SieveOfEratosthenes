#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Ancient algorithm to calculate prime numbers within a certain "size" */
void SieveOfEratosthenes(unsigned int size)
{
	int p;
	int* prime = (int*)malloc((size+1) * sizeof(int));
	memset(prime, 1, sizeof(prime));

	for (p = 2; p*p < (size+1); p++)
	{
		/* If it's not removed (assign to 0), then it's a prime number */
		if (prime[p])
		{
			/* "Remove" all multiplies */
			for (int i = p * 2; i < (size+1); i += p)
				prime[i] = 0;
		}
	}

	/* If it's a prime number, then print it */
	for (p = 2; p < (size+1); p++)
		if (prime[p])
			printf("%i ", p);
}

int main()
{
	SieveOfEratosthenes(50);

	/* Output: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 */
	
	return 0;
}
