/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:47:14 by snunes            #+#    #+#             */
/*   Updated: 2019/05/30 13:31:39 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include "../libft/include/libft.h"
#include <stdarg.h>
#include <unistd.h>


#include <stdio.h>

int print_Ldouble(va_list ap, char c, int precision);
int print_lint(va_list ap, char c, int precision);
int print_llint(va_list ap, char c, int precision);
int print_sint(va_list ap, char c, int precision);
int print_double(va_list ap, int precision);
int print_hexa(int precision, char letter, long long int nbr);
int print_unsigned_nbr(int pecision, long long int nbr);
int print_octal(int precision, long long int nbr);
int print_nbr(int precision, long long int nbr);
int	ft_printf(const char *format, ...);
int	print_char(va_list ap);
int print_str(va_list ap, int precision);
int print_ptr(va_list ap);

#endif
