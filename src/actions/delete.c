/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-baptiste.barbotin
** File description:
** delete
*/

#include "my_ftp.h"

void handle_delete(client_data_t *client, char *arg)
{
    char *new_path = set_new_path(client, arg);

    if (remove(new_path) == 0) {
        write(client->client_fd, CODE_250, strlen(CODE_250));
    } else {
        write(client->client_fd, CODE_550, strlen(CODE_550));
    }
    free(new_path);
}

void delete_command(client_data_t *client)
{
    int argNb = compt_command_args(client);
    char temp[CLIENT_BUFF_SIZE];
    char *new_directory = NULL;

    if (argNb == 2) {
        new_directory = get_command_args(client, temp, 2);
        handle_delete(client, new_directory);
    } else
        write(client->client_fd, CODE_501, strlen(CODE_501));
    return;
}
