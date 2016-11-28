/*
** my_strcpy.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (*src)
    dest[i++] = *src++;
  dest[i] = '\0';
  return (dest);
}
