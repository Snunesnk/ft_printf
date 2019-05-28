/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snunes <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 18:47:14 by snunes            #+#    #+#             */
/*   Updated: 2019/05/28 18:41:07 by snunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

#include "../libft/include/libft.h"
#include <stdarg.h>
#include <unistd.h>


#include <stdio.h>

int	ft_printf(const char *format, ...);
int	print_char(va_list ap);
int print_str(va_list ap, int precision);
int print_ptr(va_list ap);

#endif
