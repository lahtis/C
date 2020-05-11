#include <stdio.h>

/*
    Simple example how to count lines text file in C-program.
*/

int main() {

    int nline;
    nline=0;

    /* Open words file */
    FILE *f = fopen("./names.txt", "r");

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
    printf("nline:%d\n", nline);
    fclose(f);
    return 0;
}
