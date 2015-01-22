// nonrecurse.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

char *str = "0**1*0*11";

int _tmain(int argc, _TCHAR* argv[]) {
    int scnt = 0;
    char *c = str;
    do { 
        scnt += *c == '*';
    } while (*++c);

    if (scnt > 64) {
        return 0;
    }

    unsigned long int cval = 0;

    do { 
        unsigned long int mask = 1 << (scnt - 1);
        char *c = str;
        do { 
            if ( *c == '*' ) {
                putc(cval & mask ? '1' : '0', stdout);
                mask >>= 1;
            } else { 
                putc(*c, stdout);
            }
            c++;
        } while (*c);
        putc('\n', stdout);
        cval++;
    } while (cval && cval <= (1 << scnt) - 1); 

    return 0;
}


