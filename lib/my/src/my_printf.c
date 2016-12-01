/*
** my_printf.c for PSU_2016_my_printf in /home/arthur.melin/Code/PSU_2016/PSU_2016_my_printf/src
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 21:13:23 2016 Arthur Melin
** Last update Thu Nov 17 00:28:50 2016 Arthur Melin
*/

#include "my.h"
#include "my_printf.h"

uintmax_t	my_printf_arg_mask(int length_modifier)
{
  uintmax_t	mask;

  mask = 0;
  if (length_modifier == 0)
    length_modifier = sizeof(int);
  while (length_modifier--)
    {
      mask <<= 8;
      mask |= 0xFF;
    }
  return (mask);
}

static int		my_printf_do(int fd, const char *str,
                        	     va_list *args, int *written)
{
  const char		*str_start;
  int			i;
  t_printf_fmt		fmt;
  t_printf_func_map	func_map[14];

  str_start = str;
  str++;
  my_memset(&fmt, 0, sizeof(fmt));
  fmt.fd = fd;
  my_printf_parse_flags(&fmt, &str);
  my_printf_parse_width(&fmt, &str, args);
  my_printf_parse_precision(&fmt, &str, args);
  my_printf_parse_length(&fmt, &str);
  fmt.specifier = *str++;
  my_printf_func_map_fill(func_map);
  i = 0;
  while (i < 14)
    {
      if (func_map[i].chr == fmt.specifier)
	return (func_map[i].func(&fmt, args, written) ? 0 : str - str_start);
      i++;
    }
  return (0);
}

int		my_fprintf(int fd, const char *format, ...)
{
  int		off;
  int		written;
  va_list	args;

  if (!format)
    return (-1);
  written = 0;
  va_start(args, format);
  while (*format)
    {
      off = 0;
      if (*format != '%' || !(off = my_printf_do(fd, format, &args, &written)))
	{
	  my_putchar_fd(fd, *format);
	  off = 1;
	  written++;
	}
      format += off;
    }
  va_end(args);
  return (written);
}
