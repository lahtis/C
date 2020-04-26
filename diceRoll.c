#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>

// Random 1-6 diceRoll generator with C code.

int main() 
{

	int i;
	int diceRoll;
	time_t t;

    	/* Intializes random number generator */
    	srand((unsigned) time(&t));

	for(i=0; i<6; i++) 
	{
	   diceRoll = ( rand()%6 ) + 1;
	   printf("%d \n",  diceRoll);
	}
	return 0;
}
