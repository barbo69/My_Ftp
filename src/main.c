/*
** EPITECH PROJECT, 2022
** Boostrap_ftp
** File description:
** main
*/

#include "my_ftp.h"

int user_input_handling(int ac, char **av, int *server_port, char **path)
{
    if (ac == 1)
        return 84;
    if (strcmp(av[1], "-h") == 0) {
        printf(USAGE_MESSAGE);
        return 1;
    }
    if (ac != 3)
        return 84;
    *server_port = atoi(av[1]);
    *path = malloc(sizeof(char) * (strlen(av[2]) + 1));
    strcpy(*path, av[2]);
    return 0;
}

int main(int ac, char **av)
{
    int arg_status = 0;
    int server_fd = 0;
    int server_port = 0;
    char *path = NULL;

    arg_status = user_input_handling(ac, av, &server_port, &path);
    if (arg_status == 84)
        return 84;
    if (arg_status == 1)
        return 0;
    server_fd = init_socket(server_port);
    if (server_fd < 0)
        return 84;
    if (socket_listening(server_fd) == 84)
        return 84;
    handle_clients(server_fd, path);
    close(server_fd);
    return 0;
}
