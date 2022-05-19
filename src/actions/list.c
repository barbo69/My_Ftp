/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-baptiste.barbotin
** File description:
** list
*/

#include "my_ftp.h"

void list_dir(char *path)
{
    DIR *dp = NULL;
    struct dirent *dir = NULL;

    printf("path = %s\n", path);
    dp = opendir(path);
    if (dp == NULL)
        return;
    dir = readdir(dp);
    while (dir != NULL) {
        printf("%s\n", dir->d_name);
        dir = readdir(dp);
    }
    closedir(dp);
    return;
}

void list_command(client_data_t *client)
{
    int argNb = compt_command_args(client);

    if (argNb == 1) {
        list_dir(client->path);
    } else
        write(client->client_fd, CODE_501, strlen(CODE_501));
    return;
}
