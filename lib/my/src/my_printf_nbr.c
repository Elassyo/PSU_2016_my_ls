/*
** my_printf_nbr.c for PSU_2016_my_printf in /home/arthur.melin/Code/PSU_2016/PSU_2016_my_printf/src
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Tue Nov 15 17:04:47 2016 Arthur Melin
** Last update Thu Nov 17 00:33:25 2016 Arthur Melin
*/

#include "my_printf.h"

int		my_printf_nbr_length(t_printf_fmt *fmt, uintmax_t nbr,
				     int base_length)
{
  int		length;

  if (nbr == 0 && fmt->precision != 0)
    return (1);
  length = 0;
  while (nbr)
    {
      nbr /= base_length;
      length++;
    }
  return (length);
}

int	my_printf_nbr_digits(t_printf_fmt *fmt, uintmax_t nbr,
			     char *base, int written)
{
  int	length;
  int	padding;
  int	base_length;

  base_length = my_strlen(base);
  length = my_printf_nbr_length(fmt, nbr, base_length);
  if (!fmt->flag_ljust && fmt->flag_zero && fmt->precision == -1)
    padding = fmt->field_width - length;
  else
    padding = fmt->precision - length;
  while (padding-- > 0 && ++written)
    my_putchar(base[0]);
  while (length-- && ++written)
    my_putchar(base[nbr / my_power_ite(base_length, length) % base_length]);
  return (written);
}

int		my_printf_nbr(t_printf_fmt *fmt, uintmax_t nbr,
			      int *written_ptr, t_printf_base_fmt *base_fmt)
{
  int		length;
  int		padding;
  int		written;

  length = my_printf_nbr_length(fmt, nbr, my_strlen(base_fmt->base));
  length += fmt->flag_hash ? my_strlen(base_fmt->prefix) : 0;
  written = 0;
  if (!fmt->flag_ljust && !fmt->flag_zero)
    {
      padding = fmt->field_width - MY_MAX(length, fmt->precision);
      while (padding-- > 0 && ++written)
	my_putchar(' ');
    }
  if (fmt->flag_hash)
    {
      my_putstr(base_fmt->prefix);
      written += my_strlen(base_fmt->prefix);
    }
  written = my_printf_nbr_digits(fmt, nbr, base_fmt->base, written);
  while (fmt->flag_ljust && written < fmt->field_width && ++written)
    my_putchar(' ');
  *written_ptr += written;
  return (0);
}
