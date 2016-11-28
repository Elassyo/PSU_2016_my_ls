/*
** my_put_nbr.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

int	my_put_nbr(int nbr)
{
  int	i;

  if (nbr == 0)
    my_putchar('0');
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
    }
  i = 0;
  while (my_power_rec(10, i - 1) < 214748364
         && nbr >= my_power_rec(10, i))
    i++;
  while (i-- > 0)
    my_putchar('0' + (nbr / my_power_rec(10, i) % 10));
  return (0);
}
