/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 19:11:10 by kaboussi          #+#    #+#             */
/*   Updated: 2022/11/24 19:18:06 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	ft_printf(const char *bibo, ...)
{
	va_list	taxi;
	int		calcule;
	int		i;

	calcule = 0;
	i = 0;
	va_start(taxi, bibo);
	while (bibo[i] != '\0')
	{
		if (bibo[i] != '%')
		{
			calcule += ft_putchar(bibo[i]);
			i++;
		}
		else
		{
			calcule += ft_poursantage(bibo[i + 1], taxi);
			i += 2;
		}
	}
	va_end(taxi);
	return (calcule);
}

// int main()
// {
// 	char c = 'a';
// 	char *p = &c;

// 	printf("\n%c%d\n", printf("%p", p));
// 	ft_printf("\n%d\n", ft_printf("%p", p));
// }