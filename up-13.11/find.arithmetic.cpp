// find.arithmetic.cpp : Defines the entry point for the console application.
//

/* 

	Задача:

	Да се намери най-дългата аритметична прогресия измежду INT_MAX >> 4 числа, 
	генерирани от генератор на случайни числа в интервала 0..64 и да се изведе

*/

#include "stdafx.h"

#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

#define uint unsigned int

const int RMAX = 64;
const int NUMTOTAL = INT_MAX >> 4;

int main() {
	srand (time(NULL));

	uint pelem = 0;		// previous element

	uint first = pelem = rand() % RMAX;
	int cdiff = 0;		// current difference
	uint cplen = 1;		// length of current progression 

	uint bestplen = 0;
	int bestdiff = cdiff;
	uint bestfirst;

	for ( uint cnt = 0; cnt <= NUMTOTAL; cnt++ ) {
		uint celem = rand() % RMAX;
		if ( cnt % (1 << 17) == 0 ) 
			printf(".");

		if ( celem - pelem == cdiff ) { 
			cplen++;
		} else { 
			if ( cplen > bestplen ) {
				bestplen = cplen;
				bestdiff = cdiff;
				bestfirst = first;
			}

			cplen = 2;
			cdiff = pelem - celem;
			first = pelem;
		}

		pelem = celem;
	}

	printf("\n sequence found: ");
	
	for ( int i = bestfirst; i < bestfirst + bestdiff * bestplen; i += bestdiff ) { 
		printf ("%d, ", i);
	}

	return 0;
}

