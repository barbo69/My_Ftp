/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-baptiste.barbotin
** File description:
** cdup
*/

#include "my_ftp.h"

void handle_cdup(client_data_t *client)
{
    char *new_path = set_new_path(client, "../\0");

    if (check_if_directory(new_path)) {
        free(client->path);
        client->path = new_path;
        set_new_path(client, new_path);
        write(client->client_fd, CODE_250, strlen(CODE_250));
    } else {
        write(client->client_fd, CODE_550, strlen(CODE_550));
    }
}

void cdup_command(client_data_t *client)
{
    int argNb = compt_command_args(client);

    if (argNb == 1)
        handle_cdup(client);
    else
        write(client->client_fd, CODE_501, strlen(CODE_501));
    return;
}
