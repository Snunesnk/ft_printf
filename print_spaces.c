/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 05:51:15 by snunes            #+#    #+#             */
/*   Updated: 2019/06/05 03:17:20 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_frontspaces(int flags[7][1], long double nb, int len)
{
	int ret;

	ret = flags[5][0];
	if (flags[1][0] == 1 && flags[4][0] && nb >= 0)
		write(1, "+", 1);
	else if (flags[2][0] == 1 && nb >= 0)
		write(1, " ", 1);
	while (!flags[3][0] && flags[5][0] && (flags[5][0] - len - 1 > 0))
	{
		if (flags[4][0] == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		flags[5][0]--;
	}
	if (!flags[4][0] && flags[5][0] && flags[1][0]  && nb >= 0)
		write(1, "+", 1);
}

void	print_frontnb(int flags[7][1], char c)
{
	if (flags[0][0] == 1 && c == 'o')
		write(1, "0", 1);
	if (flags[0][0] == 1 && c == 'a')
		write(1, "0x", 2);
	if (flags[0][0] == 1 && c == 'A')
		write(1, "0X", 2);;
}

void	print_endspaces(int flags[7][1], int len)
{
	if (flags[1][0] == 1)
		len++;
	while (flags[3][0] && flags[5][0] && (flags[5][0] - len - 1> 0))
	{
		write(1, " ", 1);
		flags[5][0]--;
	}
}

void	order_flags(int flags[7][1])
{
	if (flags[1][0] == 1)
		flags[2][0] = 0;
	if (flags[3][0] == 1)
		flags[4][0] = 0;
}
