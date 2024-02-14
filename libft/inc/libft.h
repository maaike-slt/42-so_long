/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msloot <msloot@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:56:09 by msloot            #+#    #+#             */
/*   Updated: 2023/11/21 19:56:37 by msloot           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
bool	ft_is_in(const char *str, char c);

void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);

size_t	ft_nbrlen_base(ssize_t n, size_t base);
size_t	ft_unbrlen_base(size_t n, size_t base);
size_t	ft_nbrlen(ssize_t n);
size_t	ft_unbrlen(size_t n);

void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);

typedef struct s_base {
	const char	*base;
	size_t		len;
}	t_base;

# define B2			"01"
# define B2_LEN		2
# define B8			"01234567"
# define B8_LEN		8
# define B10		"0123456789"
# define B10_LEN	10
# define B16		"0123456789abcdef"
# define B16X		"0123456789ABCDEF"
# define B16_LEN	16

int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);

char	*ft_ntoa_base(ssize_t n, const t_base *b);
char	*ft_untoa_base(size_t n, const t_base *b);
char	*ft_ntoa(ssize_t n);
char	*ft_untoa(size_t n);

char	*ft_nbr_convert_base(
			char *dst,
			ssize_t n,
			size_t n_len,
			const t_base *b
			);
char	*ft_unbr_convert_base(
			char *dst,
			size_t n,
			size_t n_len,
			const t_base *b
			);
char	*ft_nbr_convert(char *dst, ssize_t n, size_t n_len);
char	*ft_unbr_convert(char *dst, size_t n, size_t n_len);

size_t	ft_check_base(const char *base);

char	*ft_strdup(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);

char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);

ssize_t	ft_putchar_fd(char c, int fd);
ssize_t	ft_putchar(char c);
ssize_t	ft_putstr_fd(const char *s, int fd);
ssize_t	ft_putstr(const char *s);
ssize_t	ft_putendl_fd(const char *s, int fd);

ssize_t	ft_putnbr_base_fd(ssize_t n, const t_base *base, int fd);
ssize_t	ft_putnbr_base(ssize_t n, const t_base *base);
ssize_t	ft_putnbr_fd(ssize_t n, int fd);
ssize_t	ft_putnbr(ssize_t n);

ssize_t	ft_putunbr_base_fd(size_t n, const t_base *base, int fd);
ssize_t	ft_putunbr_base(size_t n, const t_base *base);
ssize_t	ft_putunbr_fd(size_t n, int fd);
ssize_t	ft_putunbr(size_t n);

void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
