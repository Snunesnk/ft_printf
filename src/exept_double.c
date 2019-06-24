/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exept_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:53:28 by snunes            #+#    #+#             */
/*   Updated: 2019/06/24 21:15:10 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int handle_zero(t_flags *flag, int sign)
{
	int len;
	int ret;

	flag->diez = (flag->preci > 0) ? 1 : flag->diez;
	len = 0;
	if (!flag->minus)
	{
		while (flag->width-- > flag->preci + 1 + flag->diez + flag->plus)
			len += write(1, " ", 1);
	}
	if (flag->plus)
		len += (sign == 0) ? write(1, "-", 1) : write(1, "+", 1);
	len += write(1, "0", 1);
	if (flag->diez)
		len += write(1, ".", 1);
	ret = flag->preci;
	while (ret--)
		len += write(1, "0", 1);
	if (flag->minus)
	{
		while (flag->width-- > flag->preci + 1 + flag->diez + flag->plus)
			len += write(1, " ", 1);
	}
	return (len);
}

int	handle_exept(t_flags *flag, int nb_exept, int sign)
{
	int len;

	flag->plus = (sign == 0 && nb_exept != -3) ? 1 : flag->plus;
	len = 0;
	if (nb_exept == -1)
		return (handle_zero(flag, sign));
	if (!flag->minus)
	{
		while (flag->width-- > 3 + flag->plus)
			len += write(1, " ", 1);
	}
	if (flag->plus && nb_exept != -3)
		len += (sign == 0) ? write(1, "-", 1) : write(1, "+", 1);
	len += (nb_exept == -2) ? write(1, "inf", 3) : write(1, "nan", 3);
	if (flag->minus)
	{
		while (flag->width-- > 3 + flag->plus)
			len += write(1, " ", 1);
	}
	return (len);
}

int	is_exept(char *mant, int exp)
{
	int i;
	double mantissa;
	double pow;
	
	pow = 1;
	mantissa = 1;
	i = 2;
	while (mant[i])
	{
		pow /= 10;
		mantissa += (double)(mant[i++] - 48) * pow;
	}
	if (exp == -1023 && mantissa == 1)
		return (-1);
	if (exp == 1024 && mantissa == 1.5)
		return (-3);
	if (exp == 1024 && mantissa == 1)
		return (-2);
	return (0);
}
