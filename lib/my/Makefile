##
## Makefile for libmy in /home/arthur.melin/Code/libmy
##
## Made by Arthur Melin
## Login   <arthur.melin@epitech.net>
##
## Started on  Mon Nov  7 15:41:08 2016 Arthur Melin
## Last update Fri Nov 18 15:53:45 2016 Arthur Melin
##

CC	=	gcc

CFLAGS	=	-c -W -Wall -Wextra -pedantic

AR	=	ar -rc

CP	=	cp

MKDIR	=	mkdir -p

RM	=	rm -rf

NAME	=	libmy.a

SRCDIR	=	src

OBJDIR	=	tmp

SRC	=	my_find_prime_sup.c 	\
		my_getnbr_base.c 	\
		my_getnbr.c 		\
		my_isalnum.c 		\
		my_isalpha.c 		\
		my_islower.c 		\
		my_isneg.c 		\
		my_isnum.c 		\
		my_isupper.c		\
		my_issign.c		\
		my_is_prime.c 		\
		my_isprintable.c 	\
		my_math.c 		\
		my_memcpy.c		\
		my_memset.c		\
		my_power_ite.c		\
		my_power_rec.c 		\
		my_printf.c		\
		my_printf_parsers.c	\
		my_printf_func_map.c	\
		my_printf_nbr.c		\
		my_printf_nbr_dec.c	\
		my_printf_nbr_bases.c	\
		my_printf_chars.c	\
		my_printf_misc.c	\
		my_putchar_fd.c		\
		my_putchar_hex.c 	\
		my_putnbr_base.c 	\
		my_put_nbr.c 		\
		my_putstr_fd.c 		\
		my_revstr.c 		\
		my_showmem.c 		\
		my_showstr.c 		\
		my_show_wordtab.c 	\
		my_sort_int_tab.c 	\
		my_square_root.c 	\
		my_strcapitalize.c 	\
		my_strcat.c 		\
		my_strcmp.c 		\
		my_strcpy.c 		\
		my_strdup.c 		\
		my_str_isalpha.c 	\
		my_str_islower.c 	\
		my_str_isnum.c 		\
		my_str_isprintable.c 	\
		my_str_isupper.c 	\
		my_strlen.c 		\
		my_strlowcase.c 	\
		my_strncat.c 		\
		my_strncmp.c 		\
		my_strncpy.c 		\
		my_strstr.c 		\
		my_str_to_wordtab.c 	\
		my_strupcase.c 		\
		my_swap.c

HDR	=	my.h			\
		my_printf.h

OBJ	=	$(SRC:.c=.o)

INC	=	$(SRCDIR)/my.h

INCDIR	=	../../include

all: $(NAME)

$(INCDIR):
	$(MKDIR) $(INCDIR)

dist: $(NAME) | $(INCDIR)
	$(CP) $(INC) $(INCDIR)/

$(OBJDIR):
	$(MKDIR) $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(addprefix $(SRCDIR)/, $(HDR)) | $(OBJDIR)
	$(CC) $< $(CFLAGS) -o $@

$(NAME): $(addprefix $(OBJDIR)/, $(OBJ))
	$(AR) $(NAME) $(addprefix $(OBJDIR)/, $(OBJ))

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all dist clean fclean re
