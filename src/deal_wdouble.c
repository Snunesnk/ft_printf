/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_wdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:51:29 by snunes            #+#    #+#             */
/*   Updated: 2019/06/24 20:50:29 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_round(char *mant, char *precision)
{
	int i;
	int unit;
	char two[55];

	ft_bzero(two, 56);
	two[0] = '1';
	i = 0;
	while (precision[i])
		i++;
	i--;
	unit = precision[i] - 48;
	if (unit >= 5 && precision[--i] != '.')
	{
		unit = precision[i] - 47;
		precision[i] = (unit % 10) + 48;
		while (unit > 9 && precision[--i] != '.')
		{
			unit = precision[i] - 47;
			precision[i] = (unit % 10) + 48;
		}	
	}
	if (precision[i] == '.')
		ft_add(mant, two);
	return ((precision[i] == '.') ? 1 : 0);
}

int print_mant(t_flags *flag, char *mant)
{
	int len;
	int m_len;
	int precis;
	char preci[flag->preci + 3];

	ft_bzero(preci, flag->preci + 3);
	precis = 0;
	preci[flag->preci + 3] = '\0';
	m_len = 0;
	while (mant[m_len] != '.')
		m_len++;
	while (flag->preci-- > -2)
	{
		preci[precis] = (mant[m_len + precis]) ? mant[m_len + precis] : '0';
		precis++;
	}
	m_len += ft_round(mant, preci);
	len = write(1, mant, m_len);
	len += write(1, preci, precis - 1);
	return (len);
}

int	print_double(t_flags *flag, char *mant, char *espaces, char *att)
{
	int len;
	int esp_len;
	int att_len;

	flag->preci = (flag->preci == 0) ? flag->diez : flag->preci;
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
	len = print_mant(flag, mant);
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
	char	two[55];

	ft_bzero(two, 55);
	two[0] = '1';
	exp = ((bits[7] & 0x7F) << 4) + ((bits[6] & 0xF0) >> 4) - 1023;
	i = 6;
	ft_divide(two);
	while (i > -1)
	{
		char_to_bits(bits[i], mant, two, i);
		i--;
	}
	if (is_exept(mant, exp) < 0)
		return (is_exept(mant, exp));
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
