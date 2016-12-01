/*
** parse_args.c for PSU_2016_my_ls in /home/arthur.melin/Code/PSU_2016_my_ls
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Tue Nov 29 16:58:54 2016 Arthur Melin
** Last update Thu Dec  1 00:27:11 2016 Arthur Melin
*/

#include <my_ls.h>

int	parse_opt(t_ls_opts *opts, char *arg)
{
  while (*arg)
    {
      if (*arg == 'a')
	opts->all = 1;
      else if (*arg == 'd')
	opts->directory = 1;
      else if (*arg == 'l')
	opts->list = 1;
      else if (*arg == 'R')
	opts->recursive = 1;
      else if (*arg == 'r')
	opts->reverse = 1;
      else if (*arg == 't')
	opts->sort_time = 1;
      else
	{
	  my_fprintf(2, "./my_ls: invalid option -- \'%c\'\n", *arg);
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
  if (!(args->paths = malloc((ret == 0 ? 2 : ret + 1) * sizeof(t_ls_path))))
    {
      my_puterr("error: malloc failed\n");
      return (1);
    }
  my_memset(args->paths, 0, (ret == 0 ? 2 : ret + 1) * sizeof(t_ls_path));
  i = 0;
  if (ret == 0)
    args->paths[i++].str = my_strdup(".");
  else
    {
      args->opts.arg_paths = ret > 1;
      j = 0;
      while (++j < argc)
      	if (*argv[j] != '-')
      	  args->paths[i++].str = my_strdup(argv[j]);
    }
  args->paths[i].str = NULL;
  return (0);
}
