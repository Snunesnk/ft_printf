/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 05:51:15 by snunes            #+#    #+#             */
/*   Updated: 2019/06/04 06:08:34 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_frontspaces(int flags[7][1], int len)
{
	while (!flags[3][0] && flags[5][0] && flags[5][0] - len)
	{
		if (flags[4][0] == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		flag[5][0]--;
	}
}

void	print_frontnb(int flags[7][1], long double  nb)
{
	if (flags[1][0] == 1 && nb >= 0)
			write(1, "+", 1);
	else if (flag[2][0] == 1 && nb >= 0)
		write(1, " ", 1);
}

void	print_endspaces(int flags[7][1], int len)
{
	while (flags[3][0] && flags[5][0] && flags[5][0] - len)
	{
		write(1, " ", 1);
		flags[5][0]--;
	}
}
