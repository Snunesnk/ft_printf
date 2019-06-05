/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 18:35:49 by snunes            #+#    #+#             */
/*   Updated: 2019/06/05 02:10:10 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int get_nbr(const char *str, int *pos)
{
	int position;
	char *result;
	
	position = *pos;
	while (ft_isdigit(str[position]))
		position++;
	if (!(result = (char *)ft_memalloc(sizeof(char) * (position + 1))))
		return (-1);
	position = 0;
	while (ft_isdigit(str[*pos]))
		result[position++] = str[(*pos)++];
	position = ft_atoi(result);
	return (position);	
}

void	find_douixXf(const char *str, int *pos, va_list ap, int flags[7][1])
{
	if ((str[*pos] == 'd' || str[*pos] == 'i') && ++(*pos))
		print_nbr(flags, va_arg(ap, int));
	else if (str[*pos] == 'o' && ++(*pos))
		print_octal(flags, va_arg(ap, unsigned int));
	else if (str[*pos] == 'u' && ++(*pos))
		print_nbr(flags, va_arg(ap, unsigned int));
	else if ((str[*pos] == 'x' || str[*pos] == 'X') && ++(*pos))
		print_hexa(flags, str[*pos - 1], va_arg(ap, unsigned int));
	else if (str[*pos] == 'f' && ++(*pos))
		print_double(ap, flags);
}

void	find_hhllL(const char *str, int *pos, va_list ap, int flags[7][1])
{
	if (str[*pos] == 'h' && str[*pos + 1] == 'h' && (*pos += 3))
		print_sint(ap, str[*pos - 1], flags);
	else if (str[*pos] == 'h' && (*pos += 2))
		print_sint(ap, str[*pos - 1], flags);
	else if (str[*pos] == 'l' && str[*pos + 1] == 'l' && (*pos += 3))
		print_llint(ap, str[*pos - 1], flags);
	else if (str[*pos] == 'l' && (*pos += 2))
		print_lint(ap, str[*pos - 1], flags);
	else if (str[*pos] == 'L' && (*pos += 2))
		print_Ldouble(ap, flags);
	else
		find_douixXf(str, pos, ap, flags);
}

void	find_csp(const char *str, int *pos, va_list ap, int flags[7][1])
{
	flags[6][0] = -1;
	if (str[*pos] == '.' && ++(*pos))
		 flags[6][0] = get_nbr(str, pos);
	if (str[*pos] == 'c' && ++(*pos))
		print_char(ap, flags);
	else if (str[*pos] == 's' && ++(*pos))
		print_str(ap, flags);
	else if (str[*pos] == 'p' && ++(*pos))
		print_ptr(ap, flags);
	else
		find_hhllL(str, pos, ap, flags);
}

void	find_first_flags(const char *str, int *pos, va_list ap)
{
	int i;
	int flags[7][1];

	i = 0;
	if (str[*pos] == '%' && ++(*pos))
		return ((void)i);
	while (i < 7)
		flags[i++][0] = 0;
	while (str[*pos] != '.' && (!ft_isalnum(str[*pos]) && str[*pos] != 0))
	{
		if (str[*pos] == '#' && ++(*pos))
			flags[0][0] = 1;
		if (str[*pos] == '+' && ++(*pos))
			flags[1][0] = 1;
		if (str[*pos] == ' '  && ++(*pos))
			flags[2][0] = 1;
		if (str[*pos] == '-' && ++(*pos))
			flags[3][0] = 1;
		if (str[*pos] == '0' && ++(*pos))
			flags[4][0] = 1;
	}
	order_flags(flags);
	flags[5][0] = get_nbr(str, pos);
	find_csp(str, pos, ap, flags);
}
