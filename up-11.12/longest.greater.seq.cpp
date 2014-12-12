// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/* 

task: among numbers fread from standard input, 
find the size of the longest sequence of numbers greater than 128 

i.e. in 

3 56  21 34 75 3 424 111 9 128 128 128 23 7457 456 342 5435 4 4 

the longest sequence has length 4

*/

#include "stdafx.h"

#include <iostream>;
using namespace std;

int main()  {
	int nmax = 0;
	int cmax = 0;
	int num;

	do { 
		cin >> num;
		
		if (num > 128) { 
			cmax ++;
		} else { 
			if ( cmax > nmax ) {
				nmax = cmax;
				cmax = 0;
			}
		}
	} while (num);

	cout << "longest seq. of numbers greater than 128 has length : " << nmax;

	return 0;
}


