/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-baptiste.barbotin
** File description:
** quit
*/

#include "my_ftp.h"

void quit_command(client_data_t *client, client_data_t **list)
{
    write(client->client_fd, CODE_221, strlen(CODE_221));
    close(client->client_fd);
    pop_client(list, client->client_fd);
    return;
}
