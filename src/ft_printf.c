/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 04:53:01 by snunes            #+#    #+#             */
/*   Updated: 2019/06/21 16:00:29 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_next_percent(const char *str, t_flags *flag)
{
	int		i;
	int		len;
	char	*stuff;

	i = 0;
	len = 0;
	while (str[flag->spos + len] && str[flag->spos + len] != '%')
		(len)++;
	if (!(stuff = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (-1);
	ft_reset_flags(flag, 7);
	while (str[flag->spos] && str[flag->spos] != '%')
		stuff[i++] = str[flag->spos++];
	write(1, stuff, len);
	free(stuff);
	if (!str[flag->spos] && len == 0)
		return (-1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flags flag;
	int		len;
	int		i;
	int 	w_len;
	static int	(*func[])(t_flags *flag, va_list ap) = 
	{
		&print_char, &print_str, &print_ptr, &get_hh_int, &get_uhh_int,
		&get_h_int, &get_uh_int, &get_l_int, &get_ul_int, &get_ll_int,
		&get_ull_int, &get_L_double, &get_double, &get_int, &get_u_int,
		&get_j_int, &get_uj_int
	};

	i = 0;
	ft_reset_flags(&flag, 10);
	len = 0;
	va_start(ap, format);
	//printf("\n");
	while ((w_len = get_next_percent(format, &flag)) >= 0)
	{
		len += w_len;
		if ((i = find_first_flags(format, &flag) - 1) >= 0)
			len += (*func[i])(&flag, ap);
	}
	va_end(ap);
	return (len);
}
