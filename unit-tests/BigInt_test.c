/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BigInt_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 16:39:21 by snunes            #+#    #+#             */
/*   Updated: 2019/06/20 20:12:38 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_zero(char buff[65])
{
	int i;

	i = 0;
	while (i < 65)
		buff[i++] = '\0';
}

int main(void)
{
	char buff[65];
	char two[65];


	ft_zero(buff);
	ft_zero(two);
	ft_strcat(buff, "789");
	ft_strcat(two, "987");
	printf("tests sur \"%s\"\n", buff);
	ft_shiftstr(buff, 0, 1);
	printf("decalage a droite : %s\n", buff);
	ft_shiftstr(buff, 0, 2);
	printf("decalage a gauche : %s\n\n", buff);
/*	while (buff[0] != '0')
	{
		ft_divide(buff, 0);
		printf("division par deux : %s\n", buff);
	}
	while ((buff[0] != '2' || buff[1] != '4'))
	{
		ft_multiply(buff, 0, 8);
		printf("multiplication par deux : %s\n", buff);
	}*/
	printf("addition de %s et %s : ", buff, two);
	ft_add(buff, two);
	printf("%s\n", buff);
	return (0);
}
