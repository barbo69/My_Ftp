/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-baptiste.barbotin
** File description:
** handle_arg
*/

#include "my_ftp.h"

int compt_command_args(client_data_t *client)
{
    char temp[CLIENT_BUFF_SIZE];

    strcpy(temp, client->buffer + (client->start
    % CLIENT_BUFF_SIZE));
    return compt_arg(temp);
}

char *get_command_args(client_data_t *client, char *temp, int argNb)
{
    strcpy(temp, client->buffer + (client->start % CLIENT_BUFF_SIZE));
    return get_arg(argNb, temp);
}
