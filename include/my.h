/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** header lib
*/
#ifndef MY_H_
# define MY_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <fcntl.h>
// #include <string.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <sys/uio.h>
// #include <sys/sysmacros.h>
// #include <dirent.h>
// #include <time.h>

// array
int	my_show_word_array(char * const *);
char	**my_str_to_wordtab_delim(char *str, char *delim);
void	my_sort_int_array(int *, int);
int	my_strarraylen(char **);
int	*my_tab_to_int(char **, int);

// char
int	my_char_is_alpha(char c);
int	my_char_is_num(char c);
int	my_char_is_alphanum(char c);

// mem
void	my_free(void *ptr);
void	*my_malloc(int size);
void	my_memdel(void **ap);
void	my_memset(char *str, int size);
int	*my_realloc_nb(int *nb, int size);
char	*my_realloc_str(char *str, int size);

// nbr
int	my_compute_factorial_it(int nb);
int	my_compute_factorial_rec(int nb);
int	my_compute_power_it(int nb, int p);
int	my_compute_power_rec(int nb, int p);
int	my_compute_square_root(int nb);
int	my_is_prime(int nb);
int	my_find_prime_sup(int nb);
int	my_getnbr(char const *str);
int	my_getnbr_base(char const *str, char const *base);
int	my_isneg(int n);
void	my_swap(int *a, int *b);

// print
void	my_print_err(char *c);
int	my_print_alpha(void);
int	my_print_digits(void);
void	my_putstr(char const *str);
int	my_put_nbr(int nb);
void	my_putchar(char c);
int	my_putnbr_base(int nbr, char const *base);
int	my_putnbr_base_2(unsigned long nbr, char const *base);
void	my_print_err(char *);
int	my_printf(char const *str, ...);

// str
char	*my_itoa(int nb);
char	*my_revstr(char *str);
int	my_str_isalpha(char const *str);
int	my_str_isnum(char const *str);
int	my_str_isprintable(char const *str);
int	my_str_islower(char const *str);
int	my_str_isupper(char const *str);
char	*my_strcat(char *dest, char const *src);
char	*my_strcpy(char *dest, char const *src);
int	my_strcmp(char const *s1, char const *s2);
char	*my_strdup(char const *src);
int	my_strisalphanum(char *str);
int	my_strlen(char const *str);
char	*my_strlowcase(char *str);
char	*my_strncat(char *dest, char const *src, int nb);
int	my_strncmp(char const *s1, char const *s2, int n);
char	*my_strncpy(char *dest, char const *src, int n);
char	*my_strndup(char const *src, int n);
char	*my_strstr(char *str, char const *to_find);
char	*my_strupcase(char *str);
char	*get_next_line(int fd);

#endif