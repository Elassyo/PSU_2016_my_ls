/*
** my_printf_parsers.c for PSU_2016_my_printf in /home/arthur.melin/Code/PSU_2016/PSU_2016_my_printf/src
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov 14 16:41:43 2016 Arthur Melin
** Last update Tue Nov 15 20:39:09 2016 Arthur Melin
*/

#include "my_printf.h"

void	my_printf_parse_flags(t_printf_fmt *fmt, const char **str)
{
  int	cont;

  cont = 1;
  while (cont)
    {
      if (**str == '-')
	fmt->flag_ljust = 1;
      else if (**str == '+')
	fmt->flag_plus = 1;
      else if (**str == ' ')
	fmt->flag_space = 1;
      else if (**str == '#')
	fmt->flag_hash = 1;
      else if (**str == '0')
	fmt->flag_zero = 1;
      else
	cont = 0;
      if (cont)
	(*str)++;
    }
}

void	my_printf_parse_width(t_printf_fmt *fmt, const char **str,
			      va_list *args)
{
  if (**str == '*')
    {
      fmt->field_width = va_arg(*args, int);
      (*str)++;
    }
  else
    {
      while (my_isnum(**str))
	{
	  fmt->field_width *= 10;
	  fmt->field_width += **str - '0';
	  (*str)++;
	}
    }
}

void	my_printf_parse_precision(t_printf_fmt *fmt, const char **str,
				  va_list *args)
{
  if (**str == '.')
    {
      (*str)++;
      if (**str == '*')
	{
	  fmt->precision = va_arg(*args, int);
	  (*str)++;
	}
      else
	{
	  while (my_isnum(**str))
	    {
	      fmt->precision *= 10;
	      fmt->precision += **str - '0';
	      (*str)++;
	    }
	}
    }
  else
    fmt->precision = -1;
}

void	my_printf_parse_length(t_printf_fmt *fmt, const char **str)
{
  if (**str == 'h' && *(*str + 1) == 'h')
    {
      fmt->length_modifier = sizeof(char);
      (*str)++;
    }
  else if ((**str == 'l' && *(*str + 1) == 'l') || **str == 'L')
    {
      fmt->length_modifier = sizeof(long long);
      *str += (**str == 'l' ? 1 : 0);
    }
  else if (**str == 'h')
    fmt->length_modifier = sizeof(short);
  else if (**str == 'l')
    fmt->length_modifier = sizeof(long);
  else if (**str == 'j')
    fmt->length_modifier = sizeof(intmax_t);
  else if (**str == 'z')
    fmt->length_modifier = sizeof(size_t);
  else if (**str == 't')
    fmt->length_modifier = sizeof(ptrdiff_t);
  else
    return ;
  (*str)++;
}
