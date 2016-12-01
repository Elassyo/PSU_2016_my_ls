/*
** handle_error.c for PSU_2016_my_ls in /home/arthur.melin/Code/PSU_2016_my_ls
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Wed Nov 30 23:14:14 2016 Arthur Melin
** Last update Wed Nov 30 23:15:05 2016 Arthur Melin
*/

#include <my_ls.h>

long		handle_error(char *msg, char *path, long ret_code)
{
  my_fprintf(STDERR_FILENO, "./my_ls: %s '%s': %m\n", msg, path);
  return (ret_code);
}

void	*malloc_failed()
{
  my_puterr("error: malloc failed\n");
  return (NULL);
}
