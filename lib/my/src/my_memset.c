/*
** my_memset.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

void	*my_memset(void *ptr, int c, int size)
{
  int	i;

  i = 0;
  while (i < size)
    ((char *)ptr)[i++] = c;
  return (ptr);
}
