/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_wfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 16:27:36 by snunes            #+#    #+#             */
/*   Updated: 2019/06/17 18:49:38 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

union float_bits
{
	float f;
	uint32_t bits;
};

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i++]);
	return (i - 1);
}

void	ft_shiftstr(char *str)
{
	int i;
	int ret_prev;
	int ret_curr;

	i = (str[i] == '-') ? 1 : 0;
	ret_prev = str[i];
	str[i] = '0';
	while (str[i++])
	{
		ret_curr = str[i];
		str[i] = ret_prev;
		ret_prev = ret_curr;
	}
}

void	ft_multiply(char *str, int nb)
{
	int len;
	int unit;
	int ret_len;

	ret_len = len;
	len = ft_strlen(str) - 1;
	while (len >= 0)
	{
		if (str[len] == '.')
			len--;
		unit = (str[len] - 48) * nb;
		str[len] = unit % 10 + 48;
		while (unit > 9)
		{
			len--;
			if (str[len] == '.')
				len--;
			unit = (str[len] - 48) * 2 + 1;
			str[len] = unit % 10 + 48;
			if ((str[len] == '-' || len == 0))
			{
				ft_shiftstr(str);
				unit = 0;
				len = 0;
			}
		}
		len--;
	}
	//printf("result = %s\n", str);
}

void	get_bin_nbr(long double nbr)
{
	int sign;
	int exp;
	long double mantisse;
	union float_bits floa;
	int i;
	long double num;
	long double two;
	char 	*result;
	int div;
	long double ret_m;

	printf("nb a print : %Lf\n", nbr);
	i = 0;
	result = (char *)malloc(sizeof(char) * 82);
	result[64] = '\0';
	floa.f = nbr;
	exp = ((floa.bits >> 23) & 0xffu) - 127;
	two = 1;
	div = 0;
	while (div++ < 23)
		two /= 2;
	mantisse = 1;
	div = 23;
	while (two < 1)
	{
		mantisse += ((floa.bits & 1) > 0) ? two : 0;
		floa.bits = floa.bits >> 1;
		two *= 2;
	}
	ret_m = mantisse;
	result[i++] = (int)mantisse % 10 + 48;
	result[i++] = '.';
	while (mantisse)
	{
		mantisse -= (int)mantisse;
		mantisse *= 10;
		result[i++] = (int)mantisse % 10 + 48;
	}
	result[i] = '\0';
	two = 2;
	while (exp--)
	{
		two *= 2;
		ft_multiply(result, 2);
	}
	printf("result = %s\n", result);
}

int main()
{
	long double nbr;

	nbr = 1677568764.341651687;
	printf("nbr passe = %Lf\n", nbr);
	get_bin_nbr(nbr);
	return (0);
}
