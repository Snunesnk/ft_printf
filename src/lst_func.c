/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:23:23 by snunes            #+#    #+#             */
/*   Updated: 2019/06/17 11:40:25 by snunes           ###   ########.fr       */
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
** mauvaise gestion du champs, et de la justification a gauche
** arrondi a implementer sur la partie entiere
** trouver pourquoi certain nombre ne passent pas bien
*/
int get_double(t_flags *flag, va_list ap, char buff[2000])
{
	int len;
	double nb;
	intmax_t ret;
	int pow;

	flag->preci = (flag->preci == -1) ? 6 : flag->preci;
	pow = 0;
	nb = va_arg(ap, double);
	ret = nb;
	len = ft_nblen(nb) + 1;
	len = (flag->diez || flag->preci) ? len + 1 : len;
	len += store_float_fspaces(flag, nb >= 0, len - 1, buff);
	nb = (nb < 0) ? -nb : nb;
	len += store_fnb(nb, flag, buff, ft_nblen(nb));
	ret = nb;
	nb = nb - ret;
	ret = flag->preci;
	while (ret-- )
		nb *= 10;
	nb = ((ret = nb * 10) % 10 >= 5) ? nb + 1 : nb;
	(flag->diez == 1 || flag->preci > 0) ? (buff[flag->bpos++] = '.') : 0;
	len += store_fnb(nb, flag, buff, flag->preci);
	store_espaces(flag, len, buff);
	return (len);
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
