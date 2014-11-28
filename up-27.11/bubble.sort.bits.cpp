// sort.bits.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <iostream>

unsigned char nums[] =  {64, 55, 46, 24, 13, 114, 211, 212};

int numbits(unsigned char a) {
	int res = 0;

	do { 
		if ( a & 1 ) {
			res ++;
		}
		a = a >> 1; // a /= 2
	} while( a );

	return res;
}

void asbin(unsigned char a) { 
	for (int i = 7; i >= 0; i--)
	{
		int mask = 1 << i;
		std::cout << ( a & mask )  ? 1 : 0;
	}
}

void printall() {
	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++ ) {
		asbin(nums[i]);
		std::cout << '(' << numbits(nums[i]) << ')' << std::endl;
	}

	std::cout << std::endl;
}

void swap(int i, int j) {
	int t = nums[j];
	nums [j] = nums [i];
	nums [i] = t;

}

int main() {
	printall();

	bool change;

	do { 
		change = false;

		for (int i = 0; i < sizeof(nums) / sizeof(nums[0]) - 1; i++ )
		{
			if (numbits(nums[i]) > numbits(nums [i+1]))
			{
				swap(i, i+ 1);
				change = true;
			}
		}

	} while (change);

	printall();
	return 0;
}


