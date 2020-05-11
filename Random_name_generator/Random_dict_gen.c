#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD   100
#define NUM_WORDS  10

int main(void)
{
    /* Open words file */
    FILE *fp = fopen("/usr/share/dict/words", "r");

    if (fp == NULL) {
        perror("Unable to locate word list");
        exit(EXIT_FAILURE);
    }

    /* Count words in file */
    char word[MAX_WORD];
    long wc = 0;
    while (fgets(word, sizeof word, fp) != NULL) {
        ++wc;
    }

    /* Store random words in array */
    char randwords[NUM_WORDS][MAX_WORD];
    srand((unsigned) time(NULL));
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

    /* Display results */
    for (size_t i = 0; i < NUM_WORDS; i++) {
        printf("%s", randwords[i]);
    }

    return 0;
}
