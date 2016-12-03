/*
** spacing.c for PSU_2016_my_ls in /home/arthur.melin/Code/PSU_2016_my_ls
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Sat Dec  3 17:51:36 2016 Arthur Melin
** Last update Sat Dec  3 19:16:13 2016 Arthur Melin
*/

#include <my_ls.h>

static int	my_nbrlen(long nbr)
{
  int		res;

  res = 1;
  while (nbr / my_power_ite(10, res) && res < 18)
    res++;
  return (res);
}

void		spacing_calc(t_ls_path *path)
{
  t_ls_file	*c;

  my_memset(&path->spacing, 0, sizeof(t_ls_spacing));
  c = path->content;
  while (c)
    {
      if (my_nbrlen(c->stat.st_nlink) > path->spacing.hard_links)
	path->spacing.hard_links = my_nbrlen(c->stat.st_nlink);
      if (my_strlen(getpwuid(c->stat.st_uid)->pw_name) > path->spacing.owner)
	path->spacing.owner = my_strlen(getpwuid(c->stat.st_uid)->pw_name);
      if (my_strlen(getgrgid(c->stat.st_gid)->gr_name) > path->spacing.group)
	path->spacing.group = my_strlen(getgrgid(c->stat.st_gid)->gr_name);
      if (S_ISCHR(c->stat.st_mode) || S_ISBLK(c->stat.st_mode))
	{
	  if (my_nbrlen(major(c->stat.st_rdev)) > path->spacing.major)
	    path->spacing.major = my_nbrlen(major(c->stat.st_rdev));
	  if (my_nbrlen(minor(c->stat.st_rdev)) > path->spacing.minor)
	    path->spacing.minor = my_nbrlen(minor(c->stat.st_rdev));
	}
      else if (my_nbrlen(c->stat.st_size) > path->spacing.size)
	path->spacing.size = my_nbrlen(c->stat.st_size);
      c = c->next;
    }
}
