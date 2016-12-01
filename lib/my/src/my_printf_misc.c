/*
** my_printf_misc.c for PSU_2016_my_printf in /home/arthur.melin/Code/PSU_2016/PSU_2016_my_printf/src
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Thu Nov 17 00:20:27 2016 Arthur Melin
** Last update Thu Nov 17 00:34:33 2016 Arthur Melin
*/

#include "my_printf.h"

int		my_printf_ptr(t_printf_fmt *fmt, va_list *args, int *written)
{
  uintmax_t		ptr;
  t_printf_base_fmt	base_fmt;

  ptr = va_arg(*args, uintmax_t);
  base_fmt.base = "0123456789abcdef";
  if (ptr == 0)
    {
      base_fmt.prefix = "(nil)";
      fmt->precision = 0;
    }
  else if (fmt->flag_plus)
    base_fmt.prefix = "+0x";
  else if (fmt->flag_space)
    base_fmt.prefix = " 0x";
  else
    base_fmt.prefix = "0x";
  fmt->flag_hash = 1;
  return (my_printf_nbr(fmt, ptr, written, &base_fmt));
}

int		my_printf_wrt(t_printf_fmt *fmt, va_list *args,
			      int *written_ptr)
{
  intmax_t	written;
  void		*ptr;

  ptr = va_arg(*args, void *);
  if (ptr == NULL)
    return (0);
  written = *written_ptr;
  if (fmt->length_modifier == 0)
    fmt->length_modifier = sizeof(int);
  my_memcpy(ptr, &written, fmt->length_modifier);
  return (0);
}

int		my_printf_pct(t_printf_fmt *fmt, va_list *args,
			      int *written_ptr)
{
  (void)args;
  my_putchar_fd(fmt->fd, '%');
  (*written_ptr)++;
  return (0);
}
