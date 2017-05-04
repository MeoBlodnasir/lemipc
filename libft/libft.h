/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduban <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 16:54:11 by aduban            #+#    #+#             */
/*   Updated: 2016/04/25 16:51:56 by aduban           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <locale.h>
# include <stdint.h>
# include <stdint.h>
# define MAXDIGITS   21
# define N_LG_MAX        (sizeof(long long) * 8 )
# define C_BASENUMMAX_MAJ    "0123456789ABCDEF"
# define C_BASENUMMAX_MIN   "0123456789abcdef"

typedef struct	s_env
{	int			diese;
	int			zero;
	int			moins;
	int			plus;
	int			hh;
	int			h;
	int			ll;
	int			l;
	int			j;
	int			z;
	int			size;
	char		conv;
	int			negative;
	int			space;
	int			prec;
	int			precis;
}				t_flags;
void			finalprintu(long long i, t_flags options);
int				finalprinto(unsigned long i, t_flags options);
char			**subtab(char **tab, char *hip);
char			*rectifhip(char *hip, char *str);
char			*fillhip(char **tab, int j);
char			**filltab(int j);
char			*dectobin(unsigned long long n, unsigned int base);
int				power(int i, int j);
int				getnboct(char *str);
int				getidsize(unsigned long long a, t_flags options);
int				printidplus(unsigned long long a, t_flags options);
void			ft_putlnbr(long long n);
int				getsize(const char *str, int i);
t_flags			*getinc(const char *format);
int				prints(char *str, t_flags options);
void			ft_putlnbr(long long n);
int				calc(unsigned long long n, int k);
int				printbigd(long long a, t_flags options);
int				printid(long long a, t_flags options);
char			*dectohex(unsigned long number, int a);
int				printxx(unsigned long long i, int a, t_flags options);
int				afficher_nombre(unsigned long long l, unsigned int base, t_flags
		options, int h);
int				printprc();
int				printlc(int i, int l);
int				prints(char *str, t_flags options);
int				printid(long long a, t_flags options);
int				printbigd(long long a, t_flags options);
int				printp(void *thing, t_flags options);
int				printo(unsigned long i, t_flags options);
int				printbigo(unsigned long i, t_flags options);
int				printu(long long i, t_flags options);
int				printbigu(long long i, t_flags options);
int				printxx(unsigned long long i, int a, t_flags options);
int				printc(int i, t_flags options);
int				printbigc(int i, t_flags options);
int				printls(wchar_t *str, t_flags options);
int				getargs(t_flags *options, va_list args, int i);
int				isthere(char c, char *str);
int				ft_printf(const char *format, ...);
int				ft_getnbr(char *s);
void			*ft_memset(void *b, int c, size_t len);
double			ft_atof(const char *str);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *s1, const void *s2, size_t n);
void			*ft_memccpy(void *s1, const void *s2, int c, size_t n);
void			*ft_memmove(void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_putchar(char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr(char const *s);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl(char const *s);
void			ft_putendl_fd(char const *s, int fd);
char			*ft_strcat(char *s1, const char *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *s1, const char *s2);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strcpy(char *s1, const char *s2);
char			*ft_strncpy(char *s1, const char *s2, size_t n);
void			ft_putnbr(int n);
void			ft_putnbr_fd(int n, int fd);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
int				ft_unspace(int c);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strdup(const char *s1);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
char			*ft_stradd(char *str);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
int				ft_strisdigit(char *str);

#endif
