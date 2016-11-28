/*
** my_getnbr_base.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

static int	my_map_nbr_base(char c, char *base)
{
  int		nbr;

  nbr = 0;
  while (c != *base && *base)
    {
      nbr++;
      base++;
    }
  if (*base)
    return (nbr);
  return (-1);
}

int	my_getnbr_base(char *str, char *base)
{
  int	base_len;
  int	number;
  int	sign;

  base_len = 0;
  while (base[base_len])
    base_len++;
  number = 0;
  sign = 1;
  while (*str && (*str == '-' || *str == '+'))
    {
      if (*str == '-')
	sign *= -1;
      str++;
    }
  while (*str && my_map_nbr_base(*str, base) >= 0)
    {
      if (number - my_map_nbr_base(*str, base) >= (2147483647 / base_len))
	return (0);
      number = number * base_len + my_map_nbr_base(*str++, base);
    }
  return (sign * number);
}
