/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:30:10 by snunes            #+#    #+#             */
/*   Updated: 2019/06/12 20:24:52 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int get_nbr(const char *str, int *pos)
{
	int position;
	char *result;

	position = 0;
	while (ft_isdigit(str[position + *pos]))
		position++;
	if ((result = (char *)ft_memalloc(sizeof(char) * (position + 1))) == NULL)
		return (-1);
	position = 0;
	while (ft_isdigit(str[*pos]))
		result[position++] = str[(*pos)++];
	position = ft_atoi(result);
	return (position);	
}

int	find_douixXf(const char *str, int pos)
{
	int nb;

	nb = -1;
	if (str[pos] == 'c')
		nb = 1;
	else if (str[pos] == 's')
		nb = 2;
	else if (str[pos] == 'p')
		nb = 3;
	else if (str[pos] == 'd' || str[pos] == 'i')
		nb = 15;
	else if (str[pos] == 'o' || str[pos] == 'x' || str[pos] == 'X'
			|| str[pos] == 'u')
		nb = 15;
	else if (str[pos] == 'f')
		nb = 13;
	else if (str[pos] == 'D')
		nb = 8;
	return (nb);
}

int	find_hhllL(const char *str, int flags[10][1])
{
	int nb;
	int pos;

	flags[6][0] = -1;
	if (str[flags[9][0]] == '.' && ++flags[9][0])
		 flags[6][0] = get_nbr(str, &flags[9][0]);
	pos = flags[9][0];
	if (str[pos] == 'h' && str[pos + 1] == 'h' && (pos += 2) && (nb = 5))
		flags[7][0] = str[pos];
	else if (str[pos] == 'h' && (pos += 1) && (nb = 7))
		flags[7][0] = str[pos];
	else if (str[pos] == 'l' && str[pos + 1] == 'l' && (pos += 2) && (nb = 11))
		flags[7][0] = str[pos];
	else if (str[pos] == 'l' && (pos += 1) && (nb = 9))
		flags[7][0] = str[pos];
	else if (str[pos] == 'L' && (pos += 1) && (nb = 12))
		flags[7][0] = str[pos];
	else
		nb = find_douixXf(str, pos);
	flags[7][0] = str[pos];
	flags[9][0] = pos + 1;
	nb = (str[pos] == 'd' || str[pos] == 'i') ? nb - 1 : nb;
	return (nb);
}

int	find_first_flags(const char *str, int flags[10][1])
{
	int pos;

	pos = flags[9][0]--;
	if (str[pos] == '%' && ++(pos))
		return (0);
	while (flags[9][0] != pos)
	{
		flags[9][0] = pos;
		if (str[pos] == '#' && ++pos)
			flags[0][0] = 1;
		if (str[pos] == '+' && ++pos)
			flags[1][0] = 1;
		if (str[pos] == ' '  && ++pos)
			flags[2][0] = 1;
		if (str[pos] == '-' && ++pos)
			flags[3][0] = 1;
		if (str[pos] == '0' && ++pos)
			flags[4][0] = 1;
	}
	order_flags(flags);
	if (ft_isdigit(str[pos]))
		flags[5][0] = get_nbr(str, &pos);
	flags[9][0] = pos;
	return (find_hhllL(str, flags));
}
