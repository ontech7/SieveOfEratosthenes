#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define boolean char
#define TRUE 1
#define FALSE 0

/* Ancient algorithm to calculate prime numbers within a certain "size" */
void SieveOfEratosthenes(unsigned int nSize)
{
	int p, i;
	boolean* bPrime = (boolean*)malloc((nSize+1) * sizeof(boolean));
	memset(prime, TRUE, sizeof(bPrime));
	
	/* Starting from 2; p^2 is less or equal than nSize; p++ */
	for (p = 2; p*p < (nSize+1); p++)
	{
		/* If it's not removed (assigned to FALSE), then it's a prime number (assigned to TRUE) */
		if (bPrime[p])
		{
			/* Unset all multiples */
			for (i = p * 2; i < (nSize+1); i += p)
				bPrime[i] = FALSE;
		}
	}

	/* If it's a prime number, then print it */
	for (p = 2; p < (nSize+1); p++)
		if (bPrime[p])
			printf("%i ", p);
}

int main()
{
	SieveOfEratosthenes(50);

	/* Output: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 */
	
	return 0;
}
