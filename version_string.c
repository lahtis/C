/* Tulostuksen yhdistäminen
​Jos VERSION_STRING on määritelty esimerkiksi muodossa 1.0.5, voit upottaa sen muihin tulostusmerkkijonoihin C-kielen ominaisuuden avulla: vierekkäiset merkkijonoliteraalit yhdistyvät automaattisesti yhdeksi merkkijonoksi.
*/

#define VERSION_STRING  "1.0.5" // Tässä on jo merkkijono
#define VER_PREFIX "Ohjelman versio: "

printf(VER_PREFIX XSTR(VERSION_STRING) "\n");
// Esikääntäjän jälkeen (ja automaattisen yhdistämisen ansiosta):
// printf("Ohjelman versio: 1.0.5\n"); 

/*
Jos VERSION_STRING olisi numeerinen, tarvitaan edellä mainitut STR ja XSTR makrot:
*/

#define VERSION_MAJOR 1
#define VERSION_MINOR 0
#define VERSION_PATCH 5

#define STR(x) #x
#define XSTR(x) STR(x)

printf("Versio: %s.%s.%s\n", XSTR(VERSION_MAJOR), XSTR(VERSION_MINOR), XSTR(VERSION_PATCH));
// Tulostaa: Versio: 1.0.5
