/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_wdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:51:29 by snunes            #+#    #+#             */
/*   Updated: 2019/06/22 20:09:56 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_to_bits(char c, char mant[66], char two[66], int nb)
{
	int i;
	int gap;

	gap = (nb == 6) ? 8 : 128;
	while (gap > 0)
	{
		i = (c & gap);
		if (i >= 1)
			ft_add(mant, two);
		gap /= 2;
		ft_divide(two);
	}
}

void	create_doub(char *bits, char mant[55])
{
	int		i;
	int		exp;
	char	two[55];

	ft_bzero(two, 55);
	two[0] = '1';
	exp = ((bits[7] & 0x7F) << 4) + ((bits[6] & 0xF0) >> 4) - 1023;
	i = 6;
	while (i > -1)
	{
		char_to_bits(bits[i], mant, two, i);
		i--;
	}
	while (exp > 0)
	{
		ft_multiply(mant);
		exp--;
	}
	while (exp < 0)
	{
		ft_divide(mant);
		exp++;
	}
}
