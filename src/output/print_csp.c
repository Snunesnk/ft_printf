/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 18:37:12 by snunes            #+#    #+#             */
/*   Updated: 2019/06/27 20:09:26 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(t_flags *flag, va_list *ap)
{
	char			*espaces;
	unsigned char	c;
	int				espaces_len;
	int				len;

	espaces_len = 0;
	c = (unsigned char)va_arg(*ap, int);
	while (flag->width-- > 1)
		espaces_len++;
	len = espaces_len + 1;
	if (!(espaces = make_espaces(flag, espaces_len)))
		return (-1);
	if (!flag->minus)
		write(1, espaces, espaces_len);
	(c == '\0') ? write(1, "\0", 1) : write(1, &c, 1);
	if (flag->minus)
		write(1, espaces, espaces_len);
	free(espaces);
	return (len);
}

int	print_str(t_flags *flag, va_list *ap)
{
	int		i;
	char	*str;
	int		len;
	char	*espaces;

	espaces = NULL;
	i = 0;
	str = va_arg(*ap, char *);
	len = (!str) ? 6 : ft_strlen(str);
	flag->preci = (flag->preci < 0 || flag->preci > len) ? len : flag->preci;
	len = flag->preci;
	while (flag->width > len + i)
		i++;
	if (!(espaces = make_espaces(flag, i)))
		return (-1);
	if (!flag->minus)
		write(1, espaces, i);
	(!str) ? write(1, "(null)", len) : write(1, str, len);
	if (flag->minus)
		write(1, espaces, i);
	free(espaces);
	return (len + i);
}

int	print_ptr(t_flags *flag, va_list *ap)
{
	unsigned long int nb;

	nb = (unsigned long int)(va_arg(*ap, void *));
	return (print_unb(flag, nb, 16));
}
