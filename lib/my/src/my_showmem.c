/*
** my_showmem.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

static void	my_putaddr(int addr)
{
  my_putchar_hex((addr >> 24) & 0xFF, "0123456789abcdef");
  my_putchar_hex((addr >> 16) & 0xFF, "0123456789abcdef");
  my_putchar_hex((addr >> 8) & 0xFF, "0123456789abcdef");
  my_putchar_hex(addr & 0xFF, "0123456789abcdef");
  my_putstr(": ");
}

static void	my_space_padding(int size)
{
  while (size--)
    my_putchar(' ');
}

static void	my_print_mem_line(char *line, int size)
{
  int		offset;

  offset = 0;
  while (offset < 16 && offset < size)
    {
      if (my_isprintable(line[offset]))
	my_putchar(line[offset]);
      else
	my_putchar('.');
      offset++;
    }
}

int	my_showmem(char *str, int size)
{
  int	line;
  int	offset;

  line = 0;
  while (line < (size / 16) + (size % 16 ? 1 : 0))
    {
      my_putaddr(line * 16);
      offset = 0;
      while (offset < 16 && (line * 16 + offset) < size)
	{
	  my_putchar_hex(str[line * 16 + offset], "0123456789abcdef");
	  if (offset++ % 2)
	    my_putchar(' ');
	}
      if (line == (size / 16))
	my_space_padding((2 * (16 - offset)) + ((15 - offset) / 2) + 1);
      offset = 0;
      my_print_mem_line(str + line * 16, size - (line * 16));
      my_putchar('\n');
      line++;
    }
  return (0);
}
