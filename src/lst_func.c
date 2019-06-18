/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:23:23 by snunes            #+#    #+#             */
/*   Updated: 2019/06/18 20:42:15 by snunes           ###   ########.fr       */
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
	double nbr;
	int len;
	int lim;
	double mantisse;
	int exp;

	lim = 0;
	flag->preci = (flag->preci < 0) ? 6 : flag->preci;
	nbr = va_arg(ap, double);
	if (!(exept(get_info(nbr, &mantisse, &exp), flag, buff, nbr >= 0)))
	{
		store_float_fspaces(flag, nbr >= 0, nbr, buff);
		nbr = (nbr < 0) ? - nbr : nbr;
		store_double(flag, mantisse, exp, buff);
		len = 0;
		while (buff[len] != '.')
			len++;
		flag->bpos = len;
		while (flag->preci--)
		{
			buff[flag->bpos] = (lim == 1) ? '0' : buff[flag->bpos];
			if (!buff[++flag->bpos])
				lim = 1;
		}
		buff[flag->bpos] = '0';
		buff[flag->bpos + 1] = '\0';
		len = flag->bpos;
		if (buff[len + 1] >= '5')
			flag->bpos += ft_round(buff, len);
		flag->bpos += 1;
	}
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
