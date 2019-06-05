/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diouxX_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:23:05 by snunes            #+#    #+#             */
/*   Updated: 2019/06/05 03:54:24 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_nbr(int flags[7][1], long long int nbr)
{
	int len;

	len = ft_nbrlen(nbr);
	print_frontspaces(flags, nbr, len);
	while (flags[6][0] > len)
	{
		write(1, "0", 1);
		len++;
	}
	print_frontnb(flags, 'i');
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
	len = ft_nbrlen(conv);
	flags[6][0] = ((unsigned int)flags[6][0] > len) ? flags[6][0] : len + 1;
	print_frontspaces(flags, -1, flags[6][0] - len + 1);
	while ( flags[6][0] > 0 && len + flags[0][0] < (unsigned int)flags[6][0])
	{
		write(1, "0", 1);
		len++;
	}
	print_frontnb(flags, 'o');
	nbr = ft_nbrrev((int)(conv));
	ft_putnbr(nbr);
	len = ft_nbrlen(nbr);
	print_endspaces(flags, len);
}

void	print_hexa(int flags[7][1], char letter, long long int nbr)
{
	char			*conv;
	int				len;
	long long int	res;
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
	len = ft_strlen(conv);
	flags[6][0] = (flags[6][0] > len) ? flags[6][0] : len;
	flags[6][0] = (flags[0][0] == 1) ? flags[6][0] + 2: flags[6][0];
//	printf("flags[6] = %d, len = %d\n", flags[6][0], len);
	print_frontspaces(flags, -1, flags[6][0] - len + 1);
	print_frontnb(flags, let);
	while (flags[6][0] > 0 && len + 2 * flags[0][0] < flags[6][0]--)
		write(1, "0", 1);
	ft_putstr(conv);
	print_endspaces(flags, ft_strlen(conv));
	free(conv);
}

void	print_double(va_list ap, int flags[7][1])
{
	int		len;
	int		ret;
	double	nb;

	flags[6][0] = (flags[6][0] == -1) ? 6 : flags[6][0];
	nb = va_arg(ap, double);
	len = ft_nbrlen(nb);
	print_frontspaces(flags, nb, len);
	print_frontnb(flags, 'f');
	ft_putnbr(nb);
	if (flags[6][0] >= 0 || flags[0][0] == 1)
		ft_putchar('.');
	if (flags[6][0])
	{
		ret = nb;
		nb = nb - ret;
		while (flags[6][0]--)
			nb = nb * 10; 
		if (nb)
			ft_putnbr(nb);
	}
	print_endspaces(flags, ft_nbrlen(nb));
}
