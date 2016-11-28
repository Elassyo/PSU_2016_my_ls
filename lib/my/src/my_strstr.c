/*
** my_strstr.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

char	*my_strstr(char *str, char *to_find)
{
  int	len;

  len = 0;
  while (to_find[len])
    len++;
  if (len == 0)
    return (str);
  while (*str && my_strncmp(str, to_find, len))
    str++;
  if (*str)
    return (str);
  return (0);
}
