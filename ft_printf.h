/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:05:57 by jkaczmar          #+#    #+#             */
/*   Updated: 2021/12/08 14:54:56 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		gethexlen(unsigned long long nbr);
void	puthex(unsigned long long num, int format);
// int		ft_printf(const char *, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		checkfortype(char s, va_list *list);
int		ft_strlen(const char *str);
int		printdig(va_list *list);
int		printunsigned(va_list *list);
int		printstr(va_list *list);
int		printhex(va_list *list, int form);
int		printptr(va_list *list);
int		ft_printf(const char *str, ...);
int		counterofdigits(long long n);
void	ft_putunsignednbr_fd(unsigned int n, int fd);
char	*createptraddress(void *ptr);

#endif