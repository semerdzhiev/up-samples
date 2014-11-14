// bitplay.c.cpp : Defines the entry point for the console application.
//

#ifdef USE_PRECOMPILED_HEADER
#include "stdafx.h"
#endif

// get this uint type as in C#

#define uint unsigned int

/* 

задача . дадено е 32 битово число

а) да се провери дали числото има еднакъв брой битове в младшата и старшата си част

б) да се провери дали ако разменим младшите 8 бита със старшите 8 бита числото ще остане същото

*/

int main()
{
	uint mynum = (1 << 31) + (1 << 30) + (1 << 7) + (1 << 6);   // 11000001 00000000 00000000 11000000
    int lcount = 0; // low count

	// destructive approach 

	/* 
    for (int i = 0; i < 32; i++) 
    {
        if ((mynum & 1) == 1)	// if (mynum % 2 == 1) ;
        {
            lcount = lcount +
                ((i < 16) ? 1 : -1);
        } 

        mynum >>= 1;
    }
	*/

    for (int i = 0; i < 32; i++) 
    {
        if ((mynum & ( 1 << i )))
		{
            lcount = lcount +
                ((i < 16) ? 1 : -1);
        } 
	}

    if (lcount == 0)
    {
        printf("the number has same number of bits in lo and high parts \n");
    }

	uint mask = (1 << 8) - 1;

	if ( ( mynum >> 24 ) == ( mynum & mask )) { 
		printf("the num will stay the same if we change the lower and higher 8 bits \n");
	}

}
