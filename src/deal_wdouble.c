/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_wdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:51:29 by snunes            #+#    #+#             */
/*   Updated: 2019/06/27 15:39:52 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_round(char *mant, int bound)
{
	int i;
	int unit;
	char two[55];

	ft_bzero(two, 55);
	two[0] = '1';
	i = (bound > 54) ? 54 : bound;
	unit = mant[i] - 48;
	if (unit >= 5 && mant[--i] != '.')
	{
		unit = mant[i] - 47;
		mant[i] = (unit % 10) + 48;
		while (unit > 9 && mant[--i] != '.')
		{
			unit = mant[i] - 47;
			mant[i] = (unit % 10) + 48;
		}	
	}
	if (mant[i] == '.')
		ft_add(mant, two);
	return ((mant[i] == '.') ? 1 : 0);
}

int print_mant(t_flags *flag, char *mant)
{
	int 	len;
	int		int_part;

	flag->diez = (flag->preci > 0) ? 1 : flag->diez;
	int_part = 0;
	len = ft_strlen(mant);
	while (mant[++int_part] != '.');
	int_part += ft_round(mant, flag->preci + int_part + 1);
	write(1, mant, int_part);
	while (mant[0] != '.')
		ft_shiftstr(mant, 2);
	len = ft_strlen(mant);
	len = (flag->preci <= len) ? flag->preci : len;
	write(1, mant, len + 1);
	flag->preci = flag->preci - len;
	while (flag->preci-- > 0)
		len += write(1, "0", 1);
	return (len + int_part + flag->diez);
}

int	print_double(t_flags *flag, char *mant, char *espaces, char *att)
{
	int len;
	int esp_len;
	int att_len;

	esp_len = 0;
	while (espaces[esp_len])
		esp_len++;
	att_len = 0;
	while (att[att_len])
		att_len++;
	len = 0;
	while (mant[len] && mant[len] != '.')
		len++;
	len++;
	if (flag->zero)
		write(1, att, att_len);
	if (!flag->minus)
		write(1, espaces, esp_len);
	if (!flag->zero)
		write(1, att, att_len);
	if ((len = print_mant(flag, mant)) == -1)
		return (-1);
	if (flag->minus)
		write(1, espaces, esp_len);
	return (len + esp_len + att_len);
}

void	char_to_bits(char c, char *mant, char *two, int nb)
{
	int i;
	int gap;

	(void)mant;
	gap = (nb == 6) ? 8 : 128;
	while (gap > 0)
	{
		i = (c & gap);
		if (i >= 1)
			ft_add(mant, two);
		gap /= 2;
		ft_divide(two);
	}
}

int	create_doub(char *bits, char *mant)
{
	int		i;
	int		exp;
	char	two[56];

	ft_bzero(two, 56);
	ft_strcat(two, "0.5\0");
	exp = ((bits[7] & 0x7F) << 4) + ((bits[6] & 0xF0) >> 4) - 1023;
	i = 6;
	while (i > -1)
	{
		char_to_bits(bits[i], mant, two, i);
		i--;
	}
	if ((i = is_exept(mant, exp)) < 0)
		return (i);
	while (exp > 0)
	{
		ft_multiply(mant);
		exp--;
	}
	while (exp < 0)
	{
		ft_divide(mant);
		exp++;
	}
	return (0);
}
