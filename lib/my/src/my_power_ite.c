/*
** my_power_ite.c for libmy in /home/arthur.melin/Code/libmy/src
** 
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
** 
** Started on  Wed Nov 16 21:49:14 2016 Arthur Melin
** Last update Wed Nov 16 21:52:49 2016 Arthur Melin
*/

long	my_power_ite(int base, int power)
{
  long	res;

  if (power < 0)
    return (0);
  if (power == 0)
    return (1);
  res = 1;
  while (power--)
    res *= base;
  return (res);
}
