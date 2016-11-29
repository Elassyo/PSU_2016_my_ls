/*
** my_ls.c for PSU_2016_my_ls in /home/arthur.melin/Code/PSU_2016_my_ls
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov 28 21:06:58 2016 Arthur Melin
** Last update Tue Nov 29 17:21:04 2016 Arthur Melin
*/

#include <my_ls.h>

int		main(int argc, char **argv)
{
  int		i;
  t_ls_args	args;

  my_memset(&args, 0, sizeof(t_ls_args));
  if (parse_args(&args, argc, argv))
      return (84);
  i = 0;
  while (args.paths[i])
    free(args.paths[i++]);
  free(args.paths);
  return (0);
}
