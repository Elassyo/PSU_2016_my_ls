/*
** my_is_prime.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

int	my_is_prime(int nb)
{
  int	div;

  if (nb <= 1)
    return (0);
  div = 2;
  while (nb != div)
    {
      if (nb % div == 0)
	return (0);
      div++;
    }
  return (1);
}
