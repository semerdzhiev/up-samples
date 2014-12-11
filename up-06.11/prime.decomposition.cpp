//

/* print the decomposition of a number to it's prime factors */


#include "stdafx.h"
#include <stdio.h>

using namespace std;

int primes[100];

int main() {
	int counter = 0;
	unsigned long mynum = 2*2*3*3*5;
	int i = 2;

	// while modulo of the number by some divisor 
	// gives zero -> note this divisor of prime factor
	// of the number
	// divide the number and continue as long as
	// the current divisor is less than the number

	do {
		while(mynum % i == 0) {
			primes[counter] = i;
			counter++;
			mynum /= i;
		}

		i++;

	} while (i <= mynum);

	for (int c = 0; primes[c]; c++ ) {
		printf("%u ", primes[c]);
	}
}

