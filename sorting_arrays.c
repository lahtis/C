#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>

// g++ -o main main.c
// This program generates 10 individual random numbers and arranges them from smallest to largest.

int main() {

    int i, temp, swapped;
    int howMany = 10;
    int goals[howMany];
    time_t t;

    /* Intializes random number generator */
    srand((unsigned) time(&t));

    // Randomize 10 numbers list.
    for(i=0; i<howMany; i++)
    {
    goals[i] = ( rand()%100 )+1;
    }

    printf("Orginal List\n");

    for(i=0; i<howMany; i++){
        printf("%d \n", goals[i]);
    }

    // Sorting (arrays) randoms numbers to low to high.
    // It is easy read the list
    while(1){

        swapped = 0;   // sorted

        for(i=0; i<howMany-1; i++)
        {
            if(goals[i]>goals[i+1]){
                int temp = goals[i];
                goals[i] = goals[i+1];
                goals[i+1] = temp;
                swapped = 1;
            }
        }

        if(swapped==0){
            break;
        }
    }

    printf("\nSorted List\n");
    for(i=0; i<howMany; i++){
        printf("%d \n", goals[i]);
    }

    return 0;
}
