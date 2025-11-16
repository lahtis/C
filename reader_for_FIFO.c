/* 
lukijaohjelma (reader), 
joka toimii sekä Linuxissa että Windowsissa ja 
vastaanottaa sen datan reaaliajassa.
*/

#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#endif

int main() {
#ifdef _WIN32
    // Windows-toteutus: Named Pipe lukija
    HANDLE hPipe;
    char buffer[1024];
    DWORD read;

    // Yhdistetään olemassa oleva putki
    hPipe = CreateFile(
        "\\\\.\\pipe\\MyPipe",   // sama nimi kuin writer-ohjelmassa
        GENERIC_READ,
        0,
        NULL,
        OPEN_EXISTING,
        0,
        NULL);

    if (hPipe == INVALID_HANDLE_VALUE) {
        printf("Putkeen yhdistäminen epäonnistui.\n");
        return 1;
    }

    // Luetaan data putkesta
    ReadFile(hPipe, buffer, sizeof(buffer), &read, NULL);
    printf("Vastaanotettu Windows-putkesta: %s\n", buffer);

    CloseHandle(hPipe);

#else
    // Linux-toteutus: FIFO lukija
    const char *fifo = "/tmp/myfifo";
    char buffer[1024];
    int fd;

    // Avataan FIFO lukua varten
    fd = open(fifo, O_RDONLY);
    read(fd, buffer, sizeof(buffer));
    printf("Vastaanotettu Linux-FIFO: %s\n", buffer);

    close(fd);
#endif

    return 0;
}
