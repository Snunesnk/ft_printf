/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_wdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:51:29 by snunes            #+#    #+#             */
/*   Updated: 2019/06/21 16:26:53 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_round(char buff[2000])
{
	(void)buff;
	return (0);/*
	int unit;

	unit = buff[len] - 48 + 1;
	while (unit > 9)
	{
		buff[len--] = unit % 10 + 48;
		if (buff[len] == '.')
			len--;
		if (!len || buff[len] == '-' || buff[len] == '+' || buff[len] == ' ')
		{
			ft_shiftstr(buff, len);
			buff[len + 1] = '1';
			return (1);
		}
		unit = buff[len] - 48 + 1;
	}
	buff[len] += 1;
	return (0);
*/}

int	get_info(long double nbr, long double *mantisse, int *exp)
{
	(void)nbr;
	(void)mantisse;
	(void)exp;
	return (0);/*
	union u_bits bin;
	int i;
	long double two;
	int gap;

	gap = 64;
	nbr = (nbr < 0) ? -nbr : nbr;
	bin.nb = nbr;
	*exp = ((bin.bits[9] & 0x7F) << 8) + (bin.bits[8] & 0xFF) - 16383;
	two = 1;
	*mantisse = (nbr > 1) ? 1 : 0;
	i = 7;
	while (i >= 0)
	{
		*mantisse += (((bin.bits[i] >> gap) & 1) > 0) ? two : 0;
		two /= 2;
		gap /= 2;
		if (gap == 0)
		{
			gap = 128;
			i--;
		}
	}
	if (!*mantisse && *exp == -16383) // zero
		return (1);
	else if (*exp == 16384 && !(*mantisse - (nbr > 1))) // infini
		return (2);
	else if (*exp == 16384 && *mantisse) // NaN, not a number
		return (3);
	return (0);
*/}

int	store_double(t_flags *flag, long double mant, int exp, char buff[2000])
{
	(void)flag;
	(void)mant;
	(void)exp;
	(void)buff;
	return (0);/*
	int min;

	min = (flag->plus == 1) ? 0 : -1;
	buff[flag->bpos++] = (int)mantisse % 10 + 48;
	buff[flag->bpos++] = '.';
	while (mantisse)
	{
		mantisse -= (int)mantisse;
		mantisse *= 10;
		buff[flag->bpos++] = (int)mantisse % 10 + 48;
	}
	buff[flag->bpos++] = '\0';
	buff[flag->bpos++] = '\0';
	while (exp-- > 0)
		flag->bpos += ft_multiply(flag, buff, min + flag->space);
	return (1);
*/}
