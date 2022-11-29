/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:00:55 by kaboussi          #+#    #+#             */
/*   Updated: 2022/11/29 12:30:44 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int		i;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	char	*s;
	int		ret;

	s = ft_itoa(n);
	ret = ft_strlen(s);
	ft_putstr(s);
	free(s);
	return (ret);
}

int	ft_putnbrunsignedint(unsigned int n)
{
	int	ret;

	ret = 0;
	if (n >= 10)
		ret += ft_putnbrunsignedint(n / 10);
	ret += ft_putchar(n % 10 + 48);
	return (ret);
}

int	ft_hexadecimal(unsigned long n, int x)
{
	int	ret;
	int	nb;

	ret = 0;
	if (n >= 16)
		ret += ft_hexadecimal(n / 16, x);
	nb = n % 16;
	if (nb > 9 && nb < 16)
	{
		nb = nb % 10 + x;
		ret += ft_putchar(nb);
	}
	else
		ret += ft_putchar(nb + 48);
	return (ret);
}
