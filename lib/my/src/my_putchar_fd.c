/*
** my_putchar_fd.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"
#include <unistd.h>

void	my_putchar_fd(int fd, char c)
{
  write(fd, &c, 1);
}
