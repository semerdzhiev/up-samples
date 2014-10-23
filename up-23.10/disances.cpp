// up-23.10-2.cpp : Defines the entry point for the console application.
//
\
#include "stdafx.h"
#include <math.h>

/* 

	d   Signed integer								-20
	u	Unsigned decimal integer					7235
	x	Unsigned hexadecimal integer				7fa
	X	Unsigned hexadecimal integer (uppercase)	7FA
	f	Decimal floating point, lowercase			392.65
	c	Character									a
	s	String of characters						sample

	\n	- new line
	\t	- tab

*/

#include <iostream>
using namespace std;

int main() {
	/*
	float x1, y1;
	float x2, y2;

	printf("please enter coordinates for point A: ");
	scanf_s("%f", &x1);
	scanf_s("%f", &y1);

//	x1 = 2;
//	y1 = 1.5;
	x2 = 3;
	y2 = -2;

	printf("distance between A(%.2f, %.2f) and B(%.2f, %.2f) = %.5f",
		x1, y1, x2, y2,
		sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
	);
	*/
	
	float x1 = 0;
	float y1 = 0;

	float res = 0;

	float xnew, ynew;
	
	do { 
		printf("please enter coordinates for next point: ");
		scanf_s("%f", &xnew);
		scanf_s("%f", &ynew);

		float d = sqrt((x1 - xnew) * (x1 - xnew) + (y1 - ynew) * (y1 - ynew));
		printf("distance from previous point : %f \n", d);   

		res = res + d;

		x1 = xnew;
		y1 = ynew;
	} while( (xnew < 0 || xnew > 0 ) && ( ynew < 0 || ynew > 0 ) );

	printf("the total length is : %.5f", res ); 

	return 0;
}
