// up-13.11-2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <math.h>

/* 

	Иван обича да пише задачи със символни низове. Днес той е решил 
	вместо с цифри да работи само с букви. И така всички величини в
	неговия стандартен вход са последователности от малки букви, които 
	се интерпретират като целочислени велични.

	тоест например

	"abc bbb eee" 

	е запис на величините

	123, 222, 555

	напишете програма, която при така подаден вход намира най-малката
	и най-голямата величина получена от записа на Иван

	abcdefghij
	0123456789

*/

int main() {
	unsigned tmax = 0; // текуща максимална стойност
	unsigned tval = 0; // текуща величина получена от буквите
	char cchar;

	do { 
		cchar = getc(stdin); // четем символ
		if (cchar >= 'a' && cchar <= 'j') {
			tval = tval*10 + cchar - 'a' + 1;
		} else {
			// ако текущата най-голяма величина е по-малка
			// от тъкмо натрупаната стойност -> сменяме я
			if ( tmax < tval ) {
				tmax = tval;
			}
			tval = 0;	// нулираме tval
		}

	} while( cchar != '\n');

	printf("largest value among these: %u - ", tmax);

/*
	for(int i = log10((double)tmax); i >= 0; i--) {
		int cdiv = (int)pow((double)10, i);
		int d = tmax / cdiv;
		tmax = tmax % cdiv;
		putc(d + 'a' - 1, stdout);
	}
*/

	int i = 1;

	while ( i < tmax ) {
		i*=10;
	}

	do { 
		i /= 10;
		int d = tmax / i;
		tmax = tmax % i;
		putc(d + 'a' - 1, stdout);
	} while(i!=1);

	return 0;
}


