/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diouxX_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:23:05 by snunes            #+#    #+#             */
/*   Updated: 2019/06/04 06:08:30 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int print_nbr(int flags[7][1], long long int nbr)
{
	int len;

	len = ft_nbrlen(nbr);
	print_frontspaces(flags, len);
	while (flags[6][0] > len)
	{
		write(1, "0", 1);
		len++;
	}
	print_frontnb(flags, nbr);
	ft_putnbr(nbr);
	print_endspaces(flags, len);
	return (nbr);
}

int	print_octal(int flags[7][1], long long int nbr)
{
	unsigned int	len;
	long long int	conv;

	conv = 0;
	while (nbr > 1)
	{
		conv = conv * 10 + nbr % 8;
		nbr = nbr / 8;
	}
	len = ft_nbrlen(conv);
	print_frontspaces(flags, len);
	while ( >= 0 && len < (unsigned int)precision)
	{
		write(1, "0", 1);
		len++;
	}
	nbr = ft_nbrrev((int)(conv));
	ft_putnbr(nbr);
	return (nbr);
}

int	print_unsigned_nbr(int precision, long long int nbr)
{
	unsigned int len;

	len = ft_nbrlen(nbr);
	while (precision >= 0 && len < (unsigned int)precision)
	{
		write(1, "0", 1);
		len++;
	}
	ft_putnbr(nbr);
	return (nbr);
}

int	print_hexa(int precision, char letter, long long int nbr)
{
	char			*conv;
	unsigned int	len;
	int				res;
	char			let;

	let = (letter == 'x') ? 'a' : 'A';
	res = nbr;
	len = 1;
	while (res > 0 && ++len)
		res /= 16;
	conv = (char *)ft_memalloc(sizeof(char) * len--);
	while (nbr > 0)
	{
		conv[--len] = (nbr % 16 < 10) ? nbr % 16 + '0' : nbr % 16 - 10 + let;
		nbr /= 16;
	}
	ft_strrev(conv);
	while (precision != -1 && ft_strlen(conv) < (size_t)precision--)
		write(1, "0", 1);
	ft_putstr(conv);
	free(conv);
	return (1);
}

int	print_double(va_list ap, int precision)
{
	int		ret;
	double	nb;

	precision = (precision == -1) ? 6 : precision;
	nb = va_arg(ap, double);
	ft_putnbr(nb);
	if (precision)
	{
		ft_putchar('.');
		ret = nb;
		nb = nb - ret;
		while (precision--)
			nb = nb * 10; 
		if (nb)
			ft_putnbr(nb);
	}
	return (1);
}
