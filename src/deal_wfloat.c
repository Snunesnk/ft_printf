/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_wfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:27:36 by snunes            #+#    #+#             */
/*   Updated: 2019/06/11 18:53:35 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*double_unit(long double nbr)
{
	int i;
	char		*test;
	int			unit;
	int			len;
	long double num;
	long double pow;

	test = (char *)ft_memalloc(sizeof(char) * 999);
	i = 0;
	len = 1;
	pow = 1;
	while (pow * 10 <= nbr && ++len)
		pow *= 10;
	while (pow > 1)
	{
		unit = nbr / pow;
		num = unit * pow;
		nbr -= num;
		test[i++] = unit + '0';
		pow /= 10;
	}
	test[i] = '\0';
//	printf("test = %s\n", test);
//	printf("unite = %Lf\n", nbr);
	return (test);
}
