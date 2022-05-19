/*
** EPITECH PROJECT, 2022
** server
** File description:
** client
*/

#include "my_ftp.h"

int accept_new_client_connection(int server_fd)
{
    unsigned int clientLen = 0;
    struct sockaddr_in client;
    int clientfd = 0;

    clientLen = sizeof(client);
    clientfd = accept(server_fd, (struct sockaddr *)&client, &clientLen);
    if (clientfd < 0) {
        printf("connection to the server failed\n");
        return clientfd;
    }
    printf("New client is connected\n");
    printf("IP: %s\n", inet_ntoa(client.sin_addr));
    printf("PORT: %u\n", ntohs(client.sin_port));
    write(clientfd, CODE_220, strlen(CODE_220));
    return clientfd;
}

void check_not_closed_sockets(client_data_t *list, sockets_t *sockets)
{
    while (list != NULL) {
        if (list->w_or_rd == true)
            FD_SET(list->client_fd, &sockets->rd_sockets);
        else
            FD_SET(list->client_fd, &sockets->w_sockets);
        list = list->next;
    }
}

void reset_fd_set(sockets_t *sockets)
{
    FD_ZERO(&sockets->rd_sockets);
    FD_SET(sockets->server_fd, &sockets->rd_sockets);
    FD_ZERO(&sockets->w_sockets);
    FD_SET(sockets->server_fd, &sockets->w_sockets);
    FD_ZERO(&sockets->e_sockets);
    FD_SET(sockets->server_fd, &sockets->e_sockets);
}

int handle_clients(int server_fd, char *path)
{
    sockets_t sockets;
    client_data_t *client = NULL;

    sockets.path = path;
    sockets.server_fd = server_fd;
    sockets.big_socket = server_fd + 1;
    while (1) {
        reset_fd_set(&sockets);
        check_not_closed_sockets(client, &sockets);
        if (select(sockets.big_socket, &sockets.rd_sockets,
        &sockets.w_sockets, &sockets.e_sockets, NULL) < 0) {
            return 84;
        }
        handle_error_sockets(&sockets, &client);
        handle_selected_sockets(&sockets, &client);
    }
    return 0;
}
