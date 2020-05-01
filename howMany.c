#include <stdio.h>
#include <stdlib.h>

/*

    C-language example.
    How many numbers do you want to avarage?
    Save to "heap" to memory.

*/

int main() {

    int i, howMany = 0;
    int total = 0.0;
    float avarage = 0.0;
    int * pointsArray = 0;

    printf("How many numbers do you want to avarage?\n");
    scanf(" %d", &howMany);

    pointsArray = (int *) malloc(howMany * sizeof(int));

    printf("Enter them! \n");

    for(i=0; i<howMany; i++) {
        scanf(" %d", &pointsArray[i]);
        total += pointsArray[i];
    }

    avarage = (float)total / (float)howMany;
    printf("Avarage is %f", avarage);

    free(pointsArray);
    return 0;
}

