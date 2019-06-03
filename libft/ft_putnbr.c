/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <snunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:54:25 by snunes            #+#    #+#             */
/*   Updated: 2019/05/30 14:27:23 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(long long int n)
{
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -9223372036854775807)
		{
			ft_putchar('9');
			ft_putnbr(223372036854775807);
		}
		else
			ft_putnbr(-n);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + 48);
		else
		{
			ft_putnbr(n / 10);
			ft_putchar((n % 10) + 48);
		}
	}
}
