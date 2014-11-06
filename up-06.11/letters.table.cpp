// letters.table.cpp : Defines the entry point for the console application.
//

#ifdef USE_PRECOMPILED_HEADER
#include "stdafx.h"
#endif

#include <cstdlib>

#include <iostream>
#include <iomanip>

int main()  {

	/* alternate approach */

	/*
	for( char cchar  = 'a' ; cchar  <= 'z' ; cchar ++ ) {
//		std::cout << cchar << ' ';
		printf("[%03d] %c ", cchar, cchar);

		if ( ( cchar - 'a' ) % 3 == 2 ) 
			std::cout << '\n';
	} */

	for(int i=0; i < 2; i++){
		for(int j=0; j < 13; j++){
			unsigned short int cdigit = i*13 + j ;
			std::cout << std::setw(2) << cdigit << ' ';
			std::cout << (char)('a' + cdigit) << ' ';
		}
		std::cout << std::endl;
	}

	return 0;
}


