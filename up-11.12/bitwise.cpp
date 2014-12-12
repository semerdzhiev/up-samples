// bitwise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

const unsigned int INT_BIT_SIZE = sizeof(unsigned int) * 8;

unsigned int v = (1 << 31) + ( 1 << 24 ) + (1 << 15) + (1 << 8) + (1 << 3);

//
// 2^10 + 2 ^ 3
// sizeof(unsigned int) == 32 bits == 4 bytes

char str[] = " asdf asd asf ";

char brep[INT_BIT_SIZE  + 1];

int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int bpos = 0;
	unsigned int cnt = 0;
	unsigned int mask = 1 << (INT_BIT_SIZE - 1);
	do { 
		if (v & mask) {
			cnt++;
			brep[bpos] = '1';
		} else {
			brep[bpos] = '0';
		}

		bpos++;
		mask >>= 1;
	} while (mask);

	brep[INT_BIT_SIZE] = 0; // null terminate

	printf("\n bprep : %s", brep);
//  cout << brep;

	printf("\n binary : ");

	for (int i=0; i<INT_BIT_SIZE; i++) {
		if ( i % 4 == 0 ) {
			printf (" ");
		}
		printf("%c", brep[i]);
	}

	printf("\n number of bits in %u is:  %u \n", cnt);

	return 0;
}

