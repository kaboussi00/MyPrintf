/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:11:10 by kaboussi          #+#    #+#             */
/*   Updated: 2022/11/29 12:36:24 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_man(char c)
{
	if (c == 'd' || c == 'i' || c == 'c' || c == 's'
		|| c == 'u' || c == 'p' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_poursantage(char c, va_list taxi)
{
	int	calcule;

	calcule = 0;
	if (c == 'c')
		calcule += ft_putchar(va_arg(taxi, int));
	else if (c == 's')
		calcule += ft_putstr(va_arg(taxi, char *));
	else if (c == 'd' || c == 'i')
		calcule += ft_putnbr(va_arg(taxi, int));
	else if (c == 'u')
		calcule += ft_putnbrunsignedint(va_arg(taxi, unsigned int));
	else if (c == 'x')
		calcule += ft_hexadecimal(va_arg(taxi, unsigned int), 97);
	else if (c == 'X')
		calcule += ft_hexadecimal(va_arg(taxi, unsigned int), 65);
	else if (c == 'p')
		calcule += ft_pointer(va_arg(taxi, unsigned long));
	else if (c == '%')
		calcule += ft_putchar('%');
	else
		return (-1);
	return (calcule);
}

int	ft_poursantage_bonus(char c1, char c2, va_list taxi)
{
	int				calcule;
	int				x;
	unsigned long	u;

	calcule = 0;
	if ((c1 == ' ' || c1 == '+') && (c2 == 'd' || c2 == 'i'))
	{
		x = va_arg(taxi, int);
		if (x >= 0)
			calcule += ft_putchar(c1);
		calcule += ft_putnbr(x);
	}
	else if (c1 == '#' && (c2 == 'x' || c2 == 'X'))
	{
		u = va_arg(taxi, unsigned long);
		if (u != 0)
		{
			calcule += ft_putchar('0');
			calcule += ft_putchar(c2);
		}
		calcule += ft_hexadecimal(u, c2 - 23);
	}
	else
		return (-1);
	return (calcule);
}

int	ft_return(const char *bibo, va_list taxi)
{
	int	calcule;
	int	i;

	i = 0;
	calcule = 0;
	while (bibo[i] != '\0')
	{
		if (bibo[i] != '%')
		{
			calcule += ft_putchar(bibo[i]);
			i++;
		}
		else if (bibo[i] == '%' && check_man(bibo[i + 1]))
		{
			calcule += ft_poursantage(bibo[i + 1], taxi);
			i += 2;
		}
		else if (bibo[i] == '%' && !check_man(bibo[i + 1]))
		{
			calcule += ft_poursantage_bonus(bibo[i + 1], bibo[i + 2], taxi);
			i += 3;
		}
	}
	return (calcule);
}

int	ft_printf(const char *bibo, ...)
{
	va_list	taxi;
	int		calcule;

	va_start(taxi, bibo);
	calcule = ft_return(bibo, taxi);
	va_end(taxi);
	return (calcule);
}
