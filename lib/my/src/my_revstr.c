/*
** my_revstr.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	len;
  int	i;

  len = 0;
  while (str[len])
    len++;
  i = 0;
  while (i < (len / 2))
    {
      my_swap_char(str + i, str + len - i - 1);
      i++;
    }
  return (str);
}
