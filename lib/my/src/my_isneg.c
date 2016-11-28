/*
** my_isneg.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

int	my_isneg(int n)
{
  if (n < 0)
    my_putchar('N');
  else
    my_putchar('P');
  return (0);
}
