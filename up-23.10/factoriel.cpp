// up-10.24.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// #include <iostream>			// алтернативен изход
// using namespace std;

int main() {
	unsigned long long int res = 1;
//	long double res = 1;				// лоша идея
	unsigned char c = 1;
	do { 
		printf("%d! %llu \n", c, res);
//		printf("%d! %Lf \n", c, res);	// лоша идея
		c = c + 1;
		res = res * c;
/*		cout << '!' << (int) c			// алтернатива за извеждане
			<< " = " << res << endl; */
	} while( c < 20 );

	return 0;
}
