/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 12:21:59 by snunes            #+#    #+#             */
/*   Updated: 2019/06/12 16:39:51 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_l_int(int flags[10][1], va_list ap, char buff[2000])
{
	long int nbr;

	printf("entree long int\n");
	nbr = va_arg(ap, long int);
	if (flags[7][0] == 'd' || flags[7][0] == 'i')
		return (store_nb(flags, buff, nbr));
	if (flags[7][0] == 'o')
		return (store_oct(flags, buff, nbr));
	if (flags[7][0] == 'x' || flags[7][0] == 'X')
		return (store_hex(flags, buff, nbr));
	if (flags[7][0] == 'c')
		return (store_char(flags, buff, nbr));
	return (-1);
}

int get_ll_int(int flags[10][1], va_list ap, char buff[2000])
{
	long long int nbr;

	nbr = va_arg(ap, long long int);
	if (flags[7][0] == 'd' || flags[7][0] == 'i')
		return (store_nb(flags, buff, nbr));
	if (flags[7][0] == 'o')
		return (store_oct(flags, buff, nbr));
	if (flags[7][0] == 'x' || flags[7][0] == 'X')
		return (store_hex(flags, buff,nbr));
	if (flags[7][0] == 'c')
			return (store_char(flags, buff, nbr));
	return (-1);
}

int get_L_double(int flags[10][1], va_list ap, char buff[2000])
{
	long double ret;
	long double nbr;
	int 		len;
	int 		preci;
	
	flags[6][0] = (flags[6][0] == -1) ? 6 : flags[6][0];
	len = 0;
	nbr = va_arg(ap, long double);
	ret = nbr;
	while (ret >= 1 && ++len)
		ret /= 10;
	len = store_float_fspaces(flags, nbr >= 0, len, buff);
	flags[8][0] += store_nbr(flags, nbr, buff, 1);
	if (flags[0][0] == 1 || flags[6][0] >= 0)
		buff[flags[8][0]++] = '.';
	preci = flags[6][0];
	while (preci--)
		nbr *= 10;
	flags[8][0] += store_nbr(flags, nbr, buff, 2);
	store_espaces(flags, len + flags[6][0], buff);
	return (1);
}

int get_ull_int(int flags[10][1], va_list ap, char buff[2000])
{
	unsigned long long int nbr;

	nbr = va_arg(ap, unsigned long long int);
	if (flags[7][0] == 'u')
		return (store_unb(flags, buff, nbr));
	if (flags[7][0] == 'o')
		return (store_oct(flags, buff, nbr));
	if (flags[7][0] == 'x' || flags[7][0] == 'X')
		return (store_hex(flags, buff, nbr));
	if (flags[7][0] == 'c')
			return (store_char(flags, buff, nbr));
	return (-1);
}

int	get_ul_int(int flags[10][1], va_list ap, char buff[2000])
{
	unsigned long int nbr;

	nbr = va_arg(ap, unsigned long int);
	if (flags[7][0] == 'u')
		return (store_nb(flags, buff, nbr));
	if (flags[7][0] == 'o')
		return (store_oct(flags, buff, nbr));
	if (flags[7][0] == 'x' || flags[7][0] == 'X')
		return (store_hex(flags, buff, nbr));
	if (flags[7][0] == 'c')
			return (store_char(flags, buff, nbr));
	return (-1);
}
