/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 05:51:15 by snunes            #+#    #+#             */
/*   Updated: 2019/06/07 15:15:22 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	store_fspaces(int flags[10][1], int sign, int len, char buff[2000])
{
	int ret;

	ret = flags[5][0];
	if (flags[1][0] == 1 && flags[4][0] && sign >= 0)
		buff[flags[8][0]++] = '+';
	else if (flags[2][0] == 1 && sign >= 0)
		buff[flags[8][0]++] = '.';
	while (!flags[3][0] && flags[5][0] && (flags[5][0] - len - 1 > 0))
	{
		if (flags[4][0] == 1)
			buff[flags[8][0]++] = '0';
		else
			buff[flags[8][0]++] = ' ';
		flags[5][0]--;
	}
	if (!flags[4][0] && flags[1][0]  && sign >= 0)
		buff[flags[8][0]++] = '+';
	if (flags[0][0] == 1 && flags[7][0] == 111 || flags[7][0] == 120 
			|| flags[7][0] == 88)
		buff[flags[8][0]++] = '0';
	if (flags[0][0] == 1 && flags[7][0] == 120)
		buff[flags[8][0]] = 'x';
	if (flags[0][0] == 1 && flags[7][0] == 88)
		buff[flags[8][0]++] = 'X';
}

void	store_espaces(int flags[10][1], int len, char buff[2000])
{
	if (flags[1][0] == 1 || flags[2][0])
		len++;
	while (flags[3][0] && flags[5][0] && (flags[5][0] - len - 1> 0))
	{
		buff[flags[8][0]++] = ' ';
		flags[5][0]--;
	}
}

void	order_flags(int flags[7][1])
{
	if (flags[1][0] == 1)
		flags[2][0] = 0;
	if (flags[3][0] == 1)
		flags[4][0] = 0;
}

int		next_dec(long double nbr, long long int dec)
{
	long long int pow;
	long long int decimal;

	decimal = (nbr / pow > 1) nbr / pow : nbr;
	nbr = (decimal == nbr) ? nbr : nbr - (decimal * pow);
	decimal = (decimal == nbr) ? decimal : nbr;
	nbr = nbr - decimal;
	while (dec--)
		nbr *= 10;
	return (nbr);
}
