// gcd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main() {
	int a, b;

	scanf_s("%d %d", &a, &b);

	if (a == 0) {
		printf("%d", b);
	} else {
		while (b != 0 && b != a) {
			printf("a: %d b: %d \n", a, b);

			while (a > b) {
				a = a - b;
			} 

			while (b > a) {
				b = b - a;
			}
		}
		printf("%d", a);
	}
}


