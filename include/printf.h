/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:47:14 by snunes            #+#    #+#             */
/*   Updated: 2019/06/04 07:34:41 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include "../libft/include/libft.h"
#include <stdarg.h>
#include <unistd.h>


#include <stdio.h>


void	print_endspace(int flags[7][1], int len);
void	print_frontnb(int flags[7][1], long double nb, char c);
void	print_frontspaces(int flags[7][1], int len);
int		find_first_flags(const char *str, int *pos, va_list ap);
void	print_Ldouble(va_list ap, char c, int flags[7][1]);
void	print_lint(va_list ap, char c, int flags[7][1]);
void	print_llint(va_list ap, char c, int flags[7][1]);
void	print_sint(va_list ap, char c, int flags[7][1]);
void	print_double(va_list ap, int flags[7][1]);
void	print_hexa(int flags, char letter, long long int nbr);
void	print_octal(int flags[7][1], long long int nbr);
void	print_nbr(int flags[7][1], long long int nbr);
int		ft_printf(const char *format, ...);
void	print_char(va_list ap, int flags[7][1]);
void	print_str(va_list ap, int flags[7][1]);
void	print_ptr(va_list ap, int flags[7][1]);

#endif
