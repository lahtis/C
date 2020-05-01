#include <stdio.h>
#include <string.h>

#define NUMBER_OF_STRING 14
#define MAX_STRING_SIZE 15

/* in C

   Calculate string size words array.  
   Length of String using strlen() Function.
   Counts the number of letters in the name array list.

*/

void print_array(const char arr[NUMBER_OF_STRING][MAX_STRING_SIZE])
{
	for (int i = 0; i < NUMBER_OF_STRING; i++)
	{
		printf("'%s' has length %zu\n", arr[i], strlen(arr[i]));
	}
}

int main()
{
	char arr[NUMBER_OF_STRING][MAX_STRING_SIZE] =
	{ "Juho", "Kalle", "Matti", "Johan", "Antti", "Heikki", "Karl", "Frans", "Kustaa", "Pekka", "August", "Otto", "Mikko", "Jaakko" };

	printf("Name list:\n");
	print_array(arr);

	

	return 0;
}
