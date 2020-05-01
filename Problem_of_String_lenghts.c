#include <stdio.h>

/* 

Problems of String Lenghts

Cut string to 20 letters

Enter the string:
Clover is a tough farmer. He likes to cultivate the land.
Clover is a tough f

*/

#define MAX_STRING_SIZE 20

int main() 
{

	char movie [MAX_STRING_SIZE];
	char * pMovie = movie;

	printf("Enter the string:\n");
	fgets(pMovie, MAX_STRING_SIZE, stdin);	
	puts(pMovie);

	return 0;
}
