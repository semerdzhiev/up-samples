
#include <stdio.h>

/*

	find all integer values in some string read from stdin.
	and all characters as consequent numbers in the alphabet

	for example in 

		1023 asd 9023 sd 91

	we want the digits to be interpreted as numbers 
	and characters to be interpreted as values denoting
	their position in the alphabet

	thus 

	"1023" should be interpreted as 1023
	"b" should be interpreted as 2

	so in this example we wantg

	numTotal = 1023 + 9023 + 91
	charTotal = 1 * ... * 4

	*/

	int main() {
	unsigned long numTotal = 0;
	unsigned long charTotal = 0;
	
	char pc = 0;	// previous char
	char cc;		// current char

	unsigned long tval = 0;

	do {
 		cc = getc(stdin);
//		cin >> cc;
//		scanf_s("%c", &c);

		if ( cc >= '0' && cc <= '9' ) {
			tval = tval * 10 + cc - '0';
		} else { 
			numTotal += tval;
			tval = 0;
		}

		unsigned char cnext = 0; 

		if ( cc >= 'a' && cc <= 'z' ) {
			cnext = cc - 'a' + 1;
		}

		if ( cc >= 'A' && cc <= 'Z' ) {
			cnext = cc - 'A' + 1;
		}

		if  ( cnext ) {
			if ( charTotal ) {
				charTotal *= cnext;
			} else {			
 				charTotal = cnext;
			}
		}
	} while(cc != '\n');

	printf("numbers total : %lu \n", numTotal);
	printf("chars total : %lu \n", charTotal);
}
