/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_multi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:41:56 by snunes            #+#    #+#             */
/*   Updated: 2019/06/07 15:15:30 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_store_nbr(int flags[10][1], char buff[2000], long long int nbr)
{
	store_fspaces(flags, nbr >= 0, len , buff)
	while (nbr)
	{
		buff[flags[8][0]++] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (1);
}

int ft_store_oct(flags[10][1], char buff[2000], unsigned int nbr)
{
	unsigned int	len;
	long long int	conv;

	conv = 0;
	while (nbr > 1)
	{
		conv = conv * 10 + nbr % 8;
		nbr = nbr / 8;
	}
	len = ft_nbrlen(conv);
	flags[6][0] = ((unsigned int)flags[6][0] > len) ? flags[6][0] : len + 1;
	print_frontspaces(flags, -1, flags[6][0] - len + 1);
	while (flags[6][0] > 0 && len + flags[0][0] < (unsigned int)flags[6][0])
	{
		buff[flags[8][0]++] = '0';
		len++;
	}
	nbr = ft_nbrrev((int)(conv));
	ft_putlongnbir(nbr);
	len = ft_nbrlen(nbr);
	print_endspaces(flags, len);
}
