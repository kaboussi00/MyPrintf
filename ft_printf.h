/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:11:31 by kaboussi          #+#    #+#             */
/*   Updated: 2022/11/29 12:51:53 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h> 
# include <stdlib.h>
# include <stdarg.h>

int		ft_strlen(const char *str);
char	*ft_itoa(int n);
char	*ft_strdup(const char *str);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putnbrunsignedint(unsigned int n);
int		ft_hexadecimal(unsigned long n, int x);
int		ft_pointer(unsigned long p);
int		check_man(char c);
int		check_bonus(char c);
int		ft_poursantage(char c, va_list taxi);
int		ft_poursantage_bonus(char c1, char c2, va_list taxi);
int		ft_return(const char *bibo, va_list taxi);
int		ft_printf(const char *bibo, ...);

#endif
