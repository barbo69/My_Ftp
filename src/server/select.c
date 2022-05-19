/*
** EPITECH PROJECT, 2022
** Boostrap_ftp
** File description:
** select
*/

#include "my_ftp.h"

void set_biggest_fd(int fd, sockets_t *sockets)
{
    if (fd >= sockets->big_socket) {
        sockets->big_socket = fd + 1;
    }
}

int handle_readable_sockets(int fd, sockets_t *sockets, client_data_t **list)
{
    int client_fd = 0;

    if (fd == sockets->server_fd) {
        client_fd = accept_new_client_connection(sockets->server_fd);
        if (get_node(*list, client_fd) == NULL) {
            push_client(list, client_fd, sockets->path);
        }
        set_biggest_fd(client_fd, sockets);

    } else {
        handle_commands(fd, list, sockets);
    }
    return 0;
}

int handle_writable_sockets(int fd, sockets_t *sockets, client_data_t **list)
{
    if (fd != sockets->server_fd) {
        handle_response(fd, list);
    }
    return 0;
}

int handle_selected_sockets(sockets_t *sockets, client_data_t **list)
{
    for (int i = 0; i < sockets->big_socket; i++) {
        if (FD_ISSET(i, &sockets->rd_sockets))
            handle_readable_sockets(i, sockets, list);
        if (FD_ISSET(i, &sockets->w_sockets))
            handle_writable_sockets(i, sockets, list);
    }
    return 0;
}
