/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 04:53:01 by snunes            #+#    #+#             */
/*   Updated: 2019/06/05 23:44:50 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_char(va_list ap, int flags[7][1])
{
	unsigned char c;

	c = (unsigned char)va_arg(ap, int);
	while (!flags[3][0] && flags[5][0] && flags[5][0] - 1)
	{
		if (flags[4][0] == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		flags[5][0] -= 1;
	}
	write(1, &c, 1);
	while (flags[3][0] && flags[5][0] && flags[5][0] - 1)
	{
		write(1, " ", 1);
		flags[5][0] -= 1;
	}
}

void	print_str(va_list ap, int flags[7][1])
{
	int i;
	char *str;

	i = 0;
	str = va_arg(ap, char *);
	flags[6][0] = (flags[6][0] < 0) ? ft_strlen(str) : flags[6][0];
	while (str[i] && i < flags[6][0])
		++i;
	str[i] = '\0';
	while (!flags[3][0] && flags[5][0] && (flags[5][0]--) - ft_strlen(str))
		write(1, " ", 1);
	ft_putstr(str);
	while (flags[3][0] && flags[5][0] && (flags[5][0]--) - ft_strlen(str))
		write(1, " ", 1);
}

void	print_ptr(va_list ap, int flags[7][1])
{
	char tab[15];
	void *ptr;
	int i;
	long int res;

	i = 0;
	ptr = va_arg(ap, void*);
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
	while (!flags[3][0] && flags[5][0] && (flags[5][0]--) - 14)
		write(1, " ", 1);
	ft_strrev(tab);
	ft_putstr(tab);
	while (flags[3][0] && flags[5][0] && (flags[5][0]--) - 14)
		write(1, " ", 1);
}

int	get_next_percent(const char *str, int pos, char buff[2000])
{
	while (str[pos])
	{
		if ((pos > 0 && str[pos - 1] != '%' && str[pos] == '%')
				|| (pos == 0 && str[pos] == '%'))
			return (pos);
		write(1, &(str[pos]), 1);
		buff[pos] = str[pos];
		++pos;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		pos;
	va_list	ap;
	char	buffer[2000];
	va_list	(*all_ft[5])(int flags[7][1], va_list ap, char buff[2000], int pos);

	buffer[1999] = '\0';
	pos = 0;
	va_start(ap, format);
	while ((pos = get_next_percent(format, pos, buffer)) != 0)
	{
		pos++;
		printf("\nbuffer = %s\n", buffer);
		find_first_flags(format, &pos, ap);
	}
	va_end(ap);
	return (0);
}
