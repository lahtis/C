/*
    Simple C -program that reads names from a text file and return one random name.
    Random names han change NUM_WORDS.
    Counts all lines. (nline)
    Read from the beginning of the line how many characters are stored.
    Read names in line and count characters and return the results program use.
    Print random name.
    gcc main.c -o main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_WORDS  1   // how many names generated.

int main(void)
{
    int nline;
    nline=0;
    time_t t;

    /* Open words file */
    FILE *fp = fopen("names.txt", "r");

    if (fp == NULL) {
        perror("Unable to locate word list");
        exit(EXIT_FAILURE);
    }

    int c = getc(fp);
    while (c != EOF){	
	c = getc(fp);
        if (c== '\n')
          nline++;
    }
    fseek(fp, 0, SEEK_SET);  // Return the beginner of the file


    /* Count words in file */
    char word[nline];
    long wc = 0;
    while (fgets(word, sizeof word, fp) != NULL) {
        ++wc;
    }

    /* Store random words in array */
    char randwords[NUM_WORDS][nline];
    srand((unsigned)time(&t));
    for (size_t i = 0; i < NUM_WORDS; i++) {
        rewind(fp);
        int sel = rand() % wc + 1;
        for (int j = 0; j < sel; j++) {
            if (fgets(word, sizeof word, fp) == NULL) {
                perror("Error in fgets()");
            }
        }
        strcpy(randwords[i], word);
    }

    if (fclose(fp) != 0) {
        perror("Unable to close file");
    }
    fclose(fp);

    /* Display results */
    for (size_t i = 0; i < NUM_WORDS; i++) {
        printf("%s", randwords[i]);
    }

    return 0;
}
