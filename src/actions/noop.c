/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-baptiste.barbotin
** File description:
** noop
*/

#include "my_ftp.h"

void noop_command(client_data_t *client)
{
    write(client->client_fd, CODE_200, strlen(CODE_200));
    return;
}
