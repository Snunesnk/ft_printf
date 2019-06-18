/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exept_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:53:28 by snunes            #+#    #+#             */
/*   Updated: 2019/06/18 17:31:45 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_zero(t_flags *flag, char buff[2000], int sign)
{
	store_float_fspaces(flag, sign, 1.0, buff);
	buff[flag->bpos++] = '0';
	if (flag->diez || flag->preci > 0)
	{
		buff[flag->bpos++] = '.';
		while (flag->preci--)
			buff[flag->bpos++] = '0';
	}
	return (1);
}

int	exept(int nb_exept, t_flags *flag, char buff[2000], int sign)
{
	if (nb_exept == 0)
		return (0);
	if (nb_exept == 1)
		return (handle_zero(flag, buff, sign));
	while (!flag->minus && flag->width-- > 3)
		buff[flag->bpos++] = ' ';
	if (nb_exept == 2)
	{
		if (sign == 0 || flag->plus == 1)
			buff[flag->bpos++] = (sign == 0) ? '-' : '+';
		buff[flag->bpos++] = '\0';
		ft_strcat(buff, "inf");
		flag->bpos += 2;	
	}
	else if (nb_exept == 3)
	{
		buff[flag->bpos++] = '\0';
		ft_strcat(buff, "nan");
		flag->bpos += 2;
	}
	while (flag->minus && flag->width-- > 3)
		buff[flag->bpos++] = ' ';
	return (1);
}
