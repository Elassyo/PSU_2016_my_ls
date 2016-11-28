/*
** my_strcat.c for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Mon Nov  7 15:41:49 2016 Arthur Melin
*/

#include "my.h"

char	*my_strcat(char *dest, char *src)
{
  my_strcpy(dest + my_strlen(dest), src);
  return (dest);
}
