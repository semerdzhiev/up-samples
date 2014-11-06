//

#include <stdio.h>

using namespace std;

int primes[100];

// 0, 1, 2, 3, .... 9 

int main() {
	int counter = 0;
	unsigned long mynum = 2*2*3*3*5;

	for(int i = 2; i <= mynum; i++){
		while(mynum % i == 0) {
			primes[counter] = i;
			counter++;
			mynum /= i;
		}
	}

	for (int c = 0; primes[c]; c++ ) {
		printf("%u ", primes[c]);
	}
}

