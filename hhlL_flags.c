/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hhlL_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:26:26 by snunes            #+#    #+#             */
/*   Updated: 2019/06/05 06:07:10 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

void	print_sint(va_list ap, char c, int flags[7][1])
{
	int	nb;

	nb = va_arg(ap, int);
	if (c == 'o')
		print_octal(flags, (unsigned int)nb);
	else if (c == 'd' || c == 'i')
		print_nbr(flags, nb);
	else if (c == 'u')
		print_nbr(flags, (unsigned int)nb);
	else if (c == 'x' || c == 'X')
		print_hexa(flags, c, nb);
}

void	print_llint(va_list ap, char c, int flags[7][1])
{
	long long int nb;

	nb = va_arg(ap, long long int);
	if (c == 'o')
		print_octal(flags, (unsigned int)nb);
	else if (c == 'd' || c == 'i')
		print_nbr(flags, nb);
	else if (c == 'u')
		print_nbr(flags, (unsigned int)nb);
	else if (c == 'x' || c == 'X')
		print_hexa(flags, c, nb);
}

void	print_lint(va_list ap, char c, int flags[7][1])
{
	long int nb;

	nb = va_arg(ap, long int);
	if (c == 'o')
		print_octal(flags, (unsigned int)nb);
	else if (c == 'd' || c == 'i' || c == 'f')
		print_nbr(flags, nb);
	else if (c == 'u')
		print_nbr(flags, (unsigned int)nb);
	else if (c == 'x' || c == 'X')
		print_hexa(flags, c, nb);
}

void	print_Ldouble(va_list ap, int flags[7][1])
{
	int			print;
	int			ret;
	long double	nb;

	print = 0;
	flags[6][0] = (flags[6][0] == -1) ? 6 : flags[6][0];
	nb = va_arg(ap, long double);
	ret = nb;
	print = print + ft_nbrlen(ret);
	while (!flags[3][0] && flags[5][0] && (flags[5][0]--) - print)
	{
		if (flags[4][0] == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	ft_putnbr(nb);
	if (flags[6][0] || flags[0][0])
	{
		ft_putchar('.');
		nb = nb - ret;
		while (flags[6][0]--)
			nb *= 10;
		if (nb)
			ft_putnbr(nb);
	}
	while (flags[3][0] && flags[5][0] && (flags[5][0]--) - print)
		write(1, " ", 1);
}
