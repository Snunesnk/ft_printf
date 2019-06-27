/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:22:00 by snunes            #+#    #+#             */
/*   Updated: 2019/06/27 13:56:18 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_flags(t_flags *flag, int nb_flags)
{
	flag->nb = 0;
	flag->len = 0;
	flag->diez = 0;
	flag->plus = 0;
	flag->space = 0;
	flag->minus = 0;
	flag->zero = 0;
	flag->width = 0;
	flag->preci = -1;
	flag->conv = 0;
	flag->sign = 0;
	flag->color = 0;
	if (nb_flags > 0)
		flag->spos = 0;
}
