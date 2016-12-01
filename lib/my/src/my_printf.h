/*
** my_printf.h for PSU_2016_my_printf in /home/arthur.melin/Code/PSU_2016/PSU_2016_my_printf/src
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 22:14:18 2016 Arthur Melin
** Last update Wed Nov 16 10:20:32 2016 Arthur Melin
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

# include <errno.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <string.h>
# include "my.h"

typedef struct	s_printf_fmt
{
  int		fd;
  char		flag_ljust;
  char		flag_plus;
  char		flag_space;
  char		flag_hash;
  char		flag_zero;
  int		field_width;
  int		precision;
  int		length_modifier;
  char		specifier;
}		t_printf_fmt;

typedef struct	s_printf_base_fmt
{
  char		*base;
  char		*prefix;
}		t_printf_base_fmt;

typedef int (*t_printf_func)(t_printf_fmt *, va_list *, int *);

typedef struct		s_printf_func_map
{
  char			chr;
  t_printf_func		func;
}			t_printf_func_map;

void	my_printf_parse_flags(t_printf_fmt *f, const char **s);
void	my_printf_parse_width(t_printf_fmt *f, const char **s, va_list *a);
void	my_printf_parse_precision(t_printf_fmt *f, const char **s, va_list *a);
void	my_printf_parse_length(t_printf_fmt *f, const char **s);

void	my_printf_func_map_fill(t_printf_func_map *map);

uintmax_t	my_printf_arg_mask(int length_modifier);

int	my_printf_nbr(t_printf_fmt *fmt, uintmax_t nbr, int *written,
		      t_printf_base_fmt *base_fmt);
int	my_printf_nbr_length(t_printf_fmt *fmt, uintmax_t nbr, int base_len);

int	my_printf_nbr_dec_s(t_printf_fmt *fmt, va_list *args, int *written);
int	my_printf_nbr_dec_u(t_printf_fmt *fmt, va_list *args, int *written);
int	my_printf_nbr_oct(t_printf_fmt *fmt, va_list *args, int *written);
int	my_printf_nbr_bin(t_printf_fmt *fmt, va_list *args, int *written);
int	my_printf_nbr_hex_l(t_printf_fmt *fmt, va_list *args, int *written);
int	my_printf_nbr_hex_u(t_printf_fmt *fmt, va_list *args, int *written);
int	my_printf_chr(t_printf_fmt *fmt, va_list *args, int *written);
int	my_printf_str(t_printf_fmt *fmt, va_list *args, int *written);
int	my_printf_str_np(t_printf_fmt *fmt, va_list *args, int *written);
int	my_printf_ptr(t_printf_fmt *fmt, va_list *args, int *written);
int	my_printf_wrt(t_printf_fmt *fmt, va_list *args, int *written);
int	my_printf_pct(t_printf_fmt *fmt, va_list *args, int *written);
int	my_printf_err(t_printf_fmt *fmt, va_list *args, int *written);

#endif /* !MY_PRINTF_H_ */
