// bubble.sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

typedef char etype;
typedef unsigned int uint;

// list
// array

// int arr[] = {6,7,8,2,1,3};
etype arr[] = {'C', 'd', 'X', 'a', 'b', 'Y', 'G' };

int nelems = sizeof(arr) / sizeof(arr[0]);

void printme() {
	for (int i=0; i < nelems; i++) {
		// printf("arr[%d] = %d", i, arr[i]);
		std::cout << "arr[" << i << "] = " << arr[i];
		if ( i < nelems - 1) {
//			printf(", ");
			std::cout << ", ";
		}
	}

	std::cout << std::endl;
}

void swap(unsigned int ai, unsigned int aj) { 
	etype t = arr[aj];
	arr[aj] = arr[ai];
	arr[ai] = t;
}

bool isgood(unsigned int ai, unsigned int aj) { 
	etype a = arr[ai];
	etype b = arr[aj];

	if ( a >= 'a' && a <= 'z') {
		a = a -'a' + 'A';
	}

	if ( b >= 'a' && b <= 'z') {
		b = b - 'a' + 'A';
	}

	return a > b;
}

int main() {
	// get number of elements
	bool ischanged;

	printme();

	do { 
		ischanged = false;
		// check array for inconsistent elements;
		for( unsigned int i=0; i < nelems - 1; i++) {
			if ( isgood(i, i+1) ) { 
				swap(i, i+1);
				ischanged = true;
			}
		}
		// print the array
		printme();
	} while(ischanged);

	return 0;
}


