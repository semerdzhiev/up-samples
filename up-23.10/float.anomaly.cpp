// types.cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main() {
	int a = 0; 
	a = 530;

	float b = a * 1.255;

	// правилния начин за сравняване на floating point числа
	if (b - 665.15 < 0.01) { 
		printf ("yeah!");
	}
	int c = b;

	printf("%u", c);
	return 0;
}


