/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:23:23 by snunes            #+#    #+#             */
/*   Updated: 2019/06/07 15:05:36 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_get_int(int flags[10][1], va_list ap, char buff[2000])
{
	int nbr;

	nbr = va_arg(ap, int);
	if (flags[7][0] != 100 || flags[7][0] != 105)
		return (-1);
	store_fspaces(flags, nb, ft_nbrlen(nbr), buff);
	nbr = ft_nbrrev(nbr);
	while (nbr)
	{
		buff[pos++] = nbr % 10 + 48;
		nbr = nbr / 10;
	}
	return (1);
}

int	ft_get_u_int(int flags[10][1], va_list ap, char buff[2000])
{
	unsigned int nbr;

	nbr = va_arg(ap, unsigned int);
	if (flags[7][0] == 100 || flags[7][0] == 105 || flags[7][0] == 117)
		return (ft_store_nbr(flags, buff, nbr));
	if (flags[7][0] == 111)
		return (ft_store_oct(flags, buff, nbr));
	if (flags[7][0] == 120 || flags[7][0] == 88)
		return (ft_store_hex(flags, buff, nbr));
	return (-1);
}

void	ft_print_double(int flags[10][1], va_list ap, char buff[2000])
{
	
	long long int pow;
	long long int part;
	double nbr;
	int len;

	flags[6][0] = (flags[6][0] == -1) ? 6 : flags[6][0];
	pow = 10000000000000000000;
	nbr = va_arg(ap, double);
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

void	ft_get_s_char(int flags[10][1], va_list ap, char buff[2000])
{
	signed char nbr;

	nbr = va_arg(ap, signed char);
	if (flags[7][0] == 100 || flags[7][0] == 105 || flags[7][0] == 117)
		return (ft_store_nbr(flags, buff, nbr));
	if (flags[7][0] == 111)
		return (ft_store_oct(flags, buff, nbr));
	if (flags[7][0] == 120 || flags[7][0] == 88)
		return (ft_store_hex(flags, buff, nbr));
	return (-1);
}

void	ft_get_s_int(flags[10][1], va_list ap, char buff[2000])
{
	short int nbr;

	nbr = va_arg(ap, short int);
	if (flags[7][0] == 100 || flags[7][0] == 105 || flags[7][0] == 117)
		return (ft_store_nbr(flags, buff, nbr));
	if (flags[7][0] == 111)
		return (ft_store_oct(flags, buff, nbr));
	if (flags[7][0] == 120 || flags[7][0] == 88)
		return (ft_store_hex(flags, buff, nbr));
	return (-1);
}
