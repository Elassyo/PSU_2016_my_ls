##
## Makefile for PSU_2016_my_ls in /home/arthur.melin/Code/PSU_2016_my_ls
##
## Made by Arthur Melin
## Login   <arthur.melin@epitech.net>
##
## Started on  Thu Nov 24 21:40:26 2016 Arthur Melin
## Last update Thu Dec  1 19:51:19 2016 Arthur Melin
##

CC		=	gcc

CFLAGS		=	-c -g -W -Wall -Wextra -Iinclude -O3

LDFLAGS		=	-Llib/my -lmy

RM		=	rm -f

NAME		=	my_ls

SRCDIR		=	src

SRC		=	my_ls.c		\
			handle_error.c	\
			parse_args.c	\
			fs.c		\
			spacing.c	\
			ll_merge_sort.c	\
			stat.c

INCDIR		=	include

INC		=	my.h		\
			my_ls.h

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
