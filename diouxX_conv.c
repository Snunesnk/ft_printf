/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diouxX_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:23:05 by snunes            #+#    #+#             */
/*   Updated: 2019/06/04 07:10:37 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_nbr(int flags[7][1], long long int nbr)
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
}

void	print_octal(int flags[7][1], long long int nbr)
{
	unsigned int	len;
	long long int	conv;

	conv = 0;
	while (nbr > 1)
	{
		conv = conv * 10 + nbr % 8;
		nbr = nbr / 8;
	}
	len = (flags[0][0] == 1) ? ft_nbrlen(conv) : ft_nbrlen(conv) + 1;
	print_frontspaces(flags, len);
	print_frontnb(flags, -1, 'c');
	while ( flags[6][0]> 0 && len < (unsigned int)flags[])
	{
		write(1, "0", 1);
		len++;
	}
	nbr = ft_nbrrev((int)(conv));
	ft_putnbr(nbr);
	len = ft_nbrlen(nbr);
	print_endspaces(flags, len);
}

void	print_hexa(int flags[7][1], char letter, long long int nbr)
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
	len = (flag[0][0] == 1) ? ft_strlen(conv) + 2 : ft_strlen(conv);
	print_frontspaces(flags, len);
	print_frontnbr(flags, -1, letter)
	while (flags[6][0] != -1 && len < (size_t)flags[6][0]--)
		write(1, "0", 1);
	ft_putstr(conv);
	print_endspaces(flags, len);
	free(conv);
}

void	print_double(va_list ap, int flags[7][1])
{
	int		len;
	int		ret;
	double	nb;

	flags[6][0] = (flags[6][0] == -1) ? 6 : flags[6][0];
	nb = va_arg(ap, double);
	print_frontspaces(flags, len);
	ft_putnbr(nb);
	print_frontnb(flags, nb, 'f');
	len = ft_nbrlen(nb);
	if (flags[6][0] == 1 || flags[0][0] == 1)
		ft_putchar('.');
	if (flags[6][0])
	{
		ret = nb;
		nb = nb - ret;
		while (flags[6][0] && len++)
			nb = nb * 10; 
		if (nb)
			ft_putnbr(nb);
	}
	print_endspaces(flags, ft_nbrle)
}
