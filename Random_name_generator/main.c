/*
    Simple C -program that reads names from a text file and return one random name.

    Counts all lines.
    Read from the beginning of the line how many characters are stored.
    Read names in line and count characters and return the results program use.
    Print random name.

    gcc main.c -o main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int count_char(char names);

int count_char(char names) { // Counts letters from a word. aka name Antti has 5 letters.
    int countResults = 0;

    for (int i = 0; names != '\0'; i++){

        if (names == ' ' && names != ' ')
        countResults++;

    }
    return countResults;
}

int main(void)
{
    int personCount=0, n1;
    char chr, names;
    time_t t;

    /* Open words file */
    FILE *file = fopen("./names.txt", "r");

    if (file == NULL) {
        perror("Unable to locate names list");
        exit(EXIT_FAILURE);
    }

    chr = getc(file);

    while (chr != EOF)

    {
        //Count whenever new line is encountered

        if (chr == '\n')
        {
            personCount++;
        }

        //take next line from file.

        chr = getc(file);
    }

    fseek(file, 0, SEEK_SET);  // Return the beginner of the file


    // Count words in line 
    char word[personCount];
    long wc = 0;
    while (fgets(word, sizeof word, file) != NULL) {
        ++wc;
        n1 = count_char(n1); // Function counts letters from a word and return the results  
    } 
    printf("%i", n1);
    /* Store random names in array */
    char randnames[personCount][n1];
    srand((unsigned)time(&t));
    for (size_t i = 0; i < personCount; i++) {
        rewind(file);
        int sel = rand() %wc + 1;
        for (int j = 0; j < sel; j++) {
            if (fgets(word, sizeof word, file) == NULL) {
                perror("Error in fgets()");
            }
        }
        strcpy(randnames[i], word);
    }


    if (fclose(file) != 0) {
        perror("Unable to close file");
    } 
    fclose(file); 

    printf("%s", randnames[0]);
  
    return 0;
}
