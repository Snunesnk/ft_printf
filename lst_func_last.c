/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:41:14 by snunes            #+#    #+#             */
/*   Updated: 2019/06/10 17:48:35 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_get_u_char(int flags[10][1], va_list ap, char buff[2000])
{
	unsigned char nbr;

	nbr = va_arg(ap, unsigned char);
	if (flags[7][0] == 'd' || flags[7][0] == 'i' || flags[7][0] == 'u')
		return (ft_store_nbr(flags, buff, nbr));
	if (flags[7][0] == 'o')
		return (ft_store_oct(flags, buff, nbr));
	if (flags[7][0] == 'x' || flags[7][0] == 'X')
		return (ft_store_hex(flags, buff, nbr));
	return (-1);
}

void	ft_get_us_int(int flags[10][1], va_list ap, buff[2000])
{
	unsigned short nbr;

	nbr = va_arg(ap, unsigned short);
	if (flags[7][0] == 'd' || flags[7][0] == 'i' || flags[7][0] == 'u')
		return (ft_store_nbr(flags, buff, nbr));
	if (flags[7][0] == 'o')
		return (ft_store_oct(flags, buff, nbr));
	if (flags[7][0] == 'x' || flags[7][0] == 'X')
		return (ft_store_hex(flags, buff, nbr));
	return (-1);
}
