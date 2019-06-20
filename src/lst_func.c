/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:23:23 by snunes            #+#    #+#             */
/*   Updated: 2019/06/20 14:00:42 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_int(t_flags *flag, va_list ap, char buff[2000])
{
	int nbr;

	nbr = va_arg(ap, int);
	if ((*flag).conv == 'd' || (*flag).conv == 'i' || (*flag).conv == 'D')
		return (store_nb(flag, buff, nbr));
	if ((*flag).conv == 'o')
		return (store_oct(flag, buff, nbr));
	if ((*flag).conv == 'x' || (*flag).conv == 'X')
		return (store_hex(flag, buff, nbr));
	if ((*flag).conv == 'c')
		return (store_char(flag, buff, nbr));
	return (-1);
}

int	get_u_int(t_flags *flag, va_list ap, char buff[2000])
{
	unsigned int nbr;

	flag->plus = 0;
	flag->space = 0;
	nbr = va_arg(ap, unsigned int);
	if ((*flag).conv == 'u')
		return (store_unb(flag, buff, nbr));
	if ((*flag).conv == 'o')
		return (store_oct(flag, buff, nbr));
	if ((*flag).conv == 'x' || flag->conv == 'X')
		return (store_hex(flag, buff, nbr));
	if (flag->conv == 'c')
		return (store_char(flag, buff, nbr));
	return (-1);
}

/*
** implementer la justification a gauche
** trouver pourquoi un '-' fait plenter l'affichage
** sinon ba faire la meme chose pour les long doubles
*/

int get_double(t_flags *flag, va_list ap, char buff[2000])
{
	int i;
	int exp;
	double nbr;

	nbr = va_arg(ap, double);
	if (check_expt)
		return (1);
	store_float_fspaces(flag, nbr >= 0, nbr, buff);
	exp = get_mantisse(nbr, flag, buff);
	get_nbr(exp, buff, flag);
	store_espaces(flag, len, buff);
	return (1);
}

int get_hh_int(t_flags *flag, va_list ap, char buff[2000])
{
	signed char nbr;

	nbr = va_arg(ap, int);
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

int	get_h_int(t_flags *flag, va_list ap, char buff[2000])
{
	short int nbr;

	nbr = va_arg(ap, int);
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
