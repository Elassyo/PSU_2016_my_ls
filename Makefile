##
## Makefile for PSU_2016_my_ls in /home/arthur.melin/Code/PSU_2016_my_ls
##
## Made by Arthur Melin
## Login   <arthur.melin@epitech.net>
##
## Started on  Thu Nov 24 21:40:26 2016 Arthur Melin
## Last update Thu Nov 24 21:41:10 2016 Arthur Melin
##

CC		=	gcc

CFLAGS		=	-c -g -W -Wall -Wextra -Iinclude -O3

LDFLAGS		=	-Llib/my -lmy

RM		=	rm -f

NAME		=	my_ls

SRCDIR		=	src

SRC		=	my_ls.c

INCDIR		=	include

INC		=	my.h

OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

%.o: $(SRCDIR)/%.c $(addprefix $(INCDIR)/, $(INC))
	$(CC) $< $(CFLAGS) -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
