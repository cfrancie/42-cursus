/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfrancie <cfrancie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:57:07 by cfrancie          #+#    #+#             */
/*   Updated: 2023/01/09 19:43:41 by cfrancie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// ctype
bool		ft_isalnum(int c);
bool		ft_isalpha(int c);
bool		ft_isascii(int c);
bool		ft_isblank(int c);
bool		ft_iscntrl(int c);
bool		ft_isdigit(int c);
bool		ft_isgraph(int c);
bool		ft_isprint(int c);
bool		ft_ispunct(int c);
bool		ft_isspace(int c);
bool		ft_isxdigit(int c);
int			ft_tolower(int c);
int			ft_toupper(int c);

// string
void		ft_bzero(void *s, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
char		*strcat(char *dest, const char *src);
char		*ft_strchr(const char *s, int c);
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *s);
char		*ft_strncat(char *dest, const char *src, size_t n);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strncpy(char *dest, const char *src, size_t size_t);
char		*ft_strndup(const char *src, size_t size);
char		*ft_strnstr(const char *big, const char *little, size_t size);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *big, const char *little);

// stdlib
long double	ft_atof(const char *str);
int			ft_atoi(const char *nptr);
long		ft_atol(const char *str);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_itoa(int n);
char		*ft_strdup(const char *s);

// other

//  bonus
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int			ft_abs(int n);
int			ft_intlen(int n);
char		*ft_itoa(int n);
long double	ft_ldabs(long double n);
bool		ft_max(int a, int b);
bool		ft_min(int a, int b);
void		ft_putchar_fd(char c, int fd);
void		ft_putchar(char c);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putstr(char *str);
bool		ft_search_char(const char *s, char c);
char		**ft_split(char const *s, char c);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif