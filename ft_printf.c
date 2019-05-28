/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:35:49 by snunes            #+#    #+#             */
/*   Updated: 2019/05/28 19:53:46 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	preci(const char *str, int *pos)
{
	int i;
	char ret[10];
	int result;

	i = 0;
	result = 0;
	while (ft_isdigit(str[*pos]))
	{
		ret[i++] = str[*pos];
		++(*pos);
	}
	result = ft_atoi(ret);
	return (result);
}

int	determine_arg(const char *str, int *pos, va_list ap)
{
	int precision;

	precision = -1;
	++(*pos);
	if (str[*pos] == '%' && ++(*pos))
		return (1);
	if (str[*pos] == '.' && ++(*pos))
		precision = preci(str, pos);
	if (str[*pos] == 'c' && ++(*pos))
		return (print_char(ap));
	if (str[*pos] == 's' && ++(*pos))
		return (print_str(ap, precision));
	if (str[*pos] == 'p' && ++(*pos))
		return (print_ptr(ap));
	return (1);


}

int	get_next_percent(const char *str, int pos)
{
	while (str[pos])
	{
		if ((pos > 0 && str[pos - 1] != '%' && str[pos] == '%') 
				|| (pos == 0 && str[pos] == '%'))
		{
			return (pos);
		}
		write(1, &(str[pos]), 1);
		++pos;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		pos;
	va_list	ap;
	
	pos = 0;
	va_start(ap, format);
	while ((pos = get_next_percent(format, pos)) != 0)
	{
		determine_arg(format, &pos, ap);
	}
	va_end(ap);
	return (0);
}
