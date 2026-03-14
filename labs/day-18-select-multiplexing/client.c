#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 9095
#define BUF_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in server;
    char buffer[BUF_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        return 1;
    }

    printf("Connected to server. Type message:\n");

    while (1) {
        printf("> ");
        fgets(buffer, BUF_SIZE, stdin);

        write(sock, buffer, strlen(buffer));

        int n = read(sock, buffer, BUF_SIZE - 1);
        buffer[n] = '\0';

        printf("Echo: %s", buffer);
    }

    close(sock);
    return 0;
}
