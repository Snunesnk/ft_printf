/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 05:51:15 by snunes            #+#    #+#             */
/*   Updated: 2019/06/10 21:03:12 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

void	order_flags(int flags[7][1])
{
	if (flags[1][0] == 1)
		flags[2][0] = 0;
	if (flags[3][0] == 1)
		flags[4][0] = 0;
}

int	store_float_fspaces(int flags[10][0], int sign, int len, char buff[2000])
{
	
}

int	store_nbr(int flags[10][0], long double nbr, char buff[2000], int mode)
{
	long double ret;
	int 		len;
	int			len_ret;

	len = 0;
	ret = nbr;
	while (nbr >= 1 && ++len)
		nbr /= 10;
	if (mode == 2)
		len = flags[6][0];
	len_ret = len;
	while (len--)
	{
		buff[flags[8][0] + len] = (int)(ret - (int)(ret / 10) * 10) + '0';
		ret /= 10;
	}
	return (len_ret);
}
