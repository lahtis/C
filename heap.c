#include <stdio.h>
#include <stdlib.h>


/*
    Simple C-program for heap

*/


int main() {
	int *foo;
	foo = (int *) std::malloc(sizeof(int));
	*foo = 50;
	printf("%d\n", *foo);
	free(foo);


	return 0;
}
