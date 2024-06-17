/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcohen <tcohen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:34:21 by tcohen            #+#    #+#             */
/*   Updated: 2024/06/15 20:23:09 by tcohen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include "libft.h"

int	ft_printf(const char *str, ...);
int	ft_putnbr_uns(unsigned int n, char *base, unsigned int baselen);
int	ft_putptr(uintptr_t n, char *base, long baselen);
int	ft_putnbr_base(int n, char *base, long baselen);
int	ft_putstrlen(char *s);
int	ft_putchar_base(int nb, char *base);
int	ft_putcharlen(char c);
#endif
