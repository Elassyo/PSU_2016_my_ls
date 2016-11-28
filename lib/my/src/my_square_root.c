/*
** my_square_root.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

int	my_square_root(int nb)
{
  long	up;
  long	dw;
  long	md;

  if (nb < 0)
    return (0);
  dw = 0;
  up = nb;
  while (up - dw > 1)
    {
      md = dw + (up - dw) / 2;
      if (dw * dw <= nb && nb <= md * md)
	up = md;
      else
	dw = md;
    }
  if (dw * dw == nb)
    return (dw);
  if (up * up == nb)
    return (up);
  return (0);
}
