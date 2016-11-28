/*
** my_printf_func_map.c for PSU_2016_my_printf in /home/arthur.melin/Code/PSU_2016/PSU_2016_my_printf/src
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov 14 17:03:51 2016 Arthur Melin
** Last update Mon Nov 14 21:42:12 2016 Arthur Melin
*/

#include "my_printf.h"

static void	my_printf_func_map_put(t_printf_func_map *map, int i,
				       char chr, t_printf_func func)
{
  map[i].chr = chr;
  map[i].func = func;
}

void	my_printf_func_map_fill(t_printf_func_map *map)
{
  int	i;

  i = 0;
  my_printf_func_map_put(map, i++, 'd', my_printf_nbr_dec_s);
  my_printf_func_map_put(map, i++, 'i', my_printf_nbr_dec_s);
  my_printf_func_map_put(map, i++, 'u', my_printf_nbr_dec_u);
  my_printf_func_map_put(map, i++, 'o', my_printf_nbr_oct);
  my_printf_func_map_put(map, i++, 'b', my_printf_nbr_bin);
  my_printf_func_map_put(map, i++, 'x', my_printf_nbr_hex_l);
  my_printf_func_map_put(map, i++, 'X', my_printf_nbr_hex_u);
  my_printf_func_map_put(map, i++, 'c', my_printf_chr);
  my_printf_func_map_put(map, i++, 's', my_printf_str);
  my_printf_func_map_put(map, i++, 'S', my_printf_str_np);
  my_printf_func_map_put(map, i++, 'p', my_printf_ptr);
  my_printf_func_map_put(map, i++, 'n', my_printf_wrt);
  my_printf_func_map_put(map, i++, '%', my_printf_pct);
  my_printf_func_map_put(map, i++, 'm', my_printf_err);
}
