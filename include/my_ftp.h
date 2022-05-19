/*
** EPITECH PROJECT, 2022
** Boostrap_ftp
** File description:
** my_ftp
*/

#ifndef MY_FTP_H_
    #define MY_FTP_H_

/////////////////////////////
////////// INCLUDE //////////
/////////////////////////////

    #include <sys/socket.h>
    #include <sys/types.h>
    #include <netinet/ip.h>
    #include <arpa/inet.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <signal.h>
    #include <stdlib.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <dirent.h>
    #include <sys/stat.h>
    #include "response_code.h"


/////////////////////////////
////////// MACRO ////////////
/////////////////////////////

    #define CLIENT_BUFF_SIZE 255

    #define USAGE_MESSAGE "USAGE: ./myftp port path\n\
\tport is the port number on which the server socket listens\n\
\tpath is the path to the home directory for the Anonymous user\n"


/////////////////////////////
////////// STRUCT ///////////
/////////////////////////////

typedef struct sockets_s {
    int server_fd;
    fd_set rd_sockets;
    fd_set w_sockets;
    fd_set e_sockets;
    int big_socket;
    char *path;
} sockets_t;

typedef struct client_data_s {
    int client_fd;
    char buffer[256];
    unsigned int start;
    unsigned int end;
    char *path;
    bool w_or_rd;
    bool authentication[2];
    struct client_data_s *next;

} client_data_t;

/////////////////////////////
////////// Enum /////////////
/////////////////////////////

typedef enum command_type
{
    UNKNOWN,
    CDUP,
    QUIT,
    PWD,
    PASV,
    NOOP,
    HELP,
    USER,
    PASS,
    CWD,
    DELE,
    PORT,
    RETR,
    STOR,
    LIST
}command_type_e;

/////////////////////////////
//////// PROTOTYPE //////////
/////////////////////////////

//////// socket.c ///////

int init_socket(int port);
int socket_listening(int server_fd);

///////// client.c ////////
int accept_new_client_connection(int server_fd);
int handle_clients(int server_fd, char *path);

//////// select.c /////////
int handle_selected_sockets(sockets_t *sockets, client_data_t **list);

/////// error.c //////////
void handle_error_sockets(sockets_t *sockets, client_data_t **list);

/////// command.c /////////
void handle_commands(int client_fd, client_data_t **list, sockets_t *sockets);

//////// parser.c ///////////
char *get_arg(int argNb, char *buffer);
int compt_arg(char *buffer);
command_type_e parse_command_type(char *buffer);

/////// handle_arg.c /////////
int compt_command_args(client_data_t *client);
char *get_command_args(client_data_t *client, char *temp, int argNb);

/////// linked_list.c ///////
client_data_t *get_node(client_data_t *list, int client_fd);

/////// list_create.c /////////
void push_client(client_data_t **list, int client_fd, char *path);

/////// list_delete.c /////////
void pop_client(client_data_t **list, int client_fd);

//////// response.c //////////
void handle_response(int client_fd, client_data_t **list);

//////// user.c //////////////
void user_command(client_data_t *client);

/////// pass.c //////////////
void pass_command(client_data_t *client);

////// quit.c ////////////
void quit_command(client_data_t *client, client_data_t **list);

//////// list.c //////////////
void list_command(client_data_t *client);

//////// cwd.c //////////////
void cwd_command(client_data_t *client);

//////// cdup.c //////////////
void cdup_command(client_data_t *client);

//////// delete.c //////////////
void delete_command(client_data_t *client);

//////// pwd.c /////////////////
void pwd_command(client_data_t *client);

/////////// noop.c ///////////
void noop_command(client_data_t *client);

/////////// help.c /////////////
void help_command(client_data_t *client);

/////// path_handling.c //////////
char *set_new_path(client_data_t *client, char *new_path);
bool check_if_directory(char *path);

#endif /* !MY_FTP_H_ */
