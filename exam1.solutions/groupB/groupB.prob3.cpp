// quadronocci.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <time.h>

typedef unsigned int uint;

uint ary[1000];

// for input sequence of N numbers, find the sum of the 
// smallest K numbers. the program inputs N, K and then
// N integers

/* 

INPUT
    4 6
    10 20 1 500 60 700
OUTPUT
    91

*/

int main() {
    int sum = 0;
    uint n, k, spos = 0;
    uint numcount = sizeof(ary) / sizeof(int);

    std::cin >> k >> n;

    if ( k > n ) {    // bad input
        return 0;
    }

    // you can enable RAND_NUMS for tests with large 
    // arrays of randomly generated integers in the
    // [0..1000] range

#ifdef RAND_NUMS
    // just fill this array with random data, 
    // so that we don't have to input 100 numbers
    srand(time(NULL));
    for (int i=0; i<n; i++) {
        ary[i] = (rand() % 1000);
    }
#else
    for (int i=0; i<n; i++) {
        std::cin >> ary[i];
    }
#endif
    
    // do selection sort as we assume K is lot smaller than N
    do {
        for (int i = spos; i < n; i++ ) {
            if (ary[i] < ary[spos]) {
                int t = ary[spos];
                ary[spos] = ary[i];
                ary[i] = t;
            }
        }

        sum += ary[spos++];
    } while (spos < k);

    std::cout << sum;
}

