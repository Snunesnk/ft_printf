/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:23:23 by snunes            #+#    #+#             */
/*   Updated: 2019/06/22 20:09:54 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_int(t_flags *flag, va_list ap)
{
	int nbr;

	nbr = va_arg(ap, int);
	if (flag->conv == 'd' || flag->conv == 'i' || flag->conv == 'D')
		return (print_nb(flag, nbr, 10));
	if (flag->conv == 'o')
		return (print_unb(flag, nbr, 8));
	if (flag->conv == 'x' || flag->conv == 'X')
		return (print_unb(flag, nbr, 16));
	return (-1);
}

int	get_u_int(t_flags *flag, va_list ap)
{
	unsigned int nbr;

	flag->plus = 0;
	flag->space = 0;
	nbr = va_arg(ap, unsigned int);
	if (flag->conv == 'u' || flag->conv == 'U')
		return (print_unb(flag, nbr, 10));
	if (flag->conv == 'o')
		return (print_unb(flag, nbr, 8));
	if (flag->conv == 'x' || flag->conv == 'X')
		return (print_unb(flag, nbr, 16));
	return (-1);
}

/*
** implementer la justification a gauche
** trouver pourquoi un '-' fait plenter l'affichage
** sinon ba faire la meme chose pour les long doubles
*/

int get_double(t_flags *flag, va_list ap)
{
	char	*bits;
	double	nbr;
	char	nb;
	char	mant[55];
	char	*espaces;
	char 	att[5];
	int 	len;

	flag->preci = (flag->preci == -1) ? 6 : flag->preci;
	ft_bzero(mant, 55);
	nbr = va_arg(ap, double);
	bits = ((char *)nbr);
	create_double(bits, mant);
	len = fill_att(flag, nbr, att);
	len = flag->width - (ft_strlen(mant) + len);
	if (!(espaces = make_espaces(flag, len))
		return (-1);
	len = print_double(flag, mant, espaces, att);
	return (len);
}

int get_hh_int(t_flags *flag, va_list ap)
{
	signed char nbr;

	nbr = va_arg(ap, int);
	if (flag->conv == 'd' || flag->conv == 'i' || flag->conv == 'D')
		return (print_nb(flag, nbr, 10));
	if (flag->conv == 'U')
		return (print_unb(flag, nbr, 10));
	if (flag->conv == 'o' || flag->conv == 'O')
		return (print_unb(flag, nbr, 8));
	if (flag->conv == 'x' || flag->conv == 'X')
		return (print_unb(flag, nbr, 16));
	return (-1);
}

int	get_h_int(t_flags *flag, va_list ap)
{
	short int nbr;

	nbr = va_arg(ap, int);
	if (flag->conv == 'd' || flag->conv == 'i' || flag->conv == 'D')
		return (print_nb(flag, nbr, 10));
	if (flag->conv == 'U')
		return (print_unb(flag, nbr, 10));
	if (flag->conv == 'o' || flag->conv == 'O')
		return (print_unb(flag, nbr, 8));
	if (flag->conv == 'x' || flag->conv == 'X')
		return (print_unb(flag, nbr, 16));
	return (-1);
}
