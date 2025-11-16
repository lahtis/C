#include <stdio.h>
#include <string.h>

int main(void) {
    char line[256];

    printf("[\n"); // JSON-taulukon alku
    int first = 1;

    // Luetaan rivejä stdinistä kunnes EOF
    while (fgets(line, sizeof(line), stdin)) {
        char firstname[128] = {0};
        char lastname[128] = {0};
        char birthyear[16] = {0};

        // Parsitaan CSV: "Etunimi;Sukunimi;Vuosi"
        if (sscanf(line, "%127[^;];%127[^;];%15s", firstname, lastname, birthyear) == 3) {
            if (!first) {
                printf(",\n"); // erotin edellisten rivien jälkeen
            }
            printf("  {\"firstname\":\"%s\", \"lastname\":\"%s\", \"birthyear\":\"%s\"}",
                   firstname, lastname, birthyear);
            first = 0;
        }
    }

    printf("\n]\n"); // JSON-taulukon loppu
    return 0;
}
