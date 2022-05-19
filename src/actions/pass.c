/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-baptiste.barbotin
** File description:
** pass
*/

#include "my_ftp.h"

void pass_command(client_data_t *client)
{
    if (client->authentication[0] == true) {
        client->authentication[1] = true;
        write(client->client_fd, CODE_230, strlen(CODE_230));
    } else {
        write(client->client_fd, CODE_332, strlen(CODE_332));
    }
    return;
}
