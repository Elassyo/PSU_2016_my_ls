/*
** fs.c for PSU_2016_my_ls in /home/arthur.melin/Code/PSU_2016_my_ls
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Thu Dec  1 00:18:09 2016 Arthur Melin
** Last update Thu Dec  1 12:45:33 2016 Arthur Melin
*/

#include <my_ls.h>

t_ls_file	*fs_read_file(t_ls_opts *opts, char *path, char *name)
{
  t_ls_file	*file;

  if (!(file = malloc(sizeof(t_ls_file))))
    return (malloc_failed());
  my_memset(file, 0, sizeof(t_ls_file));
  if (name == NULL)
    file->path = my_strdup(path);
  else
    {
      if (!(file->path = malloc(my_strlen(path) + my_strlen(name) + 2)))
	{
	  free(file);
	  return (malloc_failed());
	}
      my_strcpy(file->path, path);
      if (my_strlen(path) > 0 && path[my_strlen(path) - 1] != '/')
	my_strcat(file->path, "/");
      my_strcat(file->path, name);
    }
  file->name = my_strdup(name ? name : path);
  if (opts->stat_func(file->path, &file->stat) == 0)
    return (file);
  free(file->path);
  free(file);
  return ((t_ls_file *)handle_error("cannot access", file->path, 0));
}

int		fs_read_path(t_ls_opts *opts, t_ls_path *path)
{
  DIR		*d;
  struct dirent	*ent;
  t_ls_file	*last;
  t_ls_file	*file;

  if (!(d = opendir(path->target->path)))
    return (handle_error("cannot open directory", path->target->path, 1));
  last = NULL;
  while ((ent = readdir(d)))
    {
      if (ent->d_name[0] != '.' || opts->all)
	{
	  if (!(file = fs_read_file(opts, path->target->path, ent->d_name)))
	    return (1);
	  if (last)
	    last->next = file;
	  else
	    path->content = file;
	  last = file;
	}
    }
  closedir(d);
  return (0);
}

void		fs_free_path(t_ls_path *path)
{
  t_ls_file	*last;
  t_ls_file	*current;

  if (!path)
    return ;
  free(path->str);
  if (path->target)
    {
      free(path->target->name);
      free(path->target->path);
    }
  free(path->target);
  if (path->content)
    {
      current = path->content;
      while (current)
	{
	  last = current;
	  current = current->next;
	  free(last->name);
	  free(last->path);
	  free(last);
	}
    }
}

long		fs_get_total(t_ls_path *path)
{
  long		total;
  t_ls_file	*current;

  total = 0;
  current = path->content;
  while (current)
    {
      total += current->stat.st_blocks;
      current = current->next;
    }
  return (total / 2);
}
