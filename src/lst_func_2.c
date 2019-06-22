/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 12:21:59 by snunes            #+#    #+#             */
/*   Updated: 2019/06/22 19:17:07 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_l_int(t_flags *flag, va_list ap)
{
	long int nbr;

	nbr = va_arg(ap, long int);
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

int get_ll_int(t_flags *flag, va_list ap)
{
	long long int nbr;

	nbr = va_arg(ap, long long int);
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

int get_L_double(t_flags *flag, va_list ap)
{
	(void)flag;
	(void)ap;
	return (0);/*
	int len;
	double nb;
	intmax_t ret;
	int pow;

	flag->preci = (flag->preci == -1) ? 6 : flag->preci;
	pow = 0;
	nb = va_arg(ap, long double);
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
*/}

int get_ull_int(t_flags *flag, va_list ap)
{
	unsigned long long int nbr;

	flag->plus = 0;
	flag->space = 0;
	nbr = va_arg(ap, unsigned long long int);
	if (flag->conv == 'u' || flag->conv == 'D')
		return (print_unb(flag, nbr, 10));
	if (flag->conv == 'U')
		return (print_unb(flag, nbr, 10));
	if (flag->conv == 'o' || flag->conv == 'O')
		return (print_unb(flag, nbr, 8));
	if (flag->conv == 'x' || flag->conv == 'X')
		return (print_unb(flag, nbr, 16));
	return (-1);
}

int	get_ul_int(t_flags *flag, va_list ap)
{	
	unsigned long int nbr;

	flag->plus = 0;
	flag->space = 0;
	nbr = va_arg(ap, unsigned long int);
	if (flag->conv == 'u' || flag->conv == 'D' || flag->conv == 'U')
		return (print_unb(flag, nbr, 10));
	if (flag->conv == 'o' || flag->conv == 'O')
		return (print_unb(flag, nbr, 8));
	if (flag->conv == 'x' || flag->conv == 'X')
		return (print_unb(flag, nbr, 16));
	return (-1);
}
