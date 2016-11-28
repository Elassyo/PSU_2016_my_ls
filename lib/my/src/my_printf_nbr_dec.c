/*
** my_printf_nbr_dec.c for PSU_2016_my_printf in /home/arthur.melin/Code/PSU_2016/PSU_2016_my_printf/src
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Tue Nov 15 20:21:08 2016 Arthur Melin
** Last update Wed Nov 16 18:54:59 2016 Arthur Melin
*/

#include "my_printf.h"

static intmax_t		signed_nbr_to_intmax(int size, va_list *args)
{
  intmax_t		res;
  intmax_t		sign;

  res = va_arg(*args, intmax_t) & my_printf_arg_mask(size);
  sign = res & (1 << (size * 8 - 1));
  if (sign)
    {
      res ^= my_printf_arg_mask(size);
      res = -res - 1;
    }
  return (res);
}

int			my_printf_nbr_dec_s(t_printf_fmt *fmt, va_list *args,
					    int *written)
{
  intmax_t		nbr;
  t_printf_base_fmt	base_fmt;

  nbr = signed_nbr_to_intmax(fmt->length_modifier, args);
  base_fmt.base = "0123456789";
  if (nbr < 0 || fmt->flag_plus || fmt->flag_space)
    {
      base_fmt.prefix = nbr < 0 ? "-" : (fmt->flag_plus ? "+" : " ");
      fmt->flag_hash = 1;
    }
  else
    base_fmt.prefix = "";
  return (my_printf_nbr(fmt, MY_ABS(nbr), written, &base_fmt));
}

int			my_printf_nbr_dec_u(t_printf_fmt *fmt, va_list *args,
					    int *written)
{
  uintmax_t		nbr;
  t_printf_base_fmt	base_fmt;

  nbr = va_arg(*args, uintmax_t) & my_printf_arg_mask(fmt->length_modifier);
  base_fmt.base = "0123456789";
  base_fmt.prefix = "";
  return (my_printf_nbr(fmt, nbr, written, &base_fmt));
}
