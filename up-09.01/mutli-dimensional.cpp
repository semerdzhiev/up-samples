/* входният файл съдържа
5 
3 one two three
4 can i do it
1 cat
2 push me
3 yes yes YES!
*/

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int *scount;
char buf[1024];
char ***hdata;

int main() {
    ifstream ifs("input.txt");

    if (!ifs) { 
        cout << "error opening file" << endl;
        return -1;
    }

    int numrows = 0;
    ifs >> numrows;

    if ( numrows == 0 ) {
        cout << " error reading number of rows. possible failure during file open operation " << endl;
        return -1;
    }

    hdata = new char**[numrows];
    scount = new int[ numrows];

    for(int i =0;i<numrows;i++){
        int numstrings;
        ifs >> numstrings;
        scount[i] = numstrings;
        hdata[i] = new char* [numstrings];

        for (int j=0;j<numstrings;j++) {
            ifs >> buf;
            int mlen = strlen(buf) + 1;
            hdata[i][j] = new char[mlen];

            // копирай (къде), колко максимум символа, от къде
#ifdef __GNUC__
            strcpy(hdata[i][j], buf);
#else
            strcpy_s(hdata[i][j], mlen, buf);
#endif
        }
    }

    for ( int i=0; i<numrows ; i ++)
        for (int j=0;j<scount[i]; j++) 
            printf("hdata[%d][%d] = %s \n", i, j, hdata[i][j]);

    return 0;
}
