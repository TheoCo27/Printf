/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:23:48 by tcohen            #+#    #+#             */
/*   Updated: 2024/06/15 20:26:59 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrlen(char *s)
{
	int	i;

	if (!s)
		return (ft_putstrlen("(null)"));
	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar_base(int nb, char *base)
{
	write(1, &base[nb], 1);
	return (1);
}

int	ft_putcharlen(char c)
{
	write(1, &c, 1);
	return (1);
}
