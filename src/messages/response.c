/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-baptiste.barbotin
** File description:
** response
*/

#include "my_ftp.h"

bool server_responses(client_data_t *client, command_type_e type,
                    client_data_t **list)
{
    if (type == QUIT) {
        quit_command(client, list);
        return true;
    }
    if (type == NOOP) {
        noop_command(client);
        return true;
    }
    if (type == HELP) {
        help_command(client);
        return true;
    }
    if (type == UNKNOWN) {
        write(client->client_fd, CODE_502, strlen(CODE_502));
        return true;
    }
    return false;
}

bool server_authentication_responses(client_data_t *client,
                                    command_type_e type)
{
    if (type == USER) {
        user_command(client);
        return true;
    }
    if (type == PASS) {
        pass_command(client);
        return true;
    }
    if (!client->authentication[1]) {
        write((client)->client_fd, CODE_530, strlen(CODE_530));
        return true;
    }
    return false;
}

void parse_folder_response(client_data_t *client, command_type_e type)
{
    if (type == LIST)
        list_command(client);
    if (type == CWD)
        cwd_command(client);
    if (type == CDUP)
        cdup_command(client);
    if (type == DELE)
        delete_command(client);
    if (type == PWD)
        pwd_command(client);
}

void handle_response(int client_fd, client_data_t **list)
{
    client_data_t *client = get_node(*list, client_fd);
    command_type_e type = UNKNOWN;

    if (client == NULL)
        return;
    type = parse_command_type(client->buffer
    + client->start % CLIENT_BUFF_SIZE);
    if (type == QUIT) {
        quit_command(client, list);
        return;
    }
    if (!server_responses(client, type, list) &&
        !server_authentication_responses(client, type)) {
        parse_folder_response(client, type);
    }
    client->w_or_rd = true;
    return;
}
