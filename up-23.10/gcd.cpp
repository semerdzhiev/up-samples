// gcd.cpp : Defines the entry point for the console application.
//



#ifdef USE_PRECOMPILED_HEADER
#include "stdafx.h"
#endif

// http://upload.wikimedia.org/wikipedia/commons/3/37/Euclid%27s_algorithm_Book_VII_Proposition_2_3.png

int main() {
    int a, b;

    scanf_s("%d %d", &a, &b);

    if (a == 0) {
    	printf("%d", b);
		return 0;
    } 

	if (b == 0) {
    	printf("%d", a);
		return 0;
    } 

	// : disambiguation : 
	// || - logical or
	// && - logical and
	// | - bitwise or
	// & - bitwise and

    while (b != 0 && b != a) {
    	printf("a: %d b: %d \n", a, b);

//		we can express the loop as modulo 
//		if ( a > b ) a = a % b; 
    	while (a > b) {
    		a = a - b;
    	}

//		we can express the loop as modulo 
//		else b = b % a; 
    	while (b > a) {
    		b = b - a;
    	}
    }

   	printf("GCD : %d", a);
	return 0;
}

