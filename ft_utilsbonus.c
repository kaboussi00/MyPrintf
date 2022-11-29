/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilsbonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaboussi <kaboussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:45:12 by kaboussi          #+#    #+#             */
/*   Updated: 2022/11/29 12:51:24 by kaboussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_bonus(char c)
{
	if (c == 'd' || c == 'i' || c == 'c' || c == 's'
		|| c == 'u' || c == 'p' || c == 'x' || c == 'X' || c == '%')
		return (0);
	return (1);
}