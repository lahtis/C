/* 
Katsotaanpa esimerkki, jossa sama lähdekoodi sisältää sekä Linuxin 
mkfifo-toteutuksen että Windowsin CreateNamedPipe-toteutuksen. 
Kääntäjä valitsee automaattisesti oikean osan esiprosessorimakrojen avulla.
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
    // Windows-toteutus: Named Pipe
    HANDLE hPipe;
    char buffer[] = "Hei Tuomas, tämä tulee Windowsin putkesta!";
    DWORD written;

    hPipe = CreateNamedPipe(
        "\\\\.\\pipe\\MyPipe",
        PIPE_ACCESS_OUTBOUND,
        PIPE_TYPE_BYTE | PIPE_WAIT,
        1,
        1024, 1024,
        0,
        NULL);

    if (hPipe == INVALID_HANDLE_VALUE) {
        printf("Putken luonti epäonnistui.\n");
        return 1;
    }

    printf("Odotetaan lukijaa Windowsissa...\n");
    ConnectNamedPipe(hPipe, NULL);

    WriteFile(hPipe, buffer, strlen(buffer)+1, &written, NULL);
    printf("Data lähetetty: %s\n", buffer);

    CloseHandle(hPipe);

#else
    // Linux-toteutus: FIFO
    const char *fifo = "/tmp/myfifo";
    char buffer[] = "Hei Tuomas, tämä tulee Linuxin FIFO:sta!";
    int fd;

    // Luodaan FIFO, jos ei ole olemassa
    mkfifo(fifo, 0666);

    printf("Odotetaan lukijaa Linuxissa...\n");
    fd = open(fifo, O_WRONLY);
    write(fd, buffer, strlen(buffer)+1);
    printf("Data lähetetty: %s\n", buffer);

    close(fd);
#endif

    return 0;
}
