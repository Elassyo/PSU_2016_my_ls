/*
** my_swap.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

int	my_swap(int *a, int *b)
{
  int	tmp;

  if (!a || !b)
    return (-1);
  tmp = *a;
  *a = *b;
  *b = tmp;
  return (0);
}

int	my_swap_char(char *a, char *b)
{
  char	tmp;

  if (!a || !b)
    return (-1);
  tmp = *a;
  *a = *b;
  *b = tmp;
  return (0);
}

int	my_swap_str(char **a, char **b)
{
  char	*tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
  return (0);
}
