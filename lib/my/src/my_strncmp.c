/*
** my_strncmp.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (*s1 && *s2 && *s1 == *s2 && i < n)
    {
      i++;
      if (i < n)
	{
	  s1++;
	  s2++;
	}
    }
  return (*s1 - *s2);
}
