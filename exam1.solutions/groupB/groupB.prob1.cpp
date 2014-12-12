// quadronocci.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

typedef unsigned int uint;

int main() {
        uint a1, a2, a3;
        uint n;

        std::cin >> a1 >> a2 >> a3 >> n;

        do {
                int an = ( a1 + a2 + a3 );
                a1 = a2; a2 = a3; a3 = an;
        } while (--n > 3);

        std::cout << a3;

        return 0;
}



