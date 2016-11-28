/*
** sum_stdarg.c for PSU_2016_my_printf_bootstrap in /home/arthur.melin/Code/PSU_2016/PSU_2016_my_printf_bootstrap/src
** 
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
** 
** Started on  Mon Nov  7 16:03:24 2016 Arthur Melin
** Last update Mon Nov  7 16:12:56 2016 Arthur Melin
*/

#include <stdarg.h>
#include "my.h"

int		sum_stdarg(int i, int nb, ...)
{
  int		sum;
  va_list	args;

  sum = 0;
  va_start(args, nb);
  if (i == 0)
    {
      while (nb--)
	sum += va_arg(args, int);
    }
  else if (i == 1)
    {
      while (nb--)
	sum += my_strlen(va_arg(args, char *));
    }
  else
    sum = 84;
  va_end(args);
  return (sum);
}
