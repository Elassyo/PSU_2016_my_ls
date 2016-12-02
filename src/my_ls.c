/*
** my_ls.c for PSU_2016_my_ls in /home/arthur.melin/Code/PSU_2016_my_ls
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov 28 21:06:58 2016 Arthur Melin
** Last update Fri Dec  2 17:58:05 2016 Arthur Melin
*/

#include <my_ls.h>

int		my_ls_recurse(t_ls_opts *opts, t_ls_path *path)
{
  int		ret;
  t_ls_path	subpath;
  t_ls_file	*current;

  ret = 0;
  current = path->content;
  while (current)
    {
      my_memset(&subpath, 0, sizeof(t_ls_path));
      if (S_ISDIR(current->stat.st_mode) &&
          strcmp(current->name, ".") && strcmp(current->name, ".."))
	{
	  if (!(subpath.target = fs_read_file(opts, path->str, current->name)))
	    ret = 1;
	  else
	    {
	      subpath.str = my_strdup(subpath.target->path);
	      if (fs_read_path(opts, &subpath) || my_ls(opts, &subpath, 0))
	        ret = 1;
	    }
	  fs_free_path(&subpath);
	}
      current = current->next;
    }
  return (ret);
}

void		my_ls_print(t_ls_opts *opts, t_ls_file *file)
{
  char		link[256];
  char		*mode;
  char		*mtime;

  if (opts->list)
    {
      mode = stat_get_mode_str(file->stat.st_mode);
      mtime = stat_get_mtime_str(file->stat.st_mtime);
      my_printf("%s %3ld %-s %-s ", mode, file->stat.st_nlink,
		getpwuid(file->stat.st_uid)->pw_name,
		getgrgid(file->stat.st_gid)->gr_name);
      if (*mode == 'c' || *mode == 'b')
	my_printf("  %3d, %3d ", major(file->stat.st_rdev),
	          minor(file->stat.st_rdev));
      else
	my_printf("%10lld ", file->stat.st_size);
      my_printf("%s %s%s", mtime, file->name, *mode == 'l' ? " -> " : "");
      if (*mode == 'l')
      	write(1, link, readlink(file->path, link, 256));
      my_putchar('\n');
      free(mtime);
      free(mode);
    }
  else
    my_printf("%s\n", file->name);
}

int		my_ls(t_ls_opts *opts, t_ls_path *path, char first)
{
  int		ret;
  t_ls_file	*current;

  ret = 0;
  if (opts->directory || !S_ISDIR(path->target->stat.st_mode))
    my_ls_print(opts, path->target);
  else
    {
      if (fs_read_path(opts, path))
      	return (1);
      path->content = ll_merge_sort(opts, path->content);
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
      if (opts->recursive && my_ls_recurse(opts, path))
	ret = 1;
    }
  return (ret);
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
  args.opts.arg_paths |= args.opts.recursive;
  i = 0;
  ret = 0;
  while (args.paths[i].str)
    {
      args.paths[i].target = fs_read_file(&args.opts, args.paths[i].str, NULL);
      if (args.paths[i].target)
      	my_ls(&args.opts, &args.paths[i], i == 0);
      else
	ret = 84;
      fs_free_path(&args.paths[i++]);
    }
  free(args.paths);
  return (ret);
}
