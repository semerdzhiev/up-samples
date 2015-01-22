// quadronocci.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

#define RAND_NUMS

typedef unsigned int uint;

uint arr1[1000];
uint arr2[1000];

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
        arr1[i] = (rand() % 128);
    }
#else
    for (int i=0; i<n; i++) {
		std::cin >> arr1[i];
	}
#endif
	int k = 0;

	for (int i=0; i < n; i++ ) {
		bool prime = true;
		for (int j = 2; j < arr1[i] && prime; j++) {
			if (arr1[i] % j == 0) { 
				prime = false;
			}
		}
		if (prime) { 
			arr2[k++] = arr1[i];
		}
	}

	for (int i=0; i < k; i++) {
		std::cout << arr2[i];
	} while (k--);
}
