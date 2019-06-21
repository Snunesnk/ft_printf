/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_func_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:41:14 by snunes            #+#    #+#             */
/*   Updated: 2019/06/21 11:57:57 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int get_uhh_int(t_flags *flag, va_list ap)
{
	(void)flag;
	(void)ap;
	return (0);/*
	unsigned char nbr;

	flag->plus = 0;
	flag->space = 0;
	nbr = va_arg(ap, int);
	if (flag->conv == 'u')
		return (store_unb(flag, buff, nbr));
	if (flag->conv == 'o')
		return (store_oct(flag, buff, nbr));
	if (flag->conv == 'x' || (*flag).conv == 'X')
		return (store_hex(flag, buff, nbr));
	if (flag->conv == 'c')
		return (store_char(flag, buff, nbr));
	return (-1);
*/}

int get_uh_int(t_flags *flag, va_list ap)
{
	(void)flag;
	(void)ap;
	return (0);/*
	unsigned short int nbr;

	flag->plus = 0;
	flag->space = 0;
	nbr = va_arg(ap, int);
	if (flag->conv == 'u')
		return (store_unb(flag, buff, nbr));
	if (flag->conv == 'o')
		return (store_oct(flag, buff, nbr));
	if (flag->conv == 'x' || (*flag).conv == 'X')
		return (store_hex(flag, buff, nbr));
	if (flag->conv == 'c')
			return (store_char(flag, buff, nbr));
	return (-1);
*/}

int get_uj_int(t_flags *flag, va_list ap)
{
	(void)flag;
	(void)ap;
	return (0);/*
	uintmax_t nbr;

	flag->plus = 0;
	flag->space = 0;
	nbr = va_arg(ap, uintmax_t);
	if (flag->conv == 'u')
		return (store_unb(flag, buff, nbr));
	if (flag->conv == 'o')
		return (store_oct(flag, buff, nbr));
	if (flag->conv == 'x' || (*flag).conv == 'X')
		return (store_hex(flag, buff, nbr));
	if (flag->conv == 'c')
			return (store_char(flag, buff, nbr));
	return (-1);
*/}

int	get_j_int(t_flags *flag, va_list ap)
{
	(void)flag;
	(void)ap;
	return (0);/*
	intmax_t nbr;

	flag->plus = 0;
	flag->space = 0;
	nbr = va_arg(ap, intmax_t);
	if (flag->conv == 'd' || flag->conv == 'i' || flag->conv == 'D')
		return (store_nb(flag, buff, nbr));
	if (flag->conv == 'u')
		return (store_unb(flag, buff, nbr));
	if (flag->conv == 'o')
		return (store_oct(flag, buff, nbr));
	if (flag->conv == 'x' || (*flag).conv == 'X')
		return (store_hex(flag, buff, nbr));
	if (flag->conv == 'c')
			return (store_char(flag, buff, nbr));
	return (-1);
*/}