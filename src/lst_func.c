/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:23:23 by snunes            #+#    #+#             */
/*   Updated: 2019/06/12 19:51:38 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_int(int flags[10][1], va_list ap, char buff[2000])
{
	int nbr;

	nbr = va_arg(ap, int);
//	printf("nbr recup = %d\n", nbr);
	if (flags[7][0] == 'd' || flags[7][0] == 'i' || flags[7][0] == 'D')
		return (store_nb(flags, buff, nbr));
	if (flags[7][0] == 'o')
		return (store_oct(flags, buff, nbr));
	if (flags[7][0] == 'x' || flags[7][0] == 'X')
		return (store_hex(flags, buff, nbr));
	if (flags[7][0] == 'c')
		return (store_char(flags, buff, nbr));
	return (-1);
}

int	get_u_int(int flags[10][1], va_list ap, char buff[2000])
{
	unsigned int nbr;

	nbr = va_arg(ap, unsigned int);
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

/*
** mauvaise gestion du champs, et de la justification a gauche
** arrondi a implementer sur la partie entiere
** trouver pourquoi certain nombre ne passent pas bien
*/
int get_double(int flags[10][1], va_list ap, char buff[2000])
{
	long long int	part;
	double			nbr;
	double 			ret;
	int				pow;

	pow = 0;
	(void)part;
	(void)flags;
	(void)buff;
	nbr = va_arg(ap, double);
	while (nbr >= 1)
	{
		ret = nbr;
		while (ret > MAX_LLINT && ++pow)
			ret /= MAX_LLINT;
		nbr /= MAX_LLINT;
	}
/*	double ret;
	double nbr;
	int len;
	int preci;


	flags[6][0] = (flags[6][0] == -1) ? 6 : flags[6][0];
	len = 0;
	nbr = va_arg(ap, double);
	len = 0;
	while (len++ < 17)
	{
		nbr *= 10;
		printf("nbr * 10 = %f\n", nbr);
	}
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
	nbr = ((long long int)(nbr * 10) % 10 >= 5) ? nbr + 1 : nbr;
	flags[8][0] += store_nbr(flags, nbr, buff, 2);
	store_espaces(flags, len + flags[6][0], buff);
*/	return (1);
}

int get_hh_int(int flags[10][1], va_list ap, char buff[2000])
{
	signed char nbr;

	nbr = va_arg(ap, int);
	if (flags[7][0] == 'd' || flags[7][0] == 'i' || flags[7][0] == 'D')
		return (store_nb(flags, buff, nbr));
	if (flags[7][0] == 'o')
		return (store_oct(flags, buff, nbr));
	if (flags[7][0] == 'x' || flags[7][0] == 'X')
		return (store_hex(flags, buff, nbr));
	if (flags[7][0] == 'c')
		return (store_char(flags, buff, nbr));
	return (-1);
}

int	get_h_int(int flags[10][1], va_list ap, char buff[2000])
{
	short int nbr;

	nbr = va_arg(ap, int);
	if (flags[7][0] == 'd' || flags[7][0] == 'i' || flags[7][0] == 'D')
		return (store_nb(flags, buff, nbr));
	if (flags[7][0] == 'o')
		return (store_oct(flags, buff, nbr));
	if (flags[7][0] == 'x' || flags[7][0] == 'X')
		return (store_hex(flags, buff, nbr));
	if (flags[7][0] == 'c')
		return (store_char(flags, buff, nbr));
	return (-1);
}
