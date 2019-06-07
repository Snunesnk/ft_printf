/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 17:44:26 by snunes            #+#    #+#             */
/*   Updated: 2019/06/07 13:05:56 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long int ft_nbrrev(long long int nbr)
{
	int len;
	long long int ret;

	ret = nbr;
	len = 1;
	ret = 0;
	while (len < nbr)
	{
		ret = ret * 10 + (nbr / len) % 10;
		len *= 10;
	}
	return (ret);
}
