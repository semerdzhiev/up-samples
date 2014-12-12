// nums.array.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

int ary[1000];

int main() {
	srand(time(NULL));

	int sum = 0;
	int cnum = 0;

	int numcount = sizeof(ary) / sizeof(int);

	// generate numbers, so that the beginning of the sequence
	// has lower values, and the end - higher 

	for (int i=0; i<numcount; i++) {
		ary[i] = (rand() % 1000) * i/numcount;
	}
	
	// clear all elements of the sequence, that 
	// are lower than the sum of the preciding elements 

	do {
		if (ary[cnum] < sum) {
//			memcpy(&ary[cnum], &ary[cnum+1], ( sizeof (int) )* (numcount-cnum-1));
//			memcpy(ary + cnum, ary + cnum + 1, ( sizeof (int) )* (numcount-cnum-1));
			for (int i=cnum; i <numcount-1; i++) { 
				ary[i] = ary[i+1];
			}
			numcount--;
			ary[numcount] = 0;
		} else { 
			sum += ary[cnum];
			cnum ++;
		}
	} while (cnum < numcount);

	return 0;
}

