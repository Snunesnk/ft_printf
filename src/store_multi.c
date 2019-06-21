/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_multi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:41:56 by snunes            #+#    #+#             */
/*   Updated: 2019/06/21 16:44:13 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	store_nb(t_flags *flag, intmax_t nb)
{
	char	*nb;
	char	*espaces;
	int		len;
	int		e_len;

	e_len = 0;
	len = ft_nblen(nb);
	while (flag->preci > len)
		len++;
	while (flag->width > len + e_len)
		e_len++;
	if (!(espaces = make_espaces(e_len))
			|| !(nb = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (-1);
	len = store_fspaces(flag, nb >= 0, len, buff);
	nb = (nb > 0) ? nb : -1 * nb;
	while (ret > 1 && ret--)
		pow *= 10;
	while (pow)
	{
		buff[flag->bpos++] = nb / pow % 10 + 48;
		pow /= 10;
	}
	return (store_espaces(flag, len, buff));
}

int	store_unb(t_flags *flag, uintmax_t nb)
{
	(void)flag;
	(void)nb;
	return (0);/*
	uintmax_t ret;
	int len;
	long long pow;

	pow = 1;
	len = 1;
	if (nb == 0 && flag->preci == 0)
	{
		(flag->plus == 1) ? buff[flag->bpos++] = '+' : 0;
		(flag->space == 1) ? buff[flag->bpos++] = ' ' : 0;
		return (0);
	}
	ret = nb;
	while (ret / 10 && ++len)
		ret /= 10;
	ret = len;
	len = store_fspaces(flag, 1, len, buff);
	while (ret > 1 && ret--)
		pow *= 10;
	while (pow)
	{
		buff[flag->bpos++] = nb / pow % 10 + 48;
		pow /= 10;
	}
	return (store_espaces(flag, len, buff));
*/}

int store_oct(t_flags *flag, uintmax_t nb)
{
	(void)flag;
	(void)nb;
	return (0);/*
	uintmax_t ret;
	int len;
	long long pow;

	pow = 1;
	len = 1;
	if (nb == 0 && flag->preci == 0)
	{
		(flag->plus == 1) ? buff[flag->bpos++] = '+' : 0;
		(flag->space == 1) ? buff[flag->bpos++] = ' ' : 0;
		return (0);
	}
	ret = nb;
	while (ret / 8 && ++len)
		ret /= 8;
	ret = len;
	(nb == 0) ? (flag->nb = 0) : (flag->nb = 1);
	len = store_fspaces(flag, 1, len, buff);
	while (ret > 1 && ret--)
		pow += 1;
	ret = pow;
	while (pow--)
	{
		buff[flag->bpos + pow] = nb % 8 + 48;
		nb /= 8;
	}
	flag->bpos += ret;
	return (store_espaces(flag, len, buff));
*/}

int	store_hex(t_flags *flag, uintmax_t nb)
{
	(void)flag;
	(void)nb;
	return (0);/*
	uintmax_t ret;
	int len;
	long long pw;
	char let;

	let = flag->conv - 23;
	pw = 1;
	len = 1;
	if (nb == 0 && flag->preci == 0)
	{
		flag->diez = 0;
		bf[flag->bpos] += store_fspaces(flag, 1, 0, bf);
		return (0);
	}
	ret = nb;
	while (ret / 16 && ++len)
		ret /= 16;
	ret = len;
	(nb == 0) ? (flag->nb = 0) : (flag->nb = 1);
	len = store_fspaces(flag, 1, len, bf);
	while (ret > 1 && ret--)
		pw += 1;
	ret = pw;
	while (pw--)
	{
		bf[flag->bpos + pw] = (nb % 16 > 9) ? nb % 16 - 10 + let : nb % 16 + 48;
		nb /= 16;
	}
	flag->bpos += ret;
	return (store_espaces(flag, len, bf));
*/}

int store_char(t_flags *flag, char c)
{
	(void)flag;
	(void)c;
	return (0);/*
	while (!flag->minus && flag->width-- > 1)
		buff[flag->bpos++] = ' ';
	buff[flag->bpos++] = (c == 0) ? -1 : c;
	while (flag->minus && flag->width-- > 1)
		buff[flag->bpos++] = ' ';
	return (1);
*/}
