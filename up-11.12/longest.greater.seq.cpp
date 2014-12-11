// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>;
using namespace std;

bool cond(int num) {
	return num > 128;
}

int main()  {
	int nmax = 0;
	int cmax = 0;
	int num;

	do { 
		cin >> num;
		
		// if current number meets condition
		if (cond(num)) { 
			cmax ++;
		} else { 
			if (cmax > nmax) {
				nmax = cmax;
				cmax = 0;
			}
		}
	} while (num);

	cout << "longest seq. of numbers greater than 128 has length : " << nmax;

	return 0;
}


