/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_wfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:27:36 by snunes            #+#    #+#             */
/*   Updated: 2019/06/18 18:54:47 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_round(char buff[2000], int len)
{
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
}

void	ft_shiftstr(char buff[2000], int len)
{
	int i;
	int ret_prev;
	int ret_curr;

	i = len + 1;
	ret_prev = buff[i];
	buff[i] = '0';
	while (buff[i++])
	{
		ret_curr = buff[i];
		buff[i] = ret_prev;
		ret_prev = ret_curr;
	}
	buff[i] = '\0';
}

int ft_multiply(t_flags *flag, char buff[2000], int min)
{
	int len;
	int unit;
	int ret_len;

	len = flag->bpos - 3;
	ret_len = len;
	while (len > min)
	{
		if (buff[len] == '.')
			len--;
		unit = (buff[len] - 48) * 2;
		buff[len] = unit % 10 + 48;
		while (unit > 9)
		{
			len--;
			if (buff[len] == '.')
				len--;
			if (len == min)
			{
				ft_shiftstr(buff, len);
				buff[len + 1] = buff[len + 1] + 1;
				return (1);
			}
			unit = (buff[len] - 48) * 2 + 1;
			buff[len] = unit % 10 + 48;
		}
		len--;
	}
	return (0);
}

int	get_info(double nbr, double *mantisse, int *exp)
{
	union u_d_bits doub;
	int i;
	double two;

	nbr = (nbr < 0) ? -nbr : nbr;
	doub.d = nbr;
	*exp = ((doub.bits >> 52) & 0x7ffL) - 1023;
	two = 1;
	i = 0;
	while (i++ < 52)
		two /= 2;
	*mantisse = (nbr > 1) ? 1 : 0;
	while (two < 1)
	{
		*mantisse += ((doub.bits & 1) > 0) ? two : 0;
		doub.bits = doub.bits >> 1;
		two *= 2;
	}
	if (!*mantisse && *exp == -1023) // zero
		return (1);
	else if (*exp == 1024 && !(*mantisse - (nbr > 1))) // infini
		return (2);
	else if (*exp == 1024 && *mantisse) // NaN, not a number
		return (3);
	return (0);
}

int	store_double(t_flags *flag, double mantisse, int exp, char buff[2000])
{
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
}
