/*
** ll_merge_sort.c for PSU_2016_my_ls in /home/arthur.melin/Code/PSU_2016_my_ls
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Thu Dec  1 15:33:20 2016 Arthur Melin
** Last update Thu Dec  1 15:51:28 2016 Arthur Melin
*/

#include <my_ls.h>

int		ll_len(t_ls_file *node)
{
  t_ls_file	*cur;
  int		len;

  len = 0;
  cur = node;
  while (cur)
    {
      cur = cur->next;
      len++;
    }
  return (len);
}

int	ll_cmp(t_ls_opts *opts, t_ls_file *a, t_ls_file *b)
{
  int	ret;

  if (opts->sort_time)
    ret = a->stat.st_mtime > b->stat.st_mtime;
  else
    ret = my_strcmp_uncase(a->name, b->name) > 0;
  return (opts->reverse ? !ret : ret);
}

t_ls_file	*ll_merge_list(t_ls_opts *opts, t_ls_file *a, t_ls_file *b)
{
  t_ls_file	*res;

  res = NULL;
  if (a == NULL)
    return (b);
  if (b == NULL)
    return (a);
  if (ll_cmp(opts, a, b))
    {
      res = b;
      res->next = ll_merge_list(opts, a, b->next);
    }
  else
    {
      res = a;
      res->next = ll_merge_list(opts, a->next, b);
    }
  return (res);
}

t_ls_file	*ll_merge_sort(t_ls_opts *opts, t_ls_file *first)
{
  int		mid;
  t_ls_file	*new;
  t_ls_file	*old;
  t_ls_file	*l1;
  t_ls_file	*l2;

  if (!first->next)
    return (first);
  old = first;
  mid = ll_len(old) / 2;
  while (mid - 1 > 0)
    {
      old = old->next;
      mid--;
    }
  new = old->next;
  old->next = NULL;
  old = first;
  l1 = ll_merge_sort(opts, old);
  l2 = ll_merge_sort(opts, new);
  return (ll_merge_list(opts, l1, l2));
}
