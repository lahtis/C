// Erilliset numeeriset määritelmät
#define VERSION_MAJOR 1
#define VERSION_MINOR 5
#define VERSION_PATCH 23

// ... ja mahdollisesti jopa kokonaislukuarvo helppoa vertailua varten:
#define VERSION (VERSION_MAJOR * 10000 + VERSION_MINOR * 100 + VERSION_PATCH) 

// Yhdistäminen tulostusmerkkijonoksi
#define STR(x) #x
#define XSTR(x) STR(x)
#define VERSION_STRING XSTR(VERSION_MAJOR) "." XSTR(VERSION_MINOR) "." XSTR(VERSION_PATCH)

// Tulostus:
printf("Versio: %s\n", VERSION_STRING); // Tulostaa: Versio: 1.5.23 
