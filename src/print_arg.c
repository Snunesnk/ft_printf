/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:30:10 by snunes            #+#    #+#             */
/*   Updated: 2019/06/18 20:42:17 by snunes           ###   ########.fr       */
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
		nb = 9;
	return (nb);
}

int	find_hhllL(const char *str, t_flags *flag)
{
	int nb;
	int pos;

	flag->preci = -1;
	if (str[flag->spos] == '.' && ++flag->spos)
		 flag->preci = get_nbr(str, &flag->spos);
	pos = flag->spos;
	if (str[pos] == 'h' && str[pos + 1] == 'h' && (pos += 2) && (nb = 5))
		flag->conv = str[pos];
	else if (str[pos] == 'h' && (pos += 1) && (nb = 7))
		flag->conv = str[pos];
	else if (str[pos] == 'l' && str[pos + 1] == 'l' && (pos += 2) && (nb = 11))
		flag->conv = str[pos];
	else if ((str[pos] == 'l' || str[pos] == 'z') && (pos += 1) 
			&& str[pos] != 'f' && (nb = 9))
		flag->conv = str[pos];
	else if (str[pos] == 'L' && (pos += 1) && (nb = 12))
		flag->conv = str[pos];
	else if (str[pos] == 'j' && (pos += 1) && (nb = 17))
		flag->conv = str[pos];
	else
		nb = find_douixXf(str, pos);
	flag->conv = str[pos];
	order_flags(flag);
	flag->spos = pos + 1;
	nb = (str[pos] == 'd' || str[pos] == 'i' || str[pos] == 'D') ? nb - 1 : nb;
	return (nb);
}

int	find_first_flags(const char *str, t_flags *flag)
{
	int pos;

	pos = flag->spos + 1;
	if (str[pos] == '%' && (flag->spos += 2))
	{
		flag->bpos += (write(1, "%", 1));
		return (0);
	}
	while (flag->spos != pos)
	{
		flag->spos = pos;
		if (str[pos] == '#' && ++pos)
			flag->diez = 1;
		if (str[pos] == '+' && ++pos)
			flag->plus = 1;
		if (str[pos] == ' ' && ++pos)
			flag->space = 1;
		if (str[pos] == '-' && ++pos)
			flag->minus = 1;
		if (str[pos] == '0' && ++pos)
			flag->zero = 1;
	}
	if (ft_isdigit(str[pos]))
		flag->width = get_nbr(str, &pos);
	flag->spos = pos;
	return (find_hhllL(str, flag));
}
