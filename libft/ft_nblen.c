/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nblen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 16:38:19 by snunes            #+#    #+#             */
/*   Updated: 2019/08/02 11:26:26 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nblen(uintmax_t nbr, unsigned int base)
{
	int pow;

	pow = 1;
	if (nbr == 0)
		return (1);
	while (nbr >= base)
	{
		pow += 1;
		nbr /= base;
	}
	return (pow);
}
