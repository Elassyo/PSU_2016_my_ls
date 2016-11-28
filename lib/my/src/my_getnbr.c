/*
** my_getnbr.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

int	my_getnbr(char *str)
{
  int	number;
  int	sign;

  number = 0;
  sign = 1;
  while (*str && (*str == '-' || *str == '+'))
    {
      if (*str == '-')
	sign *= -1;
      str++;
    }
  if (sign == -1 && !my_strcmp(str, "2147483648"))
    return (-2147483648);
  while (*str && my_isnum(*str))
    {
      if (number - *str - '0' >= (2147483647 / 10))
	return (0);
      number = number * 10 + *str++ - '0';
    }
  return (sign * number);
}
