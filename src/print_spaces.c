/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 05:51:15 by snunes            #+#    #+#             */
/*   Updated: 2019/06/14 16:21:06 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_attribute(t_flags *flag, char buff[2000], int mode, int gap)
{
	int len;

	len = 0;
	if (flag->diez == 1 && flag->conv == 'o' && !gap && flag->nb)
	{
		(mode == 1) ? ++len : (buff[flag->bpos++] = '0');
	}
	if (flag->diez == 1 && (flag->conv == 'x' || flag->conv == 'X') && flag->nb)
	{
		(mode == 1) ? ++len : (buff[flag->bpos++] = '0');
	}
	if (flag->diez == 1 && flag->conv == 'x' && flag->nb)
	{
		(mode == 1) ? ++len : (buff[flag->bpos++] = 'x');
	}
	if (flag->diez == 1 && flag->conv == 'X' && flag->nb)
	{
		(mode == 1) ? ++len : (buff[flag->bpos++] = 'X');	
	}
	return (len);
}

int	store_fspaces(t_flags *flag, int sign, int len, char buff[2000])
{
	int gap;

	gap = (flag->preci > len) ? flag->preci - len : 0;
	flag->plus = (sign <= 0) ? 1 : flag->plus;
	len += put_attribute(flag, buff, 1, gap);
	if (flag->space == 1 && sign > 0 && ++len)
		buff[flag->bpos++] = ' ';
	if (flag->plus == 1 && flag->zero && ++len && !(flag->plus = 0))
		buff[flag->bpos++] = (sign > 0) ? '+' : '-';
	if (flag->zero)
		put_attribute(flag, buff, 2, gap);
	while (!flag->minus && flag->width > len + gap + flag->plus && ++len)
		buff[flag->bpos++] = (flag->zero == 1) ? '0' : ' ';
	if (!flag->zero && flag->plus && ++len)
		buff[flag->bpos++] = (sign <= 0) ? '-' : '+';
	if (!flag->zero)
		put_attribute(flag, buff, 2, gap);
	while (gap > 0 && gap-- && ++len)
		buff[flag->bpos++] = '0';
	return (len);
}

int	store_espaces(t_flags *flag, int len, char buff[2000])
{
	while (flag->minus && flag->width > len)
	{
		buff[flag->bpos++] = ' ';
		len++;
	}
	return (len);
}

int	order_flags(t_flags *flag)
{
	if (flag->plus == 1)
		flag->space = 0;
	if (flag->minus == 1)
		flag->zero = 0;
	if (flag->preci > -1)
		flag->zero = 0;
	return (1);
}

int	store_float_fspaces(t_flags *flag, int sign, int len, char bf[2000])
{
	if (sign >= 0 && flag->space && ++len)
		bf[flag->bpos++] = ' ';
	if (sign >= 0 && flag->plus && ++len)
		bf[flag->bpos++] = '+';
	while (flag->width-- > len + flag->preci + flag->diez)
	{
		if (flag->zero)
			bf[flag->bpos++] = '0';
		else
			bf[flag->bpos++] = ' ';
	}
	return (len);
}

int store_nbr(t_flags *flag, long double nbr, char buff[2000], int mode)
{
	(void)flag;
	(void)nbr;
	(void)buff;
	(void)mode;
	return (0);
}
