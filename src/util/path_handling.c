/*
** EPITECH PROJECT, 2022
** B-NWP-400-LYN-4-1-myftp-baptiste.barbotin
** File description:
** path_handling
*/

#include "my_ftp.h"

bool check_if_directory(char *path)
{
    struct stat buff;

    if (stat(path, &buff) == -1)
        return false;
    if (S_ISDIR(buff.st_mode)) {
        return true;
    } else
        return false;
}

void get_new_path(char *new_path, char *path, int len)
{
    int compt = 0;

    for (int i = 0; i < len; i++) {
        if ((new_path[i] == '/' || new_path[i] == '.') && compt == 0) {
            continue;
        }
        path[compt] = new_path[i];
        compt++;
    }
    path[compt] = '\0';
}

char *parse_path(char *new_path)
{
    int len = strlen(new_path);
    char *path = malloc(sizeof(char) * (len + 1));

    if (strcmp(new_path, ".\0") == 0 || strcmp(new_path, "../\0") == 0) {
        strcpy(path, new_path);
        path[len] = '\0';
        return path;
    }
    get_new_path(new_path, path, len);
    return path;
}

char *set_new_path(client_data_t *client, char *new_path)
{
    char *path = parse_path(new_path);
    int len_old = strlen(client->path);
    int len_new = strlen(path);
    int final_len = len_old + len_new + 1;
    char *temp = malloc(sizeof(char) * (final_len + 1));

    temp[0] = '\0';
    strcat(temp, client->path);
    if (len_old > 0) {
        if (client->path[len_old - 1] != '/')
            strcat(temp, "/\0");
        else
            final_len = final_len - 1;
    }
    strcat(temp, path);
    free(path);
    temp[final_len] = '\0';
    return temp;
}
