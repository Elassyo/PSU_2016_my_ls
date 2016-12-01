/*
** fs.c for PSU_2016_my_ls in /home/arthur.melin/Code/PSU_2016_my_ls
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Thu Dec  1 13:40:53 2016 Arthur Melin
** Last update Thu Dec  1 13:58:08 2016 Arthur Melin
*/

#include <my_ls.h>

char	stat_get_type_chr(mode_t mode)
{
  if (S_ISBLK(mode))
    return ('b');
  else if (S_ISCHR(mode))
    return ('c');
  else if (S_ISFIFO(mode))
    return ('p');
  else if (S_ISREG(mode))
    return ('-');
  else if (S_ISDIR(mode))
    return ('d');
  else if (S_ISLNK(mode))
    return ('l');
  else if (S_ISSOCK(mode))
    return ('s');
  return ('?');
}

char	*stat_get_mode_str(mode_t mode)
{
  int	i;
  int	bit;
  char	*mode_str;

  if (!(mode_str = my_strdup("-rwxrwxrwx")))
    return (NULL);
  mode_str[0] = stat_get_type_chr(mode);
  i = 1;
  bit = 0700;
  while (bit)
    {
      if (!(mode & bit))
	mode_str[i] = '-';
      bit >>= 1;
      i++;
    }
  if (mode & S_ISUID)
    mode_str[3] = mode & S_IXUSR ? 's' : 'S';
  if (mode & S_ISGID)
    mode_str[6] = mode & S_IXGRP ? 's' : 'S';
  if (mode & S_ISVTX)
    mode_str[9] = mode & S_IXOTH ? 't' : 'T';
  return (mode_str);
}
