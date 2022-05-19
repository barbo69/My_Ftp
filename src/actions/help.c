/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-baptiste.barbotin
** File description:
** help
*/

#include "my_ftp.h"

void help_command(client_data_t *client)
{
    write(client->client_fd, CODE_214, strlen(CODE_214));
    return;
}
