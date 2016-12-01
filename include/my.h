/*
** my.h for libmy in /home/arthur.melin/Code/libmy/srcs
**
** Made by Arthur Melin
** Login   <arthur.melin@epitech.net>
**
** Started on  Mon Nov  7 15:41:44 2016 Arthur Melin
** Last update Wed Nov 16 18:54:17 2016 Arthur Melin
*/

#ifndef MY_H_
# define MY_H_

# define MY_ABS(x) (x < 0 ? -x : x)
# define MY_MIN(a, b) (a < b ? a : b)
# define MY_MAX(a, b) (a > b ? a : b)

# define my_putchar(c) my_putchar_fd(1, c)
# define my_putstr(str) my_putstr_fd(1, str)
# define my_puterr(str) my_putstr_fd(2, str)
# define my_printf(...) my_fprintf(1, __VA_ARGS__)

long	my_power_ite(int nbr, int power);
int	my_power_rec(int nbr, int power);
int	my_square_root(int nbr);
int	my_abs(int nbr);
int	my_isneg(int nbr);
int	my_is_prime(int nbr);
int	my_find_prime_sup(int nbr);
int	my_put_nbr(int nbr);
int	my_putnbr_base(int nbr, char *base);
int	my_getnbr(char *str);
int	my_getnbr_base(char *str, char *base);
int	my_isalnum(char c);
int	my_isalpha(char c);
int	my_isupper(char c);
int	my_islower(char c);
int	my_isnum(char c);
int	my_issign(char c);
int	my_isprintable(char c);
int	my_str_isalpha(char *str);
int	my_str_islower(char *str);
int	my_str_isnum(char *str);
int	my_str_isprintable(char *str);
int	my_str_isupper(char *str);
char	*my_revstr(char *str);
char	*my_strupcase(char *str);
char	*my_strcapitalize(char *str);
void	*my_memcpy(void *dest, void *src, int size);
void	*my_memset(void *ptr, int c, int size);
int	my_fprintf(int fd, const char *format, ...);
void	my_putchar_fd(int fd, char c);
int	my_putstr_fd(int fd, char *str);
int	my_fprintf(int fd, const char *format, ...);
void	my_putchar_hex(char c, char *hex_digits);
int	my_showmem(char *str, int size);
int	my_showstr(char *str);
char	**my_str_to_wordtab(char *str);
int	my_show_wordtab(char **tab);
void	my_sort_int_tab(int *arr, int size);
int	my_strlen(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int n);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_strdup(char *src);
char	*my_strstr(char *str, char *to_find);
int	my_swap(int *a, int *b);
int	my_swap_char(char *a, char *b);
int	my_swap_str(char **a, char **b);

#endif
