/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 04:53:01 by snunes            #+#    #+#             */
/*   Updated: 2019/06/14 14:43:23 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	(*g_func[])(t_flags *flag, va_list ap, char buff[2000]) = 
{
	&print_char, &print_str, &print_ptr, &get_hh_int, &get_uhh_int,
	&get_h_int, &get_uh_int, &get_l_int, &get_ul_int, &get_ll_int,
	&get_ull_int, &get_L_double, &get_double, &get_int, &get_u_int,
	&get_j_int, &get_uj_int
};

int print_char(t_flags *flag, va_list ap, char buff[2000])
{
	unsigned char c;

	(void)buff;
	c = (unsigned char)va_arg(ap, int);
	while (!flag->minus && flag->width-- > 1)
		buff[flag->bpos++] = ' ';
	buff[flag->bpos++] = (c == 0) ? -1 : c;
	while (flag->minus && flag->width-- > 1)
		buff[flag->bpos++] = ' ';
	return (1);
}

int	print_str(t_flags *flag, va_list ap, char buff[2000])
{
	int i;
	char *str;
	int len;

	i = 0;
	str = va_arg(ap, char *);
	if (str != NULL && !*str)
	{
		while (flag->width-- && !(buff[flag->bpos++] = '\0'))
			write(1, " ", 1);
		return (1);
	}
	if (str == NULL && (!(str = (char *)ft_memalloc(sizeof(char) * 7))
				|| !(str = ft_strcat(str, "(null)"))))
		return (-1);
	len = ft_strlen(str);
	flag->preci = (flag->preci < 0) ? len : flag->preci;
	len = (len > flag->preci) ? flag->preci : len;
	while (i < len)
		i++;
	while (!flag->minus && flag->width-- > i && ++len)
		buff[flag->bpos++] = ' ';
	i = 0;
	while (str[i] && flag->preci--)
		buff[flag->bpos++] = str[i++];
	while (flag->minus && flag->width-- > len)
		buff[flag->bpos++] = ' ';
	return (1);
}

int	print_ptr(t_flags *flag, va_list ap, char bf[2000])
{
	void *ptr;
	int i;
	int len;
	long int res;

	i = 0;
	bf[(*flag).bpos++] = '0';
	bf[(*flag).bpos++] = 'x';
	len = 2;
	ptr = va_arg(ap, void*);
	res = (long int)ptr;
	while (res > 0 && ++len)
		res /= 16;
	while (!(*flag).minus && (*flag).width-- > len)
		bf[(*flag).bpos++] = ' ';
	res = (long int)ptr;
	while (res > 0)
	{
		(*flag).conv = (res % 16 > 10) ? 'a' + res % 16 - 10 : '0' + res % 10;
		bf[(*flag).bpos++] = (*flag).conv;
		res /= 16;
	}
	while ((*flag).minus && (*flag).width-- > len)
		bf[(*flag).bpos++] = ' ';
	return (1);
}

int	get_next_percent(const char *str, t_flags *flag, char buff[2000])
{
	int pos;
	int i;

	i = 0;
	ft_reset_flags(flag, 7);
	pos = (*flag).spos;
	while (str[pos])
	{
		if ((str[pos] == '%'))
			return (pos);
		buff[(*flag).bpos++] = str[pos++];
	}
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flags flag;
	char	buff[2000];
	int		len;
	int		i;
	
	i = 0;
	ft_reset_flags(&flag, 10);
	len = 0;
	buff[1999] = '\0';
	va_start(ap, format);
	while ((flag.spos = get_next_percent(format, &flag, buff) + 1) != 0)
	{
	//	printf("sortie get_percent, flags[9][0] = %d, str = %c\n", flags[9][0], format[flags[9][0]]);
		buff[flag.bpos] = 0;
		ft_putstr(buff);
		len += flag.bpos;
		flag.bpos = 0;
		//printf("on a nb = %d\n", i);
		if((i = find_first_flags(format, &flag) - 1) >= 0)
			(*g_func[i])(&flag, ap, buff);
		buff[flag.bpos] = 0;
		ft_putstr(buff);
		len += flag.bpos;
		flag.bpos = 0;
//		printf("position sur la chaine = %d\n", flags[9][0]);
	//	printf("a la recherche du prochain arg\n");
	}
	buff[flag.bpos] = 0;
	ft_putstr(buff);
	len += flag.bpos;
	//printf("plus de argument\n");
	va_end(ap);
	return (len);
}
