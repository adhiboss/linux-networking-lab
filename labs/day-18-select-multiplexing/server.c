#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define PORT 9095
#define BUF_SIZE 1024

int main() {
    int server_fd, client_fd, max_fd;
    struct sockaddr_in addr;
    char buffer[BUF_SIZE];

    fd_set master_set, read_set;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(server_fd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Select server running on port %d...\n", PORT);

    FD_ZERO(&master_set);
    FD_SET(server_fd, &master_set);

    max_fd = server_fd;

    while (1) {
        read_set = master_set;

        if (select(max_fd + 1, &read_set, NULL, NULL, NULL) < 0) {
            perror("select");
            exit(1);
        }

        for (int fd = 0; fd <= max_fd; fd++) {
            if (FD_ISSET(fd, &read_set)) {

                if (fd == server_fd) {
                    client_fd = accept(server_fd, NULL, NULL);
                    if (client_fd < 0) {
                        perror("accept");
                        continue;
                    }

                    FD_SET(client_fd, &master_set);

                    if (client_fd > max_fd) {
                        max_fd = client_fd;
                    }

                    printf("New client connected: fd=%d\n", client_fd);
                } 
                else {
                    int bytes = read(fd, buffer, BUF_SIZE - 1);

                    if (bytes <= 0) {
                        printf("Client disconnected: fd=%d\n", fd);
                        close(fd);
                        FD_CLR(fd, &master_set);
                    } else {
                        buffer[bytes] = '\0';
                        printf("Client %d says: %s\n", fd, buffer);

                        write(fd, buffer, strlen(buffer));
                    }
                }
            }
        }
    }

    close(server_fd);
    return 0;
}
