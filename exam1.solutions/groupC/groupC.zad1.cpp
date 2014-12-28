#include "stdafx.h"
#include <iostream>

using namespace std;

typedef unsigned int uint;

// find first n numbers such that the sum of their digits equals k

uint gets( uint n ) {
    int res = 0;

    do {
        res += n % 10;
        n /= 10;
    } while ( n );
    return res;
};

int main()  {
    uint n, k;
	cin >> k >> n;

    uint cnum = 1;
    do {
        if (gets(cnum) == k) {
            cout << cnum << ' ';
            n--;
        }
        cnum++;
    } while(n>0);
}
