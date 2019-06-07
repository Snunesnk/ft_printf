/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 12:21:59 by snunes            #+#    #+#             */
/*   Updated: 2019/06/07 14:32:09 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_get_l_int(int flags[10][1], va_list ap, char buff[2000])
{
	long int nbr;

	nbr = va_arg(ap, long int);
	if (flags[7][0] == 100 || flags[7][0] == 105 || flags[7][0] == 117)
		return (ft_store_nbr(flags, buff));
	if (flags[7][0] == 111)
		return (ft_store_oct(flags, buff));
	if (flags[7][0] == 120 || flags[7][0] == 88)
		return (ft_store_hex(flags, buff));
	return (-1);
}

int ft_get_ll_int(int flags[10][1], va_list ap, char buff[2000])
{
	long long int nbr;

	nbr = va_arg(ap, long long int);
	if (flags[7][0] == 100 || flags[7][0] == 105 || flags[7][0] == 117)
		return (ft_store_nbr(flags, buff));
	if (flags[7][0] == 111)
		return (ft_store_oct(flags, buff));
	if (flags[7][0] == 120 || flags[7][0] == 88)
		return (ft_store_hex(flags, buff));
	return (-1);
}

int ft_get_L_double(int flags[10][1], va_list ap, char buff[2000])
{
	long long int pow;
	long long int part;
	long double nbr;
	int len;

	flags[6][0] = (flags[6][0] == -1) ? 6 : flags[6][0];
	pow = 10000000000000000000;
	nbr = va_arg(ap, long double);
	part = (nbr / pow > 1) ? ft_nbrrev(nbr / pow) : ft_nbrrev(nbr);
	len = (ft_nbrrev(part) != nbr) ? ft_nbrlen(part) + 19 : ft_nbrlen(part);
	store_fspaces(flags, nbr >= 0, len + flags[6][0], buff);
	while (len--)
	{
		buff[flags[8][0]++] = part % 10 + 48;
		part = (len == 19) ? nbr / pow - ((part = nbr / pow) * pow) : part / 10;
	}
	if (flags[6][0] >= 0)
		buff[flags[8][0]++] == '.';
	part = 0;
	while (flags[6][0] && ++part)
		buff[flags[8][0]++] = next_dec(nbr, part) % 10 + 48;
	store_espaces(flags, len + flags[6][0]);
	return (0);
}
