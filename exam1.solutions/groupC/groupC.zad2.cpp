#include "stdafx.h"
#include <iostream>

using namespace std;

typedef unsigned int uint;

uint gets(uint n) {
    int res = 0;

    do {
        res += n % 10;
        n /= 10;
    } while ( n );
    return res;
};

// find first n numbers such that the sum of their digits
// equals k and print them 

uint arr[1000];

int main() {
    uint n, pos = 0;
    cin >> n;

    uint cnum = 1;

    do {
        if (gets(cnum) == 5) {
            arr[pos++] = cnum;
            n--;
        }
        cnum++;
    } while(n);

    for (int i=0; i<pos; i++) {
    	std::cout << arr[i] << ' ';
    }
}

