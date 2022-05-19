/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-baptiste.barbotin
** File description:
** user
*/

#include "my_ftp.h"

void user_command(client_data_t *client)
{
    client->authentication[0] = true;
    write(client->client_fd, CODE_331, strlen(CODE_331));
    return;
}
