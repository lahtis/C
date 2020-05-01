#include <stdio.h>

/* Calculate String Length without Using strlen() Function */

int main() {
    char s[] = "Programming is fun";
    int i;

    for (i = 0; s[i] != '\0'; ++i);
    
    printf("Length of the string: %d\n", i);
    return 0;
}
