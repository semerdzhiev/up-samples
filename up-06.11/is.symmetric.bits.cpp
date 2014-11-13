// issymmetric.bits.cpp : Defines the entry point for the console application.
//

#ifdef USE_PRECOMPILED_HEADER
#include "stdafx.h"
#endif

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

