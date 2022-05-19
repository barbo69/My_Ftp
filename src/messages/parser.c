/*
** EPITECH PROJECT, 2022
** Boostrap_ftp
** File description:
** parser
*/

#include "my_ftp.h"

char *get_arg(int argNb, char *buffer)
{
    char *arg = NULL;

    for (int i = 0; i < argNb; i++) {
        if (i == 0) {
            arg = strtok(buffer, " ");
        } else {
            arg = strtok(NULL, " ");
        }
    }
    return arg;
}

int compt_arg(char *buffer)
{
    int compt = 0;
    char *arg = NULL;

    arg = strtok(buffer, " ");
    if (arg == NULL)
        return 0;
    while (arg != NULL) {
        arg = strtok(NULL, " ");
        compt++;
    }
    return compt;
}

command_type_e parse_first_part_commands(char *buffer)
{
    if (strcmp(buffer, "USER\0") == 0)
        return USER;
    if (strcmp(buffer, "PASS\0") == 0)
        return PASS;
    if (strcmp(buffer, "CWD\0") == 0)
        return CWD;
    if (strcmp(buffer, "CDUP\0") == 0)
        return CDUP;
    if (strcmp(buffer, "QUIT\0") == 0)
        return QUIT;
    if (strcmp(buffer, "DELE\0") == 0)
        return DELE;
    if (strcmp(buffer, "PWD\0") == 0)
        return PWD;
    if (strcmp(buffer, "PASV\0") == 0)
        return PASV;
    if (strcmp(buffer, "PORT\0") == 0)
        return PORT;
    return UNKNOWN;
}

command_type_e parse_second_part_commands(char *buffer)
{
    if (strcmp(buffer, "HELP\0") == 0)
        return HELP;
    if (strcmp(buffer, "NOOP\0") == 0)
        return NOOP;
    if (strcmp(buffer, "RETR\0") == 0)
        return RETR;
    if (strcmp(buffer, "STOR\0") == 0)
        return STOR;
    if (strcmp(buffer, "LIST\0") == 0)
        return LIST;
    return UNKNOWN;
}

command_type_e parse_command_type(char *buffer)
{
    char temp[CLIENT_BUFF_SIZE];
    char *arg = NULL;
    command_type_e type = UNKNOWN;

    strcpy(temp, buffer);
    arg = get_arg(1, temp);
    if (arg == NULL)
        return type;
    type = parse_first_part_commands(arg);
    if (type == UNKNOWN)
        type = parse_second_part_commands(arg);
    return type;
}
