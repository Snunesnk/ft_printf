/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:23:23 by snunes            #+#    #+#             */
/*   Updated: 2019/06/10 21:03:10 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_get_int(int flags[10][1], va_list ap, char buff[2000])
{
	int nbr;

	nbr = va_arg(ap, int);
	if (flags[7][0] == 'd' || flags[7][0] == 'i' || flags[7][0] == 'u')
		return (ft_store_nbr(flags, buff, nbr));
	if (flags[7][0] == 'o')
		return (ft_store_oct(flags, buff, nbr));
	if (flags[7][0] == 'x' || flags[7][0] == 'X')
		return (ft_store_hex(flags, buff, nbr));
	return (-1);
}

int	ft_get_u_int(int flags[10][1], va_list ap, char buff[2000])
{
	unsigned int nbr;

	nbr = va_arg(ap, unsigned int);
	if (flags[7][0] == 'd' || flags[7][0] == 'i' || flags[7][0] == 'u')
		return (ft_store_nbr(flags, buff, nbr));
	if (flags[7][0] == 'o')
		return (ft_store_oct(flags, buff, nbr));
	if (flags[7][0] == 'x' || flags[7][0] == 'X')
		return (ft_store_hex(flags, buff, nbr));
	return (-1);
}


/** Il faut que je puisse trouver comment garder ma position sur le buffer
** a la bonne valeur, et il va falloir que j'implemente le flag '-'
**/
int ft_get_double(int flags[10][1], va_list ap, char buff[2000])
{
	double ret;
	double nbr;
	int len;
	int preci;

	len = 0;
	nbr = va_arg(ap, double);
	ret = nbr;
	while (ret >= 1 && ++len)
		ret /= 10;
	ret = store_float_fspaces(flags, nbr >= 0, len, buff);
	flags[8][0] += store_nbr(flags, nbr, buff, 1);
	if (flags[0][0] == 1 || flags[6][0] >= 0)
		buff[flags[8][0]++] = '.';
	preci = flags[6][0];
	while (preci--)
		nbr *= 10;
	flags[8][0] += store_nbr(flags, nbr, buff, 2);

	return (1);
}

int ft_get_s_char(int flags[10][1], va_list ap, char buff[2000])
{
	signed char nbr;

	nbr = va_arg(ap, signed char);
	if (flags[7][0] == 'd' || flags[7][0] == 'i' || flags[7][0] == 'u')
		return (ft_store_nbr(flags, buff, nbr));
	if (flags[7][0] == 'o')
		return (ft_store_oct(flags, buff, nbr));
	if (flags[7][0] == 'x' || flags[7][0] == 'X')
		return (ft_store_hex(flags, buff, nbr));
	return (-1);
}

int	ft_get_s_int(flags[10][1], va_list ap, char buff[2000])
{
	short int nbr;

	nbr = va_arg(ap, short int);
	if (flags[7][0] == 'd' || flags[7][0] == 'i' || flags[7][0] == 'u')
		return (ft_store_nbr(flags, buff, nbr));
	if (flags[7][0] == 'o')
		return (ft_store_oct(flags, buff, nbr));
	if (flags[7][0] == 'x' || flags[7][0] == 'X')
		return (ft_store_hex(flags, buff, nbr));
	return (-1);
}
