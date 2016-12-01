/*
** my_ls.c for PSU_2016_my_ls in /home/arthur.melin/Code/PSU_2016_my_ls
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov 28 21:06:58 2016 Arthur Melin
** Last update Thu Dec  1 14:01:33 2016 Arthur Melin
*/

#include <my_ls.h>

void		my_ls_print(t_ls_opts *opts, t_ls_file *file)
{
  char		*mode_str;

  if (opts->list)
    {
      mode_str = stat_get_mode_str(file->stat.st_mode);
      my_printf("%s %s\n", mode_str, file->name);
      free(mode_str);
    }
  else
    my_printf("%s\n", file->name);
}

int		my_ls(t_ls_opts *opts, t_ls_path *path, char first)
{
  t_ls_file	*current;

  if (opts->directory || !S_ISDIR(path->target->stat.st_mode))
    my_ls_print(opts, path->target);
  else
    {
      if (opts->arg_paths)
	my_printf("%s%s:\n", first ? "" : "\n", path->target->path);
      if (opts->list)
      	my_printf("total %ld\n", fs_get_total(path));
      current = path->content;
      while (current)
	{
	  my_ls_print(opts, current);
	  current = current->next;
	}
    }
  return (0);
}

int		main(int argc, char **argv)
{
  int		i;
  int		ret;
  t_ls_args	args;

  my_memset(&args, 0, sizeof(t_ls_args));
  if (parse_args(&args, argc, argv))
      return (84);
  args.opts.stat_func = args.opts.list ? lstat : stat;
  i = 0;
  ret = 0;
  while (args.paths[i].str)
    {
      args.paths[i].target = fs_read_file(&args.opts, args.paths[i].str, NULL);
      if (args.paths[i].target && !fs_read_path(&args.opts, &args.paths[i]))
      	my_ls(&args.opts, &args.paths[i], i == 0);
      else
	ret = 84;
      fs_free_path(&args.paths[i++]);
    }
  free(args.paths);
  return (ret);
}
