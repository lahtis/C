#include <stdio.h>

/*
    Simple example how to count text files lines in C programming.
*/


int main() {

    int nline;
    nline=0;

    /* Open words file */
    FILE *f = fopen("names.txt", "r");

    if (f == NULL) {
        perror("Unable to locate names list");
        return -1;
    }

    int c = getc(f);
    while (c != EOF){	
	      c = getc(f);
        if (c== '\n')
          nline++;
        }
    printf("Lines:%d\n", nline);
    fclose(f);
    return 0;
}
