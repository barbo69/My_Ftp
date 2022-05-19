/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-baptiste.barbotin
** File description:
** list_create
*/

#include "my_ftp.h"

client_data_t *create_node(int client_fd, char *path)
{
    client_data_t *new_node = NULL;
    int len = strlen(path);

    new_node = malloc(sizeof(client_data_t));
    new_node->buffer[CLIENT_BUFF_SIZE] = '\0';
    new_node->client_fd = client_fd;
    new_node->start = 0;
    new_node->end = 0;
    new_node->next = NULL;
    new_node->w_or_rd = true;
    new_node->authentication[0] = false;
    new_node->authentication[1] = false;
    if (path != NULL) {
        new_node->path = malloc(sizeof(char) * (len + 1));
        strcpy(new_node->path, path);
        new_node->path[len] = '\0';
    } else
        new_node->path = NULL;
    return new_node;
}

void push_client(client_data_t **list, int client_fd, char *path)
{
    client_data_t *temp = *list;

    if (temp == NULL) {
        *list = create_node(client_fd, path);
        return;
    }
    while (temp != NULL) {
        if (temp->next == NULL) {
            temp->next = create_node(client_fd, path);
            return;
        }
        temp = temp->next;
    }
    return;
}
