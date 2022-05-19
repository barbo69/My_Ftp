/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-baptiste.barbotin
** File description:
** linked_list
*/

#include "my_ftp.h"

client_data_t *get_node(client_data_t *list, int client_fd)
{
    while (list != NULL) {
        if (list->client_fd == client_fd)
            return list;
        list = list->next;
    }
    return NULL;
}
