/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gorodrig <gorodrig@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:34:43 by gorodrig          #+#    #+#             */
/*   Updated: 2024/11/20 09:52:41 by gorodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int			ft_atoi(const char *str);
void		ft_bzero(void *s, size_t n);
void		ft_error(void);
void		*ft_calloc(size_t nitems, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
void		*ft_memchr(const void *str, int c, size_t n);
int			ft_memcmp(const void *str1, const void *str2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *str, int c, size_t n);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *src);
char		*ft_strjoin(const char *s1, const char *s2);
size_t		ft_strlcat(char *dest, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
char		*ft_strnstr(const char *str, const char *substr, size_t n);
char		*ft_strrchr(const char *str, int c);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_substr(const char *str, unsigned int start, size_t len);
char		*ft_strtrim(const char *str1, const char *set);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
char		**ft_split(const char *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
int			ft_printf(const char *str, ...);
int			ft_printhex(unsigned int n, const char format);
int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_printptr(unsigned long long ptr);
int			ft_putnbr(int n);
int			ft_put_unsignednbr(unsigned int n);
int			ft_printhex(unsigned int n, const char format);

#endif
