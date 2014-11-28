// temp.bubble.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//            0   1  2  3  4   5   5+1
int arr[] = { 10, 5, 3, 6, 11, 22, 98 };

bool cond(int a, int b) { 
	return a > b;
}

void swap(int i, int j) { 
	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}

int main() {
	int N = sizeof(arr) / sizeof(arr[0]) - 1;

	for (int i = 0; i < N; i++ ) {
		int cext = arr[i]; // " най-екстремалния "
		int epos = i; 

		for ( int j = i + 1; j < N; j++ ) { 
			if ( cond( cext, arr[j] ) ) {
				cext = arr[j];
				epos = j;
			}
		}
		
		if ( i != epos) { 
			swap(i, epos);
		}
	}

	return 0;
}

