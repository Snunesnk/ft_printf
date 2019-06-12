/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:41:14 by snunes            #+#    #+#             */
/*   Updated: 2019/06/12 16:34:33 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int get_uhh_int(int flags[10][1], va_list ap, char buff[2000])
{
	unsigned char nbr;

	nbr = va_arg(ap, int);
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

int get_uh_int(int flags[10][1], va_list ap, char buff[2000])
{
	unsigned short int nbr;

	nbr = va_arg(ap, int);
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
