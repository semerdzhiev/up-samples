// quadronocci.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

typedef unsigned int uint;

/*

 determine whether sequence of N elements, such that

 - every even element is a factor of 2
 - every Kth element a factor of k

 we assume that elements start with index 1, so that 
 we avoid division by zero
 
 INPUT:
 5 
 2 2 6 8 10
 OUTPUT:
 YES

 INPUT:
 5 
 3 4 12 4 5
 OUTPUT:
 YES

*/

int main() {
	uint n = 0, cpos = 1;
	bool even = false;
	bool goodseq = true;
	std::cin >> n;
	do {
		uint num;
 		std::cin >> num;
		if ( (even && num & 1) ||
			(cpos && num % cpos) ) {
			goodseq = false;
		}

		even = !even;
	} while (++cpos <= n && goodseq);

	std::cout << (goodseq ? "YES" : "NO");
	return 0;
}

