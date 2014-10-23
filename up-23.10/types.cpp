// up-23.10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main() {

	// a0 = 1.5
	// d = 2.5

	float a0 = 1.532;
	float d = 2.5343;	// грешно....
	float res = a0;

//	unsigned char c = 0;

/* 

	d   Signed integer								-20
	u	Unsigned decimal integer					7235
	x	Unsigned hexadecimal integer				7fa
	X	Unsigned hexadecimal integer (uppercase)	7FA
	f	Decimal floating point, lowercase			392.65
	c	Character									a
	s	String of characters						sample

	\n	- new line
	\t	- tab

*/
	unsigned char c=0;

	do { 
		// intermediate - непосредствен
		// intermediate value - непосредствена (текуща) стойност

		printf("a[%2d] = %2.5f \n", c, res);
		res = res + d;
		c = c + 1;
	} while (c < 15);

	// sizeof(char) == sizeof(unsigned char) == 1
	// char -> -127 ... 127
	// unsigned char -> 0...255

	return 0;
}
