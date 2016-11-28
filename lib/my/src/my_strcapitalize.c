/*
** my_strcapitalize.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

char	*my_strcapitalize(char *str)
{
  int	i;
  int	in_word;

  i = 0;
  in_word = 0;
  while (str[i])
    {
      if (in_word)
	{
	  if (!my_isalpha(str[i]) && !my_isnum(str[i]))
	    in_word = 0;
	  if (my_isupper(str[i]))
	    str[i] += 32;
	}
      if (!in_word && (my_isalpha(str[i]) || my_isnum(str[i])))
	{
	  if (my_islower(str[i]))
	    str[i] -= 32;
	  in_word = 1;
	}
      i++;
    }
  return (str);
}
