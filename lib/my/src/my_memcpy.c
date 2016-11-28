/*
** my_memcpy.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

void	*my_memcpy(void *dest, void *src, int size)
{
  int	offset;

  offset = 0;
  while (offset < size)
    {
      ((char *)dest)[offset] = ((char *)src)[offset];
      offset++;
    }
  return (dest);
}
