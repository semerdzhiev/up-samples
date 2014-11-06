// dig2val.cpp : Defines the entry point for the console application.
//

#ifdef USE_PRECOMPILED_HEADER
#include "stdafx.h"
#endif

int main() {

	char c;
	long long cnum = 0;
	bool minflag = false;

	unsigned mlen = 0;
	unsigned clen = 0;

	do {
		c = getc(stdin);
	
		// count a-z characters, figure out maximum
		if ( c >= 'a' && c <= 'z') {
			clen++;
		} else { 
			mlen = mlen < clen ? clen : mlen;
			clen = 0;
		}

		// find all digits and collect integer decimal values from them
		if ( c >= '0' && c <= '9') {
			cnum = cnum*10 + c - '0';
 		} else if ( c == '-' ) {
			minflag = true;
		}
		// output number whenever a non-digit characters is encountered
		// and the current value in cnum is non-null
		else if (cnum) {
			cnum = minflag ? -1 * cnum : cnum;
			long long int res = cnum * cnum;
			printf("%lld * %lld = %lld \n", 
				cnum, cnum, res); 
			cnum = 0;
			minflag = false;
		}
	} while(c != '\n');

	printf("maximum length of a-z characters: %u", mlen);

	return 0;
}


