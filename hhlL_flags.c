/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hhlL_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 19:26:26 by snunes            #+#    #+#             */
/*   Updated: 2019/06/04 05:43:22 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>

int	print_sint(va_list ap, char c, int flags[7][1])
{
	int	nb;

	nb = va_arg(ap, int);
	if (c == 'o')
		return (print_octal(flags, (unsigned int)nb));
	if (c == 'd' || c == 'i')
		return (print_nbr(flags, nb));
	if (c == 'u')
		return (print_nbr(flags, (unsigned int)nb));
	if (c == 'x' || c == 'X')
		return (print_hexa(flags, c, nb));
	return (-1);
}

int print_llint(va_list ap, char c, int flags[7][1])
{
	long long int nb;

	nb = va_arg(ap, long long int);
	if (c == 'o')
		return (print_octal(flags, (unsigned int)nb));
	if (c == 'd' || c == 'i')
		return (print_nbr(flags, nb));
	if (c == 'u')
		return (print_nbr(flags, (unsigned int)nb));
	if (c == 'x' || c == 'X')
		return (print_hexa(flags, c, nb));
	return (-1);
}

int print_lint(va_list ap, char c, int flags[7][1])
{
	long int nb;

	nb = va_arg(ap, long int);
	if (c == 'o')
		return (print_octal(flags, (unsigned int)nb));
	if (c == 'd' || c == 'i' || c == 'f')
		return (print_nbr(flags, nb));
	if (c == 'u')
		return (print_nbr(flags, (unsigned int)nb));
	if (c == 'x' || c == 'X')
		return (print_hexa(flags, c, nb));
	return (-1);
}

int print_Ldouble(va_list ap, char c, int flags[7][1])
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
	return (1);
}
