/*
** my_strncat.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

char	*my_strncat(char *dest, char *src, int n)
{
  int	len;
  int	i;

  len = my_strlen(dest);
  i = 0;
  while (src[i] && i < n)
    {
      dest[len + i] = src[i];
      i++;
    }
  dest[len + i] = 0;
  return (dest);
}
