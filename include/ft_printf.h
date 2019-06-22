/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:50:17 by snunes            #+#    #+#             */
/*   Updated: 2019/06/22 19:33:14 by snunes           ###   ########.fr       */
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
	int	sign;
	int	spos;
	int nb;
}				t_flags;

int fill_att(t_flags *flag, uintmax_t nbr, char att[5]);
char *fill_nb_base(t_flags *flag, uintmax_t nbr, int base);
char *make_espaces(t_flags *flag, int len);
int ft_add(char mantissa[311], char two[311]);
int	ft_multiply(char buff[311]);
int	ft_divide(char buff[311]);
void ft_shiftstr(char buff[311], int mode);
int	get_info(long double nbr, long double *mantisse, int *exp);
int exept(int nb_exept, t_flags *flag, char buff[311], int sign);
int handle_zero(t_flags *flag, char buff[311], int sign);
int ft_round(char buff[311]);
int store_double(t_flags *flag, long double mantisse, int exp, char buff[311]);
int	print_nb(t_flags *flag, intmax_t nb, int base);
int store_fnb(long double nbr, t_flags *flag, int len);
int	get_j_int(t_flags *flag, va_list ap);
int	get_uj_int(t_flags *flag, va_list ap);
void	ft_reset_flags(t_flags *flag, int nb_flags);
int	print_unb(t_flags *flag, uintmax_t nb, int base);
int	store_nbr(t_flags *flag, long double nbr, int mode);
int	order_flags(t_flags *flag);
int	store_float_fspaces(t_flags *flag, int sign, long double nbr);
int	get_nbr(const char *str, int *pos);
int	find_douixXf(const char *str, int pos);
int	find_hhllL(const char *str, t_flags *flag);
int	find_csp(const char *str, t_flags *flag);
int	find_first_flags(const char *str, t_flags *flag);
int	get_uh_int(t_flags *flag, va_list ap);
int	get_u_int(t_flags *flag, va_list ap);
int	get_ul_int(t_flags *flag, va_list ap);
int	get_ull_int(t_flags *flag, va_list ap);
int	get_L_double(t_flags *flag, va_list ap);
int	get_ll_int(t_flags *flag, va_list ap);
int	get_l_int(t_flags *flag, va_list ap);
int	get_h_int(t_flags *flag, va_list ap);
int	get_hh_int(t_flags *flag, va_list ap);
int	get_double(t_flags *flag, va_list ap);
int	get_uhh_int(t_flags *flag, va_list ap);
int	get_int(t_flags *flag, va_list ap);
int	get_next_percent(const char *str, t_flags *flag);
int	ft_printf(const char *format, ...);
int	print_char(t_flags *flag, va_list ap);
int	print_str(t_flags *flag, va_list ap);
int	print_ptr(t_flags *flag, va_list ap);

#endif
