// quadronocci.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

#define RAND_NUMS

typedef unsigned int uint;

uint arr1[1000];
uint arr2[1000];
uint pcache[170];

// based on the Prime Number theorem, there are less than 170 primes
// in the 1..1000 range

// in this solution we introduce a cache to keep primes that area
// already known, thus avoiding having to calculate all cached numbers
// beforehand


int main() {
    int sum = 0;
    uint n;

	std::cin >> n;

	if ( n > 1000 ) {	// bad input
		return 0;
	}

	// you can enable RAND_NUMS for tests with large 
	// arrays of randomly generated integers in the
	// [0..1000] range

#ifdef RAND_NUMS
    // just fill this array with random data, 
	// so that we don't have to input 100 numbers
    srand(time(NULL));
    for (int i=0; i<n; i++) {
        arr1[i] = (rand() % 1000);
    }
#else
    for (int i=0; i<n; i++) {
		std::cin >> arr1[i];
	}
#endif
	int k = 0;
	int pcount = 0;
	// do selection sort as we assume K is lot smaller than N
	for (int i=0; i < n; i++ ) {
		bool prime = true;

		// first check if this number can be divided by 
		// an already known prime factor
		for (int p = 0; p < pcount && prime; p++) {
			if (arr1[i] % pcache[p] == 0) {
				prime = false;
			}
		}

		for (int j = 2; j < arr1[i] && prime; j++) {
			if (arr1[i] % j == 0) { 
				prime = false;

				// we found a prime. good - add it to the cache
				//
				pcache[pcount++] = j;
			}
		}

		if (prime) { 
			arr2[k++] = arr1[i];
			pcache[pcount++] = arr1[i];
		}
	}

	for (int i=0; i < k; i++) {
		std::cout << arr2[i] << std::endl;
	} while (k--);
}
