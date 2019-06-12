/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 04:53:01 by snunes            #+#    #+#             */
/*   Updated: 2019/06/12 19:13:23 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	(*g_func[])(int flags[10][1], va_list ap, char buff[2000]) = 
{
	&print_char, &print_str, &print_ptr, &get_hh_int, &get_uhh_int,
	&get_h_int, &get_uh_int, &get_l_int, &get_ul_int, &get_ll_int,
	&get_ull_int, &get_L_double, &get_double, &get_int, &get_u_int
};

int print_char(int flags[10][1], va_list ap, char buff[2000])
{
	printf("entree print_char\n");
	unsigned char c;

	c = (unsigned char)va_arg(ap, int);
	while (!flags[3][0] && flags[5][0]-- > 1)
		buff[flags[8][0]++] = ' ';
	buff[flags[8][0]++] = c;
	while (flags[3][0] && flags[5][0]-- > 1)
		buff[flags[8][0]++] = ' ';
	printf("en sortie, buff = %s\n", buff);
	return (1);
}

int	print_str(int flags[10][1], va_list ap, char buff[2000])
{
	int i;
	char *str;
	int len;

	i = 0;
	str = va_arg(ap, char *);
	len = ft_strlen(str);
	flags[6][0] = (flags[6][0] < 0) ? len : flags[6][0];
	len = flags[6][0];
	while (i < flags[6][0])
		i++;
	while (!flags[3][0] && flags[5][0]-- > i && ++len)
		buff[flags[8][0]++] = ' ';
	i = 0;
	while (flags[6][0]--)
		buff[flags[8][0]++] = str[i++];
	while (flags[3][0] && flags[5][0]-- > len)
		buff[flags[8][0]++] = ' ';
	return (1);
}

int	print_ptr(int flags[10][1], va_list ap, char bf[2000])
{
	void *ptr;
	int i;
	int len;
	long int res;

	i = 0;
	bf[flags[8][0]++] = '0';
	bf[flags[8][0]++] = 'x';
	len = 2;
	ptr = va_arg(ap, void*);
	res = (long int)ptr;
	while (res > 0 && ++len)
		res /= 16;
	while (!flags[3][0] && flags[5][0]-- > len)
		bf[flags[8][0]++] = ' ';
	res = (long int)ptr;
	while (res > 0)
	{
		flags[7][0] = (res % 16 > 10) ? 'a' + res % 16 - 10 : '0' + res % 10;
		bf[flags[8][0]++] = flags[7][0];
		res /= 16;
	}
	while (flags[3][0] && flags[5][0]-- > len)
		bf[flags[8][0]++] = ' ';
	return (1);
}

int	get_next_percent(const char *str, int flags[10][1], char buff[2000])
{
	int pos;

	pos = flags[9][0];
	while (str[pos])
	{
		if ((pos > 0 && str[pos - 1] != '%' && str[pos] == '%')
				|| (pos == 0 && str[pos] == '%'))
			return (pos);
		buff[flags[8][0]++] = str[pos++];
	}
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	int		flags[10][1];
	int		i;
	va_list	ap;
	char	buff[2000];
	int		len;
	
	len = 0;
	i = 0;
	while (i < 10)
		flags[i++][0] = 0;
	buff[1999] = '\0';
	va_start(ap, format);
	while ((flags[9][0] = get_next_percent(format, flags, buff) + 1) != 0)
	{
	//	printf("sortie get_percent, flags[9][0] = %d, str = %c\n", flags[9][0], format[flags[9][0]]);
		buff[flags[8][0]] = '\0';
		ft_putstr(buff);
		len += flags[8][0];
		flags[8][0] = 0;
		i = find_first_flags(format, flags) - 1;
	//printf("on a nb = %d\n", i);
		if (i >= 0)
			(*g_func[i])(flags, ap, buff);
		buff[flags[8][0]] = '\0';
		ft_putstr(buff);
		len += flags[8][0];
		flags[8][0] = 0;
//		printf("position sur la chaine = %d\n", flags[9][0]);
	//	printf("a la recherche du prochain arg\n");
	}
	buff[flags[8][0]] = '\0';
	ft_putstr(buff);
	len += flags[8][0];
	//printf("plus de argument\n");
	va_end(ap);
	return (len);
}
