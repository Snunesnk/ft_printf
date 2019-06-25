/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 10:23:23 by snunes            #+#    #+#             */
/*   Updated: 2019/06/25 20:07:01 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_int(t_flags *flag, va_list ap)
{
	int nbr;

	nbr = va_arg(ap, int);
	if (flag->conv == 'd' || flag->conv == 'i' || flag->conv == 'D')
		return (print_nb(flag, nbr, 10));
	if (flag->conv == 'o')
		return (print_unb(flag, nbr, 8));
	if (flag->conv == 'x' || flag->conv == 'X')
		return (print_unb(flag, nbr, 16));
	return (-1);
}

int	get_u_int(t_flags *flag, va_list ap)
{
	unsigned int nbr;

	flag->plus = 0;
	flag->space = 0;
	nbr = va_arg(ap, unsigned int);
	if (flag->conv == 'u' || flag->conv == 'U')
		return (print_unb(flag, nbr, 10));
	if (flag->conv == 'o')
		return (print_unb(flag, nbr, 8));
	if (flag->conv == 'x' || flag->conv == 'X')
		return (print_unb(flag, nbr, 16));
	return (-1);
}

int get_double(t_flags *flag, va_list ap)
{
	char	*bits;
	double	nbr;
	char	mant[56];
	char	*espaces;
	char 	att[5];
	int 	len;

	len = 0;
	flag->preci = (flag->preci == -1) ? 6 : flag->preci;
	ft_bzero(mant, 56);
	mant[0] = '1';
	nbr = va_arg(ap, double);
	flag->sign = (nbr >= 0) ? 1 : -1;
	bits = ((char *)&nbr);
	dprintf(2, "nb = %lf\n", nbr);
	if ((len = create_doub(bits, mant)) < 0 || nbr == 0)
		return (handle_exept(flag, len, nbr >= 0));
//	dprintf(2, "flag->preci = %d\n", flag->preci);
	while (mant[len] && mant[len] != '.')
		len++;
	len += fill_att(flag, nbr, att);
	len = flag->width - (flag->preci + len + 1);
	if (!(espaces = make_espaces(flag, len)))
		return (-1);
	len = print_double(flag, mant, espaces, att);
	free(espaces);
	dprintf(2, "Checkpoint fin de fonction\n");
	return (len);
}

int get_hh_int(t_flags *flag, va_list ap)
{
	signed char nbr;

	nbr = va_arg(ap, int);
	if (flag->conv == 'd' || flag->conv == 'i' || flag->conv == 'D')
		return (print_nb(flag, nbr, 10));
	if (flag->conv == 'U')
		return (print_unb(flag, nbr, 10));
	if (flag->conv == 'o' || flag->conv == 'O')
		return (print_unb(flag, nbr, 8));
	if (flag->conv == 'x' || flag->conv == 'X')
		return (print_unb(flag, nbr, 16));
	return (-1);
}

int	get_h_int(t_flags *flag, va_list ap)
{
	short int nbr;

	nbr = va_arg(ap, int);
	if (flag->conv == 'd' || flag->conv == 'i' || flag->conv == 'D')
		return (print_nb(flag, nbr, 10));
	if (flag->conv == 'U')
		return (print_unb(flag, nbr, 10));
	if (flag->conv == 'o' || flag->conv == 'O')
		return (print_unb(flag, nbr, 8));
	if (flag->conv == 'x' || flag->conv == 'X')
		return (print_unb(flag, nbr, 16));
	return (-1);
}
