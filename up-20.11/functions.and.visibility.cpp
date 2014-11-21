// functions-and-more.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int a = 100;

void mfunc(int a) { 
	printf("step 3 : %d \n", a);
}
int main() {
	// access the global 'a' variable
	// because no other has been defined locally
	printf("step 0 : %d \n", a);

	// define a variable named a locally
	int a = 10;

	// int a = 10;	// would produce and error
	
	// print the local var
	printf("step 1 : %d \n", a);

	{ 
		// define another locally scoped var
		int a = 20;
		printf("step 2 : %d \n", a);

	}

	// pass as argument
	mfunc(a);

	return 0;
}
