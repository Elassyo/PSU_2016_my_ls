/*
** my_printf_nbr_bases.c for PSU_2016_my_printf in /home/arthur.melin/Code/PSU_2016/PSU_2016_my_printf/src
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Tue Nov 15 22:46:47 2016 Arthur Melin
** Last update Thu Nov 17 00:30:48 2016 Arthur Melin
*/

#include "my_printf.h"

int			my_printf_nbr_oct(t_printf_fmt *fmt, va_list *args,
					  int *written)
{
  uintmax_t		nbr;
  t_printf_base_fmt	base_fmt;

  nbr = va_arg(*args, uintmax_t) & my_printf_arg_mask(fmt->length_modifier);
  base_fmt.base = "01234567";
  base_fmt.prefix = "0";
  return (my_printf_nbr(fmt, nbr, written, &base_fmt));
}

int			my_printf_nbr_bin(t_printf_fmt *fmt, va_list *args,
					  int *written)
{
  uintmax_t		nbr;
  t_printf_base_fmt	base_fmt;

  nbr = va_arg(*args, uintmax_t) & my_printf_arg_mask(fmt->length_modifier);
  base_fmt.base = "01";
  base_fmt.prefix = "0b";
  return (my_printf_nbr(fmt, nbr, written, &base_fmt));
}

int			my_printf_nbr_hex_l(t_printf_fmt *fmt, va_list *args,
					    int *written)
{
  uintmax_t		nbr;
  t_printf_base_fmt	base_fmt;

  nbr = va_arg(*args, uintmax_t) & my_printf_arg_mask(fmt->length_modifier);
  base_fmt.base = "0123456789abcdef";
  base_fmt.prefix = "0x";
  return (my_printf_nbr(fmt, nbr, written, &base_fmt));
}

int			my_printf_nbr_hex_u(t_printf_fmt *fmt, va_list *args,
					    int *written)
{
  uintmax_t		nbr;
  t_printf_base_fmt	base_fmt;

  nbr = va_arg(*args, uintmax_t) & my_printf_arg_mask(fmt->length_modifier);
  base_fmt.base = "0123456789ABCDEF";
  base_fmt.prefix = "0X";
  return (my_printf_nbr(fmt, nbr, written, &base_fmt));
}
