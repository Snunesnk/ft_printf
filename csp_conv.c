/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csp_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:46:28 by snunes            #+#    #+#             */
/*   Updated: 2019/05/28 19:53:48 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_char(va_list ap)
{
	unsigned char c;
	c = (unsigned char)va_arg(ap, int);
	return (write(1, &c, 1));
}

int	print_str(va_list ap, int precision)
{
	int i;
	char *str;

	i = 0;
	str = va_arg(ap, char *);
	precision = (precision < 0) ? ft_strlen(str) : precision;
	while (str[i] && i < precision)
	{
		write(1, &str[i], 1);
		++i;
	}
	return (1);
}

int print_ptr(va_list ap)
{
	char *tab;
	void *ptr;
	int i;
	long int res;

	i = 0;
	ptr = va_arg(ap, void*);
	tab = (char *)ft_memalloc(sizeof(char) * 15);
	tab[14] = 0;
	tab[13] = '0';
	tab[12] = 'x';
	res = (long int)ptr;
	while (res > 0)
	{
		tab[i] = (res % 16 < 10) ? (res % 16) + '0' : (res % 16) - 10 + 'a';
		res /= 16;
		i++;
	}
	ft_strrev(tab);
	ft_putstr(tab);
	return (1);
}
