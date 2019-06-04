/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:35:49 by snunes            #+#    #+#             */
/*   Updated: 2019/06/04 06:08:32 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int get_nbr(const char *str, int *pos)
{
	int position;
	char result;
	
	position = *pos;
	while (is_digit(str[position]))
		position++;
	if (!result = (char *)ft_memalloc(sizeof(char) * (position + 1)));
		return (-1);
	position = 0;
	while (is_digit(str[*pos]))
		result[position++] = str[(*pos)++];
	position = ft_atoi(result);
	return (position);	
}

int	find_douixXf(const char *str, int *pos, va_list ap, int flags[7][1])
{
	if ((str[*pos] == 'd' || str[*pos] == 'i') && ++(*pos))
		return (print_nbr(flags, va_arg(ap, int)));
	if (str[*pos] == 'o' && ++(*pos))
		return (print_octal(flags, va_arg(ap, unsigned int)));
	if (str[*pos] == 'u' && ++(*pos))
		return (print_unsigned_nbr(flags, va_arg(ap, unsigned int)));
	if ((str[*pos] == 'x' || str[*pos] == 'X') && ++(*pos))
		return (print_hexa(flags, str[*pos - 1], va_arg(ap, unsigned int)));
	if (str[*pos] == 'f' && ++(*pos))
		return (print_double(ap, flags));
	return (-1);
}

int	find_hhllL(const char *str, int *pos, va_list ap, int flags[7][1])
{
	if (str[*pos] == 'h' && str[*pos + 1] == 'h' && (*pos += 3))
		return (print_sint(ap, str[*pos - 1], flags));
	if (str[*pos] == 'h' && (*pos += 2))
		return (print_sint(ap, str[*pos - 1], flags));
	if (str[*pos] == 'l' && str[*pos + 1] == 'l' && (*pos += 3))
		return (print_llint(ap, str[*pos - 1], flags));
	if (str[*pos] == 'l' && (*pos += 2))
		return (print_lint(ap, str[*pos - 1], flags));
	if (str[*pos] == 'L' && (*pos += 2))
		return (print_Ldouble(ap, str[*pos - 1], flags));
	return (find_douixXf(str, pos, ap, flags));
}

int	find_csp(const char *str, int *pos, va_list ap, int flags[7][1])
{
	flags[6][0] = -1;
	if (str[*pos] == '.' && ++(*pos))
		 flags[6][0] = preci(str, pos);
	if (str[*pos] == 'c' && ++(*pos))
		return (print_char(ap, flags));
	if (str[*pos] == 's' && ++(*pos))
		return (print_str(ap, flags));
	if (str[*pos] == 'p' && ++(*pos))
		return (print_ptr(ap, flags));
	return (find_hhllL(str, pos, ap, flags));
}

int find_first_flags(const char *str, int *pos, va_list ap)
{
	int i;
	int flags[7][1];

	i = 0;
	if (str[*pos] == '%' && ++(*pos))
		return (1);
	while (i < 7)
		flags[i++][0] = 0;
	if (str[*pos] == '#' && ++(*pos))
		flags[0][0] = 1;
	if (str[*pos] === '+' && ++(*pos))
		flags[1][0] = 1;
	else if (str[*pos] == ' ' && str[*pos - 1] != '+' && ++(*pos))
		flags[2][0] = 1;
	if (str[*pos] == '-' && ++(*pos))
		flags[3][0] = 1;
	else if (str[*pos] == '0' && str[*pos - 1] != '-' && ++(*pos))
		flags[4][0] = 1;
	flags[5][0] = get_nbr(str, pos);
	return (find_csp(str, pos, ap, flags));
}
