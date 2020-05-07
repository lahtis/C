#include <stdio.h>
#include <stdlib.h>

/*
    Simple C++ program that reads score results from a text file.
    Use malloc function. (heap-> write memory and clean it.)
    Maybe this is c++. It is not working g++ but works gcc.

*/
typedef struct
{
    char *name;
    int score;
} Entry;


int main() {

    FILE *file = fopen("scores.txt", "r");

    int entryCount;
    fscanf(file, "%i", &entryCount);

    Entry *entries = malloc(sizeof(Entry) * entryCount);
    
    if (entries == NULL) {
	    printf("Error in allocating the data array.\n");
	return 0;
    }

    printf("Score list\n");
    printf("=======================\n");
    for (int i = 0; i < entryCount; i++)
    {
        int nameLen;
        fscanf(file, "%i", &nameLen);

        entries[i].name = malloc(sizeof(char) * (nameLen + 1));
        fscanf(file, "%s %i", entries[i].name, &entries[i].score);

        printf("%i. %s - %i\n", i + 1, entries[i].name, entries[i].score);
    }

    //clean up
    fclose(file);

    for (int i = 0; i < entryCount; i++)
        free(entries[i].name);

    free(entries);

    return 0;
}
