/*
** EPITECH PROJECT, 2022
** Boostrap_ftp
** File description:
** command
*/

#include "my_ftp.h"

bool check_cariage(char car)
{
    if (car == '\r')
        return true;
    return false;
}

int get_command(int client_fd, char *buffer)
{
    char temp = '\0';
    bool cariage = false;

    for (int i = 0; i < CLIENT_BUFF_SIZE; i++) {
        if (read(client_fd, &temp, 1) < 0)
            return 0;
        if (temp == '\n' && cariage) {
            buffer[(i - 1) % CLIENT_BUFF_SIZE] = '\0';
            return i;
        }
        if (temp == '\0') {
            buffer[i % CLIENT_BUFF_SIZE] = '\0';
            return i;
        }
        buffer[i % CLIENT_BUFF_SIZE] = temp;
        cariage = check_cariage(temp);
    }
    return 0;
}

void set_client_command(client_data_t *client, char *buffer, int len)
{
    int temp = 0;

    client->start = client->end;
    for (int i = 0; i <= len; i++) {
        temp = client->start + i;
        client->buffer[temp % CLIENT_BUFF_SIZE] = buffer[i];
    }
    client->end = temp % CLIENT_BUFF_SIZE;
    return;
}

void handle_commands(int client_fd, client_data_t **list, sockets_t *sockets)
{
    char buffer[CLIENT_BUFF_SIZE];
    client_data_t *client = get_node(*list, client_fd);
    int len = get_command(client->client_fd, buffer);

    if (client == NULL)
        return;
    if (len == 0) {
        FD_CLR(client_fd, &sockets->rd_sockets);
        FD_CLR(client_fd, &sockets->w_sockets);
        pop_client(list, client_fd);
        close(client_fd);
        return;
    }
    set_client_command(client, buffer, len);
    client->w_or_rd = false;
    return;
}
