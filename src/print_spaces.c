/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 05:51:15 by snunes            #+#    #+#             */
/*   Updated: 2019/06/21 12:33:58 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *make_espaces(int len)
{
	char *str;

	if (!(str = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len--)
		str[len] = ' ';
	return (str);
}

int	put_attribute(t_flags *flag, int mode, int gap)
{
	(void)flag;
	(void)mode;
	(void)gap;
	return (0);/*
	int len;

	len = 0;
	if (flag->conv == 'p')
	{
		if (mode == 1)
			len += 2;
		else
		{
			buff[flag->bpos++] = '0';
			buff[flag->bpos++] = 'x';
		}
	}
	if (flag->diez == 1 && flag->conv == 'o' && !gap && flag->nb)
		(mode == 1) ? ++len : (buff[flag->bpos++] = '0');
	if (flag->diez == 1 && (flag->conv == 'x' || flag->conv == 'X') && flag->nb)
		(mode == 1) ? ++len : (buff[flag->bpos++] = '0');
	if (flag->diez == 1 && flag->conv == 'x' && flag->nb)
		(mode == 1) ? ++len : (buff[flag->bpos++] = 'x');
	if (flag->diez == 1 && flag->conv == 'X' && flag->nb)
		(mode == 1) ? ++len : (buff[flag->bpos++] = 'X');	
	return (len);
*/}

int	store_fspaces(t_flags *flag, int sign, int len)
{
	(void)flag;
	(void)sign;
	(void)len;
	return (0);/*
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
*/}

int	store_espaces(t_flags *flag, int len)
{
	(void)flag;
	(void)len;
	return (0);/*
	while (flag->minus && flag->width > len)
	{
		buff[flag->bpos++] = ' ';
		len++;
	}
	return (len);
*/}

int	order_flags(t_flags *flag)
{
	if (flag->plus == 1)
		flag->space = 0;
	if (flag->minus == 1)
		flag->zero = 0;
	if (flag->preci > -1 && flag->conv != 'L' && flag->conv != 'f')
		flag->zero = 0;
	return (1);
}

int	store_float_fspaces(t_flags *flag, int sign, long double nbr)
{
	(void)flag;
	(void)sign;
	(void)nbr;
	return (0);/*
	int len;

	len = 0;
	if (flag->diez || flag->preci > 0)
		len++;
	flag->plus = (sign == 0)  ? 1 : flag->plus;
	len += flag->plus;
	if (sign >= 0 && flag->space && ++len)
		bf[flag->bpos++] = ' ';
	if (flag->zero && flag->plus)
		bf[flag->bpos++] = (sign == 1) ? '+' : '-';
	while (nbr >= 1 && ++len)
		nbr /= 10;
	while (flag->width-- > len + flag->preci)
	{
		if (flag->zero)
			bf[flag->bpos++] = '0';
		else
			bf[flag->bpos++] = ' ';
	}
	if (!flag->zero && flag->plus)
		bf[flag->bpos++] = (sign == 1) ? '+' : '-';
	return (len);
*/}

int	store_fnb(long double nbr, t_flags *flag, int len)
{
	(void)nbr;
	(void)flag;
	(void)len;
	return (0);/*
	int length;
	uintmax_t ret;

	length = 0;
	ret = nbr;
	//printf("pow = %d\n", pow);
	while (len--)
	{
		buff[flag->bpos + len] = ret % 10 + 48;
		ret /= 10;
		++length;
	}
	flag->bpos += length;
 	return (length);
*/}
