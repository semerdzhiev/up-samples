#include <stdio.h>

const int MAX_NUM = 1<<19;

unsigned int primes[8192];

void find_primes1() { 

    int pcount = 2;

    unsigned int i, j;
    for (i = 3; i < MAX_NUM; i++) {
        bool isprime = true;
        for(j = 2; (j < i) && isprime; j++) {
            if (i % j == 0 ) {
                isprime = false;
             }
         }

         if (isprime) {
            pcount++;
         }
    }

    printf("primes count: %d", pcount);
}

void find_primes1_5() { 
    primes[0] = 1;
    primes[1] = 2;

    int pcount = 2;

    unsigned int i, j;
    for (i = 3; i < MAX_NUM; i++) {

        bool isprime = true;
        for(j = 1; (j < pcount) && isprime; j++) {
            if (i % primes[j] == 0 ) {
                isprime = false;
             }
         }

         if (isprime) {
            primes[pcount++] = i; 
    //    printf("%d \n", i);
         }
    }

    printf("primes count: %d", pcount);
}

/*

bool p[MAX_NUM];
 
void find_primes2() { 
    // set all to true
    for(int i=0; i<MAX_NUM; p[i++] = true);

    int pcount = 1;
    int cstart = 2;
    do { 
        if (p[cstart]) { pcount++; } 
        else { continue; } 
        for (int i = cstart + cstart; i < MAX_NUM; i += cstart)
            p[i] = false;
    } while(cstart++ < MAX_NUM);

    printf("primes count: %d", pcount);
}

*/

unsigned char p[MAX_NUM/8];

// example : 11th bit
// 11 / 8 = 1 -> in the byte with index 1
// 11 % 8 = 3 -> the bit with index 3 (actually the fourth bit)
// mask == 1 << 3 == 00001000
// ~mask == ~ (1 << 3 ) == 11110111
//

void setbit(int n, bool newbit) { 
    int nbyte = n / 8;
    int nbit = n % 8;
    int mask = 1 << nbit;
    p[nbyte] &= ~mask;    // clear bit 
    if (newbit) {         // if newval is true
        p[nbyte] |= mask; // set bit 
    }
}

bool getbit(int n) { 
    int nbyte = n / 8;
    int nbit = n % 8;
    int mask = 1 << nbit;
    return ( p[nbyte] & mask ) > 0; // set bit 
}

void find_primes2_5() { 
    // set all to true
    for(int i=0; i<MAX_NUM/8; p[i++] = (1<<8) - 1);

    int pcount = 1;
    int cstart = 2;
    do { 
        if (getbit(cstart)) { pcount++; } 
        else { continue; }

    /*
        for (int i = cstart + cstart; i < MAX_NUM; i += cstart) {
         setbit(i, false);
    }*/

        int i = cstart + cstart;

        do { 
             setbit(i, false);
                i += cstart;
        } while ( i < MAX_NUM);

    } while(cstart++ < MAX_NUM);

    printf("primes count: %d", pcount);
}

int main() 
{
//    find_primes1_5();
//    find_primes2();
    find_primes2_5();

    return 0;
}

