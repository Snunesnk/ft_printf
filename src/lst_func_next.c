/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 12:21:59 by snunes            #+#    #+#             */
/*   Updated: 2019/06/15 13:53:05 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_l_int(t_flags *flag, va_list ap, char buff[2000])
{
	long int nbr;

	nbr = va_arg(ap, long int);
	if (flag->conv == 'd' || flag->conv == 'i' || flag->conv == 'D')
		return (store_nb(flag, buff, nbr));
	if (flag->conv == 'o')
		return (store_oct(flag, buff, nbr));
	if (flag->conv == 'x' || flag->conv == 'X')
		return (store_hex(flag, buff, nbr));
	if (flag->conv == 'c')
		return (store_char(flag, buff, nbr));
	return (-1);
}

int get_ll_int(t_flags *flag, va_list ap, char buff[2000])
{
	long long int nbr;

	nbr = va_arg(ap, long long int);
	if (flag->conv == 'd' || flag->conv == 'i' || flag->conv == 'D')
		return (store_nb(flag, buff, nbr));
	if (flag->conv == 'o')
		return (store_oct(flag, buff, nbr));
	if (flag->conv == 'x' || flag->conv == 'X')
		return (store_hex(flag, buff,nbr));
	if (flag->conv == 'c')
			return (store_char(flag, buff, nbr));
	return (-1);
}

int get_L_double(t_flags *flag, va_list ap, char buff[2000])
{
	long double ret;
	long double nbr;
	int 		len;
	int 		preci;
	
	flag->preci = (flag->preci == -1) ? 6 : flag->preci;
	len = 0;
	nbr = va_arg(ap, long double);
	ret = nbr;
	while (ret >= 1 && ++len)
		ret /= 10;
	len = store_float_fspaces(flag, nbr >= 0, len, buff);
	flag->bpos += store_nbr(flag, nbr, buff, 1);
	if (flag->diez == 1 || flag->preci >= 0)
		buff[flag->bpos++] = '.';
	preci = flag->preci;
	while (preci--)
		nbr *= 10;
	flag->bpos += store_nbr(flag, nbr, buff, 2);
	store_espaces(flag, len + flag->preci, buff);
	return (1);
}

int get_ull_int(t_flags *flag, va_list ap, char buff[2000])
{
	unsigned long long int nbr;

	nbr = va_arg(ap, unsigned long long int);
	if (flag->conv == 'u' || flag->conv == 'D')
		return (store_unb(flag, buff, nbr));
	if (flag->conv == 'o')
		return (store_oct(flag, buff, nbr));
	if (flag->conv == 'x' || flag->conv == 'X')
		return (store_hex(flag, buff, nbr));
	if (flag->conv == 'c')
			return (store_char(flag, buff, nbr));
	return (-1);
}

int	get_ul_int(t_flags *flag, va_list ap, char buff[2000])
{
	unsigned long int nbr;

	nbr = va_arg(ap, unsigned long int);
	if (flag->conv == 'u' || flag->conv == 'D')
		return (store_nb(flag, buff, nbr));
	if (flag->conv == 'o')
		return (store_oct(flag, buff, nbr));
	if (flag->conv == 'x' || flag->conv == 'X')
		return (store_hex(flag, buff, nbr));
	if (flag->conv == 'c')
			return (store_char(flag, buff, nbr));
	return (-1);
}
