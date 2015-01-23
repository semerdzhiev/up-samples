// const.examples.cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <assert.h>

using namespace std;

const int b = 10;

struct tstruct { 
    int a; 
    int b;
};

//  const pointer to const pointer to const reference
void fconst2 (  int * const * const & p ) {
    cout << p;
}

// const reference. cant' change it, but can change the value
void fconst (  tstruct * const p ) {
//    tstruct x; 
    p->a ++;
    // p = &x;	// not possible -> error

}

int main() {
    auto c = 'c';

    // extremely stupid, but possible. memory leak is imminent
    int& a = *(new int[10]);

    // now this is how we can use the array
    int*aa = &a;

    aa[0] = 10;
    aa[1] = 20;

    int *pa = aa;

    // Which will increment the value and not the pointer? 

    // a) *pa++
    // b) *(pa)++
    // c) (*pa++)
    // d) (*pa)++

    *pa++;	// moves the pointer, but not the value

    // also possible, yet.... you know.
    int& b = *(int*)(malloc(10));

    // extremely stupid (also)
    delete &a;

    tstruct p;
    fconst(&p);

    return 0;
}


