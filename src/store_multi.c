/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_multi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:41:56 by snunes            #+#    #+#             */
/*   Updated: 2019/06/12 20:24:56 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	store_nb(int flags[10][1], char buff[2000], long long int nb)
{
	long long int ret;
	int len;
	long long pow;

	pow = 1;
	len = 1;
	if (nb == 0 && flags[6][0] == 0)
		return (0);
	ret = (nb >= 0) ? nb : -1 * nb;
	while (ret / 10 && ++len)
		ret /= 10;
	ret = len;
//	printf("len = %d, ret = %lld, largeur = %d, preci = %d\n", len, ret, flags[5][0], flags[6][0]);
	len = store_fspaces(flags, nb >= 0, len, buff);
	nb = (nb > 0) ? nb : -1 * nb;
	while (ret > 1 && ret--)
		pow *= 10;
	while (pow)
	{
		buff[flags[8][0]++] = nb / pow % 10 + 48;
		pow /= 10;
	}
	return (store_espaces(flags, len, buff));
}

int	store_unb(int flags[10][1], char buff[2000], unsigned long long int nb)
{
	unsigned long long int ret;
	int len;

	len = 0;
	ret = nb;
	while (ret > 0 && ++len)
		ret /= 10;
	len = store_fspaces(flags, 1, len, buff);
	while (nb)
	{
		buff[flags[8][0]++] = nb % 10 + 48;
		nb /= 10;
	}
	return (store_espaces(flags, len, buff));
}

int store_oct(int flags[10][1], char buff[2000], unsigned long long int nb)
{
	int						len;
	unsigned long long int	ret;

	len = 0;
	ret = nb;
	while (ret > 0 && ++len)
		ret = ret / 8;
	len = store_fspaces(flags, 1, len, buff);
	while (nb > 1)
	{
		buff[flags[8][0]++] = nb % 8 + '0';
		nb /= 8;
	}
	return (store_espaces(flags, len, buff));
}

int	store_hex(int flags[10][1], char buff[2000], unsigned long long int nb)
{
	int					len;
	unsigned long long	ret;

	len = 0;
	ret = nb;
	while (ret > 0 && ++len)
		ret /= 16;
	len = store_fspaces(flags, 1, len, buff);
	while (nb > 1)
	{
		ret = (nb % 16 > 10) ? 'A' + nb % 16 - 10 : '0' + nb % 10;
		buff[flags[8][0]++] = ret;
		nb /= 16;
	}
	return (store_espaces(flags, len, buff));
}

int store_char(int flags[10][1], char buff[2000], char c)
{
	while (!flags[3][0] && flags[5][0]-- > 1)
		buff[flags[8][0]++] = ' ';
	buff[flags[8][0]] = c;
	while (flags[3][0] && flags[5][0]-- > 1)
		buff[flags[8][0]++] = ' ';
	return (1);
}
