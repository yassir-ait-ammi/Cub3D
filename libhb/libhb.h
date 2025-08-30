/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libhb.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:06:04 by habenydi          #+#    #+#             */
/*   Updated: 2025/08/21 16:37:00 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBHB_H
# define LIBHB_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>
# include <stddef.h>
# include <stdio.h>
# include <stdarg.h>
# include <fcntl.h>
# include <time.h>
# include <math.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "get_next_line.h"
# define FT_CLEAR 0
# define FT_ALLOC 1

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

void	yfree(void);
void	*yalloc(size_t size);
void	*ft_malloc(size_t size, short option);
int		is_quote(char c);
int		hb_toupper(int c);
int		hb_tolower(int c);
int		hb_isalpha(int c);
int		hb_isdigit(int c);
int		hb_isalnum(int c);
int		hb_isascii(int c);
int		hb_isprint(int c);
int		hb_cputnbr(int n);
int		hb_cputstr(char *s);
int		hb_cputchar(char c);
int		hb_isorted(t_list *a);
int		hb_lstsize(t_list *lst);
int		hb_atoi(const char *nbr);
int		hb_isalphastr(char *str);
int		hb_cputunbr(unsigned int n);
int		hb_cputnbr_fd(int n, int fd);
int		hb_ft_printf(const char *f, ...);
int		hb_cputstr_fd(char *s, int fd);
int		hb_cputchar_fd(char c, int fd);
int		hb_printerr(const char *f, ...);
int		hb_cputhexa(unsigned long n, char x);
int		hb_cputunbr_fd(unsigned int n, int fd);
int		hb_strncmp(char *s, char *p, size_t n);
int		hb_strcmp(const char *s1, const char *s2);
int		hb_cputhexa_fd(unsigned long n, char x, int fd);
int		hb_memcmp(const void *s1, const void *s2, size_t n);
char	*hb_itoa(int n);
char	*hb_strdup(const char *s);
char	*hb_strchr(const char *str, int c);
char	*hb_mtrchr(char **mtr, char *str);
char	*hb_mtrfchr(char **mtr, char *str);
char	*hb_strrchr(const char *str, int c);
char	*hb_mtrrchr(char **mtr, char *str);
char	*hb_strstr(char *str, char *to_find);
char	**hb_split(char const *s, char c);
char	**hb_mtrcpy(char **mtr);
char	*hb_mtrfchr(char **mtr, char *str);
char	*hb_strjoin(char const *s1, char const *s2);
char	*hb_strtrim(char const *s1, char const *set);
char	*hb_strnstr(char *str, char *to_find, size_t len);
char	*hb_strmapi(char const *s, char (*f)(unsigned int, char));
char	*hb_substr(char const *s, unsigned int start, size_t len);
size_t	hb_mtrlen(char **mtr);
size_t	hb_strlen(const char *str);
size_t	hb_strlcpy(char *dest, const char *src, size_t l);
size_t	hb_strlcat(char *dest, const char *src, size_t l);
void	hb_mtrfree(char **mtr);
void	hb_bzero(void *ptr, int len);
void	hb_putmtr(char **mtr);
void	hb_putmtr_fd(char **mtr, int fd);
void	hb_putchar(char c);
void	hb_putendl(char *s);
void	hb_putnbr(int n);
void	hb_puthexa(unsigned long n, char x);
void	hb_putunbr(unsigned int n);
void	hb_putstr(char *s);
void	hb_rputstr(char *s, int f);
void	hb_putchar_fd(char c, int fd);
void	hb_putstr_fd(char *s, int fd);
void	hb_putnbr_fd(int n, int fd);
void	hb_putendl_fd(char *s, int fd);
void	bubble_sort(int *arr, int size);
void	*hb_calloc(size_t len, size_t b);
void	*hb_realloc(void *ptr, size_t size);
void	*hb_memset(void *arr, int c, size_t l);
void	*hb_memchr(void *str, int c, size_t n);
void	hb_lstiter(t_list *lst, void (*f)(void *));
void	hb_lstadd_back(t_list **lst, t_list *n);
void	hb_lstdelone(t_list *lst, void (*del)(void *));
void	hb_lstclear(t_list **lst, void (*del)(void *));
void	hb_striteri(char *s, void (*f)(unsigned int, char*));
void	*hb_memcpy(void *dest, const void *src, size_t len);
void	*hb_memmove(void *dest, const void *src, size_t len);
void	hb_lstadd_front(t_list **lst, t_list *n);
t_list	*hb_lstnew(void *content);
t_list	*hb_lstlast(t_list *lst);
void	hb_lstaddin(t_list **node, t_list *n);
t_list	*hb_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
