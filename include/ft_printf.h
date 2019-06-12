/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:50:17 by snunes            #+#    #+#             */
/*   Updated: 2019/06/12 19:08:36 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LLINT 1000000000000000000


#include <stdio.h>


int store_char(int flags[10][1], char buff[2000], char c);
int	store_unb(int flags[10][1], char buff[2000], unsigned long long int nb);
int	store_nbr(int flags[10][1], long double nbr, char buff[2000], int mode);
int	order_flags(int flags[7][1]);
int	store_nb(int flags[10][1], char buff[2000], long long int nb);
int	store_unb(int flags[10][1], char buff[2000], unsigned long long int nb);
int	store_oct(int flags[10][1], char buff[2000], unsigned long long int nb);
int	store_hex(int flags[10][1], char buff[2000], unsigned long long int nb);
int	store_float_fspaces(int flags[10][1], int sign, int len, char bf[2000]);
int	store_espaces(int flags[10][1], int len, char buff[2000]);
int	store_fspaces(int flags[10][1], int sign, int len, char buff[2000]);
int	get_nbr(const char *str, int *pos);
int	find_douixXf(const char *str, int pos);
int	find_hhllL(const char *str, int flags[10][1]);
int	find_csp(const char *str, int flags[10][1]);
int	find_first_flags(const char *str, int flags[10][1]);
int	get_uh_int(int flags[10][1], va_list ap, char buff[2000]);
int	get_u_int(int flags[10][1], va_list ap, char buff[2000]);
int	get_ul_int(int flags[10][1], va_list ap, char buff[2000]);
int	get_ull_int(int flags[10][1], va_list ap, char buff[2000]);
int	get_L_double(int flags[10][1], va_list ap, char buff[2000]);
int	get_ll_int(int flags[10][1], va_list ap, char buff[2000]);
int	get_l_int(int flags[10][1], va_list ap, char buff[2000]);
int	get_h_int(int flags[10][1], va_list ap, char buff[2000]);
int	get_hh_int(int flags[10][1], va_list ap, char buff[2000]);
int	get_double(int flags[10][1], va_list ap, char buff[2000]);
int	get_uhh_int(int flags[10][1], va_list ap, char buff[2000]);
int	get_int(int flags[10][1], va_list ap, char buff[2000]);
int	get_next_percent(const char *str, int flags[10][1], char buff[2000]);
int	ft_printf(const char *format, ...);
int	print_char(int flags[10][1], va_list ap, char buff[2000]);
int	print_str(int flags[10][1], va_list ap, char buff[2000]);
int	print_ptr(int flags[10][1], va_list ap, char bf[2000]);

#endif
