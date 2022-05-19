/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-baptiste.barbotin
** File description:
** error
*/

#include "my_ftp.h"

void handle_error_sockets(sockets_t *sockets, client_data_t **list)
{
    for (int i = 0; i < sockets->big_socket; i++) {
        if (FD_ISSET(i, &sockets->e_sockets)) {
            FD_ISSET(i, &sockets->rd_sockets);
            FD_ISSET(i, &sockets->w_sockets);
            pop_client(list, i);
            close(i);
        }
    }
}
