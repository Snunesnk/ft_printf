/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:50:17 by snunes            #+#    #+#             */
/*   Updated: 2019/06/27 20:37:34 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_LLINT 1000000000000000000

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
	int len;
	int color;
}				t_flags;

int				print_all(t_flags *flag, char *esp, char *num, char *att);
int				handle_colors(t_flags *flag, const char*str);
int				create_l_doub(char *bits, char *mant);
int				handle_exept(t_flags *flag, int exept, int sign);
int				print_double(t_flags *flag, char *mant, char *espaces,
																	char *att);
int				create_doub(char *bits, char *mant);
int				fill_att(t_flags *flag, uintmax_t nbr, char *att);
char			*fill_nb_base(t_flags *flag, uintmax_t nbr, int base);
char			*make_espaces(t_flags *flag, int len);
int				ft_add(char *mantissa, char *two);
int				ft_multiply(char *buff);
void			ft_divide(char *buff);
void			ft_shiftstr(char *buff, int mode);
int				is_exept(char *mant, int exp);
int				ft_round(char *mant, int bound);
int				print_nb(t_flags *flag, intmax_t nb, int base);
int				get_j_int(t_flags *flag, va_list *ap);
int				get_uj_int(t_flags *flag, va_list *ap);
void			ft_reset_flags(t_flags *flag, int nb_flags);
int				print_unb(t_flags *flag, uintmax_t nb, int base);
int				order_flags(t_flags *flag);
int				find_flags(const char *str, t_flags *flag);
int				get_uh_int(t_flags *flag, va_list *ap);
int				get_u_int(t_flags *flag, va_list *ap);
int				get_ul_int(t_flags *flag, va_list *ap);
int				get_ull_int(t_flags *flag, va_list *ap);
int				get_l_double(t_flags *flag, va_list *ap);
int				get_ll_int(t_flags *flag, va_list *ap);
int				get_l_int(t_flags *flag, va_list *ap);
int				get_h_int(t_flags *flag, va_list *ap);
int				get_hh_int(t_flags *flag, va_list *ap);
int				get_double(t_flags *flag, va_list *ap);
int				get_uhh_int(t_flags *flag, va_list *ap);
int				get_int(t_flags *flag, va_list *ap);
int				ft_printf(const char *format, ...);
int				print_char(t_flags *flag, va_list *ap);
int				print_str(t_flags *flag, va_list *ap);
int				print_ptr(t_flags *flag, va_list *ap);

#endif
