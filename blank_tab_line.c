#include <stdio.h>

/*
    Simple example how to count number of blank, tabs and lines in C programming.
*/


int main(void) {

    int c, nblank, ntab, nline;

    nblank=0;
    ntab=0;
    nline=0;

    while ((c= getchar())!= '*')
        {
            if (c== ' ')
                nblank++;
            if (c== '\t')
                ntab++;
            if (c== '\n')
                nline++;
        }
    printf(" nblank:%d\n ntab:%d\ņ nline:%d\n", nblank, ntab, nline);
    return 0;
}
