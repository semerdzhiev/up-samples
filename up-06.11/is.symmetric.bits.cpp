// issymmetric.bits.cpp : Defines the entry point for the console application.
//

/* determine whether a number is symmetric in terms of its bits.

i.e. 

1011 1101 is symmetric (8 bit number)

1000 1000 1000 1000 is not symmetric (16 bit number)

assume that we work with 32 bit numbers

*/

#include "stdafx.h"

#include <stdio.h>

int main() 
{
	// create a number for our needs
	
//	unsigned int testme = (1 << 31) + (1 << 28) + (1 << 3) + (1 << 0);
	unsigned int testme = (1 << 31) + (1 << 28) + (1 << 3);

	// initially assume the number is symmetric
	bool isgood = true;

	// create two masks to check the bits 
	unsigned int lmask = ( 1 << 31);
	unsigned int rmask = ( 1 << 0);

	// on each step - check two bits and move the masks 
	// right/left respectively
	do {
		if ( (( testme & lmask ) > 0) != (( testme & rmask ) > 0 )) {
			isgood = false;
		}

		lmask >>= 1;
		rmask <<= 1;
	} while( lmask > ( 1 << 15 ) && isgood );

	printf( isgood ? "symmetric" : "not symmetric" );
	return 0;
}

