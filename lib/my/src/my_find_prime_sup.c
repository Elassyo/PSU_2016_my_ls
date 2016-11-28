/*
** my_find_prime_sup.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

int	my_find_prime_sup(int nb)
{
  if (nb <= 1)
    return (2);
  while (!my_is_prime(nb))
    {
      if (nb == 2147483647)
	return (0);
      nb++;
    }
  return (nb);
}
