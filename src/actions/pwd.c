/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-baptiste.barbotin
** File description:
** pwd
*/

#include "my_ftp.h"

void handle_pwd(client_data_t *client)
{
    write(client->client_fd, CODE_257_1, strlen(CODE_257_1));
    write(client->client_fd, client->path, strlen(client->path));
    write(client->client_fd, CODE_257_2, strlen(CODE_257_2));
}

void pwd_command(client_data_t *client)
{
    int argNb = compt_command_args(client);

    if (argNb == 1) {
        handle_pwd(client);
    } else
        write(client->client_fd, CODE_501, strlen(CODE_501));
    return;
}
