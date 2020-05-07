#include <stdio.h>
#include <stdlib.h>


/*
    Simple C++ -program that reads score results from a text file.
    Use malloc function. (heap-> write memory and clean it.)
    This is C++ code. It only compile gcc.

*/
typedef struct
{
    char *name;
    int score;
} Person;


int main() {

    FILE *file = fopen("scores.txt", "r");

    int PersonCount;
    fscanf(file, "%i", &PersonCount);

    Person *entries = (Person *)malloc(sizeof(Person) * PersonCount);

    if (entries == NULL) {
	printf("Error in allocating the data array.\n");
	exit (1);
    }


    printf("Score list\n");
    printf("=======================\n");
    for (int i = 0; i < PersonCount; i++)
    {
        int nameLen;
        fscanf(file, "%i", &nameLen);

        entries[i].name = malloc(sizeof(char) * (nameLen + 1));
        fscanf(file, "%s %i", entries[i].name, &entries[i].score);

        printf("%i. %s - %i\n", i + 1, entries[i].name, entries[i].score);
    }

    //clean up
    fclose(file);

    for (int i = 0; i < PersonCount; i++)
        free(entries[i].name);

    free(entries);

    return 0;
}
