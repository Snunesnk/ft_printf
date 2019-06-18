/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:50:17 by snunes            #+#    #+#             */
/*   Updated: 2019/06/18 16:39:17 by snunes           ###   ########.fr       */
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


union u_d_bits
{
	double d;
	uint64_t bits;
};

typedef struct	s_flags
{
	int diez;
	int	plus;
	int	space;
	int	minus;
	int	zero;
	int	width;
	int	preci;
	int	conv;
	int	bpos;
	int	spos;
	int nb;
}				t_flags;

int	get_info(double nbr, double *mantisse, int *exp);
int exept(int nb_exept, t_flags *flag, char buff[2000], int sign);
int handle_zero(t_flags *flag, char buff[2000], int sign);
void	ft_shiftstr(char buff[2000], int len);
int ft_round(char buff[2000], int len);
int store_double(t_flags *flag, double mantisse, int exp, char buff[2000]);
int	store_nb(t_flags *flag, char buff[2000], intmax_t nb);
int store_fnb(long double nbr, t_flags *flag, char buff[2000], int len);
int	get_j_int(t_flags *flag, va_list ap, char buff[2000]);
int	get_uj_int(t_flags *flag, va_list ap, char buff[2000]);
void	ft_reset_flags(t_flags *flag, int nb_flags);
int store_char(t_flags *flag, char buff[2000], char c);
int	store_unb(t_flags *flag, char buff[2000], uintmax_t nb);
int	store_nbr(t_flags *flag, long double nbr, char buff[2000], int mode);
int	order_flags(t_flags *flag);
int	store_unb(t_flags *flag, char buff[2000], uintmax_t nb);
int	store_oct(t_flags *flag, char buff[2000], uintmax_t nb);
int	store_hex(t_flags *flag, char buff[2000], uintmax_t nb);
int	store_float_fspaces(t_flags *flag, int sign, long double nbr, char bf[2000]);
int	store_espaces(t_flags *flag, int len, char buff[2000]);
int	store_fspaces(t_flags *flag, int sign, int len, char buff[2000]);
int	get_nbr(const char *str, int *pos);
int	find_douixXf(const char *str, int pos);
int	find_hhllL(const char *str, t_flags *flag);
int	find_csp(const char *str, t_flags *flag);
int	find_first_flags(const char *str, t_flags *flag);
int	get_uh_int(t_flags *flag, va_list ap, char buff[2000]);
int	get_u_int(t_flags *flag, va_list ap, char buff[2000]);
int	get_ul_int(t_flags *flag, va_list ap, char buff[2000]);
int	get_ull_int(t_flags *flag, va_list ap, char buff[2000]);
int	get_L_double(t_flags *flag, va_list ap, char buff[2000]);
int	get_ll_int(t_flags *flag, va_list ap, char buff[2000]);
int	get_l_int(t_flags *flag, va_list ap, char buff[2000]);
int	get_h_int(t_flags *flag, va_list ap, char buff[2000]);
int	get_hh_int(t_flags *flag, va_list ap, char buff[2000]);
int	get_double(t_flags *flag, va_list ap, char buff[2000]);
int	get_uhh_int(t_flags *flag, va_list ap, char buff[2000]);
int	get_int(t_flags *flag, va_list ap, char buff[2000]);
int	get_next_percent(const char *str, t_flags *flag, char buff[2000]);
int	ft_printf(const char *format, ...);
int	print_char(t_flags *flag, va_list ap, char buff[2000]);
int	print_str(t_flags *flag, va_list ap, char buff[2000]);
int	print_ptr(t_flags *flag, va_list ap, char bf[2000]);

#endif
