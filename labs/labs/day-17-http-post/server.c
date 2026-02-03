#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8082
#define BUF_SIZE 4096

int main() {
    int server_fd, client_fd;
    struct sockaddr_in addr;
    char buffer[BUF_SIZE];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&addr, sizeof(addr));
    listen(server_fd, 5);

    printf("HTTP POST server listening on port %d\n", PORT);

    client_fd = accept(server_fd, NULL, NULL);
    int bytes = read(client_fd, buffer, BUF_SIZE - 1);
    buffer[bytes] = '\0';

    printf("Request received:\n%s\n", buffer);

    char *body = strstr(buffer, "\r\n\r\n");
    if (body) {
        body += 4;
        printf("POST body:\n%s\n", body);
    }

    const char *response =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/plain\r\n"
        "Content-Length: 14\r\n"
        "\r\n"
        "POST received";

    write(client_fd, response, strlen(response));

    close(client_fd);
    close(server_fd);
    return 0;
}
