/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 05:51:15 by snunes            #+#    #+#             */
/*   Updated: 2019/06/12 15:47:35 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	store_fspaces(int flags[10][1], int sign, int len, char buff[2000])
{
	if (flags[0][0] == 1 && (flags[7][0] == 'o' || flags[7][0] == 'x'
			|| flags[7][0] == 'X') && ++len)
		buff[flags[8][0]++] = '0';
	if (flags[0][0] == 1 && flags[7][0] == 'x' && ++len)
		buff[flags[8][0]] = 'x';
	if (flags[0][0] == 1 && flags[7][0] == 'X' && ++len)
		buff[flags[8][0]++] = 'X';
	if (flags[2][0] == 1 && sign >= 0 && ++len)
		buff[flags[8][0]++] = ' ';
	if (flags[1][0] == 1  && ++len)
		buff[flags[8][0]++] = (sign >= 0) ? '+' : '-';
	else if (sign < 0 && ++len)
		buff[flags[8][0]++] = '-';
	while (len++ < flags[6][0])
		buff[flags[8][0]++] = '0';
	while (!flags[3][0] && flags[5][0] > len++)
		buff[flags[8][0]++] = (flags[4][0] == 1) ? '0' : ' ';
	return (len);
}
int	store_espaces(int flags[10][1], int len, char buff[2000])
{
	while (flags[3][0] && flags[5][0] > len)
	{
		buff[flags[8][0]++] = ' ';
		len++;
	}
	return (len);
}

int	order_flags(int flags[7][1])
{
	if (flags[1][0] == 1)
		flags[2][0] = 0;
	if (flags[3][0] == 1)
		flags[4][0] = 0;
	return (1);
}

int	store_float_fspaces(int flags[10][1], int sign, int len, char bf[2000])
{
	if (sign >= 0 && flags[2][0] && ++len)
		bf[flags[8][0]++] = ' ';
	if (sign >= 0 && flags[1][0] && ++len)
		bf[flags[8][0]++] = '+';
	while (flags[5][0]-- > len + flags[6][0] + flags[0][0])
	{
		if (flags[4][0])
			bf[flags[8][0]++] = '0';
		else
			bf[flags[8][0]++] = ' ';
	}
	return (len);
}

int	store_nbr(int flags[10][1], long double nbr, char buff[2000], int mode)
{

	(void)flags;
	(void)nbr;
	(void)buff;
	(void)mode;
	return (1);
	/*	int				len;
	int				i;
	long long int	part;
	long double		ret;
	int				pow;
	int				*bignbr;

	pow = 0;
	(void)part;
	(void)flags;
	(void)buff;
	nbr = va_arg(ap, double);
	while (ret > MAX_LLINT && ++pow)
		ret /= MAX_LLINT;
	bignbr = (int *)malloc(sizeof(int) * ((pow * MAX_LLINT) + ft_nbrlen(ret)));
	nbr /= MAX_LLINT;
	while (nbr >= 1)
	{
		part = ret;
		while (part > 1)
		{
			bignbr[i++] = part % 10;
			part /= 10;
		}
	}
	return (pow);
*/}
