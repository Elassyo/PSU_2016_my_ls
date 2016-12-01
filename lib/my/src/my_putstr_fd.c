/*
** my_putstr.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"
#include <unistd.h>

int	my_putstr_fd(int fd, char *str)
{
  write(fd, str, my_strlen(str));
  return (0);
}
