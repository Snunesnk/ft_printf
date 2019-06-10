/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_multi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:41:56 by snunes            #+#    #+#             */
/*   Updated: 2019/06/10 19:24:36 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_store_nbr(int flags[10][1], char buff[2000], long long int nbr)
{
	long long int ret;
	int len;

	ret = nb;
	while (ret > 0 && ++len)
		ret /= 10;
	len = store_fspaces(flags, nbr >= 0, len, buff)
	while (nbr)
	{
		buff[flags[8][0]++] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (store_espaces(flags, len, buff));
}

int ft_store_oct(int flags[10][1], char buff[2000], unsigned long long int nbr)
{
	int						len;
	unsigned long long int	ret;

	len = 0;
	ret = nbr;
	while (ret > 0 && ++len)
		ret = ret / 8;
	len = print_frontspaces(flags, 1, len, buff);
	while (nb > 1)
	{
		buff[flags[8][0]++] = nb % 8 + '0';
		nb /= 8;
	}
	return (store_espaces(flags, len, buff));
}

int	ft_store_hex(int flags[10][1], char bf[2000], unsigned long long int nb)
{
	int					len;
	unsigned long long	ret;

	len = 0;
	ret = nb;
	while (ret > 0 && ++len)
		ret /= 16;
	len = print_frontspaces(flags, 1, len, buff);
	while (nb > 1)
	{
		bf[flags[8][0]++] = (nb % 16 > 10) ? 'A' + nb % 16 - 10 : '0' + nb % 10;
		nb /= 16;
	}
	return (store_espaces(flags, len, buff));
}
