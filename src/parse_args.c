/*
** parse_args.c for PSU_2016_my_ls in /home/arthur.melin/Code/PSU_2016_my_ls
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Tue Nov 29 16:58:54 2016 Arthur Melin
** Last update Tue Nov 29 17:21:23 2016 Arthur Melin
*/

#include <my_ls.h>

int	parse_opt(t_ls_opts *opts, char *arg)
{
  char	*err;

  while (*arg)
    {
      if (*arg == 'l')
	opts->lst = 1;
      else if (*arg == 'R')
	opts->rec = 1;
      else if (*arg == 'd')
	opts->dir = 1;
      else if (*arg == 'r')
	opts->rev = 1;
      else if (*arg == 't')
	opts->tim = 1;
      else
	{
	  err = my_strdup("invalid option -- \'_\'\n");
	  err[19] = *arg;
	  my_puterr(err);
	  free(err);
	  return (1);
	}
      arg++;
    }
  return (0);
}

int	parse_opts(t_ls_opts *opts, int argc, char **argv)
{
  int	i;
  int	paths;
  char	*arg;

  i = 1;
  paths = 0;
  while (i < argc)
    {
      arg = argv[i++];
      if (*arg++ == '-')
	{
	  if (parse_opt(opts, arg))
	    return (-1);
	}
      else
	paths++;
    }
  return (paths);
}

int	parse_args(t_ls_args *args, int argc, char **argv)
{
  int	i;
  int	j;
  int	ret;

  if ((ret = parse_opts(&args->opts, argc, argv)) == -1)
    return (1);
  if (!(args->paths = malloc((ret == 0 ? 2 : ret + 1) * sizeof(char *))))
    {
      my_puterr("error: malloc failed\n");
      return (1);
    }
  i = 0;
  if (ret == 0)
    args->paths[i++] = my_strdup(".");
  else
    {
      j = 0;
      while (++j < argc)
      	if (*argv[j] != '-')
      	  args->paths[i++] = my_strdup(argv[j]);
    }
  args->paths[i] = NULL;
  return (0);
}
