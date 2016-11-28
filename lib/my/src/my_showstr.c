/*
** my_showstr.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

int	my_showstr(char *str)
{
  while (*str)
    {
      if (my_isprintable(*str))
	my_putchar(*str);
      else
	{
	  my_putchar('\\');
	  my_putchar_hex(*str, "0123456789abcdef");
	}
      str++;
    }
  return (0);
}
