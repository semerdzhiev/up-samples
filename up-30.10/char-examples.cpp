// char-first.cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// #include <iostream>
// using namespace std;

int main() {
	unsigned char c;

//  example capitalization
//	c = 'x';
//	c = c - 'a' + 'A';

	printf("new char : [%c] \n", c); 

	do { 
//		we can input using scanf_s and designate reading of single char
//		scanf_s("%c", &c, 1);
//		or we can use cin 
//		cin >> c
//		but we can also say 'read one char from stdin' like :
		c = getc(stdin);

//		in either case - the result is returned as soon as enter/newline
//		is pressed on the keyboard

//		if the character is a small latin letter
		if (c > 'a' && c < 'z') {
//		 ...capitalize
			c = c - 'a' + 'A';
		}

//		we can also express the above 'if' like this:
/*		c = (c > 'a' && c < 'z')
				?	( c - 'a' + 'A' ) 
				:	c; */

		putc(c, stdout);
//		printf("%c", c);
	} while (c != '\n');

// now let's print the alphabet and the corresponding character codes

	for ( unsigned int i = 'A'; i <= 'Z'; i++ ) { 
		printf("[ %d ] [ %c ] \t", i, i);
	}

	return 0;
}

