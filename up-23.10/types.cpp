// types.cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int main() {
    int a = 0; 
    a = 530;

    // тук автоматично a ще бъде cast-нат (обърнат) до тип float
    float b = a * 1.255;

    // правилния начин за сравняване на floating point числа
    // проверяваме дали са в някаква област спрямо търсената стойност
    if (b - 665.15 < 0.01) { 
    	printf ("yeah!");
    }

    // тук ще загубим плаващата запетая
    int c = b;
    printf("%u", c);
    return 0;
}


