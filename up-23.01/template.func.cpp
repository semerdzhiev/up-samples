// const.examples.cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <assert.h>

using namespace std;

template <class ttype> 
ttype** dim(const int n, const int m) { 
    ttype** newary = new ttype*[n];

    try { 
    	for (auto i=0; i < n; i++) {
    		newary[i] = new ttype[m];
    		assert(newary[i] != NULL);	// make sure allocation of memory worked
    	}
    } catch(int e) {
    	cout << "something went wrong allocating memory for array";
    }

    return newary;
}


int main() {
    // example usage of the template function
    int** ary = dim<int> (10, 20);
    char** ary2 = dim<char> (10, 20);

    return 0;
}


