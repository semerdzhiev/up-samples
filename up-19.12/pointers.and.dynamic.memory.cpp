// pointers.examples.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

using namespace std;

// void printme(int *a, const size_t count) 

void printme(int a[], const size_t count) {
	for(size_t i=0; i < count;i++) { 
		cout << hex << (a+i)
			<< ':'
			<< dec << *(a + i) << endl;
	}
}

void printme(char a[], const size_t count) {
	for(size_t i=0; i < count;i++) { 
		cout << hex << (unsigned int) (a + i)
			<< ':'
			<< dec << (unsigned int) *(a + i) << endl;
	}
}

void sqareme(int *a, size_t nelems) {
	for(size_t i=0; i < nelems; i++) { 
		a[i] *= a[i];
	}
}

//
// create n x m matrice
// 

// this function takes a reference to 'pointer to pointer to integer'
// thus any assignment to the b variable will effectively change
// the value of the variable provided as parameter to the function
//
// thus the following line in init(): 	
//
//		b = new int*[m];
//
// would effectively mean the same as would
//
//		dynko = new int*[m] 
//
// in the main() function where dynko is prototyped

void init(int ** &b, size_t n, size_t m)  {
	b = new int*[m];

	//
	// in order to have a dynamically allocated array of arrays
	// which is two dimensional array
	// we first allocate a number of [m] pointers to integer
	// and then each of them is assigned with a pointer to [n] integers
	//

	for (size_t i=0; i<m; i++) {
		b[i] = new int[n];
		for (size_t j=0; j<n; j++) { 
			b[i][j] = i * j;
		}
	}
}

int main() 
{
	int **dynko;
	init(dynko, 10, 10);

	// some notes on sizes of variables

	int arr[10];				// sizeof (arr) == 40 
	int *darr = new int [128];	// sizeof (darr) = 4
	char* b = (char*) arr;		// sizeof (b) == 4
	
	// rule of thumb - all pointers have size of (4) in the 32bit 
	// architecture. which is the size of a memory address location

	// init with random numbers
	for (int i=0; i < sizeof(arr) / sizeof(int) ; i++) { 
		arr[i] = rand() % 128;
	}
	
	
	// demonstrate the little-endianess of x86 systems in practice

	printme(arr, 10);
	cout << "---" << endl;
	printme((char*) arr, 10*4);

	char * str = "symbol string";
	char *buf = new char[6];

	cout << str  << endl;
	cout << (str + 7) << endl;
	cout << &str[10] << endl;

	cout << str[5] << endl;
	
	printf("string: %s \n", str);

//	unsigned int uintvar;
//	scanf_s("%u", &uintvar);		// basically the same as cin >> uintvar
//	scanf_s("%s", buf, 1024);		// secure - preffered approach
//	cin >> buf;						// insecure as we may overflow the buff 
	cin.getline(buf, 1024, '\n');	// secure - preffered approach for string input

	return 0;
}

