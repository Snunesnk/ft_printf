/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_multi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 15:01:50 by snunes            #+#    #+#             */
/*   Updated: 2019/06/27 20:11:32 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_all(t_flags *flag, char *esp, char *num, char att[5])
{
	int len;

	len = 0;
	if (flag->zero)
		len += write(1, att, ft_strlen(att));
	if (!flag->minus)
		len += write(1, esp, ft_strlen(esp));
	if (!flag->zero)
		len += write(1, att, ft_strlen(att));
	len += write(1, num, ft_strlen(num));
	if (flag->minus)
		len += write(1, esp, ft_strlen(esp));
	return (len);
}

int	print_nb(t_flags *flag, intmax_t nb, int base)
{
	char	*num;
	char	*esp;
	char	att[5];
	int		len;
	int		esp_len;

	flag->sign = (nb < 0) ? -1 : 1;
	nb = (nb < 0) ? -nb : nb;
	flag->diez = (flag->preci > ft_nblen(nb, 8)) ? 2 : flag->diez;
	len = (flag->preci > ft_nblen(nb, base)) ? flag->preci : ft_nblen(nb, base);
	len = (flag->preci == 0 && !nb) ? 0 : len;
	esp_len = fill_att(flag, nb, att);
	esp_len = flag->width - (esp_len + len);
	if (!(num = fill_nb_base(flag, nb, base)))
		return (-1);
	if (!(esp = make_espaces(flag, esp_len)))
	{
		free(num);
		return (-1);
	}
	len = print_all(flag, esp, num, att);
	free(num);
	free(esp);
	return (len);
}

int	print_unb(t_flags *flag, uintmax_t nb, int base)
{
	char	*num;
	char	*esp;
	char	att[5];
	int		len;
	int		esp_len;

	flag->diez = (flag->diez && flag->preci > ft_nblen(nb, 8)) ? 2 : flag->diez;
	flag->sign = 1;
	len = (flag->preci > ft_nblen(nb, base)) ? flag->preci : ft_nblen(nb, base);
	len = (flag->preci == 0 && !nb) ? 0 : len;
	esp_len = fill_att(flag, nb, att);
	esp_len = flag->width - (esp_len + len);
	if (!(num = fill_nb_base(flag, nb, base)))
		return (-1);
	if (!(esp = make_espaces(flag, esp_len)))
	{
		free(num);
		return (-1);
	}
	len = print_all(flag, esp, num, att);
	free(num);
	free(esp);
	return (len);
}
