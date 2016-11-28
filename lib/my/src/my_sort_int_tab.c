/*
** my_sort_int_tab.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

void	my_sort_int_tab(int *tab, int size)
{
  int	sort_offset;
  int	search_offset;
  int	min_offset;

  sort_offset = 0;
  while (sort_offset < size)
    {
      min_offset = sort_offset;
      search_offset = sort_offset;
      while (search_offset < size)
	{
	  if (tab[search_offset] < tab[min_offset])
	    min_offset = search_offset;
	  search_offset++;
	}
      my_swap(tab + sort_offset, tab + min_offset);
      sort_offset++;
    }
}
