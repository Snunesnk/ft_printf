/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:41:14 by snunes            #+#    #+#             */
/*   Updated: 2019/06/14 14:43:03 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int get_uhh_int(t_flags *flag, va_list ap, char buff[2000])
{
	unsigned char nbr;

	nbr = va_arg(ap, int);
	if (flag->conv == 'u')
		return (store_unb(flag, buff, nbr));
	if (flag->conv == 'o')
		return (store_oct(flag, buff, nbr));
	if (flag->conv == 'x' || (*flag).conv == 'X')
		return (store_hex(flag, buff, nbr));
	if (flag->conv == 'c')
		return (store_char(flag, buff, nbr));
	return (-1);
}

int get_uh_int(t_flags *flag, va_list ap, char buff[2000])
{
	unsigned short int nbr;

	nbr = va_arg(ap, int);
	if (flag->conv == 'u')
		return (store_unb(flag, buff, nbr));
	if (flag->conv == 'o')
		return (store_oct(flag, buff, nbr));
	if (flag->conv == 'x' || (*flag).conv == 'X')
		return (store_hex(flag, buff, nbr));
	if (flag->conv == 'c')
			return (store_char(flag, buff, nbr));
	return (-1);
}

int get_uj_int(t_flags *flag, va_list ap, char buff[2000])
{
	uintmax_t nbr;

	nbr = va_arg(ap, uintmax_t);
	if (flag->conv == 'u')
		return (store_unb(flag, buff, nbr));
	if (flag->conv == 'o')
		return (store_oct(flag, buff, nbr));
	if (flag->conv == 'x' || (*flag).conv == 'X')
		return (store_hex(flag, buff, nbr));
	if (flag->conv == 'c')
			return (store_char(flag, buff, nbr));
	return (-1);
}

int	get_j_int(t_flags *flag, va_list ap, char buff[2000])
{
	intmax_t nbr;

	nbr = va_arg(ap, intmax_t);
	if (flag->conv == 'd' || flag->conv == 'i')
		return (store_nb(flag, buff, nbr));
	if (flag->conv == 'u')
		return (store_unb(flag, buff, nbr));
	if (flag->conv == 'o')
		return (store_oct(flag, buff, nbr));
	if (flag->conv == 'x' || (*flag).conv == 'X')
		return (store_hex(flag, buff, nbr));
	if (flag->conv == 'c')
			return (store_char(flag, buff, nbr));
	return (-1);
}
