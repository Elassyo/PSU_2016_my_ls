/*
** my_ls.h for PSU_2016_my_ls in /home/arthur.melin/Code/PSU_2016_my_ls
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov 28 21:33:09 2016 Arthur Melin
** Last update Thu Dec  1 15:50:51 2016 Arthur Melin
*/

#ifndef MY_LS_H_
# define MY_LS_H_

# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <dirent.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <my.h>

typedef struct	s_ls_opts
{
  char		all;
  char		directory;
  char		list;
  char		recursive;
  char		reverse;
  char		sort_time;
  char		arg_paths;
  int		(*stat_func)(const char *, struct stat *);
}		t_ls_opts;

typedef struct		s_ls_file
{
  char			*path;
  char			*name;
  struct stat		stat;
  struct s_ls_file	*next;
}			t_ls_file;

typedef struct		s_ls_path
{
  char			*str;
  struct s_ls_file	*target;
  struct s_ls_file	*content;
}			t_ls_path;

typedef struct	s_ls_args
{
  t_ls_opts	opts;
  t_ls_path	*paths;
}		t_ls_args;

int	my_ls(t_ls_opts *opts, t_ls_path *path, char first);

long	handle_error(char *msg, char *path, long ret_code);
void	*malloc_failed();

int	parse_args(t_ls_args *opts, int argc, char **argv);

t_ls_file	*fs_read_file(t_ls_opts *opts, char *path, char *name);
int		fs_read_path(t_ls_opts *opts, t_ls_path *path);
void		fs_free_path(t_ls_path *path);
long		fs_get_total(t_ls_path *path);

char	*stat_get_mode_str(mode_t mode);
char	*stat_get_mtime_str(time_t mtime);

t_ls_file	*ll_merge_sort(t_ls_opts *opts, t_ls_file *first);

#endif /* !MY_LS_H_ */
