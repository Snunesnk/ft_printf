/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:35:49 by snunes            #+#    #+#             */
/*   Updated: 2019/06/02 17:01:53 by snunes           ###   ########.fr       */
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

int	find_douixXf(const char *str, int *pos, va_list ap, int precision)
{
	if ((str[*pos] == 'd' || str[*pos] == 'i') && ++(*pos))
		return (print_nbr(precision, va_arg(ap, int)));
	if (str[*pos] == 'o' && ++(*pos))
		return (print_octal(precision, va_arg(ap, unsigned int)));
	if (str[*pos] == 'u' && ++(*pos))
		return (print_unsigned_nbr(precision, va_arg(ap, unsigned int)));
	if ((str[*pos] == 'x' || str[*pos] == 'X') && ++(*pos))
		return (print_hexa(precision, str[*pos - 1], va_arg(ap, unsigned int)));
	if (str[*pos] == 'f' && ++(*pos))
		return (print_double(ap, precision));
	return (-1);
}

int	find_hhllL(const char *str, int *pos, va_list ap, int precision)
{
	if (str[*pos] == 'h' && str[*pos + 1] == 'h' && (*pos += 3))
		return (print_sint(ap, str[*pos - 1], precision));
	if (str[*pos] == 'h' && (*pos += 2))
		return (print_sint(ap, str[*pos - 1], precision));
	if (str[*pos] == 'l' && str[*pos + 1] == 'l' && (*pos += 3))
		return (print_llint(ap, str[*pos - 1], precision));
	if (str[*pos] == 'l' && (*pos += 2))
		return (print_lint(ap, str[*pos - 1], precision));
	if (str[*pos] == 'L' && (*pos += 2))
		return (print_Ldouble(ap, str[*pos - 1], precision));
	return (find_douixXf(str, pos, ap, precision));
}

int	find_csp(const char *str, int *pos, va_list ap)
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
	return (find_hhllL(str, pos, ap, precision));
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
		find_csp(format, &pos, ap);
	}
	va_end(ap);
	return (0);
}
