#include <stdio.h>
#include <stdlib.h>

/*
    Simple C -program that reads score results from a text file.

    Counts all lines.
    Read from the beginning of the line how many characters are stored.
    Use malloc function. (heap-> write memory and clean it.)
    Print it all.

    gcc main.c -o main
*/


typedef struct
{
    char *name;
    int score;
} Person;

int main() {

    int personCount=0;
    char chr;

    FILE *file = fopen("names.txt", "r");

    if(file== NULL) {
      perror("Error in opening file. File not found.");
      return(-1);
    }
    else

   //extract text from file and store in chr

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
    Person *entries = (Person *)malloc(sizeof(Person) * personCount);

    printf("Score list %d\n", personCount); // show how many line or person have to show
    printf("=======================\n");

    for (int i = 0; i < personCount; i++)
    {
        int nameLen;

        fscanf(file, "%i", &nameLen);  // Read the name lenght the first column of the row.

        entries[i].name = malloc(sizeof(char) * (nameLen + 1));
        fscanf(file, "%s %i", entries[i].name, &entries[i].score);

        printf("%i. %s - %i\n", i + 1, entries[i].name, entries[i].score);
    }

    //clean up
    fclose(file);

    for (int i = 0; i < personCount; i++)
        free(entries[i].name);

    free(entries);

    return 0;
}

