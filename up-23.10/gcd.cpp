// gcd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// http://upload.wikimedia.org/wikipedia/commons/3/37/Euclid%27s_algorithm_Book_VII_Proposition_2_3.png

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


