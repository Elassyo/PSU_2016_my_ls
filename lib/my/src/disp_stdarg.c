/*
** disp_stdarg.c for PSU_2016_my_printf_bootstrap in /home/arthur.melin/Code/PSU_2016/PSU_2016_my_printf_bootstrap/src
** 
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
** 
** Started on  Mon Nov  7 16:18:40 2016 Arthur Melin
** Last update Mon Nov  7 16:31:06 2016 Arthur Melin
*/

#include <stdarg.h>
#include "my.h"

int		disp_stdarg(char *s, ...)
{
  va_list	args;

  va_start(args, s);
  while (*s)
    {
      if (*s == 'c')
	my_putchar(va_arg(args, int));
      else if (*s == 's')
	my_putstr(va_arg(args, char *));
      else if (*s == 'i')
	my_put_nbr(va_arg(args, int));
      s++;
      my_putchar('\n');
    }
  va_end(args);
  return (0);
}
