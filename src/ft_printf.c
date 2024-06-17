/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:00:37 by tcohen            #+#    #+#             */
/*   Updated: 2024/06/15 20:26:28 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_set0(int *i, int *count)
{
	*i = 0;
	*count = 0;
}

static int	ft_check_char(const char c)
{
	if (ft_strchr("cspdiuxX%", (int)c) == NULL)
		return (1);
	return (0);
}

static int	ft_type_assign_bis(va_list list, char c)
{
	int			count;
	uintptr_t	i;

	count = 0;
	if (c == 'x')
		count += ft_putnbr_uns(va_arg(list, int), "0123456789abcdef", 16);
	if (c == 'X')
		count += ft_putnbr_uns(va_arg(list, int), "0123456789ABCDEF", 16);
	if (c == 'u')
		count += ft_putnbr_uns(va_arg(list, unsigned int), "0123456789", 10);
	if (c == 'p')
	{
		i = va_arg(list, uintptr_t);
		if (i == 0)
			return (count += ft_putstrlen("(nil)"), count);
		count += ft_putstrlen("0x");
		count += ft_putptr(i, "0123456789abcdef", 16);
	}
	return (count);
}

static int	ft_type_assign(va_list list, char c)
{
	int	count;

	count = 0;
	if (c == '%')
		count += ft_putcharlen('%');
	if (c == 'c')
		count += ft_putcharlen((char)va_arg(list, int));
	if (c == 's')
		count += ft_putstrlen(va_arg(list, char *));
	if (c == 'd' || c == 'i')
		count += ft_putnbr_base(va_arg(list, int), "0123456789", 10);
	if (c == 'x' || c == 'X' || c == 'u' || c == 'p' )
		return (ft_type_assign_bis(list, c));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	list;

	if (!str)
		return (-1);
	va_start(list, str);
	ft_set0(&i, &count);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_check_char(str[i + 1]) == 0 && str[i + 1])
				count += ft_type_assign(list, str[i + 1]);
			i = i + 2;
		}
		else
		{
			count += ft_putcharlen(str[i]);
			i++;
		}
	}
	return (va_end(list), count);
}
