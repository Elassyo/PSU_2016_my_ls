/*
** my_ls.c for PSU_2016_my_ls in /home/arthur.melin/Code/PSU_2016_my_ls
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov 28 21:06:58 2016 Arthur Melin
** Last update Sat Dec  3 17:32:49 2016 Arthur Melin
*/

#include <my_ls.h>

int		my_ls_recurse(t_ls_opts *opts, t_ls_path *path)
{
  int		ret;
  t_ls_path	sub;
  t_ls_file	*c;

  ret = 0;
  c = path->content;
  while (c)
    {
      if (S_ISDIR(c->stat.st_mode) && strcmp(c->name, ".") &&
	  strcmp(c->name, ".."))
	{
	  my_memset(&sub, 0, sizeof(t_ls_path));
	  if (!(sub.target = fs_read_file(opts, path->str, c->name)))
	    ret = 1;
	  if (sub.target && (sub.str = my_strdup(sub.target->path)))
	    ret |= my_ls(opts, &sub, 0);
	  fs_free_path(&sub);
	}
      c = c->next;
    }
  return (ret);
}

void		my_ls_print_list(t_ls_file *f, t_ls_spacing *s)
{
  char		link[1024];
  char		*mode;
  char		*mtime;

  mode = stat_get_mode_str(f->stat.st_mode);
  mtime = stat_get_mtime_str(f->stat.st_mtime);
  my_printf("%s %*ld %-*s %-*s ", mode, s->hard_links, f->stat.st_nlink,
	    s->owner, getpwuid(f->stat.st_uid)->pw_name,
	    s->group, getgrgid(f->stat.st_gid)->gr_name);
  if (*mode == 'c' || *mode == 'b')
    my_printf("%*d, %*d", MY_MAX(s->major, s->size - s->minor - 2),
              major(f->stat.st_rdev), s->minor, minor(f->stat.st_rdev));
  else
    my_printf("%*lld", MY_MAX(s->size, s->major + s->minor + 2),
              f->stat.st_size);
  my_printf(" %s %s", mtime, f->name);
  if (*mode == 'l')
    {
      my_memset(link, 0, 1024);
      link[readlink(f->path, link, 1023)] = 0;
      my_printf(" -> %s", link);
    }
  my_printf("\n");
  free(mtime);
  free(mode);
}

void		my_ls_print(t_ls_opts *opts, t_ls_file *f, t_ls_spacing *s)
{
  if (opts->list)
    my_ls_print_list(f, s);
  else
    my_printf("%s\n", f->name);
}

int		my_ls(t_ls_opts *opts, t_ls_path *path, char first)
{
  int		ret;
  t_ls_file	*current;

  ret = 0;
  if (opts->directory || !S_ISDIR(path->target->stat.st_mode))
    my_ls_print(opts, path->target, &path->spacing);
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
	  my_ls_print(opts, current, &path->spacing);
	  current = current->next;
	}
      ret |= opts->recursive && my_ls_recurse(opts, path);
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
