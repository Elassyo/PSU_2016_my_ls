/*
** my_strupcase.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (my_islower(str[i]))
	str[i] -= 32;
      i++;
    }
  return (str);
}
