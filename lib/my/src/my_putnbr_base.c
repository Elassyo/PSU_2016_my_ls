/*
** my_putnbr_base.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

int	my_putnbr_base(int nbr, char *base)
{
  int	i;
  int	base_len;

  base_len = 0;
  while (base[base_len])
    base_len++;
  if (base_len < 2)
    return (-1);
  if (nbr == 0)
    my_putchar(*base);
  if (nbr < 0)
    {
      my_putchar('-');
      nbr = -nbr;
    }
  i = 0;
  while (my_power_rec(base_len, i - 1) < (2147483647 / base_len)
	 && nbr >= my_power_rec(base_len, i))
    i++;
  while (i-- > 0)
    my_putchar(base[nbr / my_power_rec(base_len, i) % base_len]);
  return (0);
}
