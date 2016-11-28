/*
** my_putchar_hex.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

void	my_putchar_hex(char c, char *hex_digits)
{
  my_putchar(hex_digits[(c >> 4) & 0xF]);
  my_putchar(hex_digits[c & 0xF]);
}