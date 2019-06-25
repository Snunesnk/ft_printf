/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:22:00 by snunes            #+#    #+#             */
/*   Updated: 2019/06/25 12:01:09 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_flags(t_flags *flag, int nb_flags)
{
	int i;

	i = 0;
	flag->len = 0;
	if (i++ < nb_flags)
		flag->diez = 0;
	if (i++ < nb_flags)
		flag->plus = 0;
	if (i++ < nb_flags)
		flag->space = 0;
	if (i++ < nb_flags)
		flag->minus = 0;
	if (i++ < nb_flags)
		flag->zero = 0;
	if (i++ < nb_flags)
		flag->width = 0;
	if (i++ < nb_flags)
		flag->preci = -1;
	if (i++ < nb_flags)
		flag->conv = 0;
	if (i++ < nb_flags)
		flag->sign = 0;
	if (i++ < nb_flags)
		flag->spos = 0;
}
