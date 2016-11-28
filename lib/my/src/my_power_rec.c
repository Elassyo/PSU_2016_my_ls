/*
** my_power_rec.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

int	my_power_rec(int nbr, int p)
{
  int	prev;

  if (p < 0)
    return (0);
  if (p == 0)
    return (1);
  if (p == 1)
    return (nbr);
  prev = my_power_rec(nbr, p - 1);
  if ((-2147483648 / my_abs(nbr)) > prev || prev > (2147483647 / my_abs(nbr)))
    return (0);
  return (nbr * prev);
}
