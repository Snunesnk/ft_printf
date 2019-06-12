/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:34:52 by snunes            #+#    #+#             */
/*   Updated: 2019/06/07 13:12:06 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbrlen(long long int nbr)
{
	int len;

	len = 1;
	while (nbr > 9)
	{
		nbr /= 10;
		++len;
	}
	return (len);
}
