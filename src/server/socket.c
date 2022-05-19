/*
** EPITECH PROJECT, 2022
** Boostrap_ftp
** File description:
** socket
*/

#include "my_ftp.h"

int init_socket(int port)
{
    int serverfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;

    if (serverfd < 0) {
        printf("Connexion failed\n");
        return serverfd;
    }
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(port);
    if (bind(serverfd, (struct sockaddr *)&server, sizeof(server)) != 0) {
        printf("socket bind failed\n");
        return -1;
    }
    printf("IP: %s\n", inet_ntoa(server.sin_addr));
    printf("PORT: %u\n", ntohs(server.sin_port));
    return serverfd;
}

int socket_listening(int server_fd)
{
    if (listen(server_fd, 42) != 0) {
        printf("Listen failed\n");
        return 84;
    }
    return 0;
}
