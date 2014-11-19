// mul-table.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main () {
	for(unsigned short int rows = 0; rows <= 9; rows++) {
		for ( unsigned short int cols = 0; cols <= 9; cols++ ) {
			if ( rows !=0 && cols !=0) {
				printf("%02d ", rows * cols);
			}
			else { 
				if (rows == 0 && cols != 0 ) 
					printf("%02d ", cols );
				// if we are on the zero column, output the row number
				else if (cols == 0)
					printf("%02d | ", rows );
			}
		}
		
		if ( rows == 0 ) {
			printf("\n-");
			for (unsigned short int j = 0; j <= 9; j++)
				printf("---");
		}
		printf("\n");
	}

	return 0;
}

