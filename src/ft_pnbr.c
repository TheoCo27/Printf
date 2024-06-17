/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pnbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:23:01 by tcohen            #+#    #+#             */
/*   Updated: 2024/06/15 20:27:45 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_uns(unsigned int n, char *base, unsigned int baselen)
{
	int		count;

	count = 0;
	if (n >= baselen)
	{
		count += ft_putnbr_uns(n / baselen, base, baselen);
		count += ft_putnbr_uns(n % baselen, base, baselen);
	}
	else
		count += ft_putchar_base(n, base);
	return (count);
}

int	ft_putptr(uintptr_t n, char *base, long baselen)
{
	int		count;

	count = 0;
	if (n >= baselen)
	{
		count += ft_putptr(n / baselen, base, baselen);
		count += ft_putptr(n % baselen, base, baselen);
	}
	else
		count += ft_putchar_base((int)n, base);
	return (count);
}

int	ft_putnbr_base(int n, char *base, long baselen)
{
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		count += ft_putcharlen('-');
		nb = -nb;
	}
	if (nb >= baselen)
	{
		count += ft_putnbr_base(nb / baselen, base, baselen);
		count += ft_putnbr_base(nb % baselen, base, baselen);
	}
	else
		count += ft_putchar_base(nb, base);
	return (count);
}
