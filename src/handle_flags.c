/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 12:35:15 by snunes            #+#    #+#             */
/*   Updated: 2019/06/22 19:22:18 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *make_espaces(t_flags *flag, int len)
{
	char *str;

	if (len <= 0)
		len = 0;
	if (!(str = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len--)
		str[len] = (flag->zero == 1) ? '0' : ' ';
	return (str);
}

char *fill_nb_base(t_flags *flag, uintmax_t nbr, int base)
{
	int			len;
	char		*num;
	char 		letter;

	letter = (flag->conv == 'x') ? 'a' - 10: 'A' - 10;
	len = ft_nblen(nbr, base);
	len = (flag->preci == 0 && !nbr) ? 0 : len;
	while (flag->preci > len)
		++len;
	if (!(num = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len--)
	{
		num[len] = (nbr % base > 9) ? nbr % base + letter :  nbr % base + 48;
		nbr /= base;
	}
	return (num);
}
int fill_att(t_flags *flag, uintmax_t nb, char att[5])
{
	int	len;

	flag->nb = (nb == 0  && flag->preci) ? 0 : 1;
	flag->nb = (flag->preci > ft_nblen(nb, 8)) ? 0 : flag->nb;
	ft_bzero(att, 5);
	len = 0;
	if (flag->space &&  flag->sign > 0)
		att[len++] = ' ';
	if (flag->plus != 0 || flag->sign < 0)
		att[len++] = (flag->sign == -1) ? '-' : '+';
	if (flag->conv == 'p')
	{
		att[len++] = '0';
		att[len++] = 'x';
	}
	if (flag->diez == 1 && (flag->conv == 'o' || flag->conv == 'O') && flag->nb)
		att[len++] = '0';
	if (flag->diez && (flag->conv == 'x' || flag->conv == 'X') && nb)
		att[len++] = '0';
	if (flag->diez && flag->conv == 'x' && nb)
		att[len++] = 'x';
	if (flag->diez && flag->conv == 'X' && nb)
		att[len++] = 'X';
	return (len);
}

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
