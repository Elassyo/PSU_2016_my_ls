/*
** my_str_to_wordtab.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"
#include <stdlib.h>

static int	my_count_words(char *str)
{
  int		in_word;
  int		words;

  in_word = 0;
  words = 0;
  while (*str)
    {
      if (!in_word && my_isalnum(*str))
	{
	  in_word = 1;
	  words++;
	}
      if (in_word && !my_isalnum(*str))
	in_word = 0;
      str++;
    }
  return (words);
}

static char	*my_worddup(char *str)
{
  char		*word;
  int		len;

  len = 0;
  while (my_isalnum(*str++))
    len++;
  word = malloc(len + 1);
  if (word)
    my_strncpy(word, str, len);
  return (word);
}

char	**my_str_to_wordtab(char *str)
{
  int	offset;
  int	in_word;
  char	**word_tab;

  word_tab = malloc((my_count_words(str) + 1) * sizeof(char *));
  if (word_tab)
    {
      offset = 0;
      in_word = 0;
      while (*str)
	{
	  if (!in_word && my_isalnum(*str))
	    {
	      word_tab[offset++] = my_worddup(str);
	      in_word = 1;
	    }
	  if (!my_isalnum(*str))
	    in_word = 0;
	  str++;
	}
      word_tab[offset] = 0;
    }
  return (word_tab);
}
