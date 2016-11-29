/*
** my_ls.h for PSU_2016_my_ls in /home/arthur.melin/Code/PSU_2016_my_ls
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov 28 21:33:09 2016 Arthur Melin
** Last update Tue Nov 29 16:59:40 2016 Arthur Melin
*/

#ifndef MY_LS_H_
# define MY_LS_H_

# include <stdlib.h>
# include <my.h>

typedef struct	s_ls_opts
{
  char		dir;
  char		lst;
  char		rec;
  char		rev;
  char		tim;
}		t_ls_opts;

typedef struct	s_ls_args
{
  t_ls_opts	opts;
  char 		**paths;
}		t_ls_args;

int	parse_args(t_ls_args *opts, int argc, char **argv);

#endif /* !MY_LS_H_ */
