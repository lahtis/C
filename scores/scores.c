#include <stdio.h>
#include <stdlib.h>

/*
    Simple C -program that reads score results from a text file.

    Counts all lines.
    Read from the beginning of the line how many characters are stored.
    Read names in line and count characters and return the results program use.
    Use malloc function. (heap-> write memory and clean it.)
    Print it all to memory.

    gcc main.c -o main
*/
int count_char(int a);


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
        int names;
        int n1;

        fscanf(file, "%i", &names); // Read the name to file.

        n1 = count_char(names); // Put name to function, count characters and return the results.

        entries[i].name = malloc(sizeof(char) * (n1 + 1));
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

int count_char(int a) { // Function definition
    int countResults = 0, i;

    for (int i = 0; a != '\0'; i++){

        if (a == ' ' && a != ' ')
        countResults++;

    }
    return countResults;
}

