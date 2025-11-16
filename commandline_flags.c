#include <stdio.h>
# C-ohjelma lukee komentorivilippuja ja käyttää stdio.h-kirjastoa tulostamiseen:

int main(int argc, char *argv[]) {
    // argc = argument count
    // argv = argument values (taulukko merkkijonoja)

    printf("Ohjelma käynnistyi %d argumentilla.\n", argc);

    // Käydään kaikki argumentit läpi
    for (int i = 0; i < argc; i++) {
        printf("Argumentti %d: %s\n", i, argv[i]);
    }

    // Esimerkki: jos käyttäjä antaa lipun -v
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-v") == 0) {
            printf("Verbose-tila päällä!\n");
        }
    }

    return 0;
