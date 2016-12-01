/*
** my_printf_chars.c for PSU_2016_my_printf in /home/arthur.melin/Code/PSU_2016/PSU_2016_my_printf/src
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Wed Nov 16 10:59:23 2016 Arthur Melin
** Last update Wed Nov 16 21:03:32 2016 Arthur Melin
*/

#include "my_printf.h"

static int	my_strlen_np(char *str)
{
  int		length;

  length = 0;
  while (*str)
    {
      length += my_isprintable(*str) ? 1 : 4;
      str++;
    }
  return (length);
}

int	my_printf_chr(t_printf_fmt *fmt, va_list *args, int *written_ptr)
{
  int	written;

  written = 0;
  if (!fmt->flag_ljust)
    {
      while (fmt->field_width - 1  > 0 && fmt->field_width-- && ++written)
      	my_putchar_fd(fmt->fd, ' ');
    }
  my_putchar_fd(fmt->fd, va_arg(*args, int));
  written++;
  while (fmt->flag_ljust && written < fmt->field_width && ++written)
    my_putchar_fd(fmt->fd, ' ');
  *written_ptr += written;
  return (0);
}

int	my_printf_str(t_printf_fmt *fmt, va_list *args, int *written_ptr)
{
  char	*str;
  int	length;
  int	written;

  if (!(str = va_arg(*args, char *)))
    str = "(null)";
  written = 0;
  length = my_strlen(str);
  if (!fmt->flag_ljust)
    {
      while (fmt->field_width - length > 0 && fmt->field_width-- && ++written)
      	my_putchar_fd(fmt->fd, ' ');
    }
  my_putstr_fd(fmt->fd, str);
  written += length;
  while (fmt->flag_ljust && written < fmt->field_width && ++written)
    my_putchar_fd(fmt->fd, ' ');
  *written_ptr += written;
  return (0);
}

int	my_printf_str_np(t_printf_fmt *fmt, va_list *args, int *written_ptr)
{
  char	*str;
  int	length;
  int	written;

  if (!(str = va_arg(*args, char *)))
    str = "(null)";
  written = 0;
  length = my_strlen_np(str);
  if (!fmt->flag_ljust)
    {
      while (fmt->field_width - length > 0 && fmt->field_width-- && ++written)
      	my_putchar_fd(fmt->fd, ' ');
    }
  while (*str)
    {
      if (my_isprintable(*str) && ++written)
	my_putchar_fd(fmt->fd, *str++);
      else
	written += my_fprintf(fmt->fd, "\\%03hho", *str++);
    }
  while (fmt->flag_ljust && written < fmt->field_width && ++written)
    my_putchar_fd(fmt->fd, ' ');
  *written_ptr += written;
  return (0);
}

int	my_printf_err(t_printf_fmt *fmt, va_list *args, int *written_ptr)
{
  char	*err_msg;

  (void)fmt;
  (void)args;
  err_msg = strerror(errno);
  *written_ptr += my_strlen(err_msg);
  my_putstr_fd(fmt->fd, err_msg);
  return (0);
}
