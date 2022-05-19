##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

SRC		=	src/main.c\
			src/server/socket.c\
			src/server/client.c\
			src/server/select.c\
			src/server/error.c\
			src/messages/parser.c\
			src/messages/command.c\
			src/messages/response.c\
			src/messages/handle_arg.c\
			src/list/linked_list.c\
			src/list/list_create.c\
			src/list/list_delete.c\
			src/actions/quit.c\
			src/actions/user.c\
			src/actions/pass.c\
			src/actions/cdup.c\
			src/actions/cwd.c\
			src/actions/delete.c\
			src/actions/pwd.c\
			src/actions/list.c\
			src/actions/noop.c\
			src/actions/help.c\
			src/util/path_handling.c

OBJ		=	$(SRC:.c=.o)

NAME	=	myftp

CFLAGS	=	-I ./include -Wall -Wextra -g3

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

perso: $(OBJ)
	gcc $(OBJ) -o $(NAME)

p: perso clean

fcp: fclean

cp: clean

auteur:
	echo $(USER) > auteurN
