// strfuncs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdlib.h>
#include <stdio.h>
#include <cstring>
#include <string.h>

char** slist;

void read() { 
	slist = (char**) calloc(5, sizeof(char*));

	for (int i =0; i<5; i++ ) {
		slist[i] = (char*) malloc(128);
		fgets(slist[i], 128, stdin);

		// the following are essentially the same, some need C++ :
		//
		// gets_s(slist[i], 128);
		// scanf_s("%[^\n]s", slist[i], 128); getc(stdin);
		// cin.getline(slist[i], 128, '\n');	
	}
}

void swap(char* &a, char* &b) {
	char *help = a;
	a = b; 
	b = help;
}

void sort() {
	bool f = false;

	char a[128];
	char b[128];

	do { 
		f = false;
		for(int i=0; i<4; i++) {
			memcpy(a, slist[i], strlen(slist[i]));
			memcpy(b, slist[i+1], strlen(slist[i]));

#ifdef __GNUC__
			strlwr(a); 
			strlwr(b);
#else
			_strlwr_s(a, 128);
			_strlwr_s(b, 128);
#endif 

			if ( strcmp(a, b) > 0 ) {
				swap(slist[i], slist[i+1]); 
				f = true;
			}
		}

	} while(f);
}

void print() { 
	for (int i =0; i<5; i++ ) {
		printf("slist[%d] = %s \n", i, slist[i]);
	}
}

void free() { 
	for (int i =0; i<5; i++ ) {
		free(slist[i]);
	}

	free(slist);
}

// comparator when using qsort

int comparator(const void* astr, const void* bstr) {
	char a[128];
	char b[128];

	memcpy(a, astr, strlen((char*) astr) );
	memcpy(b, astr, strlen((char*) astr) );

#ifdef __GNUC__
	strlwr(a);
	strlwr(b);
#else
	_strlwr_s(a, 128);
	_strlwr_s(b, 128);
#endif
	return strcmp(a, b);
}

int main()  {

	read();
	sort();
//
// another possible apporach with quicksort
// needs the comparator function above
//	qsort(slist, 5, sizeof(slist[0]), &comparator);

	print();
	free();

}

