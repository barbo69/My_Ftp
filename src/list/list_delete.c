/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-baptiste.barbotin
** File description:
** list_delete
*/

#include "my_ftp.h"

void pop_first(client_data_t **list)
{
    client_data_t *node = *list;
    client_data_t *temp = NULL;

    temp = node;
    node = node->next;
    if (temp->path != NULL)
        free(temp->path);
    free(temp);
    *list = node;
}

void pop_next_node(client_data_t *node)
{
    client_data_t *temp = NULL;

    if (node->next == NULL)
        return;
    temp = node->next;
    node->next = node->next->next;
    if (temp->path != NULL)
        free(temp->path);
    free(temp);
}

void pop_client(client_data_t **list, int client_fd)
{
    client_data_t *node = *list;

    if (node == NULL)
        return;
    if (node->client_fd == client_fd) {
        pop_first(list);
        return;
    }
    while (node->next != NULL) {
        if (node->next->client_fd == client_fd) {
            pop_next_node(node);
            return;
        }
        node = node->next;
    }
    return;
}
