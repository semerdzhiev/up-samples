// multiply.large.cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

typedef unsigned char dtype;	// digit type

const int MDIGITS = 80;

void initlnum(dtype* &lnum);
void initlnum(dtype** lnum);

void mulx(dtype *lnum, dtype x) {
	dtype c = 0;
	
	assert(x < 10);

	for(int i=MDIGITS-1; i>=0; i--) {
		assert(lnum[i] < 10);

		int nval = ( lnum[i] * x ) % 10 + c;
		c = ( lnum[i] * x ) / 10;
		lnum[i] = nval;
	}
};

dtype* add(dtype *lnum, dtype *lnum2 ) {
	dtype* res = new dtype[MDIGITS];
	dtype c = 0;

	initlnum(res);

	for(int i=MDIGITS-1; i>=0; i--) {
		assert(lnum[i] < 10);
		assert(lnum2[i] < 10);

		res[i] = ( lnum[i] + lnum2[i] ) % 10 + c;
		c = ( lnum[i] + lnum2[i] ) / 10;
	}

	return res;
};


void plnum(dtype *lnum) { 
	for (int i=0; i < MDIGITS; i++) {
		assert(lnum[i] < 10);
		printf("%u", lnum[i]); 
	}
}

void initlnum(dtype* &lnum) { 
	lnum = new unsigned char[MDIGITS];
	memset(lnum, 0, MDIGITS);
}

void initlnum(dtype** lnum) { 
	*lnum = new unsigned char[MDIGITS];
	memset(*lnum, 0, MDIGITS);
}

int main() {
	dtype* lnum;
	dtype* ladd;

	initlnum(lnum);
	initlnum(ladd);

	lnum[MDIGITS-1] = 2;		// числото 0000000000000082
	lnum[MDIGITS-2] = 8;

	ladd[MDIGITS-1] = 2;		// числото 0000000000000082
	ladd[MDIGITS-2] = 8;

	plnum(lnum);

	mulx(lnum, 2);
	plnum(lnum);

	mulx(lnum, 3);
	plnum(lnum);

	plnum(add(lnum, ladd));

	return 0;
}


