/*
** fs.c for PSU_2016_my_ls in /home/arthur.melin/Code/PSU_2016_my_ls
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Thu Dec  1 13:40:53 2016 Arthur Melin
** Last update Fri Dec  2 18:03:44 2016 Arthur Melin
*/

#include <my_ls.h>

char	*stat_get_mtime_str(time_t mtime)
{
  char	*ctime_fmt;
  char	*mtime_str;

  if (!(mtime_str = malloc(13)))
    return (NULL);
  my_memset(mtime_str, ' ', 12);
  ctime_fmt = ctime(&mtime);
  my_strncpy(mtime_str, ctime_fmt + 4, 3);
  my_strncpy(mtime_str + 4, ctime_fmt + 8, 2);
  if (mtime < (time(NULL) - 15778458) || mtime > time(NULL))
    my_strncpy(mtime_str + 8, ctime_fmt + 20, 4);
  else
    my_strncpy(mtime_str + 7, ctime_fmt + 11, 5);
  mtime_str[12] = 0;
  return (mtime_str);
}

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
  char	*mode_str;

  if (!(mode_str = my_strdup("----------")))
    return (NULL);
  mode_str[0] = stat_get_type_chr(mode);
  mode_str[1] = (mode & S_IRUSR) ? 'r' : '-';
  mode_str[2] = (mode & S_IWUSR) ? 'w' : '-';
  mode_str[3] = (mode & S_IXUSR) ? 'x' : '-';
  mode_str[4] = (mode & S_IRGRP) ? 'r' : '-';
  mode_str[5] = (mode & S_IWGRP) ? 'w' : '-';
  mode_str[6] = (mode & S_IXGRP) ? 'x' : '-';
  mode_str[7] = (mode & S_IROTH) ? 'r' : '-';
  mode_str[8] = (mode & S_IWOTH) ? 'w' : '-';
  mode_str[9] = (mode & S_IXOTH) ? 'x' : '-';

  if (mode & S_ISUID)
    mode_str[3] = (mode & S_IXUSR) ? 's' : 'S';
  if (mode & S_ISGID)
    mode_str[6] = (mode & S_IXGRP) ? 's' : 'S';
  if (mode & S_ISVTX)
    mode_str[9] = (mode & S_IXOTH) ? 't' : 'T';
  return (mode_str);
}
