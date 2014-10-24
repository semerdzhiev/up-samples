// up-23.10-2.cpp : Defines the entry point for the console application.
//
\
#include "stdafx.h"
#include <math.h>

/* 

       printf format characters : 

    d   Signed integer					-20
    u	Unsigned decimal integer			7235
    x	Unsigned hexadecimal integer			7fa
    X	Unsigned hexadecimal integer (uppercase)	7FA
    f	Decimal floating point, lowercase		392.65
    c	Character					a
    s	String of characters				sample

    lld	- long long decimal				2^63
    Lf	- long float (i.e. double)

    escaped characters :

    \n	- new line
    \t	- tab

*/

int main() {
/*

//    пример за намиране на координати м/у две точки 
     
    float x1, y1;
    float x2, y2;

    x1 = 2;
    y1 = 1.5;
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
    //	scanf_s и printf_s са 'secure' версиите на printf/scanf
    //	които са предпочитани от Visual Studio
    //	разликата с printf/scanf е несъществена в контекста на този курс
    
    	printf_s("please enter coordinates for next point: ");
    	scanf_s("%f", &xnew);
    	scanf_s("%f", &ynew);

    	float d = sqrt((x1 - xnew) * (x1 - xnew) + (y1 - ynew) * (y1 - ynew));

    //	а може и така : 
    //	float d = sqrt(pow(x1-xnew, 2) + pow(y1-ynew, 2);
    //
    	printf("distance from previous point : %f \n", d);   

    	res += d;

    	x1 = xnew;
    	y1 = ynew;
    } while( (xnew < 0 || xnew > 0 ) && ( ynew < 0 || ynew > 0 ) );
    // може и while (abs(xnew) > 0 && abs(ynew) > 0 ) 
    
    printf("the total length is : %.5f", res ); 

    return 0;
}
